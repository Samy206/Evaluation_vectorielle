#include "../Headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "../Headers/loadwindow.h"
#include "../Headers/savewindow.h"
#include "../Headers/addfunctwindow.h"
#include "../Headers/addvectwindow.h"
#include "../Headers/executewindow.h"
#include "QMessageBox"

//possible variable
char carac[26] = {'x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w'};

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window
        | Qt::WindowContextHelpButtonHint
        | Qt::WindowCloseButtonHint);

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

    string vect = secwind.vecteur;
    string funct = secwind.funct;
    //Recuperation du contenu de l'objet loadwindow pour actualiser les listes
    if(secwind.state)
    {
        ui->listWidget_vect->addItem(QString::fromStdString(vect));
        ui->listWidget_funct->addItem(QString::fromStdString(funct));
    }
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
            std::string tmp = std::to_string(vect[i]);
            tmp.pop_back();
            componant+= tmp;
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
        componant += '(';
        for (int i = 0; i < secwind.nbr_dim; i++) {
            componant += carac[i];
            componant += ',';
        }
        componant.pop_back();
        componant += ") = (";
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

    // save the choice of the vector and the function and the number of vectors
    if(ui->listWidget_vect->selectedItems().size() == 0 || ui->listWidget_funct->selectedItems().size() == 0)
    {
        QMessageBox::critical(this, "Selection error", "You must select one vector and one function !");
        return;
    }
    vect_init = ui->listWidget_vect->currentItem()->text().toStdString();
    funct = ui->listWidget_funct->currentItem()->text().toStdString();

    //get the number of dimension of the selected vector
    int nbr_dim_vect = 0;
    for (int i = 0; i < (int)vect_init.size(); i++) {
        if(vect_init[i] == ',')
            nbr_dim_vect++;
    }
    nbr_dim_vect++;

    //get the number of dimension of the selected function
    int nbr_dim_funct = 0;
    int i =0;
    while (funct[i] != '=') {
        if(funct[i] == ',')
            nbr_dim_funct++;
        i++;
    }
    nbr_dim_funct++;

    if(nbr_dim_funct > nbr_dim_vect)
    {
        QMessageBox::critical(this, "Selection error", "The dimension number of the function must be less than or equal to that of the vector.");
        return;
    }

    nbr_vect = ui->SpinBox_nbr_vect->value();

    savewindow secwind(this);
    secwind.setModal(true);
    secwind.exec();
}

void MainWindow::makeexecute()
{

    // save the choice of the vector and the function and the number of vectors
    if(ui->listWidget_vect->selectedItems().size() == 0 || ui->listWidget_funct->selectedItems().size() == 0)
    {
        QMessageBox::critical(this, "Selection error", "You must select one vector and one function !");
        return;
    }
    vect_init = ui->listWidget_vect->currentItem()->text().toStdString();
    funct = ui->listWidget_funct->currentItem()->text().toStdString();

    //get the number of dimension of the selected vector
    int nbr_dim_vect = 0;
    for (int i = 0; i < (int)vect_init.size(); i++) {
        if(vect_init[i] == ',')
            nbr_dim_vect++;
    }
    nbr_dim_vect++;

    //get the number of dimension of the selected function
    int nbr_dim_funct = 0;
    int i =0;
    while (funct[i] != '=') {
        if(funct[i] == ',')
            nbr_dim_funct++;
        i++;
    }
    nbr_dim_funct++;

    if(nbr_dim_funct > nbr_dim_vect)
    {
        QMessageBox::critical(this, "Selection error", "The dimension number of the function must be less than or equal to that of the vector");
        return;
    }

    nbr_vect = ui->SpinBox_nbr_vect->value();

    executewindow secwind(this);
    secwind.setModal(true);
    secwind.exec();
}
