#include "addvectwindow.h"
#include "ui_addvectwindow.h"
#include "iostream"

addvectwindow::addvectwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addvectwindow)
{
    ui->setupUi(this);

    QObject::connect(ui->Button_valide1, SIGNAL(clicked()), this, SLOT(Validate1()));
    QObject::connect(ui->Button_cancel_2, SIGNAL(clicked()), this, SLOT(Cancel()));
    QObject::connect(ui->Button_valide_2, SIGNAL(clicked()), this, SLOT(Validate()));
}

addvectwindow::~addvectwindow()
{
    delete ui;
}

void addvectwindow::Validate()
{
   for (int i = 0; i < nbr_dim; i++) {
       vect_init.push_back(ui->tableWidget_vect->item(i,0)->text().toDouble()); //recuperation des données saisies dans l'objet addvectwindow
    }

   name = ui->lineEdit_name->text().toStdString();

    close();
}

void addvectwindow::Cancel()
{
    close(); //end of the window
}


void addvectwindow::Validate1()
{
    nbr_dim = ui->spinBox->value();     //Recuperation du nombre de dimension vvoulu
    ui->spinBox->setEnabled(false);
    ui->Button_valide1->setEnabled(false);
    ui->Button_valide_2->setEnabled(true);
    ui->Button_cancel_2->setEnabled(true);
    ui->tableWidget_vect->setEnabled(true);
    ui->tableWidget_vect->setRowCount(nbr_dim);     // Creation du qtablewidget avec les bonnes dimensions
}

std::vector <double> addvectwindow::getvectinit()
{
    return vect_init;
}
