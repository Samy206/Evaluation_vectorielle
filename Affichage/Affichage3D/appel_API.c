#define PY_SSIZE_T_CLEAN

#include "appel_API.h"
void Affichage3D_API(){
	//sert a initier l'API

	Py_Initialize();

  //pour pointer le du dossier actuel chemin
  char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       ;
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

  // appel du module
  pModule = PyImport_ImportModule("affichage3D");PyErr_Print();

  // message d'erreur
  if (pModule == NULL) {
    printf("ERROR importing module\n");
  }  

  Py_Finalize();
  
}


