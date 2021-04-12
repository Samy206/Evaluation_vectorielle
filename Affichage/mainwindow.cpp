#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loadwindow.h"
#include "savewindow.h"
#include "addfunctwindow.h"
#include "addvectwindow.h"
#include "executewindow.h"

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->Button_load, SIGNAL(clicked()), this, SLOT(makeload()));
    QObject::connect(ui->Button_save, SIGNAL(clicked()), this, SLOT(makesave()));
    QObject::connect(ui->Button_addvect, SIGNAL(clicked()), this, SLOT(makeadd_vect()));
    QObject::connect(ui->Button_addfunct, SIGNAL(clicked()), this, SLOT(makeadd_funct()));
    QObject::connect(ui->Button_erase_funct, SIGNAL(clicked()), this, SLOT(makeerase_funct()));
    QObject::connect(ui->Button_erase_vect, SIGNAL(clicked()), this, SLOT(makeerase_vect()));
    QObject::connect(ui->Button_excute, SIGNAL(clicked()), this, SLOT(makeexecute()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makeload()
{
    loadwindow secwind;
    secwind.setModal(true);
    secwind.exec();

    //Recuperation du contenu de l'objet loadwindow pour actualiser les listes
}

void MainWindow::makeadd_vect()
{
    addvectwindow secwind;
    secwind.setModal(true);
    secwind.exec();

    if(secwind.state == 1)
    {
        vector<double> vect = secwind.getvectinit();
        string componant = secwind.name;
        componant += " = (";
        for (int i = 0; i < (int)vect.size(); i++) {
        componant+= std::to_string(vect[i]);
        componant += ",";
        }
        componant.pop_back();
        componant += ")";

        ui->listWidget_vect->addItem(QString::fromStdString(componant));  //Recuperation de la saisie dans l'objet addvectwindow pour actualisé la QlisteeWidget_vect
    }

}

void MainWindow::makeadd_funct()
{
    addfunctwindow secwind;
    secwind.setModal(true);
    secwind.exec();

    if(secwind.state == 1)
    {
        vector<string> funct = secwind.getfunct();
        string componant = secwind.name;
        componant += "() = (";
        for (int i = 0; i < (int)funct.size(); i++) {
        componant+= funct[i];
        componant += ";";
        }
        componant.pop_back();
        componant += ")";

        ui->listWidget_funct->addItem(QString::fromStdString(componant));  //Recuperation de la saisie dans l'objet addfunctwindow pour actualisé la QlisteeWidget_funct
    }
}

void MainWindow::makeerase_funct()
{
    QListWidgetItem *it = ui->listWidget_funct->takeItem(ui->listWidget_funct->currentRow()); //Take the selected item and delete it
    delete it;
}

void MainWindow::makeerase_vect()
{
    QListWidgetItem *it = ui->listWidget_vect->takeItem(ui->listWidget_vect->currentRow());  //Take the selected item and delete it
    delete it;
}

void MainWindow::makesave()
{
    //test les dimmensions
    // save the choice of the vector and the function and the number of vectors
    vect_init = ui->listWidget_vect->currentItem()->text().toStdString();
    funct = ui->listWidget_funct->currentItem()->text().toStdString();
    nbr_vect = ui->SpinBox_nbr_vect->value();

    savewindow secwind(this);
    secwind.setModal(true);
    secwind.exec();
}

void MainWindow::makeexecute()
{
    //test les dimensions
    // save the choice of the vector and the function and the number of vectors
    vect_init = ui->listWidget_vect->currentItem()->text().toStdString();
    funct = ui->listWidget_funct->currentItem()->text().toStdString();
    nbr_vect = ui->SpinBox_nbr_vect->value();

    executewindow secwind(this);
    secwind.setModal(true);
    secwind.exec();
}
