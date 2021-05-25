#include "../Headers/savewindow.h"
#include "ui_savewindow.h"
#include <QMessageBox>
extern "C" {
#include "../Headers/liste_vecteurs.h"
#include "../Headers/statistiques.h"
#include "../Headers/gestion_ES.h"
}


//possible variable
char carcact[26] = {'x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w'};

savewindow::savewindow(MainWindow *dad,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::savewindow)
{
    ui->setupUi(this);

    QObject::connect(ui->Button_valide, SIGNAL(clicked()), this, SLOT(Validate()));
    QObject::connect(ui->Button_cancel, SIGNAL(clicked()), this, SLOT(Cancel()));

    //Retrieving the selection of the vector and the function
    nbr_vect = dad->nbr_vect;
    funct_string = dad->funct;
    vect_init = dad->vect_init;
}

savewindow::~savewindow()
{
    delete ui;
}

void savewindow::Validate()
{
    //Get the name of the output file and convert him into a char*
    if(ui->LineEdit_Name->text().isEmpty())
    {
        QMessageBox::critical(this, "Entry error", "Missing name for your file.");
        return;
    }
    QString qname = ui->LineEdit_Name->text();
    if(qname.contains('\\'))
    {
        QMessageBox::critical(this, "Entry error", "Forbiden symbol.");
        return;
    }

    char* name;
    string fname = qname.toStdString();
    name = new char [fname.size()+1];
    strcpy(name, fname.c_str() );

    int statistic[6];
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
    char vecteurinitial[vect_init2.length()+1];
    strcpy(vecteurinitial, vect_init2.c_str());

    //get the number of dimension of the selected vector
    int nbr_dim_vect = 0;
    for (int i = 0; i < (int)vect_init.size(); i++) {
        if(vect_init[i] == ',')
            nbr_dim_vect++;
    }
    nbr_dim_vect++;

    //get the number of dimension of the selected function
    int nbr_dim_funct = 0;
    int i =0;
    while (funct_string[i] != '=') {
        if(funct_string[i] == ',')
            nbr_dim_funct++;
        i++;
    }
    nbr_dim_funct++;

    //get the functon in the good shape and type
    string function = "";
    for (int i = 0; i < (int)funct_string.length() ; i++ ) {
        if(funct_string[i] == '=')
        {
            i = i+2;
            while(i < (int)funct_string.length())
            {
                function += funct_string[i];
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
          function.push_back(carcact[i]);
          nbr_dim_funct++;
        }
        function.push_back(')');
    }
    char funct[function.length()+1];
    strcpy(funct, function.c_str());

    //Get the name of all the variable
    string variablestring = "";
    for (int i = 0; i < nbr_dim_funct; i++) {
        variablestring[i] = carcact[i];
    }
    char variable[variablestring.length()+1];
    strcpy(variable, variablestring.c_str());

    Liste_vecteur *list = fonction_principale(funct,vecteurinitial,nbr_dim_vect,nbr_dim_funct,nbr_vect,variable); // Appel de la fonction de calcul de liste de vecteur avec le nombre de vecteur, le vecteur initial et la fonction
    //afficherListe(list);


    statistiques statist = calcul_des_statistiques(statistic,list);  //Appel de la fonction de calcul des statistiques avec le tableau de int
    //affichage(statist,nbr_dim_vect);


    //Appel de la fonction save du module GES
    char function_char[function.length()+1];
    strcpy(function_char, funct_string.c_str());
    Gestion_ES ges ;
    initialisation_ES(&ges,function_char,list,&statist);

    generation_fic_gnuplot(&ges,name);

    generation_script_gnuplot(&ges,name);

    generation_fic_postscript(&ges,name);

    free_gestionnaire_es(&ges);

    close();
}

void savewindow::Cancel()
{
    state = 0;
    close(); //end of the window
}

