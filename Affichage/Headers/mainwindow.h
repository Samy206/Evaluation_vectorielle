#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "iostream"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    string funct;   //Selected Function
    int nbr_vect;   //Selected nbr_vect
    string vect_init;   //Selected Vector

public slots:
    void makeload();
    void makesave();
    void makeadd_vect();
    void makeadd_funct();
    void makeerase_funct();
    void makeerase_vect();
    void makeexecute();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
