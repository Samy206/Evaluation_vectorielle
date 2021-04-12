#include "executewindow.h"
#include "ui_executewindow.h"
#include "displaywindow.h"

executewindow::executewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::executewindow)
{
    ui->setupUi(this);

    //recupeartion des données saisie avant
    QObject::connect(ui->Button_valide, SIGNAL(clicked()), this, SLOT(Validate()));
    QObject::connect(ui->Button_cancel, SIGNAL(clicked()), this, SLOT(Cancel()));
}

executewindow::~executewindow()
{
    delete ui;
}

void executewindow::Validate()
{
    //Recuperation du choix des statistiques dans tableau de int[6]
    //Recuperation du choix du vecteur de depart (test du nombre de dimension)

    //Recuperation de la selection du vecteur et de la fonction de la fenetre principale (test du nombre de dimension)

    //Creation de la nouvelle fenetre bloquante avec comme paramettre un objet contenant les infos
    displaywindow secwind(this);
    secwind.setModal(true);
    secwind.exec();


    close();
}

void executewindow::Cancel()
{
    close(); //end of the window
}
