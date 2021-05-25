

#ifndef H_LISTE_VECTEURS
#define H_LISTE_VECTEURS

#ifdef __cplusplus
extern "C" {
#endif


#include "../Headers/vecteurs.h"
#include "../Headers/tinyexpr.h"

typedef struct element        //Brique de la liste appelée "element" : Un vecteur et un pointeur vers le suivant
{
    Vector vecteur;
    struct element * suivant;
}
element;


typedef struct Liste_vecteur          //Liste à proprement parler
{
    element * premier;
    int taille;
}
Liste_vecteur;

Liste_vecteur* initialisation_liste(Vector vec);   						//initialisation

void push_liste(Liste_vecteur * liste, Vector vec);              		//Ajout d'un vecteur à la liste
Vector top_liste(Liste_vecteur * liste);                         		//Consultation du dernier vecteur ajouté
void pop_liste(Liste_vecteur * liste);                           		//Suppression du dernier élément ajouté
Vector consultation_liste(Liste_vecteur * liste, int indice);    		//Consultation d'un vecteur dans la liste
void free_liste(Liste_vecteur* liste);                            		//Libération de la mémoire allouée
void afficherListe(Liste_vecteur * liste);


// initialisation des variables globales :
void initialisation_noms_composantes(char* noms, int taille_vecteur);

//
int recherche_dichotomique(int valeurRecherchee, int borne_inf, int borne_sup);		// pour charger les variables dans le parser 
int est_une_lettre(int valeurRecherchee, int borne_inf, int borne_sup);				// pour vérifier si une inconnus est bien une lettre
int* retourne_nombre_inconnues(char **chaine);								// calcul le nb d'inconnues dans chaque fonctions
char** retourne_tableau_inconnues(char **chaine);							// stocke en mémoire chaque inconnue de chaque fonction

Vector calcul_vecteur(Vector v_precedent, char **chaine);									// calcul le prochain vecteur
void calcul_suite_vecteurs(Liste_vecteur * liste, char **chaine, int taille_liste_max);			// calcul récursivement jusqu'a taille_liste_max


Liste_vecteur* fonction_principale(const char *chaine,const char *val_initiales, int taille_vecteur, int nb_fct, int nb_vec_max, char *noms_compo);

#ifdef __cplusplus
}
#endif


#endif

