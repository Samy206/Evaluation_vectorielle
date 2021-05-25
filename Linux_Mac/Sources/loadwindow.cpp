#include "ui_loadwindow.h"
#include "../Headers/loadwindow.h"
#include "iostream"
#include "QMessageBox"
#ifdef WIN32
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

extern "C" {
#include "../Headers/gestion_ES.h"
#include "../Headers/vecteurs.h"
}

loadwindow::loadwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loadwindow)
{
    ui->setupUi(this);
    state = 1;

    QObject::connect(ui->PushButton_valide, SIGNAL(clicked()), this, SLOT(Validate()));
    QObject::connect(ui->Button_cancel, SIGNAL(clicked()), this, SLOT(Cancel()));
}

loadwindow::~loadwindow()
{
    delete ui;
}

void loadwindow::Validate()
{
    state = 1;
    std::string path = ui->LineEdit_location->text().toStdString();
    char chemin[path.length()+1];
    strcpy(chemin, path.c_str());
    strcat(chemin,".txt");
    Vector vecteur1;
    char function[50];

    int check = chargement_fic_gnup(&vecteur1,function,chemin);

    if(check == 1)
    {
        QString error = "The file ";
        error.append(chemin);
        error+= " cannot be open !";
        QMessageBox::critical(this, "File error", error);
        state = 0;
        return;
    }

    if(check == 2)
    {
        QString error = "The file ";
        error.append(chemin);
        error+= " is not writen with the good format !";
        QMessageBox::critical(this, "File error", error);
        state = 0;
        return;
    }


    //mettre sous forme de fonction
    funct = function;
    funct.pop_back();
    funct.erase(0,1);


    //mettre sous forme de vecteur
    vecteur = "U = (";
    for (int i = 0; i < (int)vecteur1.taille ; i++)
    {
        std::string tmp = std::to_string(vecteur1.tableau[i]);
        vecteur += tmp;
        vecteur += ",";
    }
    vecteur.pop_back();
    vecteur += ")";

    close();
}

void loadwindow::Cancel()
{
    state = 0;
    close(); //end of the window
}

