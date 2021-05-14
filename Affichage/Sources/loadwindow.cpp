#include "../Headers/loadwindow.h"
#include "ui_loadwindow.h"

loadwindow::loadwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loadwindow)
{
    ui->setupUi(this);


    QObject::connect(ui->PushButton_valide, SIGNAL(clicked()), this, SLOT(Validate()));
    QObject::connect(ui->Button_cancel, SIGNAL(clicked()), this, SLOT(Cancel()));
}

loadwindow::~loadwindow()
{
    delete ui;
}

void loadwindow::Validate()
{
    std::string path = ui->LineEdit_location->text().toStdString();
    char chemin[path.length()+1];
    strcpy(chemin, path.c_str());

    //Appel de la fonction load du module GES
    //enregistrement du vecteur et de la fonction
}

void loadwindow::Cancel()
{
    close(); //end of the window
}

