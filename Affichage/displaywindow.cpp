#include "displaywindow.h"
#include "ui_displaywindow.h"
extern "C" {
#include "liste_vecteurs.h"
#include "statistiques.h"
}

//possible variable
char carc[26] = {'x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w'};

displaywindow::displaywindow(executewindow *toto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displaywindow)
{
    ui->setupUi(this);

    //get the vector in the good shape and type
    string vect_init2 = "";
    for (int i = 0; i < (int)toto->vect_init.length(); i++) {
        if(toto->vect_init[i] == '(')
        {
            while (toto->vect_init[i] != ')') {
                vect_init2+= toto->vect_init[i];
                i++;
            }
        }
    }
    vect_init2.push_back(')');
    const char * vecteurinitial = vect_init2.c_str();
    std::cout << vecteurinitial << std::endl;

    //get the number of dimension of the selected vector
    int nbr_dim_vect = 0;
    for (int i = 0; i < (int)toto->vect_init.size(); i++) {
        if(toto->vect_init[i] == ',')
            nbr_dim_vect++;
    }
    nbr_dim_vect++;

    //get the number of dimension of the selected function
    int nbr_dim_funct = 0;
    int i =0;
    while (toto->funct[i] != '=') {
        if(toto->funct[i] == ',')
            nbr_dim_funct++;
        i++;
    }
    nbr_dim_funct++;

    //get the functon in the good shape and type
    string function = "";
    for (int i = 0; i < (int)toto->funct.length() ; i++ ) {
        if(toto->funct[i] == '=')
        {
            i = i+2;
            while(i < (int)toto->funct.length())
            {
                function += toto->funct[i];
                i++;
            }
            break;
        }
    }
    char funct[function.length()+1];
    strcpy(funct, function.c_str());
    std::cout << funct << std::endl;

    //Get the name of all the variable
    string variablestring = "";
    for (int i = 0; i < nbr_dim_funct; i++) {
        variablestring[i] = carc[i];
    }
    char variable[variablestring.length()+1];
    strcpy(variable, variablestring.c_str());
    std::cout << variable << std::endl;

    Liste_vecteur *vectors = fonction_principale(funct,vecteurinitial,nbr_dim_vect,nbr_dim_funct,toto->nbr_vect,variable); // Appel de la fonction de calcul de liste de vecteur avec le nombre de vecteur, le vecteur initial et la fonction
    afficherListe(vectors);

    std::cout << "fin" << std::endl;

    statistiques statistiquee = calcul_des_statistiques(toto->statistic,vectors);  //Appel de la fonction de calcul des statistiques avec le tableau de int
    affichage(statistiquee,nbr_dim_vect);

    std::cout << "" << std::endl;

    //Appel de la fonction affichage 2D ou 3D suvant le nombre de dimension du vecteur initial
}


displaywindow::~displaywindow()
{
    delete ui;
}
