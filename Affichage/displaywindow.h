#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H
#include "executewindow.h"
#include <QDialog>
#include "statistiques.h"

namespace Ui {
class displaywindow;
}

class displaywindow : public QDialog
{
    Q_OBJECT

public:
    explicit displaywindow(executewindow *toto, QWidget *parent = nullptr);
    ~displaywindow();
    int nbr_dim_vecteur;
    statistiques statist;
    Liste_vecteur * list;

private:
    Ui::displaywindow *ui;
};

#endif // DISPLAYWINDOW_H
