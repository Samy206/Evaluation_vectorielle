#include "../Headers/transfert_fichiers_affichage3D.h"

void transfert_stat(size_t nb_dim, std::string nom, statistiques stat)
{
	std::ofstream fichier;

	fichier.open("../Affichage/Affichage3D/"+nom, std::ofstream::out|std::ofstream::trunc);

	if(!fichier)
	{
		std::cout<<"erreur lors de l'ouverture du fichier"<<std::endl;
	}
	else
	{
	
        if(stat.statistiques_demandees[0]){
			fichier << "min normes: "<< stat.min_n << std::endl;
			fichier << "min x: "<< stat.min_d[0] << std::endl; 
			fichier << "min y: "<< stat.min_d[1] << std::endl; 
			fichier << "min z: "<< stat.min_d[2] << std::endl; 
        }
           
        if(stat.statistiques_demandees[1]){
			fichier << "max normes: "<< stat.max_n << std::endl;
			fichier << "max x: "<< stat.max_d[0] << std::endl;
			fichier << "max y: "<< stat.max_d[1] << std::endl;
			fichier << "max z: "<< stat.max_d[2] << std::endl;
		}
		
		
		if(stat.statistiques_demandees[2]){
			fichier << "moyenne normes: "<< stat.moy_n << std::endl;
			fichier << "moyenne x: "<< stat.moy_d[0] << std::endl;
            fichier << "moyenne y: "<< stat.moy_d[1] << std::endl;
            fichier << "moyenne y: "<< stat.moy_d[2] << std::endl;
            
		}
		
	    if(stat.statistiques_demandees[3]){
			fichier <<"variance normes: " << stat.var_n << std::endl;
			fichier <<"variance x: "<< stat.var_d[0] << std::endl;
			fichier <<"variance y: "<< stat.var_d[1] << std::endl;
			fichier <<"variance z: "<< stat.var_d[2] << std::endl;
	    }
		
		
   	    if(stat.statistiques_demandees[4]){
			fichier << "écart-type normes: "<< stat.ect_n << std::endl;
            fichier << "écart-type x: "<< stat.ect_d[0] << std::endl;
            fichier << "écart-type y: "<< stat.ect_d[1] << std::endl;
            fichier << "écart-type z: "<< stat.ect_d[2] << std::endl;
		}

	    if(stat.statistiques_demandees[5]) {
			fichier << "auto-corellation x: "<< stat.atc_d[0] << std::endl;
			fichier << "auto-corellation x: "<< stat.atc_d[1] << std::endl;
			fichier << "auto-corellation x: "<< stat.atc_d[2] << std::endl; 

		}
	}

	
	fichier.close();
}

void transfert_vecteurs(std::string nom, Liste_vecteur *l)
{
	size_t nb_dim = consultation_liste(l, 0).taille;
	std::ofstream fichier;

	fichier.open("../Affichage/Affichage3D/"+nom, std::ofstream::out|std::ofstream::trunc);
	
	if(!fichier)
	{
		std::cout<<"erreur lors de l'ouverture du fichier"<<std::endl;
	}
	
	else
	{
		//ajout de l'origine (x,y,z) = (0,0,0)
		fichier << "0" << std::endl;
		fichier << "0" << std::endl;
		fichier << "0" << std::endl;

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
	std::ofstream fichier;

	fichier.open("../Affichage/Affichage3D/"+nom, std::ofstream::out|std::ofstream::trunc);
	
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
