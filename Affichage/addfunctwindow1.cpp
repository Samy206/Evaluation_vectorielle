#include "addfunctwindow.h"
#include "ui_vectorlistwindow.h"

vectorlistwindow::vectorlistwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vectorlistwindow)
{
    ui->setupUi(this);

    QObject::connect(ui->Button_valide, SIGNAL(clicked()), this, SLOT(Validate()));
    QObject::connect(ui->Button_cancel, SIGNAL(clicked()), this, SLOT(Cancel()));
}

vectorlistwindow::~vectorlistwindow()
{
    delete ui;
}

void vectorlistwindow::Validate()
{
    //recuperationn de la selection de liste vecteur et fucntion
    //Recuperation du depart (vo ou saisie utilisateur)
    //Si saisi utilisateur alors verification (nombre de dimension + forme)
    // appel fonction calcul liste vecteur (PL) avec comme parametre nombre de vecteur, vecteur init, vecteur depart, funct
    // recuparation de la lsite de vecteur + enregistrement dans obejet pour tranfere a fenetre principale

    close();
}

void vectorlistwindow::Cancel()
{
    close(); //end of the window
}
