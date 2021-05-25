#ifdef WIN32
#define OSexecute 0
#else
#define OSexecute 1
#endif

#include "../Headers/executewindow.h"
#include "ui_executewindow.h"
#include "../Headers/displaywindow.h"
#include "../Headers/mainwindow.h"
#include "QMessageBox"
#include "../Headers/display_4d.h"
#include "../Headers/transfert_fichiers_affichage3D.h"

extern "C" {
#include "../Headers/liste_vecteurs.h"
#include "../Headers/statistiques.h"
}

//possible variable
char carc[25] = {'x','y','z','a','b','c','d','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w'};

executewindow::executewindow(MainWindow *dad , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::executewindow)
{
    ui->setupUi(this);

    //recupeartion des données saisie avant
    QObject::connect(ui->Button_valide, SIGNAL(clicked()), this, SLOT(Validate()));
    QObject::connect(ui->Button_cancel, SIGNAL(clicked()), this, SLOT(Cancel()));

    //Retrieving the selection of the vector and the function
    nbr_vect = dad->nbr_vect;
    funct = dad->funct;
    vect_init = dad->vect_init;
}

executewindow::~executewindow()
{
    delete ui;
}

void executewindow::Validate()
{
    //Choice of the statistics
    for (int i = 0; i < 6; i++) {
        statistic[i] = false;
    }

    if(ui->CheckBox_Minimum->isChecked())
    {
     statistic[0] = true;
    }
    if(ui->CheckBox_Maximum->isChecked())
     statistic[1] = true;
    if(ui->CheckBox_Moyenne->isChecked())
     statistic[2] = true;
    if(ui->CheckBox_Variance->isChecked())
     statistic[3] = true;
    if(ui->CheckBox_Ecarttype->isChecked())
     statistic[4] = true;
    if(ui->CheckBox_Autocor->isChecked())
    {
        int shift = ui->lineEdit->text().toInt();
        if((shift > (-1*nbr_vect)) && (shift < nbr_vect) && (shift != 0))
            statistic[5] = shift;
        else
        {
            QMessageBox::critical(this, "Entry error", "The shift must be between [-nbr_vect; 0 [and] 0; nbr_vect].");
            return;
        }
    }


    //get the vector in the good shape and type
    string vect_init2 = "";
    for (int i = 0; i < (int)vect_init.length(); i++) {
        if(vect_init[i] == '(')
        {
            while (vect_init[i] != ')') {
                vect_init2+= vect_init[i];
                i++;
            }
        }
    }
    vect_init2.push_back(')');
    const char * vecteurinitial = vect_init2.c_str();

    //get the number of dimension of the selected vector
    int nbr_dim_vect = 0;
    for (int i = 0; i < (int)vect_init.size(); i++) {
        if(vect_init[i] == ',')
            nbr_dim_vect++;
    }
    nbr_dim_vect++;
    nbr_dim_vecteur = nbr_dim_vect;

    //get the number of dimension of the selected function
    int nbr_dim_funct = 0;
    int i =0;
    while (funct[i] != '=') {
        if(funct[i] == ',')
            nbr_dim_funct++;
        i++;
    }
    nbr_dim_funct++;

    //Departure choice
    if((ui->checkBox_v0->isChecked() && !ui->LineEdit_Name->text().isEmpty()) || (!ui->checkBox_v0->isChecked() && ui->LineEdit_Name->text().isEmpty()))
    {
        QMessageBox::critical(this, "Entry error", "You must choose only one departure.");
        return;
    }
    if(ui->checkBox_v0->isChecked())
    {
        string dep = "(";
        if(nbr_dim_vect == 1 || nbr_dim_vect == 2)
            dep = "(0,0)";
        else
        {
            for (int i = 0; i < nbr_dim_vect; i++) {
                dep+="0,";
            }
        }
        dep.pop_back();
        dep.push_back(')');
        departur = dep;
    }
    if(!ui->LineEdit_Name->text().isEmpty())
    {
        //tester si c'est bien ecrit + l'ajouter dans une varible char*
        std::string temp = ui->LineEdit_Name->text().toStdString();
        for (int i = 0; i < (int)temp.length(); i++)
             if (isdigit(temp[i]) == false && temp[i] != ',' && temp[i] != '-')
             {
                  QMessageBox::critical(this, "Entry error", "The number can only containe integer");
                  return;
             }
        int nbr_dim_vecteur_departure = 0;
        for (int i = 0; i < (int)temp.size(); i++) {
            if(temp[i] == ',')
                nbr_dim_vecteur_departure++;
        }
        nbr_dim_vecteur_departure++;
        if(nbr_dim_vecteur_departure != nbr_dim_vect)
        {
            QMessageBox::critical(this, "Entry error", "The departure vector must have the same dimension of the initial vector.");
            return;
        }
        string dep = "(";
        dep+=temp;
        if(nbr_dim_vecteur_departure == 1)
        {
            dep += ",0";
        }
        dep.push_back(')');
        departur = dep;
    }

    //get the functon in the good shape and type
    string function = "";
    for (int i = 0; i < (int)funct.length() ; i++ ) {
        if(funct[i] == '=')
        {
            i = i+2;
            while(i < (int)funct.length())
            {
                function += funct[i];
                i++;
            }
            break;
        }
    }
    if(nbr_dim_vect > nbr_dim_funct)
    {
        function.pop_back();
        for (int i = nbr_dim_funct; i < nbr_dim_vect; i++ ) {
          function.append(";");
          function.push_back(carc[i]);
          nbr_dim_funct++;
        }
        function.push_back(')');
    }
    char funct[function.length()+1];
    strcpy(funct, function.c_str());

    //Get the name of all the variable
    string variablestring = "";
    char variable[nbr_dim_vect+1];
    for(int i = 0 ; i < nbr_dim_vect ; i++)
    {
        variable[i] = carc[i];
    }
    variable[nbr_dim_vect] = '\0';
    list = fonction_principale(funct,vecteurinitial,nbr_dim_vect,nbr_dim_funct,nbr_vect,variable); // Appel de la fonction de calcul de liste de vecteur avec le nombre de vecteur, le vecteur initial et la fonction
    if(list->taille == -1)
    {
        QMessageBox::critical(this, "Entry error", "Error in your function");
        return;
    }

    statist = calcul_des_statistiques(statistic,list);  //Appel de la fonction de calcul des statistiques avec le tableau de int

    /*//Creation de la nouvelle fenetre bloquante avec comme paramettre un objet contenant les infos*/

    if(nbr_dim_vecteur <= 2)
    {
        displaywindow secwind(this);
        secwind.setModal(true);
        secwind.exec();

        close();
    }

    else
    {
        if (nbr_dim_vecteur == 3)
        {
        //appel fonction chloe
            transfert_fonction("Transfert_equations.txt", this->funct);
            transfert_vecteurs("Transfert_liste_vecteurs.txt", this->list,this->departur);
            transfert_stat(3, "Transfert_donnees_statistiques_API.txt", this->statist);
        
        //choix de l'OS
            if (OSexecute)
                system("./Affichage3D/run3D.sh");
            else
            {
                system("start 3D_run.bat");
            }
        }
        else
        {
            display_4D secwind(this);
            secwind.setModal(true);
            secwind.exec();
        }
    }


    state = 1;
    close();
}

void executewindow::Cancel()
{
    state = 0;
    close(); //end of the window
}
