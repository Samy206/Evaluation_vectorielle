#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#ifdef _WIN32
#include <direct.h>
#define OS 0
#define GetCurrentDir _getcwd
#else
#define OS 1
#include <unistd.h>
#define GetCurrentDir getcwd
#endif
#include "../Headers/gestion_ES.h"

void initialisation_ES(Gestion_ES * gestionnaire,char * fct, Liste_vecteur * liste, statistiques * stats)
{
    if(fct != NULL)
    {
        gestionnaire->fonction = malloc(100);
        memset(gestionnaire->fonction, 0, 100 * sizeof(char));
        strcpy(gestionnaire->fonction, fct);
    }

    gestionnaire->liste = liste;
    gestionnaire->stats = stats;

    gestionnaire->fic_gnup = malloc(200 * sizeof(char));
    gestionnaire->fic_post = malloc(200 * sizeof(char));
    gestionnaire->script_gnup = malloc(200 * sizeof(char));
    GetCurrentDir(gestionnaire->fic_gnup,200 );
    GetCurrentDir(gestionnaire->fic_post,200 );
    GetCurrentDir(gestionnaire->script_gnup,200 );

    strcat(gestionnaire->fic_gnup,"/ressources/");
    strcat(gestionnaire->fic_post,"/ressources/");
    strcat(gestionnaire->script_gnup,"/ressources/");

};

/*Écriture des coordonnées des vecteurs dans un fichier qui sera lu par le script gnuplot*/
int generation_fic_gnuplot(Gestion_ES * gestionnaire, char * filename)
{
    //Récupération du nombre de dimensions et applications des vérifications dessus
    int taille_vec = gestionnaire->liste->premier->vecteur.taille;
    
    //Génération du chemin absolu du fichier de coordonnées
    strcat(gestionnaire->fic_gnup,filename);
    strcat(gestionnaire->fic_gnup,".txt");

    //Ouverture fichier
    FILE * file ;
    file = fopen(gestionnaire->fic_gnup, "w");
    if(!file )
    {
        printf("Erreur d'ouverture du fichier de coordonnees gnuplot\n");
        return -1;
    }

    int i,j;
    element * tmp = gestionnaire->liste->premier;

    //Tableau temporaire qui nous servira à définir les points où on arrive à chaque fois
    double tableau_tmp3 [taille_vec];
    for(i =0 ; i < taille_vec ; i++)
    {
        tableau_tmp3[i] = 0.0;
    }

    //Récupération du nombre de vecteurs
    int taille_liste = gestionnaire->liste->taille;

    //Écriture des coordonnées avec le format que gnuplot demande
    if(taille_liste > 1)
    {
        for (i = 0; i < taille_vec; i++)
            fprintf(file, "%.16f ",0.0);

        for (i = 0; i < taille_liste - 1; i++)
        {
            if (i == 0)
            {
                for (j = 0; j < taille_vec; j++)
                {
                    fprintf(file, "%.16f ", tmp->vecteur.tableau[j]);
                }
            }
            else if (i == 1)
            {
                fprintf(file, "\n");

                for (j = 0; j < taille_vec; j++)
                    fprintf(file, "%.16f ", tableau_tmp3[j]);

                for (j = 0; j < taille_vec; j++)
                    fprintf(file, "%.16f ", tmp->vecteur.tableau[j]);


            }
            else if (i > 1)
            {
                fprintf(file,"\n");

                for (j = 0; j < taille_vec; j++)
                    fprintf(file, "%.16f ", tableau_tmp3[j]);

                for (j = 0; j < taille_vec; j++)
                    fprintf(file, "%.16f ", tmp->vecteur.tableau[j]);

            }

            for (int j = 0; j < taille_vec; j++)
                tableau_tmp3[j] += tmp->vecteur.tableau[j];

            tmp = tmp->suivant;
        }
        fprintf(file,"\n");
    }


    for(i = 0 ; i < taille_vec ; i++)
        fprintf(file,"%.16f ",tableau_tmp3[i]);

    for(i = 0 ; i < taille_vec ; i++)
        fprintf(file,"%.16f ",tmp->vecteur.tableau[i]);

    for(i = 0 ; i < taille_vec ; i++)
        tableau_tmp3[i] += tmp->vecteur.tableau[i];

    fprintf(file,"\n");

    for(i = 0 ; i < taille_vec ; i++)
        fprintf(file,"%.16f ",tableau_tmp3[i]);

    for(i = 0 ; i < taille_vec ; i++)
        fprintf(file,"%.16f ",0.0);


    //Écriture de la fonction
    fprintf(file,"\n# %s\n",gestionnaire->fonction);

    fclose(file);
    return 0;
};

