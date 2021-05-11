#include "addvectwindow.h"
#include "ui_addvectwindow.h"

addvectwindow::addvectwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addvectwindow)
{
    ui->setupUi(this);

    QObject::connect(ui->Button_valide, SIGNAL(clicked()), this, SLOT(Validate()));
    QObject::connect(ui->Button_cancel, SIGNAL(clicked()), this, SLOT(Cancel()));
}

addvectwindow::~addvectwindow()
{
    delete ui;
}

void addvectwindow::Validate()
{
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
     stat[5] = true;

    QString s = ui->ListWidget_traj->currentItem()->text(); //get the name of the vector list

    //Application d'une fonction pour recuper la liste des vecteurs de la fenetre principale (Voir avec Antoine)


    makestat();

    close();
}

void addvectwindow::Cancel()
{
    close(); //end of the window
}

void addvectwindow::makestat()
{

    //Appel de la fonction pour calculer les stats avec comme paramettres les stats souhaitées et la lsite des vecteurs.
    //retour tableau de double avec les stats calculées
    //enregistrement du tableau dans un autre tableau de l'objet stat afin de le transferer dans la fenetre principale



}
