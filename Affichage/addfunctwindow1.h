#ifndef VECTORLISTWINDOW_H
#define VECTORLISTWINDOW_H

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

public slots:
    void Validate(); //Button for validation
    void Cancel();  // Button for cancel
private:
    Ui::addfunctwindow *ui;
};

#endif // VECTORLISTWINDOW_H
