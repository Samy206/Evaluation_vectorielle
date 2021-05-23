#ifndef TRANSFERT
#define TRANSFERT

#include "statistiques.h"
#include <string>
#include <iostream>
#include <fstream>

void transfert_stat(size_t nb_dim, std::string nom, statistiques stat);
void transfert_vecteurs(std::string nom, Liste_vecteur *l);
void transfert_fonction(std::string nom, std::string equation);

#endif
