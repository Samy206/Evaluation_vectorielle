#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif
#include "../headers/gestion_ES.h"

Gestion_ES * initialisation_ES(char * fct, Liste_vecteur * liste, statistiques * stats)
{
    Gestion_ES * gestionnaire = malloc(sizeof(Gestion_ES));

    gestionnaire->fonction = malloc(100);
    memset(gestionnaire->fonction,0,100*sizeof(char));
    strcpy(gestionnaire->fonction,fct);

    gestionnaire->liste = liste;
    gestionnaire->stats = stats;

    gestionnaire->fic_gnup = GetCurrentDir(NULL, 0);
    gestionnaire->fic_post= GetCurrentDir(NULL, 0);
    strcat(gestionnaire->fic_gnup,"/ressources/");
    strcat(gestionnaire->fic_post,"/ressources/");
    return gestionnaire;
};

int generation_fic_gnuplot(Gestion_ES * gestionnaire, char * filename)
{
    strcat(gestionnaire->fic_gnup,filename);
    strcat(gestionnaire->fic_gnup,".p");
    FILE * file ;
    file = fopen(gestionnaire->fic_gnup, "w");
    if(!file ) return -1;
    Vector tmp1;
    int taille_vec = gestionnaire->liste->premier->vecteur.taille;
    double * tableau_tmp3 = malloc(taille_vec * sizeof(double));

    for(int i = 0 ; i < taille_vec ; i++)
        fprintf(file,"0 ");

    for(int i = 0 ; i < gestionnaire->liste->taille ; i++)
    {
        if(i == 0)
        {
            tmp1 = consultation_liste(gestionnaire->liste,i);
            for(int i = 0 ; i < taille_vec ; i++)
            {
                fprintf(file,"%.16f ",tmp1.tableau[i]);
            }
        }

        else if(i == 1)
        {
            fprintf(file,"\n");

            for(int i = 0 ; i < taille_vec ; i++)
                fprintf(file,"%.16f ",tmp1.tableau[i]);

            for(int i = 0 ; i < taille_vec ; i++)
                tableau_tmp3[i] = tmp1.tableau[i];

            tmp1 = consultation_liste(gestionnaire->liste,i);

            for(int i = 0 ; i < taille_vec ; i++)
                fprintf(file,"%.16f ",tmp1.tableau[i]);

            for(int i = 0 ; i < taille_vec ; i++)
                tableau_tmp3[i] += tmp1.tableau[i];

        }
        else if(i > 1 && i < (gestionnaire->liste->taille - 1) )
        {
            fprintf(file,"\n");

            for(int i = 0 ; i < taille_vec ; i++)
                fprintf(file,"%.16f ",tableau_tmp3[i]);

            tmp1 = consultation_liste(gestionnaire->liste,i);

            for(int i = 0 ; i < taille_vec ; i++)
                fprintf(file,"%.16f ",tmp1.tableau[i]);

            for(int i = 0 ; i < taille_vec ; i++)
                tableau_tmp3[i] += tmp1.tableau[i];

        }
        else if(i == (gestionnaire->liste->taille - 1) )
        {
            fprintf(file,"\n");
            tmp1 = consultation_liste(gestionnaire->liste,i);

            for(int i = 0 ; i < taille_vec ; i++)
                fprintf(file,"%.16f ",tableau_tmp3[i]);

            for(int i = 0 ; i < taille_vec ; i++)
                fprintf(file,"%.16f ",tmp1.tableau[i]);

            for(int i = 0 ; i < taille_vec ; i++)
                tableau_tmp3[i] += tmp1.tableau[i];

            fprintf(file,"\n");

            for(int i = 0 ; i < taille_vec ; i++)
                fprintf(file,"%.16f ",tableau_tmp3[i]);

            for(int i = 0 ; i < taille_vec ; i++)
                fprintf(file,"0 ");


        }
    }
    fprintf(file,"\n# %s\n",gestionnaire->fonction);
    fclose(file);
    return 1;
};

