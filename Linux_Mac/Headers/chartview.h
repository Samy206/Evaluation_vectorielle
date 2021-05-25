

#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QtGui/QMouseEvent>
#include <QtCharts/QChartView>
#include <QtWidgets/QRubberBand>
#include <QtCharts/QLineSeries>
#include <QtWidgets/QApplication>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>

QT_CHARTS_USE_NAMESPACE



class ChartView : public QChartView

{
public:
    ChartView(QChart *chart, int mode, QWidget *parent = 0);
    QPointF lastpoint;  //permet de stocker le dernier point du curseur
    bool pressed;   //permet de stocker si la souris est cliquée ou non
    void chartreset();  //methode qui permet de reset le chart
    bool first_time;    //methode qui permet de savoir si le chart a deja été reset ou non
    QGraphicsSimpleTextItem *m_coordX;  //Item qui permet l'affichage en temps réel de X
    QGraphicsSimpleTextItem *m_coordY;  //Item qui permet l'affichage en temps réel de Y
    int mode;   //permet de stocker le mode (mousemode ou Rubbermode)


protected:
    void mousePressEvent(QMouseEvent *event); //permet de savoir quand la souris est cliquée
    void mouseMoveEvent(QMouseEvent *event);  //permet de se deplacer avec la souris en mousemode
    void mouseReleaseEvent(QMouseEvent *event); //permet de savoir quand la souris est relachée
    void keyPressEvent(QKeyEvent *event);   //permet de se deplacer avec les touches du clavier
    void wheelEvent(QWheelEvent *event);    //permet de zoomer avec la molette


};

#endif
