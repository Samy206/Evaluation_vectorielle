#include "displaywindow.h"
#include "ui_displaywindow.h"
#include "display_4d.h"
extern "C" {
#include "liste_vecteurs.h"
#include "statistiques.h"
}

displaywindow::displaywindow(executewindow *toto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displaywindow)
{
    ui->setupUi(this);

    close();
    //Appel de la fonction affichage 2D ou 3D suvant le nombre de dimension du vecteur initial
}


displaywindow::~displaywindow()
{
    delete ui;
}