int draw_table_postscript(FILE * file,int x, int y, int largeur)
{
    if(!file) return -1;
    fprintf(file,"%d %d moveto\n"
                 "%d %d lineto\n"
                 "%d %d lineto\n"
                 "%d %d lineto\n"
                 "%d %d lineto\n"
                 "%d %d moveto\n"
                 "%d %d lineto\n",
                 x, y,
                 x + 500, y,
                 x + 500, y - largeur,
                 x, y - largeur,
                 x , y,
                 x + 250, y,
                 x + 250, y - largeur
                 );
    return 0;
};


int stat_string_parser(char * string,char ** tableau)
{
    if(string[0] ==' ')
    {
        free(string);
        return 0;
    }

    int cmp = 0;
    int j = 0;


    for(int i = 0 ; i < strlen(string) ; i++)
    {
        if(i == 0)
        {
            tableau[cmp] = malloc(20 * sizeof(char));
            memset(tableau[cmp],0,20);
            tableau[cmp][j] = string[i];
            j++;
        }
        else
        {

            if(string[i] == '|')
            {
                cmp++;
                tableau[cmp] = malloc(20 * sizeof(char));
                memset(tableau[cmp],0,20);
                j = 0;

            }
            else
            {
                 tableau[cmp][j] = string[i];
                j++;
            }
        }
    }
    printf("string : %s, tableau : %s, cmp : %d\n",string,tableau[4],cmp);

    return cmp;
};