/*Génération d'un fichier graphique gnuplot sous format png sur deux ou trois dimensions suite à la lecture des
 coordonnées des vecteurs*/
int generation_script_gnuplot(Gestion_ES * gestionnaire, char* filename)
{
    //Récupération du nombre de dimensions et vérifications
    int dimension = gestionnaire->liste->premier->vecteur.taille;
    if(dimension > 3 || dimension == 1)
    {
        printf("Les vecteurs n'ont pas un nombre de dimensions satifaisant les caractéristiques d'affichage gnuplot : une dimension ou plus de trois\n");
        return dimension;
    }

    //Formation du chemin absolu du script
    strcat(gestionnaire->script_gnup,filename);
    strcat(gestionnaire->script_gnup,".p");

    FILE * file = fopen(gestionnaire->script_gnup,"w");
    if(!file)
    {
        printf("Erreur d'ouverture de fichier script gnuplot\n");
        return -1;
    }

    //Écriture du script
    fprintf(file,"set terminal png\n");
    if(!OS)
        sprintf(gestionnaire->fic_gnup,"ressources/%s.txt",filename);
    fprintf(file,"set output %cressources/%s.png%c\n",'"',filename,'"');
    fprintf(file,"Graph = %c%s%c\n",'"',gestionnaire->fic_gnup,'"');

    if (dimension == 2)
    {
        fprintf(file, "plot Graph using 1:2 with lines\n");
    }

    else if(dimension == 3)
    {
        fprintf(file, "splot Graph using 1:2:3 with lines\n");
    }


    //Lancement du script sur un autre processeur
    pthread_t thread;
    if(OS)
        pthread_create(&thread,NULL,launch_gnup_script,filename);
    else
        pthread_create(&thread,NULL,launch_gnup_script_WIN,filename);

    fclose(file);
    return 0;
}

/*Lancement du script_gnuplot*/
void * launch_gnup_script(void * filename)
{
    char * name = (char *) (filename);
    char cmd[50];
    sprintf(cmd,"gnuplot -c ressources/%s.p",name);     //Écriture de la commande système dans un char *
    system(cmd);                                        //Lancement de celle-ci
    pthread_exit(NULL);
}

void * launch_gnup_script_WIN(void * filename)
{
    char * name = (char *) (filename);
    char cmd[50];
    sprintf(cmd,"start Gnuplot_call.bat ressources/%s.p",name);     //Écriture de la commande système dans un char *
    system(cmd);                                        //Lancement de celle-ci
    pthread_exit(NULL);
}

/*Dessine une case du tableau sous format postscript sur une longueur de 500 et une largeur dépendant du nombre
 de statistiques à afficher*/
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

/*Lecture, séparation et stockage de chaque statistique à afficher dans la variable tableau*/
int stat_string_parser(char * string,char ** tableau)
{
    if(string[0] ==' ')
        return 0;

    int cmp = 0;
    int j = 0;
    int size = strlen(string);

    for(int i = 0 ; i < size ; i++)
    {
        if(i == 0)
        {
            if(string[i] != '|')
            {
                tableau[cmp][j] = string[i];
                j++;
            }
        }
        else
        {
            if(string[i] == '|')
            {
                tableau[cmp][j] = '\0';
                cmp++;
                j = 0;

            }
            else
            {
                tableau[cmp][j] = string[i];
                j++;
            }
        }
        if(i == (size-1))
            tableau[cmp][j] ='\0';
    }

    return cmp;
};

