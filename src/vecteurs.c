#include <stdio.h>
#include <stdlib.h>
#include "vecteurs.h"

// Initialisation d'un vecteur :
int vector_init(Vector* v, size_t dimension)
{
	v->tableau = malloc(sizeof(double) * dimension);
	if(!v->tableau) return -1;
	
	v->taille = dimension;
	v->nb_element = 0;
}

// Ajout element :
void vector_push_back(Vector *v, double element)
{
	if(v->nb_element < v->taille)
	{
		v->tableau [v->nb_element] = element;
		v->nb_element = v->nb_element + 1;
	}
	else
	{
		fprintf(stderr, "Erreur, index depassant la taille maximale \n");
		exit(-1);
	}
}


// retourne la dimension du vecteur initial :
int calcul_dimension(char *parametres)
{
	int dimension = 1;
	for(int i=0; i<strlen(parametres); ++i)
	{
		if(parametres[i] == 41) dimension++;
	}
	return dimension;
}

