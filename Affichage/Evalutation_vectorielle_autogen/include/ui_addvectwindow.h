/********************************************************************************
** Form generated from reading UI file 'addvectwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDVECTWINDOW_H
#define UI_ADDVECTWINDOW_H

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

class Ui_addvectwindow
{
public:
    QTableWidget *tableWidget_vect;
    QPushButton *Button_valide_2;
    QPushButton *Button_cancel_2;
    QPushButton *Button_valide1;
    QSpinBox *spinBox;
    QTextBrowser *Display_title;
    QLineEdit *lineEdit_name;

    void setupUi(QDialog *addvectwindow)
    {
        if (addvectwindow->objectName().isEmpty())
            addvectwindow->setObjectName(QString::fromUtf8("addvectwindow"));
        addvectwindow->resize(427, 344);
        addvectwindow->setMinimumSize(QSize(427, 344));
        addvectwindow->setMaximumSize(QSize(427, 344));
        tableWidget_vect = new QTableWidget(addvectwindow);
        if (tableWidget_vect->columnCount() < 1)
            tableWidget_vect->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_vect->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget_vect->rowCount() < 25)
            tableWidget_vect->setRowCount(25);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(7, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(8, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(9, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(10, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(11, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(12, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(13, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(14, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(15, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(16, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(17, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(18, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(19, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(20, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(21, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(22, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(23, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_vect->setVerticalHeaderItem(24, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_vect->setItem(0, 0, __qtablewidgetitem26);
        tableWidget_vect->setObjectName(QString::fromUtf8("tableWidget_vect"));
        tableWidget_vect->setEnabled(false);
        tableWidget_vect->setGeometry(QRect(10, 110, 191, 211));
        Button_valide_2 = new QPushButton(addvectwindow);
        Button_valide_2->setObjectName(QString::fromUtf8("Button_valide_2"));
        Button_valide_2->setEnabled(false);
        Button_valide_2->setGeometry(QRect(250, 300, 80, 25));
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
        Button_valide_2->setPalette(palette);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        Button_valide_2->setFont(font);
        Button_valide_2->setAutoFillBackground(false);
        Button_valide_2->setAutoDefault(true);
        Button_valide_2->setFlat(false);
        Button_cancel_2 = new QPushButton(addvectwindow);
        Button_cancel_2->setObjectName(QString::fromUtf8("Button_cancel_2"));
        Button_cancel_2->setEnabled(true);
        Button_cancel_2->setGeometry(QRect(340, 300, 80, 25));
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
        Button_cancel_2->setPalette(palette1);
        Button_valide1 = new QPushButton(addvectwindow);
        Button_valide1->setObjectName(QString::fromUtf8("Button_valide1"));
        Button_valide1->setGeometry(QRect(280, 70, 80, 25));
        spinBox = new QSpinBox(addvectwindow);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(10, 60, 191, 41));
        spinBox->setMinimum(1);
        spinBox->setMaximum(25);
        Display_title = new QTextBrowser(addvectwindow);
        Display_title->setObjectName(QString::fromUtf8("Display_title"));
        Display_title->setGeometry(QRect(10, 10, 401, 41));
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
        lineEdit_name = new QLineEdit(addvectwindow);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setEnabled(false);
        lineEdit_name->setGeometry(QRect(260, 160, 131, 24));
        lineEdit_name->setToolTipDuration(-1);

        retranslateUi(addvectwindow);

        Button_valide_2->setDefault(false);


        QMetaObject::connectSlotsByName(addvectwindow);
    } // setupUi

    void retranslateUi(QDialog *addvectwindow)
    {
        addvectwindow->setWindowTitle(QCoreApplication::translate("addvectwindow", "Add Vector Window", nullptr));
#if QT_CONFIG(whatsthis)
        addvectwindow->setWhatsThis(QCoreApplication::translate("addvectwindow", "<html><head/><body><p>First, you need to enter the number of dimensions of your vector.</p><p>Next, you need to grab all the components of your vector.</p><p>Finally, enter the name of your vector.</p><p><a name=\"gen-h1-1-00000001\"/><span style=\" font-family:'Source Sans Pro','Roboto','San Francisco','Segoe UI','sans-serif'; font-size:14pt; color:#373637;\">\342\232\240</span>Your componant must be integer.</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        QTableWidgetItem *___qtablewidgetitem = tableWidget_vect->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("addvectwindow", "Vector", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_vect->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("addvectwindow", "X = ", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_vect->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("addvectwindow", "Y =", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_vect->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("addvectwindow", "Z =", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_vect->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("addvectwindow", "A =", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_vect->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("addvectwindow", "B =", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_vect->verticalHeaderItem(5);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("addvectwindow", "C =", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_vect->verticalHeaderItem(6);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("addvectwindow", "D = ", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_vect->verticalHeaderItem(7);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("addvectwindow", "F =", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_vect->verticalHeaderItem(8);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("addvectwindow", "G =", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_vect->verticalHeaderItem(9);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("addvectwindow", "H =", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_vect->verticalHeaderItem(10);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("addvectwindow", "I = ", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_vect->verticalHeaderItem(11);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("addvectwindow", "J =", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_vect->verticalHeaderItem(12);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("addvectwindow", "K =", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_vect->verticalHeaderItem(13);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("addvectwindow", "L =", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_vect->verticalHeaderItem(14);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("addvectwindow", "M =", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_vect->verticalHeaderItem(15);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("addvectwindow", "N =", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_vect->verticalHeaderItem(16);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("addvectwindow", "O = ", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_vect->verticalHeaderItem(17);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("addvectwindow", "P =", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_vect->verticalHeaderItem(18);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("addvectwindow", "Q =", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_vect->verticalHeaderItem(19);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("addvectwindow", "R =", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_vect->verticalHeaderItem(20);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("addvectwindow", "S =", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_vect->verticalHeaderItem(21);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("addvectwindow", "T = ", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_vect->verticalHeaderItem(22);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("addvectwindow", "U =", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_vect->verticalHeaderItem(23);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("addvectwindow", "V =", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_vect->verticalHeaderItem(24);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("addvectwindow", "W =", nullptr));

        const bool __sortingEnabled = tableWidget_vect->isSortingEnabled();
        tableWidget_vect->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_vect->item(0, 0);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("addvectwindow", "5", nullptr));
        tableWidget_vect->setSortingEnabled(__sortingEnabled);

#if QT_CONFIG(tooltip)
        tableWidget_vect->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        Button_valide_2->setText(QCoreApplication::translate("addvectwindow", "Validate", nullptr));
        Button_cancel_2->setText(QCoreApplication::translate("addvectwindow", "Cancel", nullptr));
        Button_valide1->setText(QCoreApplication::translate("addvectwindow", "Valide", nullptr));
        spinBox->setPrefix(QCoreApplication::translate("addvectwindow", "How many dimension ", nullptr));
        Display_title->setHtml(QCoreApplication::translate("addvectwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">Add vector</span></p></body></html>", nullptr));
        lineEdit_name->setPlaceholderText(QCoreApplication::translate("addvectwindow", "name of your vector", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addvectwindow: public Ui_addvectwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDVECTWINDOW_H
