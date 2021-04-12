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
    string vect_init;
    string funct;
    int nbr_vect;

public slots:
    void makeload();
    void makesave();
    void makeadd_vect();
    void makeadd_funct();
    void makeerase();
    void makeexecute();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
