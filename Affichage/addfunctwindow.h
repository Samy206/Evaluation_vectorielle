#ifndef ADDFUNCTWINDOW_H
#define ADDFUNCTWINDOW_H

#include <QDialog>

namespace Ui {
class addfunctwindow;
}

class addfunctwindow : public QDialog
{
    Q_OBJECT

public:
    explicit addfunctwindow(QWidget *parent = nullptr);
    ~addfunctwindow();
     std::string name;
    int nbr_dim;
    std::vector<std::string> getfunct();

public slots:
    void Validate(); //Button for validation
    void Cancel();  // Button for cancel
    void Validate1();  // Button for 1st button valide
    void Pi();  // Button for pi
    void sum();  // Button for sum
    void Rc();  // Button for racine carre

private:
    Ui::addfunctwindow *ui;
    std::vector<std::string> funct;
};

#endif // ADDFUNCTWINDOW_H
