#ifndef H_VECTEURSIMPLE
#define H_VECTEURSIMPLE

#include <string.h>

// Structure d'un vecteur :
typedef struct {
	double* tableau;
	size_t taille;
	size_t nb_element;
} Vector;

//
int vector_init(Vector* v, size_t dimension);
void vector_push_back(Vector* v, double element);


//
int calcul_dimension(char *parametres);


// pour le c, on utilise atof() pour convertir un char* en float



#endif
