#ifndef H_VECTEURS
#define H_VECTEURS

#include <string.h>

// Structure d'un vecteur :
typedef struct {
	double* tableau;
	size_t taille;
	size_t nb_element;
} Vector;


//
int vector_init(Vector* v, size_t dimension);		// initialisation
void vector_push_back(Vector* v, double d);	// ajout d'un élément dans le vecteur
void free_vector(Vector v);

//
int calcul_dimension(char *parametres);
double* recupere_composantes(int dimension, char *p);

//
char * to_string_vec(Vector v);

// pour le c, on utilise atof() pour convertir un char* en float
// 44 = ,
// 41 = )
// 46 = .


#endif
