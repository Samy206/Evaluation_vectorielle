#include "../Headers/addvectwindow.h"
#include "ui_addvectwindow.h"
#include <iostream>
#include <string>
#include "QMessageBox"

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
    int size;
    double number;
    std::string::size_type sz;
   for (int i = 0; i < nbr_dim; i++)
   {
       std::string temp = ui->tableWidget_vect->item(i,0)->text().toStdString();
       size = temp.length();
       for (int j = 0; j < size; j++)
       {
           if (isdigit(temp[j]) != true && temp[j] != '.' && temp[j] != '-')
           {
               QMessageBox::critical(this, "Entry error", "The number can only contain integer");
               vect_init.clear();
               return;
           }
       }
       number = std::stod(temp,&sz);
       vect_init.push_back(number); //recuperation des données saisies dans l'objet addvectwindow
    }

   if(ui->lineEdit_name->text().isEmpty())
   {
       QMessageBox::critical(this, "Entry error", "Missing name for your vector.");
       vect_init.clear();
       return;
   }
   name = ui->lineEdit_name->text().toStdString();

    state = 1;
    close();
}

void addvectwindow::Cancel()
{
    state = 0;
    close(); //end of the window
}


void addvectwindow::Validate1()
{
    nbr_dim = ui->spinBox->value();     //Recuperation du nombre de dimension vvoulu
    if(nbr_dim == 0)
    {
        QMessageBox::critical(this, "Entry error", "The number of dimension can't be 0");
        return;
    }
    ui->spinBox->setEnabled(false);
    ui->Button_valide1->setEnabled(false);
    ui->lineEdit_name->setEnabled(true);
    ui->Button_valide_2->setEnabled(true);
    ui->Button_cancel_2->setEnabled(true);
    ui->tableWidget_vect->setEnabled(true);
    ui->tableWidget_vect->setRowCount(nbr_dim);     // Creation du qtablewidget avec les bonnes dimensions
}

std::vector <double> addvectwindow::getvectinit()
{
    return vect_init;
}
