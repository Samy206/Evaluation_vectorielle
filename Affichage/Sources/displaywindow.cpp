#include "../Headers/displaywindow.h"
#include "ui_displaywindow.h"
#include "../Headers/display_4d.h"
#include "../Headers/chartview.h"
extern "C" {
#include "../Headers/liste_vecteurs.h"
#include "../Headers/statistiques.h"
}

displaywindow::displaywindow(executewindow *toto, QWidget *parent) :
        QDialog(parent),
        ui(new Ui::displaywindow)
{

    ///*************************************************************
    ///Initialisation
    //Initilisation de la displaywindow
    ui->setupUi(this);

    //Display_stat_2 qui permet d'afficher la fonction est remplis par la fonction
    ui->Display_stat_2->setText(QString::fromStdString(toto->funct));

    //On connecte dans l'ordre :
    //Le tableau de vecteur a la fonction addselectvector qui permet d'afficher en rouge le vecteur choisi.
    //La checkbox scientific notation a la fonction scientific notation qui permet de changer l'ecriture des nombres des axes.
    //Le bouton_2 rubberband mode a la fonction Rubbermode() qui permet de changer de mode de selection.
    //Le bouton mouse mode a la fonction Mousemode() qui permet de se deplacer avec la souris.
    connect(ui->tableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(AddSelectVector()));
    connect(ui->checkBox, SIGNAL(stateChanged(int)), this, SLOT(Scientific_notation(int)));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(Rubbermode()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Mousemode()));

    //Modif = 0 car nous n'avons pas encore ajouté de deuxieme serie au graphique.
    //Modif sert a savoir si il faut supprimer ou pas la derniere QLineSerie afficher sur le chart.
    modif = 0;

    //Mode = 1 car nous initialisons le mode de deplacement en mousemode qui est pour nous le plus intuitif.
    //+ affichage du mode utilisé dans Display_stat_3 qui permet de savoir sous quel mode nous sommes.
    mode = 1;
    ui->Display_stat_3->setText("Using Mouse mode");


    ///**************************************************************
    ///Recupération de l'origine

    //On initialise manipulation qui va nous permettre le troncage de departure
    QString manipulation = QString::fromStdString(toto->departur);

    //On initialise v_pos qui est un compteur pour trouver la position de la virgule
    int v_pos = 0;

    //On enleve les parenthèses
    manipulation.remove("(");
    manipulation.remove(")");

    //Tant que le caractère à la position v_pos n'est pas une virgule, v_pos++ (ce qui nous permet d'avoir la position du dernier car avant la virgule)
    while( manipulation.at(v_pos) != ',' ) v_pos++;

    //x est égal a departure coupé avant la virgule. x est une variable de l'objet pour pouvoir retrouver x de l'origine dans n'importe quelle méthode de la classe.
    x = manipulation;
    x.truncate(v_pos);

    //y est égal a departure coupé apres la virgule. y est une variable de l'objet pour les memes raison que x.
    y = manipulation.right(manipulation.size() - v_pos-1);

    ///***************************************************************
    ///Création du graphique 1|2D

    //Initialisation du QLineSeries qui sera la serie du point du graphique
    QLineSeries *series = new QLineSeries();

    //Initialisation de buffer qui est une variable qui nous permet de naviguer dans la liste
    element* buffer;

    //La list de l'objet est egal a la liste de l'objet pere. this.list permet d'avoir acces a cette liste dans n'importe quelle methode de la classe.
    list = toto->list;

    //Pour chaque vecteur de la liste nous l'ajoutons a la QLineSerie. Si les vecteurs sont a une dimension y fixe.
    for(int i = 0 ; i < list->taille ; i++)
    {
        if(!i) buffer = list->premier;
        else buffer = buffer->suivant;
        if(toto->nbr_dim_vecteur == 1) { if(!i) series->append(x.toDouble(),y.toDouble()); series->append(buffer->vecteur.tableau[0] + x.toDouble() , y.toDouble());}
        if(toto->nbr_dim_vecteur == 2) { if(!i) series->append(x.toDouble(),y.toDouble()); series->append(buffer->vecteur.tableau[0] + x.toDouble() ,buffer->vecteur.tableau[1] + y.toDouble()); }
    }

    //On rend visible les points de la Qlineseries
    series->setPointsVisible();

    //On créé un nouveau chart qui sera le graphique.
    QChart *chart = new QChart();

    //On ajoute la QLineSeries precedement complété au chart.
    chart->addSeries(series);

    //Main_chart de l'objet est egal au chart. Ceci va nous permettre de pouvoir acceder a ce chart dans n'importe quelle methode de la classe.
    main_chart = chart;

    //On ajoute un titre vide, une animation et on cache la legende du chart.
    chart->setTitle(" ");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->legend()->hide();

    //On créé les axes par defaut du chart.
    chart->createDefaultAxes();

    //On initialise un ChartView qui est notre methode d'affichage du chart.
    ChartView *chartView = new ChartView(chart,mode);

    //On ajoute de l'anti alisasing a la trajectoire.
    chartView->setRenderHint(QPainter::Antialiasing);

    //Last chartview est egal au chart view actuel. Cette variable de l'objet permet de supprimer le dernier chartview du widget et d'en rajouter un nouveau.
    last_chartview = chartView;

    //On affiche le graphique
    ui->verticalLayout->addWidget(chartView);

    ///*******************************************************************************
    ///Tableau de vecteurs

    //Initialisation d'un font (police) a 18 pour remplir les tableaux de données
    QFont font;
    font.setPixelSize(18);

    //Initialisation du string tampon que l'on va remplir puis affecter a chaque cases des tableaux
    QString tampon;

    //On met la barre de scroll verticale toujours active
    ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    //On initialise les lignes du tableau
    ui->tableWidget->setRowCount(list->taille);

    //Les colonnes en fonction de la dimension des vecteurs
    if(toto->nbr_dim_vecteur == 1) ui->tableWidget->setColumnCount(1);
    else ui->tableWidget->setColumnCount(2);

    //On set le font que l'on a initialisé precedement
    ui->tableWidget->setFont(font);

    //On change la largeur des colonnes
    if(toto->nbr_dim_vecteur == 1) ui->tableWidget->setColumnWidth(0,200);
    else{ui->tableWidget->setColumnWidth(0,100); ui->tableWidget->setColumnWidth(1,100);}

    //Dans l'ordre, on enleve la possibiliter de modifier, on permet de selectionner que les lignes, et on autorise qu'une seule selection a la fois.
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    //Headers premiere et deuxieme colonne x & y
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("x"));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("y"));

    //On rempli les headers des lignes
    for( int i = 0 ; i < list->taille ; i++)
    {
        tampon = "v" + QString::number(i);
        ui->tableWidget->setVerticalHeaderItem(i,new QTableWidgetItem(tampon));
    }

    //On rempli le tableau de vecteurs
    for( int i = 0 ; i < list->taille ; i++)
    {
        //changement de buffer
        if(!i) buffer = list->premier;
        else buffer = buffer->suivant;

        //Case x
        tampon = QString::number(buffer->vecteur.tableau[0],'g',4);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(tampon));

        //Case y si dim == 2
        if(toto->nbr_dim_vecteur == 2)
        {
            tampon = QString::number(buffer->vecteur.tableau[1],'g',4);
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(tampon));
        }
    }

    ///*******************************************************************************
    ///Tableau de statistiques

    //On set le font precedement initialisé
    ui->tableWidget_2->setFont(font);

    //Dans l'ordre : on met la scroll bar horizontale toujours active, on ne permet pas de modifier les cases
    ui->tableWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //Variable qui va nous permettre de savoir le nombre de choix pour initialiser le tableau et nous permettre de le remplir.
    int pos = 0;

    //Recuperation du nombre de choix
    for(int i = 0 ; i < 6; i ++) if(toto->statistic[i]) pos++;

    //Initialisation de tableau si il y a au moins un choix
    if(pos)
    {
        ui->tableWidget_2->setRowCount(pos);
        ui->tableWidget_2->setColumnCount(toto->nbr_dim_vecteur+1);
    }

    //Remplissage des headers des colonnes
    ui->tableWidget_2->setHorizontalHeaderItem(0,new QTableWidgetItem("norme"));
    ui->tableWidget_2->setHorizontalHeaderItem(1,new QTableWidgetItem("x"));
    if(toto->nbr_dim_vecteur == 2) ui->tableWidget_2->setHorizontalHeaderItem(2,new QTableWidgetItem("y"));

    //Reset de pos
    pos = 0;

    //Remplissage des headers des lignes en fonction du tableau de choix
    if(toto->statistic[0]) ui->tableWidget_2->setVerticalHeaderItem(pos++,new QTableWidgetItem("min"));
    if(toto->statistic[1]) ui->tableWidget_2->setVerticalHeaderItem(pos++,new QTableWidgetItem("max"));
    if(toto->statistic[2]) ui->tableWidget_2->setVerticalHeaderItem(pos++,new QTableWidgetItem("moy"));
    if(toto->statistic[3]) ui->tableWidget_2->setVerticalHeaderItem(pos++,new QTableWidgetItem("var"));
    if(toto->statistic[4]) ui->tableWidget_2->setVerticalHeaderItem(pos++,new QTableWidgetItem("ect"));
    if(toto->statistic[5]) ui->tableWidget_2->setVerticalHeaderItem(pos++,new QTableWidgetItem("atc"));

    //reset de pos
    pos = 0;

    //Si l'utilisateur veut afficher le minimum
    if(toto->statistic[0])
    {
        //On affiche la norme
        tampon = QString::number(toto->statist.min_n,'g',4);
        ui->tableWidget_2->setItem(pos, 0, new QTableWidgetItem(tampon));

        //On affiche pour chaque dimension
        for(int i=1; i<toto->nbr_dim_vecteur+1; i++)
        {
            tampon = QString::number(toto->statist.min_d[i-1],'g',4);
            ui->tableWidget_2->setItem(pos, i, new QTableWidgetItem(tampon));
        }

        //on incrémente pos pour avoir la position de la prochaine ligne
        pos++;
    }

    //Si l'utilisateur veut afficher le maximum
    if(toto->statistic[1])
    {
        tampon = QString::number(toto->statist.max_n,'g',4);
        ui->tableWidget_2->setItem(pos, 0, new QTableWidgetItem(tampon));

        for(int i=1; i<toto->nbr_dim_vecteur+1; i++)
        {
            tampon = QString::number(toto->statist.max_d[i-1],'g',4);
            ui->tableWidget_2->setItem(pos, i, new QTableWidgetItem(tampon));
        }

        pos++;
    }

    //Si l'utilisateur veut afficher la moyenne
    if(toto->statistic[2])
    {
        tampon = QString::number(toto->statist.moy_n,'g',4);
        ui->tableWidget_2->setItem(pos, 0, new QTableWidgetItem(tampon));

        for(int i=1; i<toto->nbr_dim_vecteur+1; i++)
        {
            tampon = QString::number(toto->statist.moy_d[i-1],'g',4);
            ui->tableWidget_2->setItem(pos, i, new QTableWidgetItem(tampon));
        }

        pos++;
    }

    //Si l'utilisateur veut afficher la variance
    if(toto->statistic[3])
    {
        tampon = QString::number(toto->statist.var_n,'g',4);
        ui->tableWidget_2->setItem(pos, 0, new QTableWidgetItem(tampon));

        for(int i=1; i<toto->nbr_dim_vecteur+1; i++)
        {
            tampon = QString::number(toto->statist.var_d[i-1],'g',4);
            ui->tableWidget_2->setItem(pos, i, new QTableWidgetItem(tampon));
        }

        pos++;
    }

    //Si l'utilisateur veut afficher l'écart-type
    if(toto->statistic[4])
    {
        tampon = QString::number(toto->statist.ect_n,'g',4);
        ui->tableWidget_2->setItem(pos, 0, new QTableWidgetItem(tampon));

        for(int i=1; i<toto->nbr_dim_vecteur+1; i++)
        {
            tampon = QString::number(toto->statist.ect_d[i-1],'g',4);
            ui->tableWidget_2->setItem(pos, i, new QTableWidgetItem(tampon));
        }

        pos++;
    }

    //Si l'utilisateur veut afficher l'auto correlation
    if(toto->statistic[5])
    {
        tampon = "NULL"; //car il n'y a pas d'auto correlation avec la norme
        ui->tableWidget_2->setItem(pos, 0, new QTableWidgetItem(tampon));

        for(int i=1; i<toto->nbr_dim_vecteur+1; i++)
        {
            tampon = QString::number(toto->statist.atc_d[i-1],'g',4);
            ui->tableWidget_2->setItem(pos, i, new QTableWidgetItem(tampon));
        }

        pos++;
    }

    close();
}



