#ifndef DISPLAY_4D_H
#define DISPLAY_4D_H

#include <QDialog>

namespace Ui {
class display_4D;
}

class display_4D : public QDialog
{
    Q_OBJECT

public:
    explicit display_4D(QWidget *parent = nullptr);
    ~display_4D();

private:
    Ui::display_4D *ui;
};

#endif // DISPLAY_4D_H