int generation_fic_postscript(Gestion_ES * gestionnaire, char * filename)
{
    strcat(gestionnaire->fic_post,filename);
    strcat(gestionnaire->fic_post,".ps");
    printf("path ps : %s\n",gestionnaire->fic_post);

    FILE * file ;
    file = fopen(gestionnaire->fic_post, "w");

    if(!file) return -1;

    fprintf(file,"newpath\n"
                 "/Helvetica 20 selectfont\n"
                 "30 750 moveto\n"
                 "(%s) show\n"
                 "30 700 moveto\n"
                 "(V_0 = %s) show\n",
                 gestionnaire->fonction,
                 to_string_vec(gestionnaire->liste->premier->vecteur)
            );

    int cmp;
    char * nb_stats = to_string(*(gestionnaire->stats));
    char ** tableau_string = NULL;
    tableau_string = malloc(6 * sizeof(char*));
    int dimension = gestionnaire->liste->premier->vecteur.taille;
    float x,y,largeur;
    x = 100 ; y = 650;
    int nb_stats_diff = stat_string_parser(nb_stats,tableau_string);
    int vrai_nb_stats = 0 ;

    for(int i = 0 ; i < 2; i++)
    {

        for(int j = 0 ; j <= nb_stats_diff ; j++)
        {

            if(i == 0)
            {
                if(strcmp(tableau_string[j],"Autocorrelaton") == 0)
                    vrai_nb_stats += (dimension);

                else
                    vrai_nb_stats += (dimension + 1);
            }

            else
            {
                if(strcmp(tableau_string[j],"Autocorrelation") == 0)
                {
                    for(int k = 0 ; k < dimension ; k++)
                    {
                        fprintf(file , "%f %f moveto\n"
                                       "(%s %d) show\n"
                                       "%f %f moveto\n"
                                       "(%f) show\n",
                                       x, y,
                                       tableau_string[j],k,
                                       x + 250, y,
                                       gestionnaire->stats->atc_d[k]
                               );
                               y = y - largeur;
                    }
                }
                else if(strcmp(tableau_string[j],"Maximum") == 0)
                {
                    fprintf(file , "%f %f moveto\n"
                                   "(Maximum_n) show\n"
                                   "%f %f moveto\n"
                                   "(%f) show\n",
                                   x, y,
                                   x + 250, y,
                                   gestionnaire->stats->max_n
                    );
                    y = y - largeur;
                    for(int k = 0 ; k < dimension ; k++)
                    {
                        fprintf(file , "%f %f moveto\n"
                                       "(%s %d) show\n"
                                       "%f %f moveto\n"
                                       "(%f) show\n",
                                       x, y,
                                       tableau_string[j],k,
                                       x + 250, y,
                                       gestionnaire->stats->max_d[k]
                               );
                               y = y - largeur;
                    }
                }

                else if(strcmp(tableau_string[j],"Minimum") == 0)
                {
                    fprintf(file , "%f %f moveto\n"
                                   "(%s _n) show\n"
                                   "%f %f moveto\n"
                                   "(%f) show\n",
                                   x, y,
                                   tableau_string[j],
                                   x + 250, y,
                                   gestionnaire->stats->min_n
                    );
                    y = y - largeur;
                    for(int k = 0 ; k < dimension ; k++)
                    {
                        fprintf(file , "%f %f moveto\n"
                                       "(%s %d) show\n"
                                       "%f %f moveto\n"
                                       "(%f) show\n",
                                       x, y,
                                       tableau_string[j],k,
                                       x + 250, y,
                                       gestionnaire->stats->min_d[k]
                               );
                               y = y - largeur;
                    }
                }
                else if(strcmp(tableau_string[j],"Variance") == 0)
                {
                    fprintf(file , "%f %f moveto\n"
                                   "(%s _n) show\n"
                                   "%f %f moveto\n"
                                   "(%f) show\n",
                                   x, y,
                                   tableau_string[j],
                                   x + 250, y,
                                   gestionnaire->stats->var_n
                    );
                    y = y - largeur;
                    for(int k = 0 ; k < dimension ; k++)
                    {
                        fprintf(file , "%f %f moveto\n"
                                       "(%s %d) show\n"
                                       "%f %f moveto\n"
                                       "(%f) show\n",
                                       x, y,
                                       tableau_string[j],k,
                                       x + 250, y,
                                       gestionnaire->stats->var_d[k]
                               );
                               y = y - largeur;
                    }
                }
                else if(strcmp(tableau_string[j],"Standard deviation") == 0)
                {
                    printf("entered standart deviation\n");
                    fprintf(file , "%f %f moveto\n"
                                   "(%s _n) show\n"
                                   "%f %f moveto\n"
                                   "(%f) show\n",
                                   x, y,
                                   tableau_string[j],
                                   x + 250, y,
                                   gestionnaire->stats->ect_n
                    );
                    y = y - largeur;
                    for(int k = 0 ; k < dimension ; k++)
                    {
                        fprintf(file , "%f %f moveto\n"
                                       "(%s %d) show\n"
                                       "%f %f moveto\n"
                                       "(%f) show\n",
                                       x, y,
                                       tableau_string[j],k,
                                       x + 250, y,
                                       gestionnaire->stats->ect_d[k]
                               );
                        y = y - largeur;
                    }
                }
                else if(strcmp(tableau_string[j],"Average") == 0)
                    {
                        fprintf(file , "%f %f moveto\n"
                                       "(%s _n) show\n"
                                       "%f %f moveto\n"
                                       "(%f) show\n",
                                       x, y,
                                       tableau_string[j],
                                       x + 250, y,
                                       gestionnaire->stats->moy_n
                        );
                        y = y - largeur;
                        for(int k = 0 ; k < dimension ; k++)
                        {
                            fprintf(file , "%f %f moveto\n"
                                           "(%s %d) show\n"
                                           "%f %f moveto\n"
                                           "(%f) show\n",
                                           x, y,
                                           tableau_string[j],k,
                                           x + 250, y,
                                           gestionnaire->stats->moy_d[k]
                                   );
                            y = y - largeur;
                        }
                    }

                }
        }
        largeur = 650 / vrai_nb_stats;
        y = y - (largeur/ 2);
        if(i == 0)
        {
            fprintf(file,"/Helvetica %f selectfont\n",
                           largeur/2);
        }
    }



    x = 50; y = 650;
    for(int i = 0 ; i < (vrai_nb_stats-1) ; i++)
    {
        draw_table_postscript(file,x,y,largeur);
        y = y - largeur;
        x = 50;
    }
    fprintf(file,"stroke\nshowpage\n");
    fclose(file);
    return 0;

};