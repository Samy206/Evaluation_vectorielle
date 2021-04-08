#include "vecteur.h"

#ifndef LISTE_VECTEURS
#define LISTE_VECTEURS

typedef struct element        //Brique de la liste appelée "element" : Un vecteur et un pointeur vers le suivant
{
    Vector vecteur;
    Vector * suivant;
}
element;

typedef struct liste          //Liste à proprement parler
{
    elem * premier;
    int taille;
}
Liste_vecteur;

Liste_vecteur * initialisation_liste();                          //initialisation

void push_liste(Liste_vecteur * liste, Vector vec);              //Ajout d'un vecteur à la liste
Vector top_liste(Liste_vecteur * liste);                         //Consultation du dernier vecteur ajouté
void pop_liste(Liste_vecteur * liste);                           //Suppression du dernier élément ajouté
Vector consultation_liste(Liste_vecteur * liste, int indice);    //Consultation d'un vecteur dans la liste
void free_liste(Liste_vecteur liste);                            //Libération de la mémoire allouée



#endif