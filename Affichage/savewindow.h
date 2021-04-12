#ifndef SAVEWINDOW_H
#define SAVEWINDOW_H

#include <QDialog>
#include "iostream"
using namespace std;

namespace Ui {
class savewindow;
}

class savewindow : public QDialog
{
    Q_OBJECT

public:
    explicit savewindow(QWidget *parent = nullptr);
    ~savewindow();
    string vect_init;
    string funct;
    int nbr_vect;
    string departur;

public slots:
    void Validate(); //Button for validation
    void Cancel();  // Button for cancel



private:
    Ui::savewindow *ui;
};

#endif // SAVEWINDOW_H
