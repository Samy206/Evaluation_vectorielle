#include "display_4d.h"
#include "ui_display_4d.h"

display_4D::display_4D(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::display_4D)
{
    ui->setupUi(this);
}

display_4D::~display_4D()
{
    delete ui;
}
