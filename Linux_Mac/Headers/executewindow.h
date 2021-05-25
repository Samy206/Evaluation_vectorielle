#ifndef EXECUTEWINDOW_H
#define EXECUTEWINDOW_H

#include <QDialog>
#include "iostream"
#include "../Headers/mainwindow.h"
#include "../Headers/statistiques.h"
#include "../Headers/liste_vecteurs.h"
using namespace std;


namespace Ui {
class executewindow;
}

class executewindow : public QDialog
{
    Q_OBJECT

public:
    explicit executewindow(MainWindow *dad, QWidget *parent = nullptr);
    ~executewindow();
    int state; //To know if the window end with the validate button(1) or cancel button(0)
    int statistic[6]; //statistic wanted
    string departur;
    string funct;
    string vect_init;
    int nbr_vect;
    statistiques statist;
    Liste_vecteur * list;
    int nbr_dim_vecteur;



public slots:
    void Validate(); //Button for validation
    void Cancel();  // Button for cancel

private:
    Ui::executewindow *ui;
};

#endif // EXECUTEWINDOW_H
