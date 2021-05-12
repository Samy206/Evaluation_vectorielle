#ifndef GESTION_ES
#define GESTION_ES

#include "Headers/liste_vecteurs.h"
#include "Headers/statistiques.h"
#include "Headers/vecteurs.h"
#include <string.h>

typedef struct gestion_es
{
    char * fonction;                            //Fonction entrée par l'utilisateur
    Liste_vecteur * liste;                      //Liste de vecteurs formant la courbe
    statistiques * stats;                       //Liste des statistiques sur la courbe
    char * fic_gnup;                            //Chemin absolu du fichier contenant les coordonnées des vecteurs
    char * script_gnup;                         /*Chemin absolu du fichier contenant script utilisant les coordonnées
                                                   des vecteurs*/
    char * fic_post;                            //Chemin absolu du fichier contenant le script postscript affichant les statistiques
}
        Gestion_ES;


void initialisation_ES(Gestion_ES * gestionnaire,char * fct, Liste_vecteur * liste, statistiques * stats);

int generation_fic_gnuplot(Gestion_ES * gestionnaire, char *file_name);    //Génération fichier de coordonnées gnup

int generation_script_gnuplot(Gestion_ES * gestionnaire, char* file_name); //Génération script lancement de gnuplot
void * launch_gnup_script(void * filename); /*Lancement du script gnuplot afin de générer un graphe sous format png*/


int generation_fic_postscript(Gestion_ES * gestionnaire, char * filename); //génération fichier postscript ( écriture statistiques )
int draw_table_postscript(FILE * file,int x, int y, int largeur);          //Dessin de chaque partie du tableau
int stat_string_parser(char * string,char ** tableau);                     //Récupération des stats à affichier
char index_to_char(int index);                                             //Transforme un 0 par un X, un 1 par un Y etc

Liste_vecteur * chargement_fichier(char * fichier);       //Lecture de coordonnées des vecteurs en chargement
double * string_parser(char * entiers);                   //Transformation des lignes lues en tableau de double

void free_gestionnaire_es(Gestion_ES * gestionnaire);      //Libération de la mémoire

#endif