/*Transformation d'un indice de tableau en son axe correspondant (x,y,z ...)*/
char traduction_index_axe(int index)
{
    switch (index) {
        case 0 :
            return 'x';
        case 1 :
            return 'y';
        case 2 :
            return 'z';
        default :
            return ((char) (94 + index));
    }
}

/*Fonction principale écrivant les statistiques et faisant appel aux fonctions précédentes afin de former un premier
 fichier postscript qui est transformé via une commande système en un fichier pdf*/
int generation_fic_postscript(Gestion_ES * gestionnaire, char * filename)
{
    //Génération du path du fichier ps
    strcat(gestionnaire->fic_post,filename);
    strcat(gestionnaire->fic_post,".ps");

    //Ouverture du fichier
    FILE * file ;
    file = fopen(gestionnaire->fic_post, "w");

    if(!file)
    {
        printf("Erreur d'ouverture du fichier postscript\n");
        return -1;
    }


    //Écriture des informations précédents les statistiques : Fonction, vecteur initial et nombre de vecteurs
    fprintf(file,"newpath\n"
                 "/Helvetica 20 selectfont\n"
                 "30 750 moveto\n"
                 "(F(x) = ( %s) ) show\n"
                 "30 700 moveto\n"
                 "(V_0 = %s) show\n"
                 "30 650 moveto\n"
                 "(Nombre de vecteurs : %d) show\n",
            gestionnaire->fonction,
            to_string_vec(gestionnaire->liste->premier->vecteur),
            gestionnaire->liste->taille
    );

    //Récupération de la string contenant les statistiques à afficher
    char * string = malloc(70 * sizeof(char));
    memset(string,0,70);
    to_string(*(gestionnaire->stats),string);

    //Séparation des statistiques à afficher à partir de la string précédente
    char ** tableau_string = NULL;
    tableau_string = malloc(6 * sizeof(char*));
    for(int i = 0 ; i < 6 ; i++)
    {
        tableau_string[i] = malloc(20 * sizeof(char));
    }
    int nb_stats_diff = stat_string_parser(string,tableau_string);

    //Récupération du nombre de dimension des vecteurs
    int dimension = gestionnaire->liste->premier->vecteur.taille;
    int x,y,largeur;
    x = 100 ; y = 600;

    int vrai_nb_stats = 0 ;

    for(int i = 0 ; i < 2; i++)
    {
        for (int j = 0; j <= nb_stats_diff; j++)
        {
            /*Calcul du nombre total des statistiques à afficher ( celles s'appliquant sur plusieurs champs tels que la
             norme et les différentes dimensions) */
            if(i == 0)
            {
                if (strcmp(tableau_string[j], "Standard deviation") == 0)
                    vrai_nb_stats += (dimension);

                else
                    vrai_nb_stats += (dimension + 1);

            }

            /*Écriture des statistique sur la norme et sur les différentes dimensions*/
            else
            {
                    if(strcmp(tableau_string[j],"Autocorrelation") == 0)
                    {
                        for(int k = 0 ; k < dimension ; k++)
                        {
                            fprintf(file , "%d %d moveto\n"
                                           "(%s_%c) show\n"
                                           "%d %d moveto\n"
                                           "(%g) show\n",
                                    x, y,
                                    tableau_string[j], traduction_index_axe(k),
                                    x + 250, y,
                                    gestionnaire->stats->atc_d[k]
                            );
                            y = y - largeur;
                        }
                    }
                    else if(strcmp(tableau_string[j],"Maximum") == 0)
                    {
                        fprintf(file , "%d %d moveto\n"
                                       "(Maximum_n) show\n"
                                       "%d %d moveto\n"
                                       "(%g) show\n",
                                x, y,
                                x + 250, y,
                                gestionnaire->stats->max_n
                        );
                        y = y - largeur;
                        for(int k = 0 ; k < dimension ; k++)
                        {
                            fprintf(file , "%d %d moveto\n"
                                           "(%s_%c) show\n"
                                           "%d %d moveto\n"
                                           "(%g) show\n",
                                    x, y,
                                    tableau_string[j], traduction_index_axe(k),
                                    x + 250, y,
                                    gestionnaire->stats->max_d[k]
                            );
                            y = y - largeur;
                        }
                    }

                    else if(strcmp(tableau_string[j],"Minimum") == 0)
                    {
                        fprintf(file , "%d %d moveto\n"
                                       "(%s_n) show\n"
                                       "%d %d moveto\n"
                                       "(%g) show\n",
                                x, y,
                                tableau_string[j],
                                x + 250, y,
                                gestionnaire->stats->min_n
                        );
                        y = y - largeur;
                        for(int k = 0 ; k < dimension ; k++)
                        {
                            fprintf(file , "%d %d moveto\n"
                                           "(%s_%c) show\n"
                                           "%d %d moveto\n"
                                           "(%g) show\n",
                                    x, y,
                                    tableau_string[j], traduction_index_axe(k),
                                    x + 250, y,
                                    gestionnaire->stats->min_d[k]
                            );
                            y = y - largeur;
                        }
                    }
                    else if(strcmp(tableau_string[j],"Variance") == 0)
                    {
                        fprintf(file , "%d %d moveto\n"
                                       "(%s_n) show\n"
                                       "%d %d moveto\n"
                                       "(%g) show\n",
                                x, y,
                                tableau_string[j],
                                x + 250, y,
                                gestionnaire->stats->var_n
                        );
                        y = y - largeur;
                        for(int k = 0 ; k < dimension ; k++)
                        {
                            fprintf(file , "%d %d moveto\n"
                                           "(%s_%c) show\n"
                                           "%d %d moveto\n"
                                           "(%g) show\n",
                                    x, y,
                                    tableau_string[j], traduction_index_axe(k),
                                    x + 250, y,
                                    gestionnaire->stats->var_d[k]
                            );
                            y = y - largeur;
                        }
                    }
                    else if(strcmp(tableau_string[j],"Standard deviation") == 0)
                    {
                        fprintf(file , "%d %d moveto\n"
                                       "(%s_n) show\n"
                                       "%d %d moveto\n"
                                       "(%g) show\n",
                                x, y,
                                tableau_string[j],
                                x + 250, y,
                                gestionnaire->stats->ect_n
                        );
                        y = y - largeur;
                        for(int k = 0 ; k < dimension ; k++)
                        {
                            fprintf(file , "%d %d moveto\n"
                                           "(%s_%c) show\n"
                                           "%d %d moveto\n"
                                           "(%g) show\n",
                                    x, y,
                                    tableau_string[j], traduction_index_axe(k),
                                    x + 250, y,
                                    gestionnaire->stats->ect_d[k]
                            );
                            y = y - largeur;
                        }
                    }
                    else if(strcmp(tableau_string[j],"Average") == 0)
                    {
                        fprintf(file , "%d %d moveto\n"
                                       "(%s_n) show\n"
                                       "%d %d moveto\n"
                                       "(%g) show\n",
                                x, y,
                                tableau_string[j],
                                x + 250, y,
                                gestionnaire->stats->moy_n
                        );
                        y = y - largeur;
                        for(int k = 0 ; k < dimension ; k++)
                        {
                            fprintf(file , "%d %d moveto\n"
                                           "(%s_%c) show\n"
                                           "%d %d moveto\n"
                                           "(%g) show\n",
                                    x, y,
                                    tableau_string[j], traduction_index_axe(k),
                                    x + 250, y,
                                    gestionnaire->stats->moy_d[k]
                            );
                            y = y - largeur;
                        }
                    }

                }
            }

        /*Calcul de la largeur en fonction du nombre de case à dessiner*/
        largeur = 600 / vrai_nb_stats;

        if(largeur > 20)
            fprintf(file,"/Helvetica 15 selectfont\n");
        else
            fprintf(file,"/Helvetica 10 selectfont\n");

        y = y - ((3*largeur)/4);
    }

    //Dessin des cases du tableau
    x = 50; y = 600;
    for(int i = 0 ; i < vrai_nb_stats  ; i++)
    {
        draw_table_postscript(file,x,y,largeur);
        y = y - largeur;
        x = 50;
    }

    fprintf(file,"stroke\nshowpage\n");
    fclose(file);

    //Libération de la mémoire allouée
    for(int i = 0 ; i < 6 ; i++)
    {
        free(tableau_string[i]);
    }
    free(tableau_string);
    free(string);

    //Conversion ps to pdf via commande système
    char command1[100];
    //Suppression du fichier .ps après la conversion en pdf
    char command2[100];
    if(OS) {
        sprintf(command1, "ps2pdf ressources/%s.ps ressources/%s.pdf", filename, filename);
        sprintf(command2, "rm ressources/%s.ps", filename);
    }
    else {
        sprintf(command1, "start Postscript_call.bat ressources/%s.ps ressources/%s.pdf", filename, filename);
        sprintf(command2, "del ressources/%s.ps", filename);
    }

    system(command1);
    system(command2);

    return 0;

};

