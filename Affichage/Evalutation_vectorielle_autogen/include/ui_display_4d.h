/********************************************************************************
** Form generated from reading UI file 'display_4d.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAY_4D_H
#define UI_DISPLAY_4D_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_display_4D
{
public:
    QListWidget *listWidget;
    QTextBrowser *Display_stat_2;
    QListWidget *listWidget_2;

    void setupUi(QDialog *display_4D)
    {
        if (display_4D->objectName().isEmpty())
            display_4D->setObjectName(QString::fromUtf8("display_4D"));
        display_4D->resize(740, 452);
        display_4D->setMinimumSize(QSize(740, 452));
        display_4D->setMaximumSize(QSize(740, 452));
        listWidget = new QListWidget(display_4D);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 100, 321, 301));
        Display_stat_2 = new QTextBrowser(display_4D);
        Display_stat_2->setObjectName(QString::fromUtf8("Display_stat_2"));
        Display_stat_2->setGeometry(QRect(140, 20, 451, 41));
        Display_stat_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_2 = new QListWidget(display_4D);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(390, 100, 321, 301));

        retranslateUi(display_4D);

        QMetaObject::connectSlotsByName(display_4D);
    } // setupUi

    void retranslateUi(QDialog *display_4D)
    {
        display_4D->setWindowTitle(QCoreApplication::translate("display_4D", "Display 4D+", nullptr));
        Display_stat_2->setHtml(QCoreApplication::translate("display_4D", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">F(x,y,z,a) = 9x + 8; 5y; 9+8z; 8/x+a</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class display_4D: public Ui_display_4D {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAY_4D_H
