/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QPushButton *LockButton;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *Button_7;
    QPushButton *Button_8;
    QPushButton *Button_9;
    QPushButton *Button_4;
    QPushButton *Button_5;
    QPushButton *Button_6;
    QPushButton *Button_1;
    QPushButton *Button_2;
    QPushButton *Button_3;
    QPushButton *Button_10;
    QPushButton *Button_0;
    QPushButton *BackButton;
    QLabel *LockLight;
    QLabel *ConnectLight;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(342, 542);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(40, 54, 261, 41));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));
        LockButton = new QPushButton(centralwidget);
        LockButton->setObjectName(QString::fromUtf8("LockButton"));
        LockButton->setGeometry(QRect(130, 380, 80, 80));
        sizePolicy.setHeightForWidth(LockButton->sizePolicy().hasHeightForWidth());
        LockButton->setSizePolicy(sizePolicy);
        LockButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(114, 159, 207);\n"
"color:white;\n"
"border-radius:40px;\n"
"border:2px groove gray;\n"
"border-style:outset;\n"
"}\n"
"\n"
"QPushButton\357\274\232hover{\n"
"	background-color: rgb(153, 202, 238);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"    \n"
"	background-color: rgb(52, 101, 164);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("icon/Button1.png"), QSize(), QIcon::Normal, QIcon::Off);
        LockButton->setIcon(icon);
        LockButton->setIconSize(QSize(60, 60));
        LockButton->setCheckable(false);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 110, 261, 251));
        sizePolicy.setHeightForWidth(layoutWidget->sizePolicy().hasHeightForWidth());
        layoutWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Button_7 = new QPushButton(layoutWidget);
        Button_7->setObjectName(QString::fromUtf8("Button_7"));
        sizePolicy.setHeightForWidth(Button_7->sizePolicy().hasHeightForWidth());
        Button_7->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Button_7, 0, 0, 1, 1);

        Button_8 = new QPushButton(layoutWidget);
        Button_8->setObjectName(QString::fromUtf8("Button_8"));
        sizePolicy.setHeightForWidth(Button_8->sizePolicy().hasHeightForWidth());
        Button_8->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Button_8, 0, 1, 1, 1);

        Button_9 = new QPushButton(layoutWidget);
        Button_9->setObjectName(QString::fromUtf8("Button_9"));
        sizePolicy.setHeightForWidth(Button_9->sizePolicy().hasHeightForWidth());
        Button_9->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Button_9, 0, 2, 1, 1);

        Button_4 = new QPushButton(layoutWidget);
        Button_4->setObjectName(QString::fromUtf8("Button_4"));
        sizePolicy.setHeightForWidth(Button_4->sizePolicy().hasHeightForWidth());
        Button_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Button_4, 1, 0, 1, 1);

        Button_5 = new QPushButton(layoutWidget);
        Button_5->setObjectName(QString::fromUtf8("Button_5"));
        sizePolicy.setHeightForWidth(Button_5->sizePolicy().hasHeightForWidth());
        Button_5->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Button_5, 1, 1, 1, 1);

        Button_6 = new QPushButton(layoutWidget);
        Button_6->setObjectName(QString::fromUtf8("Button_6"));
        sizePolicy.setHeightForWidth(Button_6->sizePolicy().hasHeightForWidth());
        Button_6->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Button_6, 1, 2, 1, 1);

        Button_1 = new QPushButton(layoutWidget);
        Button_1->setObjectName(QString::fromUtf8("Button_1"));
        sizePolicy.setHeightForWidth(Button_1->sizePolicy().hasHeightForWidth());
        Button_1->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Button_1, 2, 0, 1, 1);

        Button_2 = new QPushButton(layoutWidget);
        Button_2->setObjectName(QString::fromUtf8("Button_2"));
        sizePolicy.setHeightForWidth(Button_2->sizePolicy().hasHeightForWidth());
        Button_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Button_2, 2, 1, 1, 1);

        Button_3 = new QPushButton(layoutWidget);
        Button_3->setObjectName(QString::fromUtf8("Button_3"));
        sizePolicy.setHeightForWidth(Button_3->sizePolicy().hasHeightForWidth());
        Button_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Button_3, 2, 2, 1, 1);

        Button_10 = new QPushButton(layoutWidget);
        Button_10->setObjectName(QString::fromUtf8("Button_10"));
        sizePolicy.setHeightForWidth(Button_10->sizePolicy().hasHeightForWidth());
        Button_10->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Button_10, 3, 0, 1, 1);

        Button_0 = new QPushButton(layoutWidget);
        Button_0->setObjectName(QString::fromUtf8("Button_0"));
        sizePolicy.setHeightForWidth(Button_0->sizePolicy().hasHeightForWidth());
        Button_0->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Button_0, 3, 1, 1, 1);

        BackButton = new QPushButton(layoutWidget);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        sizePolicy.setHeightForWidth(BackButton->sizePolicy().hasHeightForWidth());
        BackButton->setSizePolicy(sizePolicy);
        BackButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(BackButton, 3, 2, 1, 1);

        LockLight = new QLabel(centralwidget);
        LockLight->setObjectName(QString::fromUtf8("LockLight"));
        LockLight->setGeometry(QRect(320, 30, 20, 20));
        LockLight->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(239, 41, 41);\n"
"border:2px groove gray;\n"
"border-style:outset;"));
        ConnectLight = new QLabel(centralwidget);
        ConnectLight->setObjectName(QString::fromUtf8("ConnectLight"));
        ConnectLight->setGeometry(QRect(320, 0, 20, 20));
        ConnectLight->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(239, 41, 41);\n"
"border:2px groove gray;\n"
"border-style:outset;"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 342, 28));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        LockButton->setText(QString());
        Button_7->setText(QApplication::translate("MainWindow", "7", nullptr));
        Button_8->setText(QApplication::translate("MainWindow", "8", nullptr));
        Button_9->setText(QApplication::translate("MainWindow", "9", nullptr));
        Button_4->setText(QApplication::translate("MainWindow", "4", nullptr));
        Button_5->setText(QApplication::translate("MainWindow", "5", nullptr));
        Button_6->setText(QApplication::translate("MainWindow", "6", nullptr));
        Button_1->setText(QApplication::translate("MainWindow", "1", nullptr));
        Button_2->setText(QApplication::translate("MainWindow", "2", nullptr));
        Button_3->setText(QApplication::translate("MainWindow", "3", nullptr));
        Button_10->setText(QApplication::translate("MainWindow", "C", nullptr));
        Button_0->setText(QApplication::translate("MainWindow", "0", nullptr));
        BackButton->setText(QApplication::translate("MainWindow", "Back", nullptr));
        LockLight->setText(QString());
        ConnectLight->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