///**************************************************************************************************
///AddSelectVector permet d'ajouter le vecteur selectionné dans le tableau des vecteurs au chart.

void displaywindow::AddSelectVector()
{
    //Initialisation de pos qui est égal a la ligne selectionné
    int pos = ui->tableWidget->currentRow();

    //Initialisation de n, une nouvelle serie.
    QLineSeries* n = new QLineSeries();

    //Si pos == 0 le vecteur a afficher sera celui de l'origne a v0
    if(pos == 0)
    {
        //ajout de l'origine
        n->append(x.toDouble(),y.toDouble());

        //Nous nous positionons a l'element v0
        element* buffer = list->premier;

        //ajout de v0
        if(buffer->vecteur.taille == 1) n->append(buffer->vecteur.tableau[0] + x.toDouble() ,y.toDouble());
        else n->append(buffer->vecteur.tableau[0] + x.toDouble() , buffer->vecteur.tableau[1] + y.toDouble());
    }

        //Sinon le vecteur a afficher sera celui de la ligne selectionné-1 a la ligne selectionné
    else
    {
        //On initialise buffer a v0
        element* buffer = list->premier;

        //On se place a v_ligne_selectionné-1
        for(int i = 0 ; i < pos-1 ; i++) buffer = buffer->suivant;

        //On l'ajoute
        if(buffer->vecteur.taille == 1) n->append(buffer->vecteur.tableau[0] + x.toDouble() ,y.toDouble());
        else n->append(buffer->vecteur.tableau[0] + x.toDouble() , buffer->vecteur.tableau[1] + y.toDouble());

        //on se place a v_ligne_selectionné
        buffer = buffer->suivant;

        //On l'ajoute
        if(buffer->vecteur.taille == 1) n->append(buffer->vecteur.tableau[0] + x.toDouble() ,y.toDouble());
        else n->append(buffer->vecteur.tableau[0] + x.toDouble() , buffer->vecteur.tableau[1] + y.toDouble());
    }

    //On initialise un pen rouge de largeur 2 et on l'ajoute a la serie de point n.
    QPen pen(Qt::red);
    pen.setWidth(2);
    n->setPen(pen);

    //On supprime les anciens widget
    last_chartview->m_coordX->setText(" ");
    last_chartview->m_coordY->setText(" ");
    ui->verticalLayout->removeWidget(last_chartview);

    //Nous n'affichons pas les points de la nouvelle ligne de point
    n->setPointsVisible(false);

    //Si le chart n'a jamais été modifié et ne comporte qu'une seule serie de point modif = 1
    if(!modif) modif = 1;

        //Sinon on enleve la derniere serie ajouté au chart
    else main_chart->removeSeries(last_serie);

    //last_serie est egal a la nouvelle serie
    last_serie = n;

    //On ajoute la nouvelle serie au main_chart et on créé les axes par defaut.
    main_chart->addSeries(n);
    main_chart->createDefaultAxes();

    //On recuperes les axes
    QValueAxis* axiesX = (QValueAxis*) main_chart->axes(Qt::Horizontal).front();
    QValueAxis* axiesY = (QValueAxis*) main_chart->axes(Qt::Vertical).front();

    //Si l'utilisateur a demandé une notation scientifique, on met les chiffres des axes en notation scientique
    if(scientific_notation == 2)
    {
        axiesX->setLabelFormat("%.2g");
        axiesY->setLabelFormat("%.2g");
    }

        //Sinon on les met en notation normale
    else if(scientific_notation == 0)
    {

        axiesX->setLabelFormat("%.2f");
        axiesY->setLabelFormat("%.2f");
    }

    //On met un titre vide, une animation d'affichage et on cache la legende
    main_chart->setTitle(" ");
    main_chart->setAnimationOptions(QChart::SeriesAnimations);
    main_chart->legend()->hide();

    //on créé un nouveau chart view de main_chart avec le mode mode
    ChartView *chartView = new ChartView(main_chart,mode);
    chartView->first_time = last_chartview->first_time;
    chartView->setRenderHint(QPainter::Antialiasing);

    //last_chartview prend la valeur du nouveau chart view
    last_chartview = chartView;

    //On affiche le nouveau chart view dans le verticalLayout qui est l'mplacement du graphique.
    ui->verticalLayout->addWidget(chartView);

}