/*Chargement d'un fichier gnuplot*/
int chargement_fic_gnup(Vector * vecteur, char * funct, char * filename)
{
    FILE * file = fopen(filename,"r");
    if(!file)
    {
        return 1;
    }
    char line[255];

    int i = 0, j;
    int cmp = 0;
    int size;

    //Lecture ligne par ligne
    while( fgets(line, sizeof(line), file) != NULL )
    {
        size = strlen(line);
        //Récupération de la dimension et des coordonnées du premier vecteur à partir de la première ligne
        if(i == 0 && line[0] != '#')
        {
            //Compte du nombre de dimensions
            for(j = 0 ; j < size ; j++)
            {
                if((line[j] == ' ' || line[j] == '\n'))
                    cmp++;
            }

            //Vérification de la valeur obtenue
            if(cmp % 2 != 0)
            {
                return 2;
            }

            //Initialisation du vecteur avec le bom nombre de dimensions
            vector_init(vecteur,cmp/2);

            //Récupération des coordonnées
            string_parser(vecteur,line,cmp);
        }

        else if(line[0] == '#')
        {
            //Lecture et copie de la fonction
            for(j = 1 ; j < size ; j++)
            {
                funct[j-1] = line[j];
            }
            funct[j] = '\0';
        }
        i++;
    }
    fclose(file);
    return 0;
}


