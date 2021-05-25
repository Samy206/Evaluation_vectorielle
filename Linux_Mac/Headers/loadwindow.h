#ifndef LOADWINDOW_H
#define LOADWINDOW_H

#include <QDialog>

namespace Ui {
class loadwindow;
}

class loadwindow : public QDialog
{
    Q_OBJECT

public:
    explicit loadwindow(QWidget *parent = nullptr);
    ~loadwindow();
    std::string vecteur;
    std::string funct;
    int state;

public slots:
    void Validate(); //Button for validation
    void Cancel();  // Button for cancel

private:
    Ui::loadwindow *ui;
};

#endif // LOADWINDOW_H
