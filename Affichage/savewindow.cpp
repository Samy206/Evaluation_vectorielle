#include "savewindow.h"
#include "ui_savewindow.h"
#include <QMessageBox>

savewindow::savewindow(MainWindow *dad,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::savewindow)
{
    ui->setupUi(this);

    QObject::connect(ui->Button_valide, SIGNAL(clicked()), this, SLOT(Validate()));
    QObject::connect(ui->Button_cancel, SIGNAL(clicked()), this, SLOT(Cancel()));

    //Retrieving the selection of the vector and the function
    nbr_vect = dad->nbr_vect;
    funct = dad->funct;
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

    //Choice of the statistics
    int stat[6];
    if(ui->CheckBox_Minimum->isChecked())
     stat[0] = true;
    if(ui->CheckBox_Maximum->isChecked())
     stat[1] = true;
    if(ui->CheckBox_Moyenne->isChecked())
     stat[2] = true;
    if(ui->CheckBox_Variance->isChecked())
     stat[3] = true;
    if(ui->CheckBox_Ecarttype->isChecked())
     stat[4] = true;
    if(ui->CheckBox_Autocor->isChecked())
    {
        int shift = ui->lineEdit->text().toInt();
        if((shift > (-1*nbr_vect)) && (shift < nbr_vect) && (shift != 0))
            stat[5] = shift;
        else
        {
            QMessageBox::critical(this, "Entry error", "The shift must be between [-nbr_vect; 0 [and] 0; nbr_vect].");
            return;
        }
    }

    //Departure choice
    char *departur;
    if((ui->checkBox_v0->isChecked() && !ui->LineEdit_Name_2->text().isEmpty()) || (!ui->checkBox_v0->isChecked() && ui->LineEdit_Name_2->text().isEmpty()))
    {
        QMessageBox::critical(this, "Entry error", "You must choose only one departure.");
        return;
    }
    if(ui->checkBox_v0->isChecked())
    {
        string dep = "(0,0)";
        departur = new char [dep.size()+1];
        strcpy(departur, dep.c_str() );
    }
    if(!ui->LineEdit_Name_2->text().isEmpty())
    {
        //tester si c'est bien ecrit + l'ajouter dans une varible char*
        std::string temp = ui->LineEdit_Name_2->text().toStdString();
        for (int i = 0; i < (int)temp.length(); i++)
             if (isdigit(temp[i]) == false && (temp[i] != '.' || temp[i] != ',' || temp[i] != '(' || temp[i] != ')'))
             {
                  QMessageBox::critical(this, "Entry error", "The number can only containe integer");
                  return;
             }


    }

    //Appel de la fonction de calcul de liste de vecteur
    //Appel de la fonction de calcul des statistiques
    //Appel de la fonction save du module GES

    state = 1;
    close();
}

void savewindow::Cancel()
{
    state = 0;
    close(); //end of the window
}

