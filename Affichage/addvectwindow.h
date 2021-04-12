#ifndef ADDVECTWINDOW_H
#define ADDVECTWINDOW_H

#include <QDialog>
#include "vector"

namespace Ui {
class addvectwindow;
}

class addvectwindow : public QDialog
{
    Q_OBJECT

public:
    explicit addvectwindow(QWidget *parent = nullptr);
    ~addvectwindow();
    int state; //To know if the window end with the validate button(1) or cancel button(0)
    int nbr_dim;
    std::string name;
    std::vector<double> getvectinit();


public slots:
    void Validate(); //Button for validation
    void Cancel();  // Button for cancel
    void Validate1();  // Button for 1st button valide
private:
    Ui::addvectwindow *ui;
    std::vector<double> vect_init;
};

#endif // ADDVECTWINDOW_H
