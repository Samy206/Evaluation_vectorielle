#include "displaywindow.h"
#include "ui_displaywindow.h"

displaywindow::displaywindow(executewindow *toto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displaywindow)
{
    ui->setupUi(this);


    //Appel de la fonction de calcul de liste de vecteur avec le nombre de vecteur, le vecteur initial et la fonction
    //Appel de la fonction de calcul des statistiques avec le tableau de int
    //Appel de la fonction affichage 2D ou 3D suvant le nombre de dimension du vecteur initial
}

displaywindow::~displaywindow()
{
    delete ui;
}
