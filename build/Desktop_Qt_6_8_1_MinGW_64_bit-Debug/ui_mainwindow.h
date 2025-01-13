/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <optionlabel.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *mainwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *buttonwidgetl;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButtonL;
    QWidget *screenwidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *buttonwidgetr;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButtonR;
    QWidget *bottomwidget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *bottomleftwidget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_11;
    QVBoxLayout *verticalLayout_5;
    OptionLabel *label_5;
    OptionLabel *label_6;
    OptionLabel *label_7;
    OptionLabel *label_8;
    QWidget *bottomrightwidget;
    QHBoxLayout *horizontalLayout_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1222, 755);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        mainwidget = new QWidget(centralwidget);
        mainwidget->setObjectName("mainwidget");
        mainwidget->setEnabled(true);
        mainwidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 rgba(29, 95, 181, 0.6), stop: 0.5 rgba(2, 32, 41, 0.1), stop: 1 rgba(29, 95, 181, 0.6));\n"
"	border-radius: 20px; /* Rounded corners */\n"
"	border: 1px solid rgba(0, 0, 0, .5);\n"
"}"));
        horizontalLayout = new QHBoxLayout(mainwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        buttonwidgetl = new QWidget(mainwidget);
        buttonwidgetl->setObjectName("buttonwidgetl");
        buttonwidgetl->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"    background: none;\n"
"	border: none;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(buttonwidgetl);
        verticalLayout_2->setObjectName("verticalLayout_2");
        pushButtonL = new QPushButton(buttonwidgetl);
        pushButtonL->setObjectName("pushButtonL");
        pushButtonL->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"    background: none;\n"
"}"));
        pushButtonL->setIconSize(QSize(64, 64));

        verticalLayout_2->addWidget(pushButtonL, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);


        horizontalLayout->addWidget(buttonwidgetl, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        screenwidget = new QWidget(mainwidget);
        screenwidget->setObjectName("screenwidget");
        screenwidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	 background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 rgba(29, 95, 181, 0.95), stop: 0.85 rgba(2, 32, 41, 0.95), stop: 1 rgba(29, 95, 181, 0.6));\n"
"	border: 1px solid black;\n"
"	font-size: 24px;\n"
"	color: black;\n"
"	\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(screenwidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_1 = new QLabel(screenwidget);
        label_1->setObjectName("label_1");
        label_1->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"    background: none;\n"
"	border: none;\n"
"	color: white;\n"
"}"));

        verticalLayout_4->addWidget(label_1, 0, Qt::AlignmentFlag::AlignHCenter);

        label_2 = new QLabel(screenwidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"    background: none;\n"
"	border: none\n"
"}"));

        verticalLayout_4->addWidget(label_2);

        label_3 = new QLabel(screenwidget);
        label_3->setObjectName("label_3");
        label_3->setAutoFillBackground(false);
        label_3->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"   background: none;\n"
"   border: none\n"
"}"));

        verticalLayout_4->addWidget(label_3);

        label_4 = new QLabel(screenwidget);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background: none;\n"
"	border: none\n"
"}"));

        verticalLayout_4->addWidget(label_4);


        horizontalLayout->addWidget(screenwidget);

        buttonwidgetr = new QWidget(mainwidget);
        buttonwidgetr->setObjectName("buttonwidgetr");
        buttonwidgetr->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"    background: none;\n"
"	border: none;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(buttonwidgetr);
        verticalLayout_3->setObjectName("verticalLayout_3");
        pushButtonR = new QPushButton(buttonwidgetr);
        pushButtonR->setObjectName("pushButtonR");
        pushButtonR->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"    background: none;\n"
"}"));
        pushButtonR->setIconSize(QSize(64, 64));

        verticalLayout_3->addWidget(pushButtonR, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);


        horizontalLayout->addWidget(buttonwidgetr, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);


        verticalLayout->addWidget(mainwidget);

        bottomwidget = new QWidget(centralwidget);
        bottomwidget->setObjectName("bottomwidget");
        bottomwidget->setEnabled(true);
        horizontalLayout_2 = new QHBoxLayout(bottomwidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        bottomleftwidget = new QWidget(bottomwidget);
        bottomleftwidget->setObjectName("bottomleftwidget");
        bottomleftwidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 rgba(29, 95, 181, 0.6), stop: 0.5 rgba(2, 32, 41, 0.1), stop: 1 rgba(29, 95, 181, 0.6));\n"
