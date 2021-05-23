#include "../Headers/transfert_fichiers_affichage3D.h"

void transfert_stat(size_t nb_dim, std::string nom, statistiques stat)
{
	std::ofstream fichier("../Affichage/Affichage3D/"+nom);
	//int test = 0;
	//size_t nb_dim = consultation_liste(l, 0).taille;
	
	if(!fichier)
	{
		std::cout<<"erreur lors de l'ouverture du fichier"<<std::endl;
	}
	
	else
	{
		fichier << stat.min_n << std::endl;
	
        if(stat.min_d != NULL){
			fichier << "min x: "<< stat.min_d[0] << std::endl; 
			fichier << "min y: "<< stat.min_d[1] << std::endl; 
			fichier << "min z: "<< stat.min_d[2] << std::endl; 
        }
		fichier << stat.max_n << std::endl;
           
        if(stat.max_d != NULL){
			fichier << "max x: "<< stat.max_d[0] << std::endl;
			fichier << "max y: "<< stat.max_d[1] << std::endl;
			fichier << "max z: "<< stat.max_d[2] << std::endl;
		}
		
		fichier << stat.moy_n << std::endl;
		
		if(stat.moy_d != NULL){
			fichier << "moy x: "<<stat.moy_d[0] << std::endl;
            fichier << "moy y: "<<stat.moy_d[1] << std::endl;
            fichier << "moy y: "<<stat.moy_d[2] << std::endl;
            
		}
		
		fichier << stat.var_n << std::endl;
	    if(stat.var_d != NULL){
			fichier <<"variance x: "<< stat.var_d[0] << std::endl;
			fichier <<"variance y: "<< stat.var_d[1] << std::endl;
			fichier <<"variance z: "<< stat.var_d[2] << std::endl;
	    }
		
		fichier << stat.ect_n << std::endl;
		
   	    if(stat.ect_d != NULL){
            fichier << "ecart-type x: "<<stat.ect_d[0] << std::endl;
            fichier << "ecart-type y: "<<stat.ect_d[1] << std::endl;
            fichier << "ecart-type z: "<<stat.ect_d[2] << std::endl;
		}

	    if(stat.atc_d != NULL) {
			fichier << "auto-corellation x: "<<stat.atc_d[0] << std::endl;
			fichier << "auto-corellation x: "<<stat.atc_d[1] << std::endl;
			fichier << "auto-corellation x: "<<stat.atc_d[2] << std::endl;

		}
		/*
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
	*/
	}

	
	fichier.close();
}

void transfert_vecteurs(std::string nom, Liste_vecteur *l)
{
	size_t nb_dim = consultation_liste(l, 0).taille;
	//std::ifstream input("../Affichage/Affichage3D/"+nom);
	std::ofstream fichier("../Affichage/Affichage3D/"+nom);
	
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
	std::ofstream fichier("../Affichage/Affichage3D/"+nom);
	
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
