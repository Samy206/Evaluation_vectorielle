#ifndef OUVERTURE_H
#define OUVERTURE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

typedef struct taille
{
    int * t_val;
    int nb_val;
}taille;

typedef struct donnee
{
    char ** entier;
    float * valeur;
    char * fonction;
    int nombre;
    int erreur;
}donnee;

donnee init_struct_d(donnee d);
taille init_struct_t(taille t);
void free_struct(donnee d);
donnee val(donnee d, int i);
donnee chargement_fic_gnup(char *nom, donnee d, taille t);

void free_struct_d(donnee d,int t_taille);

#ifdef __cplusplus
}
#endif

#endif
