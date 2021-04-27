#ifndef STATISTIQUEWINDOW_H
#define STATISTIQUEWINDOW_H

#include <QDialog>

namespace Ui {
class addvectwindow;
}

class addvectwindow : public QDialog
{
    Q_OBJECT

public:
    explicit addvectwindow(QWidget *parent = nullptr);
    ~addvectwindow();
    bool stat[6];   //Stat wanted
    double statcalc[6];
    void makestat();
    //list des vecteurs

public slots:
    void Validate(); //Button for validation
    void Cancel();  // Button for cancel

private:
    Ui::addvectwindow *ui;

};

#endif // STATISTIQUEWINDOW_H
