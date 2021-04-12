#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H
#include "executewindow.h"
#include <QDialog>

namespace Ui {
class displaywindow;
}

class displaywindow : public QDialog
{
    Q_OBJECT

public:
    explicit displaywindow(executewindow *toto, QWidget *parent = nullptr);
    ~displaywindow();

private:
    Ui::displaywindow *ui;
};

#endif // DISPLAYWINDOW_H
