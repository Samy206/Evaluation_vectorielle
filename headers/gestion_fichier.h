#ifndef Gestion_fichier_h
#define Gestion_fichier_h

#include <fstream>
/* Manipulation de fichiers */

#include <iostream>
/* Affichage messages d'erreurs */

#include <vector>
#include <map>
#include <string>
/* Librairies correspondantes aux types des attributs */

#include "Statistiques.h"
#include "Vecteur.h"
/* Modules nécessaires au bon fonctionnement de celui-ci */

class Gestion_fichier
{

    private :/* Parceque une fois que les données nécessaires à la génération de fichiers ont été stockées on ne veut
    plus qu'elles soient modifiées */

        std::vector<Vecteur> liste_vec;  /* Liste de vecteurs formant la courbe */
        std::map<std::string,double> statistiques; /* Liste de statistiques à afficher avec leur nom et leur valeur */

    public : /* Les méthodes restent accessible afin de pouvoir générer des fichiers */

        Gestion_fichier(); /*Constructeur vide : utilisable pour charger des données à partir d'un fichier par exemple*/
        Gestion_fichier( std::vector<Vecteur> ); /* Manipulation de fichier une fois que la courbe est calculée */
        Gestion_fichier( Gestion_fichier& ); /* Constructeur par recopie */

        ~Gestion_fichier(); /* Destructeur */

        chargement_fichier(std::string ); /* Lecture puis stockage des coordonnées des vecteurs formant la courbe */
        generation_gnuplot();
        generation_postscript();

        void operator=( Gestion_fichier& ); /* Seul opérateur utile => sert à reprendre les valeurs d'une autre courbe */
}

#endif