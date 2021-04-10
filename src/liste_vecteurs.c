#include <stdio.h>
#include <stdlib.h>
#include "../headers/liste_vecteurs.h"

Liste_vecteur* initialisation_liste(Vector * vec)
{
	Liste_vecteur * liste = malloc(sizeof(Liste_vecteur));
	element * nouveau = malloc(sizeof(element));
	
	nouveau->vecteur = *vec;
	nouveau->suivant = NULL;
	
	liste->taille = 1;
	liste->premier = nouveau;
	return liste;
}

void push_liste(Liste_vecteur * liste, Vector vec)
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
		
		while(tmp->suivant)
		{
			tmp = tmp->suivant;
		}
		tmp->suivant = nouveau;
		
	}
	liste->taille++;
	
}

void pop_liste(Liste_vecteur * liste)
{
	if(liste->premier == NULL || liste->taille == 0)
	{
		printf("Liste vide \n");
		return;
	}
	else if (liste->taille == 1 )
	{
		free_vector(liste->premier->vecteur);
        liste->premier = NULL;
        liste->taille--;
	}
	else
	{
		element * tmp1 = liste->premier;
        while(tmp1->suivant->suivant != NULL)
        {
			tmp1 = tmp1->suivant;
		}
        
        element * tmp2 = tmp1->suivant;
        tmp1->suivant = NULL;
        free_vector(tmp2->vecteur);
        liste->taille--;
	}
}

Vector consultation_liste(Liste_vecteur * liste, int indice)
{
    if (liste == NULL || indice >= liste->taille) exit(EXIT_FAILURE);

    element * tmp = liste->premier;

    for(int i = 0 ; i < indice ; i++)
        tmp = tmp->suivant;

    return tmp->vecteur;
};

Vector top_liste(Liste_vecteur * liste)
{
    if (liste == NULL ) exit(EXIT_FAILURE);

    element * tmp = liste->premier;

    while(tmp->suivant != NULL)
        tmp = tmp->suivant;

    return tmp->vecteur;
};

void afficherListe(Liste_vecteur * liste)
{
    if (liste == NULL) exit(EXIT_FAILURE);
    

    element * actuel = liste->premier;

    while (actuel != NULL)
    {
		printf(" ( ");
		for(int i=0; (size_t)i<actuel->vecteur.taille; ++i)
		{
			printf("%f  ", actuel->vecteur.tableau[i]);
		}
		printf(")\n");
        actuel = actuel->suivant;
    }
	
}

void free_liste(Liste_vecteur * liste)
{
	while(liste->premier != NULL )
        pop_liste(liste);
}





