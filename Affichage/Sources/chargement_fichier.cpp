#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "../Headers/chargement_fichier.h"

taille init_struct_t(taille t)
{
    t.t_val = NULL;
    t.nb_val = 0;
    return t;
}

donnee init_struct_d(donnee d)
{
    d.entier = NULL;
    d.valeur = NULL;
    d.fonction = NULL;
    d.nombre = 0;
    return d;
}

void free_struct_t(taille t)
{
    free(t.t_val);
}

void free_struct_d(donnee d,int t_taille)
{
    for(int i = 0; i < t_taille; i++)
    {
        free(d.entier[i]);
    }
    free(d.entier);
    free(d.valeur);
    free(d.fonction);
}

taille calc_taille(taille t, char *nom)
{
    t.t_val = (int*)malloc(sizeof(int));
    t.t_val[0] = 0;
    int curseur = 0;
    int i = 1;
    int j = 0;
    int k = 0;
    FILE *fichier = NULL;
    fichier = fopen(nom,"r");
    if(!fichier)
    {
        printf("le fichier n'a pas pu être ouvert");
        //d.erreur = 2;
        return t;
    }
    while(k != 1)
    {
        curseur = fgetc(fichier);
        if(curseur != 32 && curseur != '\n')
        {
            j = j + 1;
        }
        else
        {
            if(curseur == '\n')
            {
                i = i+1;
                t.t_val = (int*)realloc(t.t_val,i*sizeof(int));
                t.t_val[i-2] = j;
                j = 0;
                t.nb_val = t.nb_val + 1;
                k = 1;
            }
            else
            {
                i = i+1;
                t.t_val = (int*)realloc(t.t_val,i*sizeof(int));
                t.t_val[i-2] = j;
                j = 0;
                t.nb_val = t.nb_val + 1;
            }
        }
    }
    fclose(fichier);
    return t;
}

donnee val(donnee d, int i)
{
    int j = i/2;
    d.valeur = (float*)malloc(j*sizeof(float));
    for(int t = 0; t < (i/2); t++)
    {
        d.valeur[t] = atof(d.entier[j]);
        j = j+1;
    }
    return d;
}

donnee chargement_fic_gnup(char *nom, donnee d, taille t)
{
    t = calc_taille(t,nom);
    FILE * fichier = NULL;
    fichier = fopen(nom,"r");
    if(!fichier)
    {
        printf("le fichier n'a pas pu être ouvert");
        d.erreur = 2;
        return d;
    }
    d.entier = (char**)malloc((t.nb_val+1) * sizeof(char*));
    d.fonction = (char*)malloc(sizeof(char));
    for(int i = 0; i < t.nb_val; i++)
    {
        d.entier[i] = (char*)malloc((t.t_val[i]+1) * sizeof(char));
    }
    int c = 0;
    int i = 0;
    int j = 0;
    while(c != '\n')
    {
        if(c < 48 && c > 57 && c != 32 && c != 45)
        {
            printf("le fichier n'est pas valide, les caractères de la première ligne ne sont pas que des chiffres ou des espaces");
            break;
            d.erreur = 1;
        }
        c = fgetc(fichier);
        if(c != 32)
        {
            d.entier[i][j] = c;
            j = j+1;
        }
        else
        {
            i = i+1;
            j = 0;
        }
    }
    while(c != 35)
    {
        c = fgetc(fichier);
        if(c == EOF)
        {
            printf("le fichier n'est pas valide il n'y a pas de # devant la fonction");
            d.erreur = 1;
            break;
        }
    }

    if(d.erreur == 0)
    {
        c = fgetc(fichier);
        c = fgetc(fichier);
    }
    i = 1;
    while (c != EOF)
    {
        i = i + 1;
               d.fonction =  (char*)realloc(d.fonction,i*sizeof(char));
        d.fonction[i-1] = c;
        c = fgetc(fichier);
    }
    if(!t.nb_val%2)
    {
        printf("le nombre de vecteur de la première ligne n'est pas valide");
        d.erreur = 1;
    }
    d = val(d,t.nb_val);
    fclose(fichier);
    d.nombre = t.nb_val;
    free_struct_t(t);
    return d;
}

