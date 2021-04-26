#include <stdio.h>
#include <stdlib.h>
#include "../headers/vecteurs.h"

// Initialisation d'un vecteur :
int vector_init(Vector* v, size_t dimension)
{

	v->tableau = malloc(sizeof(double) * dimension);
	if(!v->tableau) return -1;
	
	v->taille = dimension;
	v->nb_element = 0;
	return 0;
}

// Ajout element :
void vector_push_back(Vector *v, double d)
{
	if(v->nb_element < v->taille)
	{
		v->tableau [v->nb_element] = d;
		v->nb_element = v->nb_element + 1;
	}
	else
	{
		fprintf(stderr, "Erreur, index depassant la taille maximale \n");
		exit(-1);
	}
}

// libération de la mémoire d'un vector : 
void free_vector(Vector v)
{
	free(v.tableau);
}


// retourne la dimension du vecteur initial :
int calcul_dimension(char *parametres)
{
	int dimension = 1;
	for(int i=0; i<strlen(parametres); ++i)
	{
		if(parametres[i] == 44) dimension++;
	}
	return dimension;
}

// transforme une chaine de caractère en un tableau de double 
double* recupere_composantes(int dimension, char *p)
{
	double * T = malloc(sizeof(double) * dimension);
	char msg[100];
	int index_T = 0, j = 0;
	double number = 0.0;
	
	for(int i=1; i<strlen(p); i++)
	{
		if (p[i] == 44 || p[i] == 41)
		{
			number = atof(msg);
			j = 0;
			T[index_T] = number;
			index_T++;
		}
		else
		{
			msg[j] = p[i];
			j++;
		}
	}
	return T;
}

char * to_string_vec(Vector v)
{
    char * string = malloc(75*sizeof(char));
    memset(string,0,75*sizeof(char));

    sprintf(string,"( ");
    for(int i = 0 ; i < v.taille ; i++)
    {
        if(i != (v.taille - 1) )
        {
           sprintf(string,"%s %f ;",string,v.tableau[i]);
        }
        else
        {
           sprintf(string,"%s %f )",string,v.tableau[i]);
        }
    }
    return string;
}
