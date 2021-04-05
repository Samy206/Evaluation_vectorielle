#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/****************************************************************************************************************
 *                                                                                                              *
 *    CLASS VECTEUR :                                                                                           *
 *                                                                                                              *
 *         - Vecteur(std::vector<double> coordonnees, int dimensions) :                      (voir ligne 38)    *
 *                                                                                                              *
 *                Constructeur qui prend en argument une liste de coordonnees de type                           *
 *                 double et le nombre de coordonnées de cette liste de type int.                               *
 *                                                                                                              *
 *                                                                                                              *
 *         - vector<Vecteur> Vecteur::get_coordonnees() :                                    (voir ligne 45)    *
 *                                                                                                              *
 *                Getter qui renvoie la liste de coordonnées de type std::vector<double>.                       *
 *                                                                                                              *
 *                                                                                                              *
 *         - int Liste::get_dimensions() :                                                   (voir ligne 51)    *
 *                                                                                                              *
 *                Getter qui renvoie le nombre de dimensions de type int                                        *
 *                                                                                                              *
 ***************************************************************************************************************/


Vecteur::Vecteur(std::vector<double> coordonnees, int dimensions) //Déclaration du constructeur de la classe Vecteur//
{
    this->coordonnees = coordonnees;
    this->dimensions = dimensions;
}


std::vector<double> Vecteur::get_coordonnees() //Déclaration du getter get_coordonnees//
{
    return coordonnees;
}


int Vecteur::get_dimensions() //Déclaration du getter get_dimensions//
{
    return dimensions;
}



/****************************************************************************************************************
 *                                                                                                              *
 *    CLASS LISTE :                                                                                             *
 *                                                                                                              *
 *         - Liste(std::vector<Vecteur> liste, int nombre_de_vecteurs) :                     (voir ligne 85)    *
 *                                                                                                              *
 *                Constructeur qui prend en argument une liste de vecteur de class                              *
 *                 Vecteur et le nombre de vecteurs de cette liste de type int.                                 *
 *                                                                                                              *
 *                                                                                                              *
 *         - vector<Vecteur> Liste::get_liste() :                                            (voir ligne 92)    *
 *                                                                                                              *
 *                Getter qui renvoie la liste de coordonnées de type std::vector<Vecteur>.                      *
 *                                                                                                              *
 *                                                                                                              *
 *         - int Liste::get_nombre_de_vecteurs() :                                                              *
 *                                                                                           (voir ligne 98)    *
 *                Getter qui renvoie le nombre_de_vecteur de type int.                                          *
 *                                                                                                              *
 *                                                                                                              *
 *         - void Liste::add_vecteur(Vecteur vecteur) :                                      (voir ligne 104)   *
 *                                                                                                              *
 *                Méthode qui ajoute un vecteur a la liste de la class Liste.                                   *
 *                                                                                                              *
 ***************************************************************************************************************/


Liste::Liste(std::vector<Vecteur> liste, int nombre_de_vecteurs) //Déclaration du constructeur de la class Liste//
{
    this->liste = liste;
    this-> nombre_de_vecteurs = nombre_de_vecteurs;
}


std::vector<Vecteur> Liste::get_liste() //Déclaration du getter get_liste//
{
    return liste;
}


int Liste::get_nombre_de_vecteurs() //Déclaration du getter get_nombre_de_vecteurs//
{
    return nombre_de_vecteurs;
}


void Liste::add_vecteur(Vecteur vecteur)
{
    this->liste.push_back(vecteur);
}


//Test de QPAINTER pour le graph 2D (useless mais on en garde une trace)//
//Si vous voulez regarder ce que cela donne: enlever le commentaire dans mainwindow.h de la methode paintevent l.19//
//enlever le commentaire egalement l.113 (ici) et mettre en commentaire w.setcentralwindow puis tt ce qui ne touche pas a w (dans main.cpp) //
/*void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QPen pointpen(Qt::red);
    pointpen.setWidth(6);

    QPen linepen(Qt::black);
    linepen.setWidth(2);

    //Supposons que la taille de notre graph doit etre x:1400  y:1000

    int AxeX = 1400;
    int AxeY = 1000;

    int maxX = 251;
    int maxY = 1457;

    double coefx = AxeX / maxX;
    double coefy = AxeY / maxY;

    QPoint Axes[4]; //2 pour laxe x // 2 pour laxe y

    painter.setPen(linepen);

    Axes[0].setX(100);   Axes[1].setX(100);  //AXE Y
    Axes[0].setY(100);   Axes[1].setY(1100); painter.drawLine(Axes[0],Axes[1]);

    Axes[2].setX(100);   Axes[3].setX(1500);  //AXE X
    Axes[2].setY(1100);   Axes[3].setY(1100); painter.drawLine(Axes[2],Axes[3]);

    for( int i = 1; i < 10; i++)  //Les calculs avec des doubles <1 deconne...
    {
        painter.drawLine( (100+((maxX/10)*i)*5.57768924) , 1095 , (100+((maxX/10)*i)*5.57768924) , 1105 ); //X
        painter.drawLine( 95 , (1100-((maxY/10)*i)*0.6863418) , 105 , (1100-((maxY/10)*i)*0.6863418) ); //Y
    }

    painter.drawLine(1490,1090,1500,1100);
    painter.drawLine(1490,1110,1500,1100);

    painter.drawLine(90,110,100,100);
    painter.drawLine(110,110,100,100);

    QPoint POINTS[6];

    POINTS[0].setX(100 + (3*coefx) );
    POINTS[0].setY(1100 - (5*0.6863418));

    POINTS[1].setX(100 + (11*coefx) );
    POINTS[1].setY(1100 - (17*0.6863418)); //

    POINTS[2].setX(100 + (27*coefx) );
    POINTS[2].setY(1100 - (53*0.6863418)); //

    POINTS[3].setX(100 + (59*coefx) );
    POINTS[3].setY(1100 - (161*0.6863418)); //

    POINTS[4].setX(100 + (123*coefx) );
    POINTS[4].setY(1100 - (485*0.6863418)); //

    POINTS[5].setX(100 + (251*coefx) );
    POINTS[5].setY(1100 - (1457*0.6863418)); //

    //printf("%f %f",(50 + (3*coefx) ),(1050 - (1457*coefy) ));



    painter.setPen(linepen);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.drawLine(Axes[2],POINTS[0]);
    painter.drawLine(POINTS[0],POINTS[1]);
    painter.drawLine(POINTS[1],POINTS[2]);
    painter.drawLine(POINTS[2],POINTS[3]);
    painter.drawLine(POINTS[3],POINTS[4]);
    painter.drawLine(POINTS[4],POINTS[5]);

    painter.setPen(pointpen);
    for(int i = 0 ; i < 6 ; i ++) painter.drawPoint(POINTS[i]);

} */

