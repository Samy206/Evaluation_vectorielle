#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H
#include "executewindow.h"
#include <QDialog>
#include "statistiques.h"
#include "chartview.h"

namespace Ui {
    class displaywindow;
}

class displaywindow : public QDialog
{
    Q_OBJECT

public:
    explicit displaywindow(executewindow *toto, QWidget *parent = nullptr);
    ~displaywindow();

    Liste_vecteur * list; //permet de stocker la liste de vecteurs
    QString x,y;    //permet de stocker l'origine
    QLineSeries* last_serie; //permet de stocker la derniere serie ajouter au chart
    ChartView* last_chartview; //permet de stocker le dernier chartview utilisé
    QChart* main_chart; //permet de stocker le chart principal utilisé au long du programme
    int scientific_notation;    //permet de stocker le choix de notation des chiffres des axes
    int mode;   //permet de stocker le choix du mode
    int modif;  //permet de stocker si main_chart a deja été modifié ou non


public slots:
            void AddSelectVector(); //permet d'afficher le vecteur selectionné dans la liste de vecteurs
    void Scientific_notation(int a);    //permet de changer la notation des chiffres des axes
    void Rubbermode();  //permet de changer de mode
    void Mousemode();   //permet de changer de mode

private:
    Ui::displaywindow *ui;
};

#endif // DISPLAYWINDOW_H
