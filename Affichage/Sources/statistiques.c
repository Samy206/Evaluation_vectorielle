#include "../Headers/statistiques.h"

statistiques init_statistiques(size_t nb_dim, int* statistiques_demandes)
{
    statistiques stat;
    stat.min_n = 0;
	stat.max_n = 0;
	stat.moy_n = 0;
	stat.var_n = 0;
	stat.ect_n = 0;
    stat.statistiques_demandees = malloc(6*sizeof(int));

    for(int i=0;i<6;i++)
    {
        stat.statistiques_demandees[i] = statistiques_demandes[i];
    }

    stat.min_d = calloc(nb_dim, sizeof(double));
    stat.max_d = calloc(nb_dim, sizeof(double));

    if(statistiques_demandes[2] || statistiques_demandes[3] || statistiques_demandes[4] || statistiques_demandes[5])
        stat.moy_d = calloc(nb_dim, sizeof(double));
    else
        stat.moy_d = NULL;


    if(statistiques_demandes[3] || statistiques_demandes[4] || statistiques_demandes[5])
        stat.var_d = calloc(nb_dim, sizeof(double));
    else
        stat.var_d = NULL;

    if(statistiques_demandes[4] || statistiques_demandes[5])
        stat.ect_d = calloc(nb_dim, sizeof(double));
    else
        stat.ect_d = NULL;

    if(statistiques_demandes[5])
        stat.atc_d = calloc(nb_dim, sizeof(double));
    else
        stat.atc_d = NULL;

    return stat;
}


statistiques free_statistiques(statistiques stat)
{
    free(stat.statistiques_demandees);
	if(stat.min_d != NULL)
		free(stat.min_d);
	
	if(stat.max_d != NULL)
		free(stat.max_d);
	
	if(stat.moy_d != NULL)
		free(stat.moy_d);
	
	if(stat.var_d != NULL)
		free(stat.var_d);
	
	if(stat.ect_d != NULL)
		free(stat.ect_d);
	
	if(stat.atc_d != NULL)
		free(stat.atc_d);
	
	return stat;
}

double calcul_norme(Vector v)
{
	double somme = 0;
    for(int i=0; i < (int)v.taille; i++)
	{
		somme += pow(v.tableau[i],2);
	}
	return sqrt(somme);
}

statistiques minimum(statistiques stat, Liste_vecteur* vecteurs)
{
	size_t nb_dim = consultation_liste(vecteurs, 0).taille;
	stat.min_n = calcul_norme(consultation_liste(vecteurs,0));
	
    for(int i = 0; i<(int)nb_dim; i++)
	{
		stat.min_d[i] = consultation_liste(vecteurs,0).tableau[i];
	}
	
	for(int w = 1; w<vecteurs->taille; w++)
	{
		double norme = calcul_norme(consultation_liste(vecteurs,w));
		if(norme < stat.min_n)
			stat.min_n = norme;
		
        for(int i = 0; i<(int)nb_dim; i++)
		{
			double dim = consultation_liste(vecteurs,w).tableau[i];
			if(dim < stat.min_d[i])
				stat.min_d[i] = dim;
		}
	}

	return stat;
}

statistiques maximum(statistiques stat, Liste_vecteur* vecteurs)
{
	size_t nb_dim = consultation_liste(vecteurs, 0).taille;
	stat.max_n = calcul_norme(consultation_liste(vecteurs,0));
	
    for(int i = 0; i<(int)nb_dim; i++)
	{
		stat.max_d[i] = consultation_liste(vecteurs,0).tableau[i];
	}
	
	for(int w = 1; w<vecteurs->taille; w++)
	{
		double norme = calcul_norme(consultation_liste(vecteurs,w));
		if(norme > stat.max_n)
			stat.max_n = norme;
		
        for(int i = 0; i<(int)nb_dim; i++)
		{
			double dim = consultation_liste(vecteurs,w).tableau[i];
			if(dim > stat.max_d[i])
				stat.max_d[i] = dim;
		}
	}

	return stat;
}

statistiques moyenne(statistiques stat, Liste_vecteur* vecteurs)
{
	size_t nb_dim = consultation_liste(vecteurs, 0).taille;
	for(int w = 0; w<vecteurs->taille; w++)
	{
		stat.moy_n += calcul_norme(consultation_liste(vecteurs,w));

        for(int i = 0; i<(int)nb_dim; i++)
		{
			double dim = consultation_liste(vecteurs,w).tableau[i];
			stat.moy_d[i] += dim;
		}
	}

	stat.moy_n = stat.moy_n/vecteurs->taille;

    for(int i = 0; i<(int)nb_dim; i++)
	{
		stat.moy_d[i] = stat.moy_d[i]/vecteurs->taille;
	}
	
	return stat;
}

//Si l'utilisateur demande le calcul de la variance la moyenne sera quand même calculer

statistiques variance(statistiques stat, Liste_vecteur* vecteurs)
{
	double nb_dim = (double)consultation_liste(vecteurs, 0).taille;
	
	for(int w = 0; w<vecteurs->taille; w++)
	{
		double norme = calcul_norme(consultation_liste(vecteurs,w));
		stat.var_n += pow(norme - stat.moy_n,2);
		
		for(int i = 0; i<nb_dim; i++)
		{
			double dim = consultation_liste(vecteurs,w).tableau[i];
			stat.var_d[i] += pow(dim - stat.moy_d[i],2);
		}
	}

	stat.var_n = stat.var_n/vecteurs->taille;
	
	for(int i = 0; i<nb_dim; i++)
	{
		stat.var_d[i] = stat.var_d[i]/vecteurs->taille;
	}
	
	return stat;
}