///**************************************************************************************************
///Scientific notation permet de changer la notation des chiffres des axes

void displaywindow::Scientific_notation(int a)
{

    //on supprime les anciens widgets
    last_chartview->m_coordX->setText(" ");
    last_chartview->m_coordY->setText(" ");
    ui->verticalLayout->removeWidget(last_chartview);

    //On recupère les axes du main_chart
    QValueAxis* axiesX = (QValueAxis*) main_chart->axes(Qt::Horizontal).front();
    QValueAxis* axiesY = (QValueAxis*) main_chart->axes(Qt::Vertical).front();

    //on set scientific_notation à a. Si la check box est coché, a = 2 sinon a = 0.
    scientific_notation = a;

    //Si a = 2 on met les chiffres des axes en notation scientific
    if(a == 2)
    {
        axiesX->setLabelFormat("%.2g");
        axiesY->setLabelFormat("%.2g");
    }

        //sinon on met ces chiffres en notation normale
    else if(a == 0)
    {
        axiesX->setLabelFormat("%.2f");
        axiesY->setLabelFormat("%.2f");
    }

    //On créé un nouveau chart_view du main_chart avec mode mode et on applique de l'antialiasing sur la trajectoire
    ChartView *chartView = new ChartView(main_chart,mode);
    chartView->first_time = last_chartview->first_time;
    chartView->setRenderHint(QPainter::Antialiasing);

    //Le last_chartview est egal au nouveau chart view
    last_chartview = chartView;

    //on affiche le nouveau chart view.
    ui->verticalLayout->addWidget(chartView);

}




