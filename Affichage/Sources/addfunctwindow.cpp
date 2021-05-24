#include "../Headers/addfunctwindow.h"
#include "ui_addfunctwindow.h"
#include "iostream"
#include "QMessageBox"
#include "../Headers/liste_vecteurs.h"

double TT[25] = {0};
te_variable varss[] = { {"x", &TT[0]}, {"y", &TT[1]}, {"z", &TT[2]}, {"a", &TT[3]},
                           {"b", &TT[4]}, {"c", &TT[5]}, {"d", &TT[6]}, {"e", &TT[7]}, {"f", &TT[8]},
                           {"g", &TT[9]}, {"h", &TT[10]}, {"i", &TT[11]}, {"j", &TT[12]}, {"k", &TT[13]},
                           {"l", &TT[14]}, {"m", &TT[15]}, {"n", &TT[16]}, {"o", &TT[17]}, {"p", &TT[18]},
                           {"q", &TT[19]}, {"r", &TT[20]}, {"s", &TT[21]}, {"t", &TT[22]}, {"u", &TT[23]},
                           {"v", &TT[24]}
                     };

addfunctwindow::addfunctwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addfunctwindow)
{
    ui->setupUi(this);

    QObject::connect(ui->Button_valide1, SIGNAL(clicked()), this, SLOT(Validate1()));
    QObject::connect(ui->Button_cancel, SIGNAL(clicked()), this, SLOT(Cancel()));
    QObject::connect(ui->Button_pi, SIGNAL(clicked()), this, SLOT(Pi()));
    QObject::connect(ui->Button_racine, SIGNAL(clicked()), this, SLOT(Rc()));
    QObject::connect(ui->Button_mod, SIGNAL(clicked()), this, SLOT(mod()));
    QObject::connect(ui->Button_valide, SIGNAL(clicked()), this, SLOT(Validate()));
}

addfunctwindow::~addfunctwindow()
{
    delete ui;
}

void addfunctwindow::Validate()
{

    int err2;

    for (int i = 0; i < nbr_dim; i++)
    {
        //validity test
        te_expr * expr_2 = te_compile(ui->tableWidget_funct->item(i,0)->text().toLower().toStdString().c_str(), varss, nbr_dim, &err2);
        if(!expr_2)
        {
            QString error = "Error in this component " + ui->tableWidget_funct->item(i,0)->text().toLower();
            QMessageBox::critical(this, "Entry error", error);
            funct.clear();
            return;
        }

        funct.push_back(ui->tableWidget_funct->item(i,0)->text().toLower().toStdString()); //recuperation des données saisies dans l'objet addvectwindow
     }
    if(ui->lineEdit_name->text().isEmpty())
    {
        QMessageBox::critical(this, "Entry error", "Missing name for your function.");
        funct.clear();
        return;
    }
    name = ui->lineEdit_name->text().toStdString();
    state = 1;
    close(); //end of the window
}

void addfunctwindow::Cancel()
{
    state = 0;
    close(); //end of the window
}

void addfunctwindow::Pi()
{
    int pos = ui->tableWidget_funct->currentRow();
    if(pos == -1)
    {
        QMessageBox::critical(this, "Entry error", "Please select a row before clic on");
        return;
    }
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

void addfunctwindow::mod()
{
    int pos = ui->tableWidget_funct->currentRow();
    if(pos == -1)
    {
        QMessageBox::critical(this, "Entry error", "Please select a row before clic on");
        return;
    }
    std::string expr;
    if(ui->tableWidget_funct->item(pos,0)->text().isEmpty())
    {
        expr = "%";
    }
    else
    {
        expr = ui->tableWidget_funct->item(pos,0)->text().toStdString();
        expr.operator+=("%");
    }
    ui->tableWidget_funct->setItem(pos,0,new QTableWidgetItem(QString::fromStdString(expr)));
}

void addfunctwindow::Rc()
{
    int pos = ui->tableWidget_funct->currentRow();
    if(pos == -1)
    {
        QMessageBox::critical(this, "Entry error", "Please select a row before clic on");
        return;
    }
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
     if(nbr_dim == 0)
     {
         QMessageBox::critical(this, "Entry error", "The number of dimension can't be 0");
         return;
     }
     ui->spinBox->setEnabled(false);
     ui->Button_valide1->setEnabled(false);
     ui->Button_valide->setEnabled(true);
     ui->lineEdit_name->setEnabled(true);
     ui->Button_pi->setEnabled(true);
     ui->Button_mod->setEnabled(true);
     ui->Button_racine->setEnabled(true);
     ui->Button_cancel->setEnabled(true);
     ui->tableWidget_funct->setEnabled(true);
     ui->tableWidget_funct->setRowCount(nbr_dim);     // Creation du qtablewidget avec les bonnes dimensions
}

std::vector<std::string> addfunctwindow::getfunct()
{
    return funct;
}
