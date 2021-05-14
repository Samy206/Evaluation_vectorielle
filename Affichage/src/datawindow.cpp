#include "../Headers/datawindow.h"
#include "ui_datawindow.h"

datawindow::datawindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::datawindow)
{
    ui->setupUi(this);
}

datawindow::~datawindow()
{
    delete ui;
}