/*Récupération des coordonnées d'un vecteur à partir d'une char * */
int string_parser(Vector * vecteur, char * line, int size)
{
    //Tableau qui contiendra les entiers
    char numbers[size][50];
    double tmp;
    int cmp = 0;
    int j = 0;
    int ascii;
    int length = strlen(line);

    for(int i = 0 ; i <length ; i++)
    {
        ascii = (int) (line[i]);
        //Les deux premières valeurs (0.0000, 0.0000) ne sont pas comptabilisés
        if( line[i] == ' ' && cmp < (size/2))
        {
            numbers[cmp][j] = '\0';
            cmp++;
            j = 0;
        }

        //Conversion des valeurs qui nous intéressent
        else if( ((line[i] == ' ') || (line[i] == '\n') )&& cmp >= (size/2))
        {
            numbers[cmp][j] = '\0';
            tmp = atof(numbers[cmp]);
            vector_push_back(vecteur,tmp);
            cmp++;
            j = 0;
        }

        //Copie des valeurs dans un char * avant leur conversion
        else if( (ascii >= 48 && ascii <= 57) || (ascii == 46) )
        {
            numbers[cmp][j] = line[i];
            j++;
        }
    }
    return 0;
}

void free_gestionnaire_es(Gestion_ES * gestionnaire)
{
    if(gestionnaire)
    {
        if(gestionnaire->fonction)
            free(gestionnaire->fonction);

        if(gestionnaire->stats)
            free_statistiques(*(gestionnaire->stats));

        if(gestionnaire->liste)
            free_liste(gestionnaire->liste);

        if(gestionnaire->fic_gnup)
            free(gestionnaire->fic_gnup);

        if(gestionnaire->fic_post)
            free(gestionnaire->fic_post);

        if(gestionnaire->script_gnup)
            free(gestionnaire->script_gnup);

    }
};
