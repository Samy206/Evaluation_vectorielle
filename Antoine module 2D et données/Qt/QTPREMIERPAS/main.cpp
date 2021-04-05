#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QTableWidget>
#include <math.h>

QT_CHARTS_USE_NAMESPACE

QString linex,liney;

//Renseigner si dessous la ligne x et y de la fonction:


Vecteur fonction(Vecteur vecteur)
{
    std::vector<double> coordonnees = vecteur.get_coordonnees();
    //Ici on sait qu'il n'y a que 2 coos car nous sommes dans le module 2D

    //on recup x et y :
    double x = coordonnees.front();
    double y = coordonnees.back();

    //on modifie x et y selon la fonction :

    x = x * 2;     //ligne x
    y = sin(y);      //ligne y;
    linex = "x * 2";
    liney = "sin(y)";

    //Création d'une nouvelle liste pour initialiser le nouveau vecteur :
    std::vector<double> retour;
    retour.push_back(x);
    retour.push_back(y);

    return Vecteur(retour,2);
}



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    //renseigner ici les coos de x , y et le nombre de vecteurs a calculer.
    double x = 5.5;
    double y = 7.7;
    int nombre_de_vecteurs = 10;

    //Creation du vector pour init le vecteur
    std::vector<double> coordonnees;
    coordonnees.push_back(x);
    coordonnees.push_back(y);

    //Initialisation du vecteur avec dim:2 car nous sommes dans le module 2D
    Vecteur vecteur = Vecteur(coordonnees,2);

    //Creation du vector pour init la liste
    std::vector<Vecteur> liste;
    liste.push_back(vecteur);

    //Initialisation de la liste a nombre_de_vecteurs + 1 car v0 + nombre_de_vecteur (qui est le nb de v a calculer)
    Liste liste_vecteurs = Liste(liste,nombre_de_vecteurs+1);

    //Création des autres vecteurs a partir de v0 et ajout dans la LISTE
    for(int i = 0; i < nombre_de_vecteurs ; i++ )
    {
         if(!i) std::cout << 'v' << i << ": " << vecteur.get_coordonnees().front() << ", " << vecteur.get_coordonnees().back() << std::endl ;
         liste_vecteurs.add_vecteur( fonction(vecteur) );
         vecteur = fonction(vecteur);
         std::cout << 'v' << i+1 << ": " << vecteur.get_coordonnees().front() << ", " << vecteur.get_coordonnees().back() << std::endl ;
    }

    //Initialisation de la fenetre principale pour le graph 2D
    MainWindow w;
    w.setWindowTitle("Exemple de graphe 2D projet évaluation vectorielle cpp");
    w.resize(1344,756);

    //Initialisation du widget pour le tableau
    QFont font;
    font.setPixelSize(25);
    QTableWidget *m_tableau = new QTableWidget(nombre_de_vecteurs+1,2);
    m_tableau->setFont(font);
    m_tableau->setColumnWidth(0,200);
    m_tableau->setColumnWidth(1,200);
    m_tableau->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_tableau->setWindowTitle("Exemple de tableau de données projet évaluation vectorielle cpp");
    m_tableau->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_tableau->setSelectionMode(QAbstractItemView::SingleSelection);

    m_tableau->resize(465,625);

    //Headers premiere et deuxieme colonne x & y
    m_tableau->setHorizontalHeaderItem(0,new QTableWidgetItem("x"));
    m_tableau->setHorizontalHeaderItem(1,new QTableWidgetItem("y"));

    //Headers lignes
    QString vecteur_string;

    for( int i = 0 ; i < nombre_de_vecteurs+1 ; i++)
    {
        vecteur_string = "v" + QString::number(i);
        m_tableau->setVerticalHeaderItem(i,new QTableWidgetItem(vecteur_string));
    }

    //Initialisation de la serie de point.
    QLineSeries *series = new QLineSeries();


    //Boucle qui ajoute tout les points a la serie de point et rempli le tableau a partir de la liste
    QString content_string;

    for(int i = 0; i < liste_vecteurs.get_nombre_de_vecteurs() ; i++)
    {
        series->append(liste_vecteurs.get_liste().at(i).get_coordonnees().front(),liste_vecteurs.get_liste().at(i).get_coordonnees().back());

        content_string = QString::number(liste_vecteurs.get_liste().at(i).get_coordonnees().front());
        m_tableau->setItem(i, 0, new QTableWidgetItem(content_string));
        content_string = QString::number(liste_vecteurs.get_liste().at(i).get_coordonnees().back());
        m_tableau->setItem(i, 1, new QTableWidgetItem(content_string));
    }

    //Initialisation du graph des axes
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();

    // Changement du font et du titre
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::black));
    QString title = "Evolution du vecteur v0( " + QString::number(x) + " , " + QString::number(y) + " ) avec f(x,y) {x: " + linex + " } {y: " + liney + " }";
    chart->setTitle(title);

    // Changement du graph et ajout des points
    QPen pen(QRgb(0x000000));
    pen.setWidth(2);
    series->setPen(pen);
    if(nombre_de_vecteurs < 100) series->setPointsVisible();

    chart->setAnimationOptions(QChart::AllAnimations); // affiche point par point (animation daffichage)

    // Affichage
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    w.setCentralWidget(chartView);
    w.show();
    m_tableau->show();

    return a.exec();

}
