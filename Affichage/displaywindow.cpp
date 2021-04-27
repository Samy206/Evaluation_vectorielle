#include "displaywindow.h"
#include "ui_displaywindow.h"
extern "C" {
#include "liste_vecteurs.h"
}

//possible variable
char carc[26] = {'x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w'};

displaywindow::displaywindow(executewindow *toto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displaywindow)
{
    ui->setupUi(this);


    //toto->vect_init =  "p = (1.00000,2.00000)";
    string vect_init2 = "";
    for (int i = 0; i < (int)toto->vect_init.length(); i++) {
        //std::cout << toto->vect_init[i] << std::endl;
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
    //std::cout << nbr_dim_vect << std::endl;

    //toto->funct = "f(x,y) = x+y;y*2";
    //get the number of dimension of the selected function
    int nbr_dim_funct = 0;
    int i =0;
    while (toto->funct[i] != '=') {
        if(toto->funct[i] == ',')
            nbr_dim_funct++;
        i++;
    }
    nbr_dim_funct++;

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
    //function.push_back(')');
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
    //toto->statistic
    //Appel de la fonction de calcul des statistiques avec le tableau de int
    //Appel de la fonction affichage 2D ou 3D suvant le nombre de dimension du vecteur initial
}


displaywindow::~displaywindow()
{
    delete ui;
}
