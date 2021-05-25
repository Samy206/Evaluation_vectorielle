#ifndef SAVEWINDOW_H
#define SAVEWINDOW_H

#include <QDialog>
#include "iostream"
#include "../Headers/mainwindow.h"
using namespace std;

namespace Ui {
class savewindow;
}

class savewindow : public QDialog
{
    Q_OBJECT

public:
    explicit savewindow(MainWindow *dad, QWidget *parent = nullptr);
    ~savewindow();
    int state; //To know if the window end with the validate button(1) or cancel button(0)
    string vect_init;
    string funct_string;
    int nbr_vect;

public slots:
    void Validate(); //Button for validation
    void Cancel();  // Button for cancel



private:
    Ui::savewindow *ui;
};

#endif // SAVEWINDOW_H
