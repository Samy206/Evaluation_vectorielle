#include <stdio.h>
#include <stdlib.h>
#include "../headers/liste_vecteurs.h"
#include "../headers/tinyexpr.h"

#define nb_lettres 26

// variables globales :
int taille_alphabet = 26;
double T[26] = {0};

// maj : 65 à 90
// min : 97 à 122
int alphabet[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78,
					79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};


te_variable vars[] = { {"A", &T[0]}, {"B", &T[1]}, {"C", &T[2]}, {"D", &T[3]}, {"E", &T[4]},
						   {"F", &T[5]}, {"G", &T[6]}, {"H", &T[7]}, {"I", &T[8]}, {"J", &T[9]},
						   {"K", &T[10]}, {"L", &T[11]}, {"M", &T[12]}, {"N", &T[13]}, {"O", &T[14]},
						   {"P", &T[15]}, {"Q", &T[16]}, {"R", &T[17]}, {"S", &T[18]}, {"T", &T[19]},
						   {"U", &T[20]}, {"V", &T[21]}, {"W", &T[22]}, {"X", &T[23]}, {"Y", &T[24]},
						   {"Z", &T[25]}
					 };

int nb_fonctions;
int *T1;		// tableau contenant le nombre d'inconnues par fonction
char **T2;		// tableau contenant chaque inconnue pour chaque fonction
char *nom_composantes;


// initialisation
Liste_vecteur* initialisation_liste(Vector vec)
{
	Liste_vecteur * liste = malloc(sizeof(Liste_vecteur));
	element * nouveau = malloc(sizeof(element));
	
	nouveau->vecteur = vec;
	nouveau->suivant = NULL;
	
	liste->taille = 1;
	liste->premier = nouveau;
	return liste;
}
// ajout 
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

// consultation :
Vector top_liste(Liste_vecteur * liste)
{
    if (liste == NULL ) exit(EXIT_FAILURE);

    element * tmp = liste->premier;

    while(tmp->suivant != NULL)
    {		
		tmp = tmp->suivant;
	}
    return tmp->vecteur;
};


Vector consultation_liste(Liste_vecteur * liste, int index)
{
    if (liste == NULL ) exit(EXIT_FAILURE);

    element * tmp = liste->premier;

    for(int i = 0 ; i < index ; i++)
    {
        tmp = tmp->suivant;
    }
    return tmp->vecteur;
};
// suppression 
void pop_liste(Liste_vecteur * liste)
{
	if(liste->premier == NULL || liste->taille == 0)
	{
		printf("Liste vide \n");
		return;
	}
	else if (liste->taille == 1 || liste->premier == NULL)
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
        free(tmp2);
        liste->taille--;
	}
}

// Libération de la mémoire :
void free_liste(Liste_vecteur * liste)
{
	while(liste->taille != 0 || liste->premier != NULL )
	{
		pop_liste(liste);
	}
}



// afficher les vecteurs de la liste :
void afficherListe(Liste_vecteur * liste)
{
    if (liste == NULL) exit(EXIT_FAILURE);
    
	printf("vecteurs de la liste : \n");
    element * actuel = liste->premier;

    while (actuel != NULL)
    {
		printf(" (");
		for(int i=0; (size_t)i<actuel->vecteur.taille; ++i)
		{
			printf("%f  ", actuel->vecteur.tableau[i]);
		}
		printf(")\n");
        actuel = actuel->suivant;
    }
	
}

// algo recherche dichotomique :
int recherche_dichotomique(int valeurRecherchee, int borne_inf, int borne_sup)
{
	int valeur_milieu;
	if(borne_inf > borne_sup)
	{
		printf("Erreur recherche\n");
		return -1;
	}
	else
	{
		valeur_milieu = (borne_inf+borne_sup)/2;
		if (valeurRecherchee == alphabet[valeur_milieu]) return valeur_milieu;
		else
		{
			if (valeurRecherchee < alphabet[valeur_milieu])
				{
					return(recherche_dichotomique(valeurRecherchee,borne_inf,valeur_milieu-1));
				}
				else
				{	
					return(recherche_dichotomique(valeurRecherchee,valeur_milieu+1, borne_sup));
				}
		}
	}
}

// algo pour vérifier si un caractère appartient à l'alphabet :
int est_une_lettre(int valeurRecherchee, int borne_inf, int borne_sup)
{
	int valeur_milieu;
	if(borne_inf > borne_sup)
	{
		return 0;
	}
	else
	{
		valeur_milieu = (borne_inf+borne_sup)/2;
		if (valeurRecherchee == alphabet[valeur_milieu]) return 1;
		else
		{
			if (valeurRecherchee < alphabet[valeur_milieu])
				{
					return(est_une_lettre(valeurRecherchee,borne_inf,valeur_milieu-1));
				}
				else
				{	
					return(est_une_lettre(valeurRecherchee,valeur_milieu+1, borne_sup));
				}
		}
	}
}

// compte le nombre d'inconnues par fonctions :
int* retourne_nombre_inconnues(char **chaine)
{
	size_t index = 0;
	int * t = malloc(sizeof(int) * nb_fonctions);
	for(int i=0; i<nb_fonctions; ++i)
	{
		t[i] = 0;
	}
	
	for(int i=0; i<nb_fonctions; ++i)
	{
		index = strlen(chaine[i])-1;
		if(strlen(chaine[i]) == 1) t[i] = 1;
		else if (strlen(chaine[i]) == 2)
		{
			printf("Erreur de fonction\n");
			exit(-1);
		}
		else
		{
			for(int j=0; j<strlen(chaine[i]); ++j)
			{
				if ( (j == 0) && (!est_une_lettre(chaine[i][j+1], 0, 26)) )
				{
					if (est_une_lettre(chaine[i][j], 0, 26)) t[i]++;
				}
				else if ((j < index) && (!est_une_lettre(chaine[i][j-1], 0, 26) && !est_une_lettre(chaine[i][j+1], 0, 26)))
				{
					if (est_une_lettre(chaine[i][j], 0, 26)) t[i]++;
				}
			}
			if (est_une_lettre(chaine[i][index], 0, 26))
				if ( !est_une_lettre(chaine[i][index-1],0,26) ) t[i]++;
		}
	}
	return t;
}

