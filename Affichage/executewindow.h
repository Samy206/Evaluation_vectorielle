#ifndef EXECUTEWINDOW_H
#define EXECUTEWINDOW_H

#include <QDialog>
#include <iostream>
using namespace std;


namespace Ui {
class executewindow;
}

class executewindow : public QDialog
{
    Q_OBJECT

public:
    explicit executewindow(QWidget *parent = nullptr);
    ~executewindow();
    int statistic[6]; //statistic wanted
    string departur;
    string funct;
    string vect_init;
    int nbr_vect;


public slots:
    void Validate(); //Button for validation
    void Cancel();  // Button for cancel

private:
    Ui::executewindow *ui;
};

#endif // EXECUTEWINDOW_H
