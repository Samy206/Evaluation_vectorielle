/********************************************************************************
** Form generated from reading UI file 'addfunctwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFUNCTWINDOW_H
#define UI_ADDFUNCTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_addfunctwindow
{
public:
    QPushButton *Button_pi;
    QPushButton *Button_racine;
    QSpinBox *spinBox;
    QPushButton *Button_valide;
    QPushButton *Button_mod;
    QPushButton *Button_cancel;
    QTableWidget *tableWidget_funct;
    QPushButton *Button_valide1;
    QTextBrowser *Display_title;
    QLineEdit *lineEdit_name;

    void setupUi(QDialog *addfunctwindow)
    {
        if (addfunctwindow->objectName().isEmpty())
            addfunctwindow->setObjectName(QString::fromUtf8("addfunctwindow"));
        addfunctwindow->resize(443, 335);
        addfunctwindow->setMinimumSize(QSize(443, 335));
        addfunctwindow->setMaximumSize(QSize(443, 335));
        Button_pi = new QPushButton(addfunctwindow);
        Button_pi->setObjectName(QString::fromUtf8("Button_pi"));
        Button_pi->setEnabled(false);
        Button_pi->setGeometry(QRect(360, 200, 61, 20));
        Button_racine = new QPushButton(addfunctwindow);
        Button_racine->setObjectName(QString::fromUtf8("Button_racine"));
        Button_racine->setEnabled(false);
        Button_racine->setGeometry(QRect(220, 200, 61, 20));
        spinBox = new QSpinBox(addfunctwindow);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(10, 60, 191, 41));
        spinBox->setMinimum(1);
        spinBox->setMaximum(25);
        Button_valide = new QPushButton(addfunctwindow);
        Button_valide->setObjectName(QString::fromUtf8("Button_valide"));
        Button_valide->setEnabled(false);
        Button_valide->setGeometry(QRect(260, 290, 80, 25));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(85, 170, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(128, 255, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(106, 212, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(43, 85, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(57, 113, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(170, 212, 127, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush9(QColor(0, 0, 0, 128));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        Button_valide->setPalette(palette);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        Button_valide->setFont(font);
        Button_valide->setAutoFillBackground(false);
        Button_valide->setAutoDefault(true);
        Button_valide->setFlat(false);
        Button_mod = new QPushButton(addfunctwindow);
        Button_mod->setObjectName(QString::fromUtf8("Button_mod"));
        Button_mod->setEnabled(false);
        Button_mod->setGeometry(QRect(290, 200, 61, 20));
        Button_cancel = new QPushButton(addfunctwindow);
        Button_cancel->setObjectName(QString::fromUtf8("Button_cancel"));
        Button_cancel->setEnabled(true);
        Button_cancel->setGeometry(QRect(350, 290, 80, 25));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush10(QColor(170, 0, 0, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush10);
        QBrush brush11(QColor(255, 0, 0, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush11);
        QBrush brush12(QColor(212, 0, 0, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush12);
        QBrush brush13(QColor(85, 0, 0, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush13);
        QBrush brush14(QColor(113, 0, 0, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush14);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush15(QColor(212, 127, 127, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush15);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush14);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush15);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush14);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        Button_cancel->setPalette(palette1);
        tableWidget_funct = new QTableWidget(addfunctwindow);
        if (tableWidget_funct->columnCount() < 1)
            tableWidget_funct->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_funct->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget_funct->rowCount() < 10)
            tableWidget_funct->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_funct->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_funct->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_funct->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_funct->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_funct->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_funct->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_funct->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_funct->setVerticalHeaderItem(7, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_funct->setVerticalHeaderItem(8, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_funct->setVerticalHeaderItem(9, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_funct->setItem(0, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_funct->setItem(1, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_funct->setItem(2, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_funct->setItem(3, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_funct->setItem(4, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_funct->setItem(5, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_funct->setItem(6, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_funct->setItem(7, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_funct->setItem(8, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_funct->setItem(9, 0, __qtablewidgetitem20);
        tableWidget_funct->setObjectName(QString::fromUtf8("tableWidget_funct"));
        tableWidget_funct->setEnabled(false);
        tableWidget_funct->setGeometry(QRect(10, 110, 191, 211));
        Button_valide1 = new QPushButton(addfunctwindow);
        Button_valide1->setObjectName(QString::fromUtf8("Button_valide1"));
        Button_valide1->setGeometry(QRect(270, 70, 80, 25));
        Display_title = new QTextBrowser(addfunctwindow);
        Display_title->setObjectName(QString::fromUtf8("Display_title"));
        Display_title->setGeometry(QRect(10, 10, 421, 41));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush16(QColor(170, 170, 170, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush16);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush6);
        QBrush brush17(QColor(212, 212, 212, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush17);
        QBrush brush18(QColor(85, 85, 85, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush18);
        QBrush brush19(QColor(113, 113, 113, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush19);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush20(QColor(163, 163, 163, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush20);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush16);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush17);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush16);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush17);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush18);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush19);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush20);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush16);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush17);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush18);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush16);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush17);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush18);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush19);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush18);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush18);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush16);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush16);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush16);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        Display_title->setPalette(palette2);
        lineEdit_name = new QLineEdit(addfunctwindow);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setEnabled(false);
        lineEdit_name->setGeometry(QRect(250, 140, 131, 24));
        lineEdit_name->setToolTipDuration(-1);

        retranslateUi(addfunctwindow);

        Button_valide->setDefault(false);


        QMetaObject::connectSlotsByName(addfunctwindow);
    } // setupUi

    void retranslateUi(QDialog *addfunctwindow)
    {
        addfunctwindow->setWindowTitle(QCoreApplication::translate("addfunctwindow", "Add Function Window", nullptr));
#if QT_CONFIG(whatsthis)
        addfunctwindow->setWhatsThis(QCoreApplication::translate("addfunctwindow", "<html><head/><body><p>First, you need to enter the number of dimensions of your function.</p><p>Next, you need to grab all the components of your function.</p><p>Finally, enter the name of your function.</p><p><a name=\"gen-h1-1-00000001\"/><span style=\" font-family:'Source Sans Pro','Roboto','San Francisco','Segoe UI','sans-serif'; font-size:14pt; color:#373637;\">\342\232\240</span>Your componant must respect the mathematical syntaxe.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        Button_pi->setText(QCoreApplication::translate("addfunctwindow", "\342\210\217", nullptr));
        Button_racine->setText(QCoreApplication::translate("addfunctwindow", "\342\210\232", nullptr));
        spinBox->setPrefix(QCoreApplication::translate("addfunctwindow", "How many dimension ", nullptr));
        Button_valide->setText(QCoreApplication::translate("addfunctwindow", "Validate", nullptr));
        Button_mod->setText(QCoreApplication::translate("addfunctwindow", "mod", nullptr));
        Button_cancel->setText(QCoreApplication::translate("addfunctwindow", "Cancel", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_funct->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("addfunctwindow", "Function", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_funct->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("addfunctwindow", "X = ", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_funct->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("addfunctwindow", "Y =", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_funct->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("addfunctwindow", "Z =", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_funct->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("addfunctwindow", "A =", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_funct->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("addfunctwindow", "B =", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_funct->verticalHeaderItem(5);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("addfunctwindow", "C =", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_funct->verticalHeaderItem(6);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("addfunctwindow", "D =", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_funct->verticalHeaderItem(7);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("addfunctwindow", "F =", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_funct->verticalHeaderItem(8);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("addfunctwindow", "G =", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_funct->verticalHeaderItem(9);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("addfunctwindow", "I =", nullptr));

        const bool __sortingEnabled = tableWidget_funct->isSortingEnabled();
        tableWidget_funct->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_funct->item(0, 0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("addfunctwindow", "5*x+3", nullptr));
        tableWidget_funct->setSortingEnabled(__sortingEnabled);

#if QT_CONFIG(tooltip)
        tableWidget_funct->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        Button_valide1->setText(QCoreApplication::translate("addfunctwindow", "Valide", nullptr));
        Display_title->setHtml(QCoreApplication::translate("addfunctwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">Add function</span></p></body></html>", nullptr));
        lineEdit_name->setPlaceholderText(QCoreApplication::translate("addfunctwindow", "name of your function", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addfunctwindow: public Ui_addfunctwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFUNCTWINDOW_H
