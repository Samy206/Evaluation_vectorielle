#include <stdlib.h>
#include <stdio.h>
#include "../headers/liste_vecteurs.h"
#include "vecteurs.c"

void initialisation_liste(Liste_vecteur * liste)
{
    liste = malloc(sizeof(Liste_vecteur));
    liste->taille = 0;
    liste->premier = NULL;
};


void push_liste(Liste_vecteur * liste,Vector vec)
{
    element * nouveau = malloc(sizeof(element));
    nouveau->vecteur = vec;
    nouveau->suivant = NULL;

    if(liste->premier == NULL)
    {
        liste->premier = nouveau;
    }

    else
    {
        element * tmp = liste->premier;

        while(tmp->suivant != NULL)
            tmp = tmp->suivant;

        tmp->suivant = nouveau;
    }

    liste->taille++;
};

Vector top_liste(Liste_vecteur * liste)
{
    element * tmp = liste->premier;

    while(tmp->suivant != NULL)
        tmp = tmp->suivant;

    return tmp->vecteur;
};

void pop_liste(Liste_vecteur * liste)
{

    if(liste->premier == NULL || liste->taille == 0)
    {
        printf("liste vide\n");
        return;
    }

    else if (liste->taille == 1 || liste->premier == NULL)
    {
        //free_vector(liste->premier->vecteur);
        liste->premier = NULL;
        liste->taille--;

    }

    else
    {
        element * tmp1 = liste->premier;
        while(tmp1->suivant->suivant != NULL)
            tmp1 = tmp1->suivant;

        element * tmp2 = tmp1->suivant;
        tmp1->suivant = NULL;
        //free_vector(tmp2->vecteur);
        liste->taille--;
    }
};


Vector consultation_liste(Liste_vecteur * liste, int indice)
{
    element * tmp = liste->premier;

    for(int i = 0 ; i < indice ; i++)
        tmp = tmp->suivant;

    return tmp->vecteur;
};

void free_liste(Liste_vecteur * liste)
{
    while(liste->taille != 0 || liste->premier != NULL )
        pop_liste(liste);

    //free(liste);
};