///**************************************************************************************************
///Rubbermode permet de passer en mode de selection avec le rectangle bleu sélection

void displaywindow::Rubbermode()
{

    //on supprime les anciens widgets
    last_chartview->m_coordX->setText(" ");
    last_chartview->m_coordY->setText(" ");
    ui->verticalLayout->removeWidget(last_chartview);

    //On set le mode a 0 qui represente le mode rubberband
    mode = 0;

    //on créé un nouveau chart view de main_chart avec mode mode et on applique de l'antialisaing sur la trajectoire
    ChartView *chartView = new ChartView(main_chart,mode);
    chartView->first_time = last_chartview->first_time;
    chartView->setRenderHint(QPainter::Antialiasing);

    //Last chart view est egal au nouveau chartview
    last_chartview = chartView;

    //On affiche quel mode nous sommes entrain d'utiliser et on affiche le nouveau chart_view
    ui->Display_stat_3->setText("Using RubberBand mode");
    ui->verticalLayout->addWidget(chartView);

}




///**************************************************************************************************
///Mousemode permet de passer en mode de deplacement avec la souris

void displaywindow::Mousemode()
{

    //on supprime les anciens widgets
    last_chartview->m_coordX->setText(" ");
    last_chartview->m_coordY->setText(" ");
    ui->verticalLayout->removeWidget(last_chartview);

    //On set le mode a 1 qui represente le mode mousemode
    mode = 1;

    //on créé un nouveau chart view de main_chart avec mode mode et on applique de l'antialisaing sur la trajectoire
    ChartView *chartView = new ChartView(main_chart,mode);
    chartView->first_time = last_chartview->first_time;
    chartView->setRenderHint(QPainter::Antialiasing);

    //Last chart view est egal au nouveau chartview
    last_chartview = chartView;

    //On affiche quel mode nous sommes entrain d'utiliser et on affiche le nouveau chart_view
    ui->Display_stat_3->setText("Using Mouse mode");
    ui->verticalLayout->addWidget(chartView);;
}


///**************************************************************************************************
///destructeur

displaywindow::~displaywindow()
{
    delete ui;
}