"	border-radius: 20px; /* Rounded corners */\n"
"	border: 1px solid rgba(0, 0, 0, .5);\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(bottomleftwidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        widget_11 = new QWidget(bottomleftwidget);
        widget_11->setObjectName("widget_11");
        widget_11->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background: none;\n"
"	border: none;\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(widget_11);
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_5 = new OptionLabel(widget_11);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("QLabel\n"
" {\n"
"    background: rgba(255, 255, 255, 0.8);\n"
"    border-radius: 20px; /* Rounded corners */\n"
"    \n"
"	padding: 15px;\n"
"	padding-right: 100px;\n"
"	font-size: 32px;\n"
" 	text-align: center; /* Horizontal center */\n"
"	color: #000000;\n"
"    font-family: Roboto, sans-serif;\n"
"    font-size: 18pt;\n"
"	letter-spacing: 2px; /* Adds space between characters */\n"
"    font-weight: 500; \n"
"}"));

        verticalLayout_5->addWidget(label_5, 0, Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        label_6 = new OptionLabel(widget_11);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("QLabel\n"
" {\n"
"    background: rgba(255, 255, 255, 0.8);\n"
"    border-radius: 20px; /* Rounded corners */\n"
"    \n"
"	padding: 15px;\n"
"	padding-right: 100px;\n"
"	font-size: 32px;\n"
" 	text-align: center; /* Horizontal center */\n"
"	color: #000000;\n"
"    font-family: Roboto, sans-serif;\n"
"    font-size: 18pt;\n"
"	letter-spacing: 2px; /* Adds space between characters */\n"
"    font-weight: 500; \n"
"}"));

        verticalLayout_5->addWidget(label_6);

        label_7 = new OptionLabel(widget_11);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("QLabel\n"
" {\n"
"    background: rgba(255, 255, 255, 0.8);\n"
"    border-radius: 20px; /* Rounded corners */\n"
"    \n"
"	padding: 15px;\n"
"	padding-right: 100px;\n"
"	font-size: 32px;\n"
" 	text-align: center; /* Horizontal center */\n"
"	color: #000000;\n"
"    font-family: Roboto, sans-serif;\n"
"    font-size: 18pt;\n"
"	letter-spacing: 2px; /* Adds space between characters */\n"
"    font-weight: 500; \n"
"}"));

        verticalLayout_5->addWidget(label_7);

        label_8 = new OptionLabel(widget_11);
        label_8->setObjectName("label_8");
        label_8->setStyleSheet(QString::fromUtf8("QLabel\n"
" {\n"
"    background: rgba(255, 255, 255, 0.8);\n"
"    border-radius: 20px; /* Rounded corners */\n"
"    \n"
"	padding: 15px;\n"
"	padding-right: 100px;\n"
"	font-size: 32px;\n"
" 	text-align: center; /* Horizontal center */\n"
"	color: #000000;\n"
"    font-family: Roboto, sans-serif;\n"
"    font-size: 18pt;\n"
"	letter-spacing: 2px; /* Adds space between characters */\n"
"    font-weight: 500; \n"
"}"));

        verticalLayout_5->addWidget(label_8);


        horizontalLayout_3->addWidget(widget_11, 0, Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);


        horizontalLayout_2->addWidget(bottomleftwidget);

        bottomrightwidget = new QWidget(bottomwidget);
        bottomrightwidget->setObjectName("bottomrightwidget");
        bottomrightwidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 rgba(29, 95, 181, 0.6), stop: 0.5 rgba(2, 32, 41, 0.1), stop: 1 rgba(29, 95, 181, 0.6));\n"
"	border-radius: 20px; /* Rounded corners */\n"
"	border: 1px solid rgba(0, 0, 0, .5);\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(bottomrightwidget);
        horizontalLayout_5->setObjectName("horizontalLayout_5");

        horizontalLayout_2->addWidget(bottomrightwidget);


        verticalLayout->addWidget(bottomwidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonL->setText(QString());
        label_1->setText(QCoreApplication::translate("MainWindow", "Home Screen", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "This will change", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "This will change", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButtonR->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Suggestions", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Scenario", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Charts", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Alerts", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
