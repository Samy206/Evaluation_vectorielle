#include "../Headers/transfert_fichiers_affichage3D.h"

void transfert_stat(size_t nb_dim, std::string nom, statistiques stat)
{
	std::ofstream fichier(nom);
	int test = 0;
	//size_t nb_dim = consultation_liste(l, 0).taille;
	
	if(!fichier)
	{
		std::cout<<"erreur lors de l'ouverture du fichier"<<std::endl;
	}
	
	else
	{
		fichier << stat.min_n << std::endl;
		while(test < nb_dim)
		{
            if(stat.min_d == NULL) break;
			fichier << stat.min_d[test] << std::endl; 
            test++;
		}
		test = 0;
		
		fichier << stat.max_n << std::endl;
		while(test < nb_dim)
		{
            if(stat.max_d == NULL) break;
			fichier << stat.max_d[test] << std::endl;
            test++;
		}
		test = 0;
		
		fichier << stat.moy_n << std::endl;
		while(test < nb_dim)
		{   
            if(stat.moy_d == NULL) break;
			fichier << stat.moy_d[test] << std::endl;
            test++;
		}
		test = 0;
		
		fichier << stat.var_n << std::endl;
		while(test < nb_dim)
		{
            if(stat.var_d == NULL) break;
			fichier << stat.var_d[test] << std::endl;
            test++;		
        }
		test = 0;
		
		fichier << stat.ect_n << std::endl;
		while(test < nb_dim)
		{
            if(stat.ect_d == NULL) break;			
            fichier << stat.ect_d[test] << std::endl;
            test++;
		}
		test = 0;
		
		while(test < nb_dim)
		{
            if(stat.atc_d == NULL) break;
			fichier << stat.atc_d[test] << std::endl;
            test++;
		}
		test = 0;
	}
	
	fichier.close();
}

void transfert_vecteurs(std::string nom, Liste_vecteur *l)
{
	size_t nb_dim = consultation_liste(l, 0).taille;
	std::ofstream fichier(nom);
	
	if(!fichier)
	{
		std::cout<<"erreur lors de l'ouverture du fichier"<<std::endl;
	}
	
	else
	{
		for(int i = 0; i < l->taille; i++)
		{
			for(int j = 0; j < nb_dim; j++)
			{
				fichier << consultation_liste(l,i).tableau[j] << std::endl;
			}
		}
	}
	
	fichier.close();
}

void transfert_fonction(std::string nom, std::string equation)
{
	std::ofstream fichier(nom);
	
	if(!fichier)
	{
		std::cout<<"erreur lors de l'ouverture du fichier"<<std::endl;
	}
	
	else
	{
		fichier << equation << std::endl;
	}
	
	fichier.close();
}
