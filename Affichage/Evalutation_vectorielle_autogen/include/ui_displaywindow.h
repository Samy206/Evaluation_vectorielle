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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_displaywindow
{
public:
    QTextBrowser *Display_stat_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextBrowser *Display_stat_3;
    QTableWidget *tableWidget_2;

    void setupUi(QDialog *displaywindow)
    {
        if (displaywindow->objectName().isEmpty())
            displaywindow->setObjectName(QString::fromUtf8("displaywindow"));
        displaywindow->resize(1112, 614);
        Display_stat_2 = new QTextBrowser(displaywindow);
        Display_stat_2->setObjectName(QString::fromUtf8("Display_stat_2"));
        Display_stat_2->setGeometry(QRect(280, 10, 491, 31));
        Display_stat_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        verticalLayoutWidget = new QWidget(displaywindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(270, 50, 841, 511));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(displaywindow);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 261, 331));
        checkBox = new QCheckBox(displaywindow);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(780, 10, 321, 29));
        pushButton = new QPushButton(displaywindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(350, 570, 211, 31));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton_2 = new QPushButton(displaywindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(820, 570, 181, 31));
        pushButton_2->setFocusPolicy(Qt::NoFocus);
        Display_stat_3 = new QTextBrowser(displaywindow);
        Display_stat_3->setObjectName(QString::fromUtf8("Display_stat_3"));
        Display_stat_3->setGeometry(QRect(580, 570, 221, 31));
        Display_stat_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_2 = new QTableWidget(displaywindow);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(10, 360, 261, 241));

        retranslateUi(displaywindow);

        QMetaObject::connectSlotsByName(displaywindow);
    } // setupUi

    void retranslateUi(QDialog *displaywindow)
    {
        displaywindow->setWindowTitle(QCoreApplication::translate("displaywindow", "Dialog", nullptr));
        Display_stat_2->setHtml(QCoreApplication::translate("displaywindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.14286pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:7.8pt;\">F(x) = 9x + 8</span></p></body></html>", nullptr));
        checkBox->setText(QCoreApplication::translate("displaywindow", "Switch to scientific representation", nullptr));
        pushButton->setText(QCoreApplication::translate("displaywindow", "Mouse mode", nullptr));
        pushButton_2->setText(QCoreApplication::translate("displaywindow", "Rubberband mode", nullptr));
        Display_stat_3->setHtml(QCoreApplication::translate("displaywindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.14286pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.14286pt;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class displaywindow: public Ui_displaywindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYWINDOW_H
