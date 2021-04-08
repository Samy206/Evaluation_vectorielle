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


int main(int argc, char** argv)
{
	
	Vector v;
	
	if(vector_init(&v, 3)) printf("initialisation reussie \n");
	else printf("Erreur \n");
	
	vector_push_back(&v, 10.12);
	vector_push_back(&v, 20.13);
	vector_push_back(&v, 30.11);
	
	printf(" taille du vecteur : %d\n", (int)v.taille);
	for(int i=0; i<(int)v.taille; ++i)
	{
		printf(" composante %d du vecteur : %f\n", i, v.tableau [i]);
	}
	
	
	/*************************************************/
	/**********   Liste de vecteur     **************/
	
	// paramètres entrés par l'utilisateur :
	char v_initial[100];
	printf("Saisissez un vecteur initial : \n");
	scanf("%s", &v_initial);
	
	char v_fonction[100];
	printf("Saisissez vos fonctions : \n");
	scanf("%s", &v_fonction);
	
	int nb_vecteurs_max = 0;
	printf("Saisissez le nombre de vecteurs à calculer : \n");
	scanf("%d", &nb_vecteurs_max);
	
	//
	int dimension = calcul_dimension(v_initial);
	
	//
	Vector liste_vecteur[nb_vecteurs_max];
	for(int i = 0; i<nb_vecteurs_max; ++i)
	{
		if(vector_init(&liste_vecteur[i], dimension)) printf("Initialisation ok \n");
		else
		{
			fprintf(stderr, "Erreur \n");
			return -1;
		}
	}
	
	
	
	
	return 0;
}
