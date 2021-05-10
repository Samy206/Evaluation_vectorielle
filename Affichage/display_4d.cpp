#include "display_4d.h"
#include "ui_display_4d.h"
#include "statistiques.h"
#include "displaywindow.h"
//possible variable
char caracte[26] = {'x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w'};

display_4D::display_4D(executewindow *wind, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::display_4D)
{
    ui->setupUi(this);

    ui->Display_stat_2->setText(QString::fromStdString(wind->funct));
    int n = wind->nbr_dim_vecteur;
    if(wind->statist.statistiques_demandees[0])
    {
        char tot[50];
        sprintf(tot,"Norme minimal : %.16f ", wind->statist.min_n);
        ui->listWidget_2->addItem(QString::fromStdString(tot));
        for(int i=0; i<(int)n; i++)
        {
            char tot[50];
            sprintf(tot,"Minimal sur dim%d : %.16f |",i, wind->statist.min_d[i]);
            ui->listWidget_2->addItem(QString::fromStdString(tot));
        }
    }
    if(wind->statist.statistiques_demandees[1])
    {
        char tot[50];
        sprintf(tot,"Norme max : %.16f ", wind->statist.max_n);
        ui->listWidget_2->addItem(QString::fromStdString(tot));
        for(int i=0; i<(int)n; i++)
        {
            char tot[50];
            sprintf(tot,"Max sur dim%d : %.16f |",i,wind-> statist.max_d[i]);
            ui->listWidget_2->addItem(QString::fromStdString(tot));
        }
    }
    if(wind->statist.statistiques_demandees[2])
    {
        char tot[50];
        sprintf(tot,"Norme moy : %.16f ", wind->statist.moy_n);
        for(int i=0; i<(int)n; i++)
        {
            char tot[50];
            sprintf(tot,"Moyenne sur dim%d : %.16f |",i, wind->statist.moy_d[i]);
            ui->listWidget_2->addItem(QString::fromStdString(tot));
        }
    }
    if(wind->statist.statistiques_demandees[3])
    {
        char tot[50];
        sprintf(tot,"Variance Norme : %lf ", wind->statist.var_n);
        for(int i=0; i<(int)n; i++)
        {
            char tot[50];
            sprintf(tot,"Variance sur dim%d : %.16f |",i, wind->statist.var_d[i]);
            ui->listWidget_2->addItem(QString::fromStdString(tot));
        }
    }
    if(wind->statist.statistiques_demandees[4])
    {
        char tot[50];
        sprintf(tot,"Ecart-type Norme : %.16f ",wind->statist.ect_n);
        for(int i=0; i<(int)n; i++)
        {
            char tot[50];
            sprintf(tot,"Ecart-type sur dim%d : %.16f |",i, wind->statist.ect_d[i]);
            ui->listWidget_2->addItem(QString::fromStdString(tot));
        }
    }
    if(wind->statist.statistiques_demandees[5])
    {
        for(int i=0; i<(int)n; i++)
        {
            char tot[50];
            sprintf(tot,"Auto-correlation sur dim%d : %.16f |",i, wind->statist.atc_d[i]);
            ui->listWidget_2->addItem(QString::fromStdString(tot));
        }
    }

    element * actuel = wind->list->premier;
    int j = 0;
    while (actuel != NULL)
    {
        char toto[50];
        char v[50];
        strcpy(toto,"");
        strcpy(v,"");
        sprintf(toto,"U%d (",j);
        for(int i=0; (size_t)i<actuel->vecteur.taille; ++i)
        {
            sprintf(v+strlen(v),"%f  ", actuel->vecteur.tableau[i]);
        }
        strcat(toto,v);
        strcat(toto,")");
        ui->listWidget->addItem(QString::fromStdString(toto));
        strcpy(toto,"");
        strcpy(v,"");
        j++;
        actuel = actuel->suivant;
    }


}



display_4D::~display_4D()
{
    delete ui;
}
