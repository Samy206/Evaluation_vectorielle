#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QChart>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    //virtual void  paintEvent(QPaintEvent *event); //Pour QPAINTER

private:
    Ui::MainWindow *ui;


};

/********************************************************************************************
 *                                                                                          *
 *    CLASS VECTEUR:                                            (voir ligne 62)             *
 *                                                                                          *
 *                                                                                          *
 *         - std::vector<double> coordonnees  :                                             *
 *                                                                                          *
 *                Liste de coordonnees de type double du vecteur.                           *
 *                                                                                          *
 *                                                                                          *
 *         - int dimensions  :                                                              *
 *                                                                                          *
 *                Nombre de dimensions du vecteur de type int.                              *
 *                                                                                          *
 *                                                                                          *
 *         - Vecteur(std::vector<double> coordonnees, int dimensions) :                     *
 *                                                                                          *
 *                Constructeur qui prend en argument une liste de coordonnees de type       *
 *                 double et le nombre de coordonnées de cette liste de type int.           *
 *                                                                                          *
 *                                                                                          *
 *         - vector<Vecteur> Vecteur::get_coordonnees() :                                   *
 *                                                                                          *
 *                Getter qui renvoie la liste de coordonnées de type std::vector<double>.   *
 *                                                                                          *
 *                                                                                          *
 *         - int Liste::get_dimensions()                                                    *
 *                                                                                          *
 *                Getter qui renvoie le nombre de dimensions de type int.                   *
 *                                                                                          *
 ********************************************************************************************/


class Vecteur {

private:

    std::vector<double> coordonnees;
    int dimensions;

public:

    Vecteur(std::vector<double> coordonnees, int dimensions);
    int get_dimensions();
    std::vector<double> get_coordonnees();

};



/********************************************************************************************
 *                                                                                          *
 *    CLASS LISTE:                                              (voir ligne 117)            *
 *                                                                                          *
 *                                                                                          *
 *         - std::vector<Vecteur> liste  :                                                  *
 *                                                                                          *
 *                Liste de vecteur(s) de type vecteur.                                      *
 *                                                                                          *
 *                                                                                          *
 *         - int nombre_de_vecteurs  :                                                      *
 *                                                                                          *
 *                Nombre de vecteurs de la liste de type int.                               *
 *                                                                                          *
 *                                                                                          *
 *         - Liste(std::vector<Vecteur> liste, int nombre_de_vecteurs) :                    *
 *                                                                                          *
 *                Constructeur qui prend en argument une liste de vecteur de class          *
 *                 Vecteur et le nombre de vecteurs de cette liste de type int.             *
 *                                                                                          *
 *                                                                                          *
 *         - vector<Vecteur> Liste::get_liste() :                                           *
 *                                                                                          *
 *                Getter qui renvoie la liste de coordonnées de type std::vector<Vecteur>.  *
 *                                                                                          *
 *                                                                                          *
 *         - int Liste::get_nombre_de_vecteurs() :                                          *
 *                                                                                          *
 *                Getter qui renvoie le nombre_de_vecteur de type int.                      *
 *                                                                                          *
 *                                                                                          *
 *         - void Liste::add_vecteur(Vecteur vecteur) :                                     *
 *                                                                                          *
 *                Méthode qui ajoute le vecteur pris en argument dans liste (cf.l.82)       *
 *                                                                                          *
 ********************************************************************************************/


class Liste {

private:

    std::vector<Vecteur> liste;
    int nombre_de_vecteurs;

public:

   Liste(std::vector<Vecteur> liste, int nombre_de_vecteurs);
   std::vector<Vecteur> get_liste();
   int get_nombre_de_vecteurs();
   void add_vecteur(Vecteur vecteur);

};

#endif // MAINWINDOW_H
