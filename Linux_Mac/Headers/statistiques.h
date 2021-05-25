#ifndef STATISTIQUES
#define STATISTIQUES

#ifdef __cplusplus
extern "C" {
#endif

#include "../Headers/liste_vecteurs.h"
#include "../Headers/vecteurs.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calcul_norme(Vector v);
//calcul la norme d'un vecteur

typedef struct statis
{
    int * statistiques_demandees;

	double min_n;
	double *min_d;	
 	double max_n;
	double *max_d;
	double moy_n;
	double *moy_d;
	double var_n;
	double *var_d;
	double ect_n;
	double *ect_d;
	double *atc_d;

} statistiques;

statistiques init_statistiques(size_t nb_dim, int* statistiques_demandes);
//les différent tableau sont alloué pour n dimention
//Pour les différent tableau de double: case 0 dimention 1; case 1 dimention 2; etc...

statistiques free_statistiques(statistiques stat);
//Libère la mémoire alloué pour les tableaux de la structure stat.

statistiques calcul_des_statistiques(int* statistiques_demandes, Liste_vecteur* vecteurs);
//remplis la struct statistiques avec les statstiques demandé via le tableau d'entier "statistiques_demandes" 

statistiques minimum(statistiques stat, Liste_vecteur* vecteurs);
//Calcul la norme minimal des vecteur, ainsi que les minimals des coordonées sur tous les axes.

statistiques maximum(statistiques stat, Liste_vecteur* vecteurs);
//Calcul la norme maximal des vecteur, ainsi que les maximals des coordonées sur tous les axes.

statistiques moyenne(statistiques stat, Liste_vecteur* vecteurs);
//Calcul la moyenne des normes des vecteur, ainsi que les coordonées moyennes sur tous les axes.

statistiques variance(statistiques stat, Liste_vecteur* vecteurs);
//Calcul la variance des normes des vecteur, ainsi que la variance des coordonées sur tous les axes.

statistiques ecart_type(statistiques stat, Liste_vecteur* vecteurs);
//Calcul l'écart-type des normes des vecteur, ainsi que l'écart-type des coordonées sur tous les axes.

statistiques calcul_auto_correlation(statistiques stat, Liste_vecteur* vecteurs, int decallage);
//Calcul le coefficient d'autocorrélation de nos vecteur sur tous les axes.

void affichage(statistiques stat, size_t n);
void to_string(statistiques stat, char * string);

#ifdef __cplusplus
}
#endif

#endif
