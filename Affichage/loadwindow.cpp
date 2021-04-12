#include "loadwindow.h"
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
    QString path = ui->LineEdit_location->text();

    //Appel de la fonction load du module GES
    //enregistrement du vecteur et de la fonction
}

void loadwindow::Cancel()
{
    close(); //end of the window
}