// stocke les inconnues de chaque fonction :
char** retourne_tableau_inconnues(char **chaine)
{
	char **t2 = malloc(sizeof(char *) * nb_fonctions);
	for(int i=0; i<nb_fonctions; ++i)
	{
		t2[i] = malloc(sizeof(char) * T1[i]);
	}
	size_t index = 0;
	int k = 0;
	char msg[100];	// pour stocker les inconnues
	for(int i=0; i<nb_fonctions; ++i)
	{
		index = strlen(chaine[i])-1;
		if(strlen(chaine[i]) == 1) msg[0] = chaine[i][0];
		else
		{
			for(int j=0; j<strlen(chaine[i]); ++j)
			{
				if ( (j == 0) && (!est_une_lettre(chaine[i][j+1], 0, nb_lettres)) )
				{
					if (est_une_lettre(chaine[i][j], 0, nb_lettres))
					{
						msg[k] = chaine[i][j];
						k++;
					}
				}
				else if ( (j < index) && (!est_une_lettre(chaine[i][j-1], 0, nb_lettres)) && (!est_une_lettre(chaine[i][j+1], 0, nb_lettres)) )
					if (est_une_lettre(chaine[i][j], 0, nb_lettres))
					{
						msg[k] = chaine[i][j];
						k++;
					}
			}
			if (est_une_lettre(chaine[i][index], 0, nb_lettres))
				if ( !est_une_lettre(chaine[i][index-1],0,nb_lettres) )
				{
					msg[k] = chaine[i][index];
					k++;
				}
		}
		memcpy(t2[i], msg, T1[i]);
		memset(&msg[0], 0, sizeof(msg));
		k = 0;
	}
	return t2;
}


// calcul le prochain vecteur :
Vector calcul_vecteur(Vector v_precedent, char **chaine)
{
	// déclaration :
	Vector v_suivant;
	// initialisation :
	vector_init(&v_suivant, v_precedent.taille);

	int err2;
	for(int i=0; i<v_precedent.taille; ++i)
	{
		te_expr * expr_2 = te_compile(chaine[i], vars, 25, &err2);
		//
		if(expr_2)
		{
			// on charge les inconnues :
			for(int j=0; j<T1[i]; ++j)
			{
				for(int k=0; k<v_precedent.taille; ++k)
				{
					if(T2[i][j] == nom_composantes[k]) 
					{
						T[recherche_dichotomique(T2[i][j], 0, nb_lettres)] = v_precedent.tableau[k];
					}
				}
			}
			// on entre la valeur du prochain vecteur :
			vector_push_back(&v_suivant, te_eval(expr_2));
			// libération de la mémoire :
			te_free(expr_2);
		}
		else
		{
			 printf("Evaluating:\n\t%s\n", chaine[i]);		// si erreur de fonction
			printf("\t%*s^\nError near here", err2-1, "");
		}
	}
	return v_suivant;
}

// calcul suite de vecteur :
void calcul_suite_vecteurs(Liste_vecteur * liste, char **chaine, int taille_liste_max)
{
	while(liste->taille < taille_liste_max)
	{
		push_liste(liste, calcul_vecteur(top_liste(liste), chaine));		// ajout nouveau vecteur
		calcul_suite_vecteurs(liste, chaine, taille_liste_max);				// on passe au vecteur suivant
	}
}



void initialisation_noms_composantes(char *noms, int taille_vecteur)
{
	nom_composantes = malloc(sizeof(char) * taille_vecteur);
	for(int i=0; i<taille_vecteur; ++i)
	{
		nom_composantes[i] = noms[i];
	}
}

Liste_vecteur* fonction_principale(char *chaine, char *val_initiales, int taille_vecteur, int nb_fct, int nb_vec_max, char *noms)
{
   // initialisation du nombre de fonctions et du tableau des fonctions :
	nb_fonctions = nb_fct;
	char ** chaine_fct = recupere_fonctions_ver2(nb_fonctions, chaine);
   // initialisation des deux tableaux d'inconnues :
	T1 = retourne_nombre_inconnues(chaine_fct);
	T2 = retourne_tableau_inconnues(chaine_fct);
	initialisation_noms_composantes(noms, taille_vecteur);
	
	// Déclaration du vecteur initial :
	Vector v_user;
	double * val_ini = recupere_composantes(taille_vecteur, val_initiales);
	
	// Initialisation du vecteur initial :
	vector_init(&v_user, taille_vecteur);
	
	for(int i=0; i < taille_vecteur; ++i)
	{
		// on remplit le vecteur :
		vector_push_back(&v_user, val_ini[i]);
	}
	
	// Liste :
	Liste_vecteur * maliste = initialisation_liste(v_user);
	calcul_suite_vecteurs(maliste, chaine_fct, nb_vec_max);		// calcul 
	
	
	// Free des variables globales :
    free(T1);
    for(int i=0; i<nb_fonctions; ++i)
	{
		free(T2[i]);
	}
	free(T2);
	free(nom_composantes);
	
	// free du tableau des fonctions :
	for(int i=0; i<nb_fonctions; ++i)
	{
		free(chaine_fct[i]);
	}
	free(chaine_fct);
	
	return maliste;
}
