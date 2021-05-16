#include "Headers/loadwindow.h"
#include "ui_loadwindow.h"
#include "iostream"
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

extern "C" {
#include "../Headers/chargement_fichier.h"
}

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
    strcat(chemin,".txt");
    std::cout << chemin << std::endl;

    donnee test;
    taille t;
    t = init_struct_t(t);
    test = init_struct_d(test);
    test = chargement_fic_gnup(chemin,test,t);



    std::cout << "vecteur init :" << test.valeur[0] << "   fucntion:" << test.fonction << std::endl;
    //free_struct_d(test,test.nombre);

    funct = test.fonction;
    funct.pop_back();
    funct.erase(0,1);
    //mettre sous forme de fonction


    //mettre sous forme de vecteur
    vecteur = "U = (";
    for (int i = 0; i < test.nombre/2; i++)
    {
        std::string tmp = std::to_string(test.valeur[i]);
        std::cout << test.valeur[i] << std::endl;
        vecteur+= tmp;
        vecteur += ",";
    }
    vecteur.pop_back();
    vecteur += ")";

    close();
}

void loadwindow::Cancel()
{
    close(); //end of the window
}

