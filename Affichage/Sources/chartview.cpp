#include "../Headers/chartview.h"
#include "../Headers/displaywindow.h"

using namespace QtCharts;

ChartView::ChartView(QChart *chart,int mode, QWidget *parent) :
        QChartView(chart, parent),
        pressed(false) , first_time(true)
{
    //On initialise m_coordX et m_coordY, ces variables vont nous permettre d'afficher la position de notre curseur
    m_coordX = new QGraphicsSimpleTextItem(chart);
    m_coordX->setPos(300, 30);
    m_coordX->setText("X: ");
    m_coordY = new QGraphicsSimpleTextItem(chart);
    m_coordY->setPos(450, 30);
    m_coordY->setText("Y: ");

    //Si le mode en argument = 0, on active le RubberBand et on stock le mode dans l'objet
    if(!mode) {setRubberBand(QChartView::RectangleRubberBand); this->mode = mode; }

        //sinon on stock juste le mode dans l'objet
    else this->mode = mode;

    //On active le suivi de la souris
    setMouseTracking(true);
}


///************************************************************************************************
/// chartreset permet de redimensionné le graphique a sa position de depart.

void ChartView::chartreset()
{

    //On reset le zoom donc on revient a la taille initiale du chart
    chart()->zoomReset();

    //on recupere la taille initiale du chart /0.5
    QRectF origin = QRectF(chart()->plotArea().left(),chart()->plotArea().top(),chart()->plotArea().width()/0.5,chart()->plotArea().height()/0.5);

    //on recupere le centre
    QPointF center = chart()->plotArea().center();

    //on se positionne au centre
    origin.moveCenter(center);

    //On remet la taille initiale du chart
    chart()->zoomIn(origin);

    //On indique que l'on a deja reset le chart. Ceci est necessaire car la premiere etape est de reset le chart
    //pour eviter de modifier la taille initiale du chart. Car si on se deplace sans zoomer cela va decaler la position initiale du chart.
    //Ici on dezoom une premiere fois avant toute methode ce qui nous permet une fois fini de faire zoomreset et de revenir a la posisition initiale.
    if(first_time) first_time = false;

}

///************************************************************************************************
/// mousePressEvent permet de savoir quand la souris est cliqué

void ChartView::mousePressEvent(QMouseEvent *event)
{
    //Si le graphique n'a jamais été reset on le reset
    if(first_time) chartreset();


    //On change la variable pressed de l'objet qui nous permet de savoir quand la souris est cliqué
    pressed = true;

    //Last point est egal au point ou nous avons cliqué sur la souris
    lastpoint = mapFromGlobal(QCursor::pos());

    QChartView::mousePressEvent(event);
}



///************************************************************************************************
/// mousemoveevent permet de se deplacer dans le graph grace a la souris

void ChartView::mouseMoveEvent(QMouseEvent *event)
{
    //Si le graphique n'a jamais été reset on le reset
    if(first_time) chartreset();

    //on affiche les coordonnées du curseur dans les items m_coordX et m_coordY
    m_coordX->setText(QString("X: %1").arg(chart()->mapToValue(event->pos()).x()));
    m_coordY->setText(QString("Y: %1").arg(chart()->mapToValue(event->pos()).y()));

    //Si la souris est cliqué et que le mode est mousemode
    if((pressed) && (mode))
    {
        //On créé un nouveau point qui est egal a la position du curseur
        QPointF newpoint = mapFromGlobal(QCursor::pos());

        //On créé deux variables qui sont la difference entre le x et le y du last_point et du newpoint
        qreal x = newpoint.x() - lastpoint.x();
        qreal y = newpoint.y() - lastpoint.y();

        //On se deplace dans le graph en fonction des variables calculé auparavant
        chart()->scroll(-1 * x, 0);
        chart()->scroll(0, y );

        //le dernier point est egal au nouveau
        lastpoint = newpoint;

    }

    chart()->update();

    QChartView::mouseMoveEvent(event);
}



///************************************************************************************************
/// mouseReleaseEvent permet de savoir quand la souris est relaché

void ChartView::mouseReleaseEvent(QMouseEvent *event)
{
    //Si le graphique n'a jamais été reset on le reset
    if(first_time) chartreset();


    //On change la variable pressed de l'objet qui nous permet de savoir quand la souris est relaché
    pressed = false;

    QChartView::mouseReleaseEvent(event);
}



///************************************************************************************************
/// keypressevent permet de se deplacer avec le clavier

void ChartView::keyPressEvent(QKeyEvent *event)
{
    //Si le graphique n'a jamais été reset on le reset
    if(first_time) chartreset();

    //Nous n'affichons rien car nous ne sommes pas capable de donner la valeur de la nouvelle position du curseur apres changement
    m_coordX->setText(QString("X: "));
    m_coordY->setText(QString("Y: "));

    switch (event->key()) {
        case Qt::Key_Plus:
            chart()->zoomIn(); //Si touche + on zoom
            break;
        case Qt::Key_Minus:
            chart()->zoomOut(); //si touche - on dezoom
            break;
        case Qt::Key_Left:
            chart()->scroll(-10, 0); //si touche <- on va a gauche
            break;
        case Qt::Key_Right:
            chart()->scroll(10, 0); //si touche -> on va a droite
            break;
        case Qt::Key_Up:
            chart()->scroll(0, 10); //si touche ^ on va en haut
            break;
        case Qt::Key_Down:
            chart()->scroll(0, -10); // si touche v on va en bas
            break;
        case Qt::Key_Space: //si touche espace on reset le chart
            chartreset();
            break;
        default:
            QGraphicsView::keyPressEvent(event);
            break;
    }
    chart()->update();
}


///************************************************************************************************
/// wheelEvent permet de zoomer/dezoomer avec la molette

void ChartView::wheelEvent(QWheelEvent *event)
{
    //Si le graphique n'a jamais été reset on le reset
    if(first_time) chartreset();


    //on initialise factor qui va nous permettre de zoomer ou dezoomer dans le graph
    qreal factor;

    if ( event->delta() > 0 ) factor = 1.5; //si la molette va en avant factor = 1.5 qui permet de zoomer de 50%
    else factor = 0.75; //sinon factor = 0.75 qui permet de dezoomer de 50%

    //on zoom ou dezoom en multipliant la position du chart par factor
    QRectF rectangle = QRectF(chart()->plotArea().left(),chart()->plotArea().top(),chart()->plotArea().width()/factor,chart()->plotArea().height()/factor);

    //on recupere la position du curseur
    QPointF mousePos = mapFromGlobal(QCursor::pos());

    //on centre le rectangle sur le curseur et on zoom dedans
    rectangle.moveCenter(mousePos);
    chart()->zoomIn(rectangle);

    chart()->update();

    //On se recentre ensuite sur le curseur
    QPointF delta = chart()->plotArea().center() -mousePos;
    chart()->scroll(delta.x(),-delta.y());

    chart()->update();
}

