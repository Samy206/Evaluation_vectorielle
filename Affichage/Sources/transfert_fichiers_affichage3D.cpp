#ifdef WIN32
#define OStrans 0
#else
#define OStrans 1
#endif

#include "../Headers/transfert_fichiers_affichage3D.h"

void transfert_stat(size_t nb_dim, std::string nom, statistiques stat)
{
	std::ofstream fichier;
	//ouverture/création du ficher txt, trunc sert a être sûr de supprimer l'ancien
    if(OStrans)
        fichier.open("./Affichage3D/"+nom, std::ofstream::out|std::ofstream::trunc);
    else
        fichier.open("./Sources_python/"+nom, std::ofstream::out|std::ofstream::trunc);

	if(!fichier)
	{
		std::cout<<"erreur lors de l'ouverture du fichier"<<std::endl;
	}
	else
	{
		// écriture dans le fichier de chaque donnée statistique 
		// a condition que l'utilisateur l'ai choisi

        if(stat.statistiques_demandees[0]){
			fichier << "minimum of norms: "<< stat.min_n << std::endl;
			fichier << "minimum of x: "<< stat.min_d[0] << std::endl; 
			fichier << "minimum of y: "<< stat.min_d[1] << std::endl; 
			fichier << "minimum of z: "<< stat.min_d[2] << std::endl; 
        }
           
        if(stat.statistiques_demandees[1]){
			fichier << "maximum of norms: "<< stat.max_n << std::endl;
			fichier << "maximum of x: "<< stat.max_d[0] << std::endl;
			fichier << "maximum of y: "<< stat.max_d[1] << std::endl;
			fichier << "maximum of z: "<< stat.max_d[2] << std::endl;
		}
		
		
		if(stat.statistiques_demandees[2]){
			fichier << "average of norms: "<< stat.moy_n << std::endl;
			fichier << "average of x: "<< stat.moy_d[0] << std::endl;
            fichier << "average of y: "<< stat.moy_d[1] << std::endl;
            fichier << "average of y: "<< stat.moy_d[2] << std::endl;
            
		}
		
	    if(stat.statistiques_demandees[3]){
			fichier <<"variance of norms: " << stat.var_n << std::endl;
			fichier <<"variance of x: "<< stat.var_d[0] << std::endl;
			fichier <<"variance of y: "<< stat.var_d[1] << std::endl;
			fichier <<"variance of z: "<< stat.var_d[2] << std::endl;
	    }
		
		
   	    if(stat.statistiques_demandees[4]){
			fichier << "standard deviation of norms: "<< stat.ect_n << std::endl;
            fichier << "standard deviation of x: "<< stat.ect_d[0] << std::endl;
            fichier << "standard deviation of y: "<< stat.ect_d[1] << std::endl;
            fichier << "standard deviation of z: "<< stat.ect_d[2] << std::endl;
		}

	    if(stat.statistiques_demandees[5]) {
			fichier << "autocorellation of x: "<< stat.atc_d[0] << std::endl;
			fichier << "autocorellation of y: "<< stat.atc_d[1] << std::endl;
			fichier << "autocorellation of z: "<< stat.atc_d[2] << std::endl; 

		}
	}

	
	fichier.close();
}

//fonction qui écrit les informations de la liste de vecteur dans un fichier texte
void transfert_vecteurs(std::string nom, Liste_vecteur *l)
{
	size_t nb_dim = consultation_liste(l, 0).taille;
	std::ofstream fichier;
	//ouverture/création du ficher txt, trunc sert a être sûr de supprimer l'ancien
    if(OStrans)
        fichier.open("./Affichage3D/"+nom, std::ofstream::out|std::ofstream::trunc);
    else
        fichier.open("./Sources_python/"+nom, std::ofstream::out|std::ofstream::trunc);
	
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

		//ajput du reste des vecteurs
		for(int i = 0; i < l->taille; i++)// boucle de taille de la liste 
		{
			for(int j = 0; j < nb_dim; j++)// boucle de taille nombre d'axes (3)
			{
				fichier << consultation_liste(l,i).tableau[j] << std::endl;
			}
		}
	}
	
	fichier.close();
}

//fonction qui écrit les informations de la liste de vecteur dans un fichier texte
void transfert_fonction(std::string nom, std::string equation)
{
	std::ofstream fichier;
	//ouverture/création du ficher txt, trunc sert a être sûr de supprimer l'ancien
    if(OStrans)
        fichier.open("./Affichage3D/"+nom, std::ofstream::out|std::ofstream::trunc);
    else
        fichier.open("./Sources_python/"+nom, std::ofstream::out|std::ofstream::trunc);
	
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
