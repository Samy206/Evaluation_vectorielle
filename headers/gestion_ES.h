#ifndef GESTION_ES
#define GESTION_ES

#include "liste_vecteurs.h"
#include "statistiques.h"
#include "vecteurs.h"
#include <string.h>

typedef struct gestion_es
{
    char * fonction;                //Fonction entrée par l'utilisateur
    Liste_vecteur * liste;          //Liste de vecteurs composant la courbe
    statistiques * stats;           //Statistiques issues de calculs sur la courbe
    char * fic_gnup;                //Path absolu du fichier de stockage des coordonnées des vecteurs
    char * fic_post;                //Path absolu du fichier contenant le script postscript
}
Gestion_ES;


Gestion_ES * initialisation_ES(char * fct, Liste_vecteur * liste, statistiques * stats);

int generation_fic_gnuplot(Gestion_ES * gestionnaire, char *file_name);    //génération fichier gnuplot ( écriture coordonnées )

int generation_fic_postscript(Gestion_ES * gestionnaire, char * filename); //génération fichier postscript ( écriture statistiques )
int draw_table_postscript(FILE * file,int x, int y, int largeur);          //Dessin de chaque partie du tableau
int stat_string_parser(char * string,char ** tableau);                     //Récupération des stats à affichier

Liste_vecteur * chargement_fichier(char * fichier);       //Lecture de coordonnées des vecteurs en chargement
double * string_parser(char * entiers);                   //Transformation des lignes lues en tableau de double

void free_gestionnaire_es(Gestion_ES * gestionnaire)      //Libération de la mémoire

#endif

