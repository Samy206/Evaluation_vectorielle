#include "executewindow.h"
#include "ui_executewindow.h"
#include "displaywindow.h"
#include "mainwindow.h"
#include "QMessageBox"

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

    //Recuperation du choix du vecteur de depart (test du nombre de dimension)

    //Creation de la nouvelle fenetre bloquante avec comme paramettre un objet contenant les infos
    displaywindow secwind(this);
    secwind.setModal(true);
    secwind.exec();

    state = 1;
    close();
}

void executewindow::Cancel()
{
    state = 0;
    close(); //end of the window
}
