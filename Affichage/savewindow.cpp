#include "savewindow.h"
#include "ui_savewindow.h"

savewindow::savewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::savewindow)
{
    ui->setupUi(this);

    //recuperation des données choisis avant
    QObject::connect(ui->Button_valide, SIGNAL(clicked()), this, SLOT(Validate()));
    QObject::connect(ui->Button_cancel, SIGNAL(clicked()), this, SLOT(Cancel()));
}

savewindow::~savewindow()
{
    delete ui;
}

void savewindow::Validate()
{
    //get the name of the data output

    //Recuperation de la selection du vecteur et de la fonction

    //Choix des statistiques
    //Appel de la fonction de calcul de liste de vecteur
    //Appel de la fonction de calcul des statistiques
    //Appel de la fonction save du module GES

    close();
}

void savewindow::Cancel()
{
    close(); //end of the window
}

