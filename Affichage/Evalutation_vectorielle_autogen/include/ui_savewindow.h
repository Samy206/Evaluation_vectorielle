/********************************************************************************
** Form generated from reading UI file 'savewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEWINDOW_H
#define UI_SAVEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_savewindow
{
public:
    QFrame *frame;
    QTextBrowser *Display_title;
    QFrame *frame_2;
    QCheckBox *CheckBox_Minimum;
    QCheckBox *CheckBox_Moyenne;
    QCheckBox *CheckBox_Variance;
    QCheckBox *CheckBox_Autocor;
    QCheckBox *CheckBox_Maximum;
    QCheckBox *CheckBox_Ecarttype;
    QLineEdit *lineEdit;
    QPushButton *Button_valide;
    QPushButton *Button_cancel;
    QFrame *frame_3;
    QLineEdit *LineEdit_Name;
    QTextBrowser *Display_title5;
    QTextBrowser *Display_title4;
    QTextBrowser *Display_title4_2;
    QCheckBox *checkBox_v0;
    QLineEdit *LineEdit_Name_2;

    void setupUi(QDialog *savewindow)
    {
        if (savewindow->objectName().isEmpty())
            savewindow->setObjectName(QString::fromUtf8("savewindow"));
        savewindow->resize(435, 370);
        savewindow->setMinimumSize(QSize(435, 370));
        savewindow->setMaximumSize(QSize(435, 370));
        frame = new QFrame(savewindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 20, 391, 211));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        Display_title = new QTextBrowser(frame);
        Display_title->setObjectName(QString::fromUtf8("Display_title"));
        Display_title->setGeometry(QRect(0, 0, 641, 41));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(170, 170, 170, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(212, 212, 212, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(85, 85, 85, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(113, 113, 113, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush6(QColor(163, 163, 163, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush8(QColor(0, 0, 0, 128));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        Display_title->setPalette(palette);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(20, 60, 351, 131));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        CheckBox_Minimum = new QCheckBox(frame_2);
        CheckBox_Minimum->setObjectName(QString::fromUtf8("CheckBox_Minimum"));
        CheckBox_Minimum->setGeometry(QRect(20, 10, 83, 22));
        CheckBox_Moyenne = new QCheckBox(frame_2);
        CheckBox_Moyenne->setObjectName(QString::fromUtf8("CheckBox_Moyenne"));
        CheckBox_Moyenne->setGeometry(QRect(180, 10, 83, 22));
        CheckBox_Variance = new QCheckBox(frame_2);
        CheckBox_Variance->setObjectName(QString::fromUtf8("CheckBox_Variance"));
        CheckBox_Variance->setGeometry(QRect(180, 50, 83, 22));
        CheckBox_Autocor = new QCheckBox(frame_2);
        CheckBox_Autocor->setObjectName(QString::fromUtf8("CheckBox_Autocor"));
        CheckBox_Autocor->setGeometry(QRect(180, 90, 121, 22));
        CheckBox_Maximum = new QCheckBox(frame_2);
        CheckBox_Maximum->setObjectName(QString::fromUtf8("CheckBox_Maximum"));
        CheckBox_Maximum->setGeometry(QRect(20, 50, 83, 22));
        CheckBox_Ecarttype = new QCheckBox(frame_2);
        CheckBox_Ecarttype->setObjectName(QString::fromUtf8("CheckBox_Ecarttype"));
        CheckBox_Ecarttype->setGeometry(QRect(20, 90, 83, 22));
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(310, 90, 31, 24));
        frame_2->raise();
        Display_title->raise();
        Button_valide = new QPushButton(savewindow);
        Button_valide->setObjectName(QString::fromUtf8("Button_valide"));
        Button_valide->setGeometry(QRect(240, 330, 80, 25));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush9(QColor(85, 170, 0, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush9);
        QBrush brush10(QColor(128, 255, 0, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush10);
        QBrush brush11(QColor(106, 212, 0, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        QBrush brush12(QColor(43, 85, 0, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush12);
        QBrush brush13(QColor(57, 113, 0, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush14(QColor(170, 212, 127, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        Button_valide->setPalette(palette1);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        Button_valide->setFont(font);
        Button_valide->setAutoFillBackground(false);
        Button_valide->setAutoDefault(true);
        Button_valide->setFlat(false);
        Button_cancel = new QPushButton(savewindow);
        Button_cancel->setObjectName(QString::fromUtf8("Button_cancel"));
        Button_cancel->setGeometry(QRect(330, 330, 80, 25));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush15(QColor(170, 0, 0, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush15);
        QBrush brush16(QColor(255, 0, 0, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush16);
        QBrush brush17(QColor(212, 0, 0, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush17);
        QBrush brush18(QColor(85, 0, 0, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush18);
        QBrush brush19(QColor(113, 0, 0, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush19);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush15);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush20(QColor(212, 127, 127, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush20);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush15);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush16);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush17);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush18);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush19);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush15);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush20);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush18);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush16);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush17);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush18);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush19);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush18);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush18);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        Button_cancel->setPalette(palette2);
        frame_3 = new QFrame(savewindow);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(20, 230, 391, 81));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Plain);
        LineEdit_Name = new QLineEdit(frame_3);
        LineEdit_Name->setObjectName(QString::fromUtf8("LineEdit_Name"));
        LineEdit_Name->setGeometry(QRect(70, 40, 113, 31));
        LineEdit_Name->setClearButtonEnabled(false);
        Display_title5 = new QTextBrowser(frame_3);
        Display_title5->setObjectName(QString::fromUtf8("Display_title5"));
        Display_title5->setGeometry(QRect(10, 40, 51, 31));
        Display_title5->setAutoFillBackground(false);
        Display_title5->setFrameShape(QFrame::StyledPanel);
        Display_title5->setOverwriteMode(false);
        Display_title4 = new QTextBrowser(frame_3);
        Display_title4->setObjectName(QString::fromUtf8("Display_title4"));
        Display_title4->setGeometry(QRect(10, 10, 121, 21));
        Display_title4->setAutoFillBackground(false);
        Display_title4->setFrameShape(QFrame::StyledPanel);
        Display_title4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Display_title4_2 = new QTextBrowser(frame_3);
        Display_title4_2->setObjectName(QString::fromUtf8("Display_title4_2"));
        Display_title4_2->setGeometry(QRect(210, 10, 141, 21));
        Display_title4_2->setAutoFillBackground(false);
        Display_title4_2->setFrameShape(QFrame::StyledPanel);
        Display_title4_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        checkBox_v0 = new QCheckBox(frame_3);
        checkBox_v0->setObjectName(QString::fromUtf8("checkBox_v0"));
        checkBox_v0->setGeometry(QRect(210, 40, 83, 31));
        LineEdit_Name_2 = new QLineEdit(frame_3);
        LineEdit_Name_2->setObjectName(QString::fromUtf8("LineEdit_Name_2"));
        LineEdit_Name_2->setGeometry(QRect(300, 40, 81, 31));
        LineEdit_Name_2->setClearButtonEnabled(false);
        frame_3->raise();
        frame->raise();
        Button_valide->raise();
        Button_cancel->raise();

        retranslateUi(savewindow);
        QObject::connect(CheckBox_Autocor, SIGNAL(clicked(bool)), lineEdit, SLOT(setEnabled(bool)));

        Button_valide->setDefault(false);


        QMetaObject::connectSlotsByName(savewindow);
    } // setupUi

    void retranslateUi(QDialog *savewindow)
    {
        savewindow->setWindowTitle(QCoreApplication::translate("savewindow", "Save Window", nullptr));
#if QT_CONFIG(whatsthis)
        savewindow->setWhatsThis(QCoreApplication::translate("savewindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">First, you have to select which statistics you want.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Then, choose your departure.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Finally, enter the name of the output file.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"gen-h1-1-00000001\"></a><span style=\" f"
                        "ont-family:'Source Sans Pro','Roboto','San Francisco','Segoe UI','sans-serif'; font-size:xx-large; color:#373637;\">\342\232\240</span>The '\\' character is forbidden in the name of file.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Source Sans Pro','Roboto','San Francisco','Segoe UI','sans-serif'; font-size:xx-large; color:#373637;\"><br /></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        Display_title->setHtml(QCoreApplication::translate("savewindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">Choose the data you want to save</span></p></body></html>", nullptr));
        CheckBox_Minimum->setText(QCoreApplication::translate("savewindow", "Minimum", nullptr));
        CheckBox_Moyenne->setText(QCoreApplication::translate("savewindow", "Average", nullptr));
        CheckBox_Variance->setText(QCoreApplication::translate("savewindow", "Variance", nullptr));
        CheckBox_Autocor->setText(QCoreApplication::translate("savewindow", "Auto-correlation", nullptr));
        CheckBox_Maximum->setText(QCoreApplication::translate("savewindow", "Maximum", nullptr));
        CheckBox_Ecarttype->setText(QCoreApplication::translate("savewindow", "Ecart-type", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("savewindow", "shift", nullptr));
        Button_valide->setText(QCoreApplication::translate("savewindow", "Validate", nullptr));
        Button_cancel->setText(QCoreApplication::translate("savewindow", "Cancel", nullptr));
        LineEdit_Name->setInputMask(QString());
        LineEdit_Name->setPlaceholderText(QCoreApplication::translate("savewindow", "Name", nullptr));
        Display_title5->setHtml(QCoreApplication::translate("savewindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Save\\</p></body></html>", nullptr));
        Display_title4->setHtml(QCoreApplication::translate("savewindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Write the name</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        Display_title4_2->setHtml(QCoreApplication::translate("savewindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Choose your departure</p></body></html>", nullptr));
        checkBox_v0->setText(QCoreApplication::translate("savewindow", "V0 = (0,0)", nullptr));
        LineEdit_Name_2->setInputMask(QString());
        LineEdit_Name_2->setPlaceholderText(QCoreApplication::translate("savewindow", "-1,8", nullptr));
    } // retranslateUi

};

namespace Ui {
    class savewindow: public Ui_savewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEWINDOW_H