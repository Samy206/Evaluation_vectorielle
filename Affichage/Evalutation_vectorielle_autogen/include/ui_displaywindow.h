/********************************************************************************
** Form generated from reading UI file 'displaywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYWINDOW_H
#define UI_DISPLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_displaywindow
{
public:
    QGraphicsView *graphicsView;
    QTextBrowser *Display_stat_2;
    QListWidget *listWidget;
    QListWidget *listWidget_2;

    void setupUi(QDialog *displaywindow)
    {
        if (displaywindow->objectName().isEmpty())
            displaywindow->setObjectName(QString::fromUtf8("displaywindow"));
        displaywindow->resize(824, 487);
        graphicsView = new QGraphicsView(displaywindow);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(230, 70, 571, 401));
        Display_stat_2 = new QTextBrowser(displaywindow);
        Display_stat_2->setObjectName(QString::fromUtf8("Display_stat_2"));
        Display_stat_2->setGeometry(QRect(230, 10, 451, 41));
        Display_stat_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget = new QListWidget(displaywindow);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 181, 231));
        listWidget_2 = new QListWidget(displaywindow);
        new QListWidgetItem(listWidget_2);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(10, 271, 181, 201));

        retranslateUi(displaywindow);

        QMetaObject::connectSlotsByName(displaywindow);
    } // setupUi

    void retranslateUi(QDialog *displaywindow)
    {
        displaywindow->setWindowTitle(QCoreApplication::translate("displaywindow", "Dialog", nullptr));
        Display_stat_2->setHtml(QCoreApplication::translate("displaywindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">F(x) = 9x + 8</p></body></html>", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("displaywindow", "V0 = (0,0)", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);


        const bool __sortingEnabled1 = listWidget_2->isSortingEnabled();
        listWidget_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem1 = listWidget_2->item(0);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("displaywindow", "Max = 18,9", nullptr));
        listWidget_2->setSortingEnabled(__sortingEnabled1);

    } // retranslateUi

};

namespace Ui {
    class displaywindow: public Ui_displaywindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYWINDOW_H
