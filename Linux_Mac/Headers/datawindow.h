#ifndef DATAWINDOW_H
#define DATAWINDOW_H

#include <QDialog>

namespace Ui {
class datawindow;
}

class datawindow : public QDialog
{
    Q_OBJECT

public:
    explicit datawindow(QWidget *parent = nullptr);
    ~datawindow();

private:
    Ui::datawindow *ui;
};

#endif // DATAWINDOW_H
