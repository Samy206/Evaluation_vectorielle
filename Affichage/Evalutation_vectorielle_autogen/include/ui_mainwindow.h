/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget_vect;
    QPushButton *Button_excute;
    QListWidget *listWidget_funct;
    QPushButton *Button_erase_vect;
    QSpinBox *SpinBox_nbr_vect;
    QPushButton *Button_addfunct;
    QPushButton *Button_addvect;
    QPushButton *Button_load;
    QPushButton *Button_erase_funct;
    QPushButton *Button_save;
    QTextBrowser *textBrowser;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(750, 540);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(750, 540));
        MainWindow->setMaximumSize(QSize(750, 540));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        listWidget_vect = new QListWidget(centralwidget);
        new QListWidgetItem(listWidget_vect);
        new QListWidgetItem(listWidget_vect);
        new QListWidgetItem(listWidget_vect);
        listWidget_vect->setObjectName(QString::fromUtf8("listWidget_vect"));
        listWidget_vect->setGeometry(QRect(120, 210, 221, 201));
        Button_excute = new QPushButton(centralwidget);
        Button_excute->setObjectName(QString::fromUtf8("Button_excute"));
        Button_excute->setGeometry(QRect(320, 30, 111, 41));
        listWidget_funct = new QListWidget(centralwidget);
        new QListWidgetItem(listWidget_funct);
        new QListWidgetItem(listWidget_funct);
        new QListWidgetItem(listWidget_funct);
        new QListWidgetItem(listWidget_funct);
        listWidget_funct->setObjectName(QString::fromUtf8("listWidget_funct"));
        listWidget_funct->setGeometry(QRect(410, 210, 221, 201));
        Button_erase_vect = new QPushButton(centralwidget);
        Button_erase_vect->setObjectName(QString::fromUtf8("Button_erase_vect"));
        Button_erase_vect->setGeometry(QRect(190, 420, 80, 21));
        SpinBox_nbr_vect = new QSpinBox(centralwidget);
        SpinBox_nbr_vect->setObjectName(QString::fromUtf8("SpinBox_nbr_vect"));
        SpinBox_nbr_vect->setGeometry(QRect(280, 150, 191, 41));
        SpinBox_nbr_vect->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        SpinBox_nbr_vect->setMinimum(1);
        SpinBox_nbr_vect->setMaximum(1000);
        Button_addfunct = new QPushButton(centralwidget);
        Button_addfunct->setObjectName(QString::fromUtf8("Button_addfunct"));
        Button_addfunct->setGeometry(QRect(410, 100, 91, 31));
        Button_addvect = new QPushButton(centralwidget);
        Button_addvect->setObjectName(QString::fromUtf8("Button_addvect"));
        Button_addvect->setGeometry(QRect(220, 100, 91, 31));
        Button_load = new QPushButton(centralwidget);
        Button_load->setObjectName(QString::fromUtf8("Button_load"));
        Button_load->setGeometry(QRect(500, 30, 111, 41));
        Button_erase_funct = new QPushButton(centralwidget);
        Button_erase_funct->setObjectName(QString::fromUtf8("Button_erase_funct"));
        Button_erase_funct->setGeometry(QRect(490, 420, 80, 21));
        Button_save = new QPushButton(centralwidget);
        Button_save->setObjectName(QString::fromUtf8("Button_save"));
        Button_save->setGeometry(QRect(130, 30, 111, 41));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(80, 470, 591, 20));
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion d'Evalutation Vectorielle", nullptr));
#if QT_CONFIG(whatsthis)
        MainWindow->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>You can add vector with the add vector button same for the add function.</p><p>To get the trajectory, the statistics and the list of vector you have to select one vector in the list of the same name and one function in the list of the same name and then click on execute.</p><p>To load a file just click on load file.</p><p>To save something do the same as for the execute button but at the end click on save file.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)

        const bool __sortingEnabled = listWidget_vect->isSortingEnabled();
        listWidget_vect->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_vect->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "V0 = (5.00000,2.00000)", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_vect->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "U = (14.00000,3.33450)", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_vect->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "W = (7.00000,2.00000,22.00000,1.00000)", nullptr));
        listWidget_vect->setSortingEnabled(__sortingEnabled);

#if QT_CONFIG(whatsthis)
        Button_excute->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>To dispay the list of vectors, the trajectory and the statictics.</p><p><br/></p><p>Please select one vector and one funtion.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        Button_excute->setText(QCoreApplication::translate("MainWindow", "Execute", nullptr));

        const bool __sortingEnabled1 = listWidget_funct->isSortingEnabled();
        listWidget_funct->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem3 = listWidget_funct->item(0);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MainWindow", "F(x) = (x+8)", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget_funct->item(1);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("MainWindow", "G(x,y) = (4*x;-2*y)", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget_funct->item(2);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("MainWindow", "W(x,y) = (5*x+1;pow(y,2))", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget_funct->item(3);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("MainWindow", "F(x,y,z,a) = (x+1;y*2;z-x;a*-1)", nullptr));
        listWidget_funct->setSortingEnabled(__sortingEnabled1);

        Button_erase_vect->setText(QCoreApplication::translate("MainWindow", "ERASE", nullptr));
#if QT_CONFIG(whatsthis)
        SpinBox_nbr_vect->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>How many vector do you want to be calculat.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        SpinBox_nbr_vect->setPrefix(QCoreApplication::translate("MainWindow", "Number of vectors : ", nullptr));
#if QT_CONFIG(whatsthis)
        Button_addfunct->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Add function</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        Button_addfunct->setText(QCoreApplication::translate("MainWindow", "Add Function", nullptr));
#if QT_CONFIG(whatsthis)
        Button_addvect->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Add vector</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        Button_addvect->setText(QCoreApplication::translate("MainWindow", "Add Vector", nullptr));
#if QT_CONFIG(whatsthis)
        Button_load->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Load file </p><p><br/></p><p>The initial vector will be add in the left list</p><p>The function will be add in the right list</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        Button_load->setText(QCoreApplication::translate("MainWindow", "Load File", nullptr));
        Button_erase_funct->setText(QCoreApplication::translate("MainWindow", "ERASE", nullptr));
#if QT_CONFIG(whatsthis)
        Button_save->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>To save the list of vectors, the trajectory and the statictics.</p><p><br/></p><p>Please select one vecteur and on function.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        Button_save->setText(QCoreApplication::translate("MainWindow", "Save File", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">To get help click on the '?' button and click where you want to get help. This work on every window.</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
