/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *mainDisplay;
    QLabel *exDisplay;
    QGridLayout *gridLayout;
    QPushButton *button4;
    QPushButton *buttonDivide;
    QPushButton *buttonInv;
    QPushButton *buttonEquals;
    QPushButton *buttonDot;
    QPushButton *button1;
    QPushButton *buttonPlus;
    QPushButton *buttonClear;
    QPushButton *button8;
    QPushButton *button2;
    QPushButton *buttonMultiply;
    QPushButton *button0;
    QPushButton *button6;
    QPushButton *buttonMinus;
    QPushButton *buttonSqr;
    QPushButton *buttonPM;
    QPushButton *buttonSqrt;
    QPushButton *button3;
    QPushButton *button7;
    QPushButton *button9;
    QPushButton *buttonBackspace;
    QPushButton *button5;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(320, 440);
        MainWindow->setMinimumSize(QSize(300, 420));
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow#MainWindow {\n"
"    background-color: #1E1E1E;   /* Dark gray background for the main window */\n"
"}\n"
"\n"
"QPushButton {\n"
"    border-radius: 8px;              /* Rounded corners */\n"
"    border: 0.5px solid #434343;  /* Button border */\n"
"    background-color: #3C3C3C;        /* Button background color */\n"
"    color: #FFFFFF;                   /* Text color */\n"
"    padding: 0px;                    /* Internal padding */\n"
"}\n"
"\n"
"\n"
"QPushButton {\n"
"    margin: 5px;                      /* External margin between buttons */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 1px solid #414141;  /* Change border color on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    border: 1px solid #3a3a3a;  /* Change border color on press */\n"
"}\n"
"\n"
"/* Special style for QPushButton with objectName 'buttonEquals' */\n"
"QPushButton#buttonEquals {\n"
"	background-color: #DB9EE5;  /* Custom background for buttonEquals */\n"
"	color: #000000;  /* Black text color for buttonEqua"
                        "ls */\n"