//Si l'utilisateur demande le calcul de l'écart type la moyenne et la variance seront quand même calculer

statistiques ecart_type(statistiques stat, Liste_vecteur* vecteurs)
{
	size_t nb_dim = consultation_liste(vecteurs, 0).taille;
	stat.ect_n = sqrt(stat.var_n);
	
    for(int i = 0; i<(int)nb_dim; i++)
	{
		stat.ect_d[i] = sqrt(stat.var_d[i]);
	}

	return stat;
}

//Si l'utilisateur demande le calcul de l'autocorrelation la moyenne et la variance seront quand même calculer

statistiques calcul_auto_correlation(statistiques stat, Liste_vecteur* vecteurs, int decallage)
{

	size_t nb_dim = consultation_liste(vecteurs, 0).taille;
	for(int w = 0; w<vecteurs->taille; w++)
	{
        for(int i = 0; i<(int)nb_dim; i++)
		{
			double dim1 = consultation_liste(vecteurs,w).tableau[i];
			double dim2;
			if(decallage > w)
			{
				dim2 = consultation_liste(vecteurs,(w - decallage)+vecteurs->taille).tableau[i]; 
			}
			else 
			{
				dim2 = consultation_liste(vecteurs,w - decallage).tableau[i];
			}
			stat.atc_d[i] += (dim1 - stat.moy_d[i]) * (dim2 - stat.moy_d[i]);
		}
	}
    for(int i=0; i<(int)nb_dim; i++)
		stat.atc_d[i] = (stat.atc_d[i]/vecteurs->taille)/stat.var_d[i];
	return stat;
}

statistiques calcul_des_statistiques(int* statistiques_demandes, Liste_vecteur* vecteurs)
{
	statistiques stat ;
	stat = init_statistiques(consultation_liste(vecteurs, 0).taille, statistiques_demandes);

	stat = minimum(stat, vecteurs);
	stat = maximum(stat, vecteurs);

	if(statistiques_demandes[2] || statistiques_demandes[3] || statistiques_demandes[4] || statistiques_demandes[5])
		stat = moyenne(stat, vecteurs);

	if(statistiques_demandes[3] || statistiques_demandes[4] || statistiques_demandes[5])
		stat = variance(stat, vecteurs);

	if(statistiques_demandes[4] || statistiques_demandes[5])
		stat = ecart_type(stat, vecteurs);
	
	if(statistiques_demandes[5])
		stat = calcul_auto_correlation(stat, vecteurs, statistiques_demandes[5]);

	return stat;
}

void to_string(statistiques stat, char * string)
{
    if(stat.statistiques_demandees[0])
        strcat(string,"Minimum");

    if(stat.statistiques_demandees[1])
        strcat(string,"|Maximum");

    if(stat.statistiques_demandees[2] || stat.statistiques_demandees[3] || stat.statistiques_demandees[4] || stat.statistiques_demandees[5])
        strcat(string,"|Average");

    if(stat.statistiques_demandees[3] || stat.statistiques_demandees[4] || stat.statistiques_demandees[5])
        strcat(string,"|Variance");

    if(stat.statistiques_demandees[4] || stat.statistiques_demandees[5])
        strcat(string,"|Standard deviation");

    if(stat.statistiques_demandees[5])
        strcat(string,"|Autocorrelation");

};

void affichage(statistiques stat, size_t n)
{
    if(stat.statistiques_demandees[0])
    {
        printf("Norme minimal:%lf \n", stat.min_n);
        for(int i=0; i<(int)n; i++)
            printf("Minimal sur dim%d :%lf |",i, stat.min_d[i]);
        printf("\n");
    }
    if(stat.statistiques_demandees[1])
    {
        printf("Norme max:%lf \n", stat.max_n);
        for(int i=0; i<(int)n; i++)
            printf("Max sur dim%d :%lf |",i, stat.max_d[i]);
        printf("\n");
    }
    if(stat.statistiques_demandees[2])
    {
        printf("Norme moy:%lf \n", stat.moy_n);
        for(int i=0; i<(int)n; i++)
            printf("Moyenne sur dim%d :%lf |",i, stat.moy_d[i]);
        printf("\n");
    }
    if(stat.statistiques_demandees[3])
    {
        printf("Variance Norme:%lf \n", stat.var_n);
        for(int i=0; i<(int)n; i++)
            printf("Variance sur dim%d :%lf |",i, stat.var_d[i]);
        printf("\n");
    }
    if(stat.statistiques_demandees[4])
    {
        printf("Ecart-type Norme:%lf \n", stat.ect_n);
        for(int i=0; i<(int)n; i++)
            printf("Ecart-type sur dim%d :%lf |",i, stat.ect_d[i]);
        printf("\n");
    }
    if(stat.statistiques_demandees[5])
    {
        for(int i=0; i<(int)n; i++)
            printf("Auto-correlation sur dim%d :%lf |",i, stat.atc_d[i]);
        printf("\n");

    }
   //to_string(stat),string);
}
