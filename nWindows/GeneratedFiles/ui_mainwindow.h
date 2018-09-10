/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *widget_2;
    QLabel *colorwindow;
    QWidget *LCDwidget;
    QLCDNumber *lcdNumber_y;
    QLCDNumber *lcdNumber_x;
    QLCDNumber *lcdNumber_z;
    QListWidget *listWidget_alljoint;
    QPushButton *pushButton;
    QPushButton *saveImageButton;
    QPushButton *saveImageButton_2;
    QWidget *tab_2;
    QPushButton *pushButton_realtimedata;
    QPushButton *pushButton_openrecord;
    QScrollArea *chartscrollArea;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *chartscrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QScrollArea *chartscrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QLCDNumber *lcdNumber_date;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1240, 726);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral("background-color:#464652;color:#E8E8E8"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 20, 1200, 590));
        tabWidget->setStyleSheet(QLatin1String("QTabBar::tab{\n"
"             border-top-left-radius: 4px;\n"
"             border-top-right-radius: 4px;\n"
"             min-width:100px; min-height:25px;\n"
"             font:20px Times New Roman;\n"
"             padding:4px;\n"
"             }\n"
"QTabBar::tab:!selected { margin-top: 0px; margin-left: 30;}\n"
"QTabBar::tab:selected {color: white}\n"
"QTabBar::tab:hover:!selected {color: rgb(0, 170, 127); }\n"
"\n"
"QTabBar::tab:selected {margin-left: 30;}\n"
"\n"
"\n"
""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        widget_2 = new QWidget(tab);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(20, 70, 941, 435));
        widget_2->setStyleSheet(QLatin1String("background-color: rgb(59, 65, 72);\n"
"border-radius: 20px"));
        colorwindow = new QLabel(widget_2);
        colorwindow->setObjectName(QStringLiteral("colorwindow"));
        colorwindow->setGeometry(QRect(200, 5, 512, 424));
        colorwindow->setStyleSheet(QStringLiteral("background-color: rgb(100, 104, 97);"));
        LCDwidget = new QWidget(widget_2);
        LCDwidget->setObjectName(QStringLiteral("LCDwidget"));
        LCDwidget->setGeometry(QRect(730, 10, 201, 411));
        LCDwidget->setStyleSheet(QLatin1String("QWidget{border-radius: 10px}\n"
"\n"
"QWidget::!hover{\n"
"background-color: rgb(76, 120, 65)}\n"
"\n"
"QWidget::hover{\n"
"background-color: rgb(76, 120, 65)}"));
        lcdNumber_y = new QLCDNumber(LCDwidget);
        lcdNumber_y->setObjectName(QStringLiteral("lcdNumber_y"));
        lcdNumber_y->setGeometry(QRect(20, 180, 161, 61));
        lcdNumber_y->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        lcdNumber_x = new QLCDNumber(LCDwidget);
        lcdNumber_x->setObjectName(QStringLiteral("lcdNumber_x"));
        lcdNumber_x->setGeometry(QRect(20, 59, 161, 61));
        lcdNumber_x->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        lcdNumber_z = new QLCDNumber(LCDwidget);
        lcdNumber_z->setObjectName(QStringLiteral("lcdNumber_z"));
        lcdNumber_z->setGeometry(QRect(20, 300, 161, 61));
        lcdNumber_z->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        listWidget_alljoint = new QListWidget(widget_2);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        new QListWidgetItem(listWidget_alljoint);
        listWidget_alljoint->setObjectName(QStringLiteral("listWidget_alljoint"));
        listWidget_alljoint->setGeometry(QRect(20, 7, 160, 420));
        QFont font;
        font.setPointSize(12);
        listWidget_alljoint->setFont(font);
        listWidget_alljoint->setStyleSheet(QLatin1String("background-color: rgb(76, 120, 65);\n"
"border-radius:10px;"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1090, 90, 71, 31));
        pushButton->setStyleSheet(QLatin1String("QPushButton{border-radius: 10px}\n"
"\n"
"QPushButton::!hover{\n"
"background-color: rgb(105, 165, 90)}\n"
"\n"
"QPushButton::hover{\n"
"background-color: rgb(76, 120, 65)}\n"
""));
        saveImageButton = new QPushButton(tab);
        saveImageButton->setObjectName(QStringLiteral("saveImageButton"));
        saveImageButton->setGeometry(QRect(1090, 170, 71, 31));
        saveImageButton->setStyleSheet(QLatin1String("QPushButton{border-radius: 10px}\n"
"\n"
"QPushButton::!hover{\n"
"background-color: rgb(105, 165, 90)}\n"
"\n"
"QPushButton::hover{\n"
"background-color: rgb(76, 120, 65)}"));
        saveImageButton_2 = new QPushButton(tab);
        saveImageButton_2->setObjectName(QStringLiteral("saveImageButton_2"));
        saveImageButton_2->setGeometry(QRect(1090, 130, 71, 31));
        saveImageButton_2->setStyleSheet(QLatin1String("QPushButton{border-radius: 10px}\n"
"\n"
"QPushButton::!hover{\n"
"background-color: rgb(105, 165, 90)}\n"
"\n"
"QPushButton::hover{\n"
"background-color: rgb(76, 120, 65)}"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        pushButton_realtimedata = new QPushButton(tab_2);
        pushButton_realtimedata->setObjectName(QStringLiteral("pushButton_realtimedata"));
        pushButton_realtimedata->setGeometry(QRect(1090, 70, 70, 30));
        pushButton_realtimedata->setStyleSheet(QLatin1String("QPushButton{border-radius: 10px}\n"
"\n"
"QPushButton::!hover{\n"
"background-color: rgb(105, 165, 90)}\n"
"\n"
"QPushButton::hover{\n"
"background-color: rgb(76, 120, 65)}\n"
""));
        pushButton_openrecord = new QPushButton(tab_2);
        pushButton_openrecord->setObjectName(QStringLiteral("pushButton_openrecord"));
        pushButton_openrecord->setGeometry(QRect(1090, 110, 70, 30));
        pushButton_openrecord->setStyleSheet(QLatin1String("QPushButton{border-radius: 10px}\n"
"\n"
"QPushButton::!hover{\n"
"background-color: rgb(105, 165, 90)}\n"
"\n"
"QPushButton::hover{\n"
"background-color: rgb(76, 120, 65)}\n"
""));
        chartscrollArea = new QScrollArea(tab_2);
        chartscrollArea->setObjectName(QStringLiteral("chartscrollArea"));
        chartscrollArea->setGeometry(QRect(150, 30, 750, 141));
        chartscrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 748, 139));
        chartscrollArea->setWidget(scrollAreaWidgetContents);
        chartscrollArea_2 = new QScrollArea(tab_2);
        chartscrollArea_2->setObjectName(QStringLiteral("chartscrollArea_2"));
        chartscrollArea_2->setGeometry(QRect(150, 190, 750, 141));
        chartscrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 748, 139));
        chartscrollArea_2->setWidget(scrollAreaWidgetContents_2);
        chartscrollArea_3 = new QScrollArea(tab_2);
        chartscrollArea_3->setObjectName(QStringLiteral("chartscrollArea_3"));
        chartscrollArea_3->setGeometry(QRect(150, 360, 750, 141));
        chartscrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 748, 139));
        chartscrollArea_3->setWidget(scrollAreaWidgetContents_3);
        tabWidget->addTab(tab_2, QString());
        lcdNumber_date = new QLCDNumber(centralWidget);
        lcdNumber_date->setObjectName(QStringLiteral("lcdNumber_date"));
        lcdNumber_date->setGeometry(QRect(1020, 630, 201, 21));
        lcdNumber_date->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1240, 23));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);
        QObject::connect(listWidget_alljoint, SIGNAL(currentRowChanged(int)), MainWindowClass, SLOT(ListCurChange(int)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", nullptr));
        colorwindow->setText(QString());

        const bool __sortingEnabled = listWidget_alljoint->isSortingEnabled();
        listWidget_alljoint->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_alljoint->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindowClass", "SpinBase", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_alljoint->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindowClass", "SpinMid", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_alljoint->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindowClass", "Neck", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget_alljoint->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MainWindowClass", "Head", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget_alljoint->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("MainWindowClass", "ShoulderLeft", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget_alljoint->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("MainWindowClass", "ElbowLeft", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget_alljoint->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("MainWindowClass", "WristLeft", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = listWidget_alljoint->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("MainWindowClass", "HandLeft", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = listWidget_alljoint->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("MainWindowClass", "ShoulderRight", nullptr));
        QListWidgetItem *___qlistwidgetitem9 = listWidget_alljoint->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("MainWindowClass", "ElbowRight", nullptr));
        QListWidgetItem *___qlistwidgetitem10 = listWidget_alljoint->item(10);
        ___qlistwidgetitem10->setText(QApplication::translate("MainWindowClass", "WristRight", nullptr));
        QListWidgetItem *___qlistwidgetitem11 = listWidget_alljoint->item(11);
        ___qlistwidgetitem11->setText(QApplication::translate("MainWindowClass", "HandRight", nullptr));
        QListWidgetItem *___qlistwidgetitem12 = listWidget_alljoint->item(12);
        ___qlistwidgetitem12->setText(QApplication::translate("MainWindowClass", "HipLeft", nullptr));
        QListWidgetItem *___qlistwidgetitem13 = listWidget_alljoint->item(13);
        ___qlistwidgetitem13->setText(QApplication::translate("MainWindowClass", "KneeLeft", nullptr));
        QListWidgetItem *___qlistwidgetitem14 = listWidget_alljoint->item(14);
        ___qlistwidgetitem14->setText(QApplication::translate("MainWindowClass", "AnkeLeft", nullptr));
        QListWidgetItem *___qlistwidgetitem15 = listWidget_alljoint->item(15);
        ___qlistwidgetitem15->setText(QApplication::translate("MainWindowClass", "FootLeft", nullptr));
        QListWidgetItem *___qlistwidgetitem16 = listWidget_alljoint->item(16);
        ___qlistwidgetitem16->setText(QApplication::translate("MainWindowClass", "HipRight", nullptr));
        QListWidgetItem *___qlistwidgetitem17 = listWidget_alljoint->item(17);
        ___qlistwidgetitem17->setText(QApplication::translate("MainWindowClass", "KneeRight", nullptr));
        QListWidgetItem *___qlistwidgetitem18 = listWidget_alljoint->item(18);
        ___qlistwidgetitem18->setText(QApplication::translate("MainWindowClass", "AnkleRight", nullptr));
        QListWidgetItem *___qlistwidgetitem19 = listWidget_alljoint->item(19);
        ___qlistwidgetitem19->setText(QApplication::translate("MainWindowClass", "FootRight", nullptr));
        QListWidgetItem *___qlistwidgetitem20 = listWidget_alljoint->item(20);
        ___qlistwidgetitem20->setText(QApplication::translate("MainWindowClass", "SpineShouder", nullptr));
        QListWidgetItem *___qlistwidgetitem21 = listWidget_alljoint->item(21);
        ___qlistwidgetitem21->setText(QApplication::translate("MainWindowClass", "HandTipLeft", nullptr));
        QListWidgetItem *___qlistwidgetitem22 = listWidget_alljoint->item(22);
        ___qlistwidgetitem22->setText(QApplication::translate("MainWindowClass", "ThumbLeft", nullptr));
        QListWidgetItem *___qlistwidgetitem23 = listWidget_alljoint->item(23);
        ___qlistwidgetitem23->setText(QApplication::translate("MainWindowClass", "HandTipRight", nullptr));
        QListWidgetItem *___qlistwidgetitem24 = listWidget_alljoint->item(24);
        ___qlistwidgetitem24->setText(QApplication::translate("MainWindowClass", "ThumbRight", nullptr));
        listWidget_alljoint->setSortingEnabled(__sortingEnabled);

        pushButton->setText(QApplication::translate("MainWindowClass", "START", nullptr));
        saveImageButton->setText(QApplication::translate("MainWindowClass", "SAVE", nullptr));
        saveImageButton_2->setText(QApplication::translate("MainWindowClass", "STOP", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindowClass", "View", nullptr));
        pushButton_realtimedata->setText(QApplication::translate("MainWindowClass", "RealTime", nullptr));
        pushButton_openrecord->setText(QApplication::translate("MainWindowClass", "OpenRecord", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindowClass", "Charts", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