"	border: 1px solid #dea5e7;  /* White border for normal state */\n"
"}\n"
"\n"
"QPushButton#buttonEquals:hover {\n"
"    border: 1px solid #a97eaf;  /* White border on hover */\n"
"}\n"
"\n"
"QPushButton#buttonEquals:pressed {\n"
"    border: 1px solid #a97eaf;  /* White border on press */\n"
"}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(230, 83));
        widget->setSizeIncrement(QSize(0, 0));
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QString::fromUtf8("background-color: #2D2D2D\n"
""));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 9, 9, 6);
        mainDisplay = new QLabel(widget);
        mainDisplay->setObjectName("mainDisplay");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mainDisplay->sizePolicy().hasHeightForWidth());
        mainDisplay->setSizePolicy(sizePolicy2);
        mainDisplay->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(26);
        font.setWeight(QFont::DemiBold);
        mainDisplay->setFont(font);
        mainDisplay->setStyleSheet(QString::fromUtf8("QLabel#mainDisplay {\n"
"    color: white;\n"
"}\n"
""));
        mainDisplay->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTop|Qt::AlignmentFlag::AlignTrailing);
        mainDisplay->setWordWrap(false);
        mainDisplay->setMargin(0);
        mainDisplay->setIndent(-1);

        gridLayout_2->addWidget(mainDisplay, 1, 0, 1, 1);

        exDisplay = new QLabel(widget);
        exDisplay->setObjectName("exDisplay");
        sizePolicy2.setHeightForWidth(exDisplay->sizePolicy().hasHeightForWidth());
        exDisplay->setSizePolicy(sizePolicy2);
        exDisplay->setStyleSheet(QString::fromUtf8("QLabel#exDisplay {\n"
"    color: #BCBCBC;\n"
"}\n"
""));
        exDisplay->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing);
        exDisplay->setMargin(1);
        exDisplay->setIndent(2);

        gridLayout_2->addWidget(exDisplay, 0, 0, 1, 1);


        verticalLayout_2->addWidget(widget);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(1);
        gridLayout->setObjectName("gridLayout");
        button4 = new QPushButton(centralwidget);
        button4->setObjectName("button4");
        sizePolicy.setHeightForWidth(button4->sizePolicy().hasHeightForWidth());
        button4->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(16);
        font1.setWeight(QFont::Medium);
        button4->setFont(font1);

        gridLayout->addWidget(button4, 3, 0, 1, 1);

        buttonDivide = new QPushButton(centralwidget);
        buttonDivide->setObjectName("buttonDivide");
        sizePolicy.setHeightForWidth(buttonDivide->sizePolicy().hasHeightForWidth());
        buttonDivide->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI Symbol")});
        font2.setPointSize(17);
        font2.setWeight(QFont::Medium);
        buttonDivide->setFont(font2);

        gridLayout->addWidget(buttonDivide, 2, 3, 1, 1);

        buttonInv = new QPushButton(centralwidget);
        buttonInv->setObjectName("buttonInv");
        sizePolicy.setHeightForWidth(buttonInv->sizePolicy().hasHeightForWidth());
        buttonInv->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI Symbol")});
        font3.setPointSize(11);
        font3.setWeight(QFont::Medium);
        font3.setItalic(false);
        buttonInv->setFont(font3);

        gridLayout->addWidget(buttonInv, 1, 0, 1, 1);

        buttonEquals = new QPushButton(centralwidget);
        buttonEquals->setObjectName("buttonEquals");
        sizePolicy.setHeightForWidth(buttonEquals->sizePolicy().hasHeightForWidth());
        buttonEquals->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Segoe UI Symbol")});
        font4.setPointSize(16);
        font4.setBold(false);
        buttonEquals->setFont(font4);
        buttonEquals->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(buttonEquals, 5, 3, 1, 1);

        buttonDot = new QPushButton(centralwidget);
        buttonDot->setObjectName("buttonDot");
        sizePolicy.setHeightForWidth(buttonDot->sizePolicy().hasHeightForWidth());
        buttonDot->setSizePolicy(sizePolicy);
        buttonDot->setFont(font1);

        gridLayout->addWidget(buttonDot, 5, 2, 1, 1);

        button1 = new QPushButton(centralwidget);
        button1->setObjectName("button1");
        sizePolicy.setHeightForWidth(button1->sizePolicy().hasHeightForWidth());
        button1->setSizePolicy(sizePolicy);
        button1->setFont(font1);

        gridLayout->addWidget(button1, 4, 0, 1, 1);

        buttonPlus = new QPushButton(centralwidget);
        buttonPlus->setObjectName("buttonPlus");
        sizePolicy.setHeightForWidth(buttonPlus->sizePolicy().hasHeightForWidth());
        buttonPlus->setSizePolicy(sizePolicy);
        buttonPlus->setMinimumSize(QSize(5, 10));
        buttonPlus->setFont(font2);

        gridLayout->addWidget(buttonPlus, 4, 3, 1, 1);

        buttonClear = new QPushButton(centralwidget);
        buttonClear->setObjectName("buttonClear");
        sizePolicy.setHeightForWidth(buttonClear->sizePolicy().hasHeightForWidth());
        buttonClear->setSizePolicy(sizePolicy);
        buttonClear->setFont(font1);

        gridLayout->addWidget(buttonClear, 0, 2, 1, 1);

        button8 = new QPushButton(centralwidget);
        button8->setObjectName("button8");
        sizePolicy.setHeightForWidth(button8->sizePolicy().hasHeightForWidth());
        button8->setSizePolicy(sizePolicy);
        button8->setFont(font1);

        gridLayout->addWidget(button8, 2, 1, 1, 1);

        button2 = new QPushButton(centralwidget);
        button2->setObjectName("button2");
        sizePolicy.setHeightForWidth(button2->sizePolicy().hasHeightForWidth());
        button2->setSizePolicy(sizePolicy);
        button2->setFont(font1);

        gridLayout->addWidget(button2, 4, 1, 1, 1);

        buttonMultiply = new QPushButton(centralwidget);
        buttonMultiply->setObjectName("buttonMultiply");
        sizePolicy.setHeightForWidth(buttonMultiply->sizePolicy().hasHeightForWidth());
        buttonMultiply->setSizePolicy(sizePolicy);
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Segoe UI")});
        font5.setPointSize(17);
        font5.setWeight(QFont::Medium);
        buttonMultiply->setFont(font5);

        gridLayout->addWidget(buttonMultiply, 1, 3, 1, 1);

        button0 = new QPushButton(centralwidget);
        button0->setObjectName("button0");
        sizePolicy.setHeightForWidth(button0->sizePolicy().hasHeightForWidth());
        button0->setSizePolicy(sizePolicy);
        button0->setFont(font1);

        gridLayout->addWidget(button0, 5, 1, 1, 1);

        button6 = new QPushButton(centralwidget);
        button6->setObjectName("button6");
        sizePolicy.setHeightForWidth(button6->sizePolicy().hasHeightForWidth());
        button6->setSizePolicy(sizePolicy);
        button6->setFont(font1);

        gridLayout->addWidget(button6, 3, 2, 1, 1);

        buttonMinus = new QPushButton(centralwidget);
        buttonMinus->setObjectName("buttonMinus");
        sizePolicy.setHeightForWidth(buttonMinus->sizePolicy().hasHeightForWidth());
        buttonMinus->setSizePolicy(sizePolicy);
        buttonMinus->setFont(font2);

        gridLayout->addWidget(buttonMinus, 3, 3, 1, 1);

        buttonSqr = new QPushButton(centralwidget);
        buttonSqr->setObjectName("buttonSqr");
        sizePolicy.setHeightForWidth(buttonSqr->sizePolicy().hasHeightForWidth());
        buttonSqr->setSizePolicy(sizePolicy);
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Segoe UI")});
        font6.setPointSize(12);
        font6.setWeight(QFont::Medium);
        buttonSqr->setFont(font6);

        gridLayout->addWidget(buttonSqr, 1, 1, 1, 1);

        buttonPM = new QPushButton(centralwidget);
        buttonPM->setObjectName("buttonPM");
        sizePolicy.setHeightForWidth(buttonPM->sizePolicy().hasHeightForWidth());
        buttonPM->setSizePolicy(sizePolicy);
        buttonPM->setFont(font1);

        gridLayout->addWidget(buttonPM, 5, 0, 1, 1);

        buttonSqrt = new QPushButton(centralwidget);
        buttonSqrt->setObjectName("buttonSqrt");
        sizePolicy.setHeightForWidth(buttonSqrt->sizePolicy().hasHeightForWidth());
        buttonSqrt->setSizePolicy(sizePolicy);
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Segoe UI")});
        font7.setPointSize(14);
        font7.setWeight(QFont::Medium);
        font7.setItalic(false);
        buttonSqrt->setFont(font7);

        gridLayout->addWidget(buttonSqrt, 1, 2, 1, 1);

        button3 = new QPushButton(centralwidget);
        button3->setObjectName("button3");
        sizePolicy.setHeightForWidth(button3->sizePolicy().hasHeightForWidth());
        button3->setSizePolicy(sizePolicy);
        button3->setFont(font1);
        button3->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(button3, 4, 2, 1, 1);

        button7 = new QPushButton(centralwidget);
        button7->setObjectName("button7");
        sizePolicy.setHeightForWidth(button7->sizePolicy().hasHeightForWidth());
        button7->setSizePolicy(sizePolicy);
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Segoe UI")});
        font8.setPointSize(16);
        font8.setBold(false);
        button7->setFont(font8);

        gridLayout->addWidget(button7, 2, 0, 1, 1);

        button9 = new QPushButton(centralwidget);
        button9->setObjectName("button9");
        sizePolicy.setHeightForWidth(button9->sizePolicy().hasHeightForWidth());
        button9->setSizePolicy(sizePolicy);
        button9->setFont(font1);

        gridLayout->addWidget(button9, 2, 2, 1, 1);

        buttonBackspace = new QPushButton(centralwidget);
        buttonBackspace->setObjectName("buttonBackspace");
        sizePolicy.setHeightForWidth(buttonBackspace->sizePolicy().hasHeightForWidth());
        buttonBackspace->setSizePolicy(sizePolicy);
        buttonBackspace->setFont(font1);

        gridLayout->addWidget(buttonBackspace, 0, 3, 1, 1);

        button5 = new QPushButton(centralwidget);
        button5->setObjectName("button5");
        sizePolicy.setHeightForWidth(button5->sizePolicy().hasHeightForWidth());
        button5->setSizePolicy(sizePolicy);
        button5->setFont(font1);

        gridLayout->addWidget(button5, 3, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 320, 17));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        mainDisplay->setText(QCoreApplication::translate("MainWindow", " 0", nullptr));
        exDisplay->setText(QString());
        button4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        buttonDivide->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        buttonInv->setText(QCoreApplication::translate("MainWindow", "1/\360\235\223\215", nullptr));
        buttonEquals->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        buttonDot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        button1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        buttonPlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        buttonClear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        button8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        button2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        buttonMultiply->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
        button0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        button6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        buttonMinus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        buttonSqr->setText(QCoreApplication::translate("MainWindow", "\360\235\223\215\302\262", nullptr));
        buttonPM->setText(QCoreApplication::translate("MainWindow", "\342\201\272/\342\202\213", nullptr));
        buttonSqrt->setText(QCoreApplication::translate("MainWindow", "\342\210\232", nullptr));
        button3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        button7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        button9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        buttonBackspace->setText(QCoreApplication::translate("MainWindow", "\342\214\253", nullptr));
        button5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
