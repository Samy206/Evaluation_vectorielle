#include "addfunctwindow.h"
#include "ui_addfunctwindow.h"
#include "iostream"

addfunctwindow::addfunctwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addfunctwindow)
{
    ui->setupUi(this);

    QObject::connect(ui->Button_valide1, SIGNAL(clicked()), this, SLOT(Validate1()));
    QObject::connect(ui->Button_cancel, SIGNAL(clicked()), this, SLOT(Cancel()));
    QObject::connect(ui->Button_pi, SIGNAL(clicked()), this, SLOT(Pi()));
    QObject::connect(ui->Button_racine, SIGNAL(clicked()), this, SLOT(Rc()));
    QObject::connect(ui->Button_sum, SIGNAL(clicked()), this, SLOT(sum()));
    QObject::connect(ui->Button_valide, SIGNAL(clicked()), this, SLOT(Validate()));
}

addfunctwindow::~addfunctwindow()
{
    delete ui;
}

void addfunctwindow::Validate()
{
    //Test de validé Pas finir pas un operateur sqrt() ne peux pas etre vide...
    for (int i = 0; i < nbr_dim; i++) {
        funct.push_back(ui->tableWidget_funct->item(i,0)->text().toStdString()); //recuperation des données saisies dans l'objet addvectwindow
        //std::cout << funct[i] << std::endl;
     }

    name = ui->lineEdit_name->text().toStdString();
     close(); //end of the window
}

void addfunctwindow::Cancel()
{
    close(); //end of the window
}

void addfunctwindow::Pi()
{
    int pos = ui->tableWidget_funct->currentRow();
    std::string expr;
    if(ui->tableWidget_funct->item(pos,0)->text().isEmpty())
    {
        expr = "pi";
    }
    else
    {
        expr = ui->tableWidget_funct->item(pos,0)->text().toStdString();
        expr.operator+=("pi");
    };
    ui->tableWidget_funct->setItem(pos,0,new QTableWidgetItem(QString::fromStdString(expr)));
}

void addfunctwindow::sum()
{
    //Ecrit "sum(...)"
}

void addfunctwindow::Rc()
{
    int pos = ui->tableWidget_funct->currentRow();
    std::string expr;
    if(ui->tableWidget_funct->item(pos,0)->text().isEmpty())
    {
        expr = "sqrt()";
    }
    else
    {
        expr = ui->tableWidget_funct->item(pos,0)->text().toStdString();
        expr.operator+=("sqrt()");
    }
    ui->tableWidget_funct->setItem(pos,0,new QTableWidgetItem(QString::fromStdString(expr)));
}

void addfunctwindow::Validate1()
{    nbr_dim = ui->spinBox->value();     //Recuperation du nombre de dimension vvoulu
     ui->spinBox->setEnabled(false);
     ui->Button_valide1->setEnabled(false);
     ui->Button_valide->setEnabled(true);
     ui->Button_pi->setEnabled(true);
     ui->Button_sum->setEnabled(true);
     ui->Button_racine->setEnabled(true);
     ui->Button_cancel->setEnabled(true);
     ui->tableWidget_funct->setEnabled(true);
     ui->tableWidget_funct->setRowCount(nbr_dim);     // Creation du qtablewidget avec les bonnes dimensions
}

std::vector<std::string> addfunctwindow::getfunct()
{
    return funct;
}
