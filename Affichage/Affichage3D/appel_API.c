#define PY_SSIZE_T_CLEAN

#include "appel_API.h"
/*
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

void affichage(statistiques stat, size_t n)
{
    if(stat.statistiques_demandes[0])
    {
        printf("Norme minimal:%.16f \n", stat.min_n);
        for(int i=0; i<n; i++)
            printf("Minimal sur dim%d :%.16f |",i, stat.min_d[i]);
        printf("\n");
    }
    if(stat.statistiques_demandes[1])
    {
        printf("Norme max:%.16f \n", stat.max_n);
        for(int i=0; i<n; i++)
            printf("Max sur dim%d :%.16f |",i, stat.max_d[i]);
        printf("\n");
    }
    if(stat.statistiques_demandes[2])
    {
        printf("Norme moy:%.16f \n", stat.moy_n);
        for(int i=0; i<n; i++)
            printf("Moyenne sur dim%d :%.16f |",i, stat.moy_d[i]);
        printf("\n");
    }
    if(stat.statistiques_demandes[3])
    {
        printf("Variance Norme:%lf \n", stat.var_n);
        for(int i=0; i<n; i++)
            printf("Variance sur dim%d :%.16f |",i, stat.var_d[i]);
        printf("\n");
    }
    if(stat.statistiques_demandes[4])
    {
        printf("Ecart-type Norme:%.16f \n", stat.ect_n);
        for(int i=0; i<n; i++)
            printf("Ecart-type sur dim%d :%.16f |",i, stat.ect_d[i]);
        printf("\n");
    }
    if(stat.statistiques_demandes[5])
    {
        for(int i=0; i<n; i++)
            printf("Auto-correlation sur dim%d :%.16f |",i, stat.atc_d[i]);
        printf("\n");
        
    }
    printf("%s\n",to_string(stat));
}
*/
void Affichage3D_API(){
	//sert a initier l'API

	Py_Initialize();

  //pour pointer le du dossier actuel chemin
  char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("Current working dir: %s\n", cwd);
   } else {
       perror("getcwd() error");
   }

  //ajoute un chemin au projet
  PyObject *sys_path = PySys_GetObject("path");
  PyList_Append(sys_path, PyUnicode_FromString(cwd));
  //PyList_Append(sys_path, PyUnicode_FromString("../Affichage/Python"));

  // déclarations
  PyObject *pval;
  PyObject *pName;
  PyObject *pModule;
  PyObject *pValue;
  PyObject *pFunc;

  //appel du module
  pModule = PyImport_ImportModule("affichage3D");PyErr_Print();

  //appel de la fonction
  // argv[2] is the function name defined in pModule
  // pFunc is the reference to the function
  if (pModule == NULL) {
   printf("ERROR importing module\n");
   }
  //obtention d'un pointeur pour la fonction
  //pFunc = PyObject_GetAttrString(pModule, "Affichage3D_fenetre");


  //Double check we have actually found it and it is callable
    /*if (!pFunc || !PyCallable_Check(pFunc)) {
        if (PyErr_Occurred()) {
            PyErr_Print();
        }
        fprintf(stderr, "Cannot find function \"blah\"\n");
    }*/
   //insertion des arguments
  //PyObject *pythonArgument;
  //pythonArgument = PyTuple_New(1);
  //pValue = PyLong_FromLong(4);
  //pValue = PyUnicode_FromString("argv[3]");
  //PyTuple_SetItem(pythonArgument, 0, pValue);
  //pValue = PyObject_CallObject(pFunc, pythonArgument);
  
  //appel de la fonction, fonctionne seulement en python3.9
  //pValue = PyObject_CallNoArgs(pFunc);
  

  Py_Finalize();
  
}


