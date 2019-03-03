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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLCDNumber *lcdNumber_date;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QPushButton *saveImageButton_2;
    QPushButton *saveImageButton;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QListWidget *listWidget_alljoint;
    QLabel *colorwindow;
    QWidget *LCDwidget;
    QLCDNumber *lcdNumber_y;
    QLCDNumber *lcdNumber_x;
    QLCDNumber *lcdNumber_z;
    QLabel *label_text_4;
    QCheckBox *checkBox_2;
    QLCDNumber *lcdNumber_KneeR;
    QLCDNumber *lcdNumber_KneeL;
    QLCDNumber *lcdNumber_ElbowL;
    QLCDNumber *lcdNumber_ElbowR;
    QCheckBox *checkBox;
    QLineEdit *lineEdit_bagX;
    QLineEdit *lineEdit_bagY;
    QLineEdit *lineEdit_bagZ;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_subjectName;
    QPushButton *pushButton_ready;
    QLabel *label_text_2;
    QLineEdit *lineEdit_f;
    QPushButton *pushButton_calibration;
    QLabel *label_text_7;
    QLineEdit *lineEdit_bodyWeight;
    QLabel *label_text_5;
    QLCDNumber *lcdNumber_force;
    QLabel *label_text_6;
    QLCDNumber *lcdNumber_M;
    QLCDNumber *lcdNumber_M_2;
    QLCDNumber *lcdNumber_M_3;
    QPushButton *pushButton_StartRec;
    QPushButton *pushButton_StopRec;
    QWidget *tab_2;
    QPushButton *pushButton_realtimedata;
    QScrollArea *chartscrollArea;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *chartscrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QScrollArea *chartscrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QPushButton *pushButton_openrecord;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1018, 839);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral("background-color:#464652;color:#E8E8E8"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lcdNumber_date = new QLCDNumber(centralWidget);
        lcdNumber_date->setObjectName(QStringLiteral("lcdNumber_date"));
        lcdNumber_date->setMaximumSize(QSize(100, 18));
        lcdNumber_date->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout->addWidget(lcdNumber_date, 3, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(1000, 740));
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
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        saveImageButton_2 = new QPushButton(tab);
        saveImageButton_2->setObjectName(QStringLiteral("saveImageButton_2"));
        saveImageButton_2->setMinimumSize(QSize(31, 21));
        saveImageButton_2->setMaximumSize(QSize(72, 16777215));
        saveImageButton_2->setStyleSheet(QLatin1String("QPushButton{border-radius: 10px}\n"
"\n"
"QPushButton::!hover{\n"
"background-color: rgb(105, 165, 90)}\n"
"\n"
"QPushButton::hover{\n"
"background-color: rgb(76, 120, 65)}"));

        gridLayout_2->addWidget(saveImageButton_2, 0, 0, 1, 1);

        saveImageButton = new QPushButton(tab);
        saveImageButton->setObjectName(QStringLiteral("saveImageButton"));
        saveImageButton->setMinimumSize(QSize(31, 21));
        saveImageButton->setMaximumSize(QSize(72, 16777215));
        saveImageButton->setStyleSheet(QLatin1String("QPushButton{border-radius: 10px}\n"
"\n"
"QPushButton::!hover{\n"
"background-color: rgb(105, 165, 90)}\n"
"\n"
"QPushButton::hover{\n"
"background-color: rgb(76, 120, 65)}"));

        gridLayout_2->addWidget(saveImageButton, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        widget_2 = new QWidget(tab);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(940, 435));
        widget_2->setStyleSheet(QLatin1String("background-color: rgb(59, 65, 72);\n"
"border-radius: 20px"));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
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
        listWidget_alljoint->setMinimumSize(QSize(160, 420));
        listWidget_alljoint->setMaximumSize(QSize(160, 16777215));
        QFont font;
        font.setPointSize(12);
        listWidget_alljoint->setFont(font);
        listWidget_alljoint->setStyleSheet(QLatin1String("background-color: rgb(76, 120, 65);\n"
"border-radius:10px;"));

        gridLayout_3->addWidget(listWidget_alljoint, 0, 0, 1, 1);

        colorwindow = new QLabel(widget_2);
        colorwindow->setObjectName(QStringLiteral("colorwindow"));
        colorwindow->setMinimumSize(QSize(512, 424));
        colorwindow->setStyleSheet(QStringLiteral("background-color: rgb(100, 104, 97);"));

        gridLayout_3->addWidget(colorwindow, 0, 1, 1, 1);

        LCDwidget = new QWidget(widget_2);
        LCDwidget->setObjectName(QStringLiteral("LCDwidget"));
        LCDwidget->setMinimumSize(QSize(200, 400));
        LCDwidget->setMaximumSize(QSize(200, 16777215));
        LCDwidget->setStyleSheet(QLatin1String("QWidget{border-radius: 10px}\n"
"\n"
"QWidget::!hover{\n"
"background-color: rgb(76, 120, 65)}\n"
"\n"
"QWidget::hover{\n"
"background-color: rgb(76, 120, 65)}"));
        lcdNumber_y = new QLCDNumber(LCDwidget);
        lcdNumber_y->setObjectName(QStringLiteral("lcdNumber_y"));
        lcdNumber_y->setGeometry(QRect(20, 100, 161, 61));
        lcdNumber_y->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        lcdNumber_x = new QLCDNumber(LCDwidget);
        lcdNumber_x->setObjectName(QStringLiteral("lcdNumber_x"));
        lcdNumber_x->setGeometry(QRect(20, 30, 161, 61));
        lcdNumber_x->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        lcdNumber_z = new QLCDNumber(LCDwidget);
        lcdNumber_z->setObjectName(QStringLiteral("lcdNumber_z"));
        lcdNumber_z->setGeometry(QRect(20, 170, 161, 61));
        lcdNumber_z->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        label_text_4 = new QLabel(LCDwidget);
        label_text_4->setObjectName(QStringLiteral("label_text_4"));
        label_text_4->setGeometry(QRect(10, 0, 181, 31));
        label_text_4->setStyleSheet(QLatin1String("\n"
"font: 87 10pt \"Arial Black\";\n"
"border-radius: 10px;"));
        label_text_4->setAlignment(Qt::AlignCenter);
        checkBox_2 = new QCheckBox(LCDwidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(20, 260, 101, 16));
        lcdNumber_KneeR = new QLCDNumber(LCDwidget);
        lcdNumber_KneeR->setObjectName(QStringLiteral("lcdNumber_KneeR"));
        lcdNumber_KneeR->setGeometry(QRect(20, 280, 161, 40));
        lcdNumber_KneeR->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        lcdNumber_KneeL = new QLCDNumber(LCDwidget);
        lcdNumber_KneeL->setObjectName(QStringLiteral("lcdNumber_KneeL"));
        lcdNumber_KneeL->setGeometry(QRect(20, 330, 161, 40));
        lcdNumber_KneeL->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        lcdNumber_ElbowL = new QLCDNumber(LCDwidget);
        lcdNumber_ElbowL->setObjectName(QStringLiteral("lcdNumber_ElbowL"));
        lcdNumber_ElbowL->setGeometry(QRect(20, 380, 161, 40));
        lcdNumber_ElbowL->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        lcdNumber_ElbowR = new QLCDNumber(LCDwidget);
        lcdNumber_ElbowR->setObjectName(QStringLiteral("lcdNumber_ElbowR"));
        lcdNumber_ElbowR->setGeometry(QRect(20, 430, 161, 40));
        lcdNumber_ElbowR->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(LCDwidget, 0, 2, 1, 1);


        gridLayout_2->addWidget(widget_2, 1, 0, 1, 10);

        checkBox = new QCheckBox(tab);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setMinimumSize(QSize(90, 30));
        checkBox->setStyleSheet(QLatin1String("background-color: rgb(76, 120, 65);\n"
"font: 87 10pt \"Arial Black\";\n"
"border-radius: 10px;"));

        gridLayout_2->addWidget(checkBox, 2, 0, 1, 1);

        lineEdit_bagX = new QLineEdit(tab);
        lineEdit_bagX->setObjectName(QStringLiteral("lineEdit_bagX"));
        lineEdit_bagX->setMinimumSize(QSize(40, 30));
        lineEdit_bagX->setMaximumSize(QSize(80, 60));
        lineEdit_bagX->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 10pt \"Arial Black\";"));
        lineEdit_bagX->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_bagX, 2, 1, 1, 1);

        lineEdit_bagY = new QLineEdit(tab);
        lineEdit_bagY->setObjectName(QStringLiteral("lineEdit_bagY"));
        lineEdit_bagY->setMinimumSize(QSize(40, 30));
        lineEdit_bagY->setMaximumSize(QSize(80, 60));
        lineEdit_bagY->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 10pt \"Arial Black\";"));
        lineEdit_bagY->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_bagY, 2, 2, 1, 1);

        lineEdit_bagZ = new QLineEdit(tab);
        lineEdit_bagZ->setObjectName(QStringLiteral("lineEdit_bagZ"));
        lineEdit_bagZ->setMinimumSize(QSize(40, 30));
        lineEdit_bagZ->setMaximumSize(QSize(80, 60));
        lineEdit_bagZ->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 10pt \"Arial Black\";"));
        lineEdit_bagZ->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_bagZ, 2, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 4, 1, 1);

        lineEdit_subjectName = new QLineEdit(tab);
        lineEdit_subjectName->setObjectName(QStringLiteral("lineEdit_subjectName"));
        lineEdit_subjectName->setMinimumSize(QSize(121, 31));
        lineEdit_subjectName->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 10pt \"Arial Black\";"));
        lineEdit_subjectName->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_subjectName, 2, 5, 1, 2);

        pushButton_ready = new QPushButton(tab);
        pushButton_ready->setObjectName(QStringLiteral("pushButton_ready"));
        pushButton_ready->setMinimumSize(QSize(71, 31));
        pushButton_ready->setMaximumSize(QSize(72, 16777215));
        pushButton_ready->setStyleSheet(QLatin1String("QPushButton{border-radius: 10px}\n"
"\n"
"QPushButton::!hover{\n"
"background-color: rgb(105, 165, 90)}\n"
"\n"
"QPushButton::hover{\n"
"background-color: rgb(76, 120, 65)}\n"
""));

        gridLayout_2->addWidget(pushButton_ready, 2, 7, 1, 1);

        label_text_2 = new QLabel(tab);
        label_text_2->setObjectName(QStringLiteral("label_text_2"));
        label_text_2->setMinimumSize(QSize(150, 30));
        label_text_2->setStyleSheet(QLatin1String("background-color: rgb(76, 120, 65);\n"
"font: 87 10pt \"Arial Black\";\n"
"border-radius: 10px;"));
        label_text_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_text_2, 3, 0, 1, 1);

        lineEdit_f = new QLineEdit(tab);
        lineEdit_f->setObjectName(QStringLiteral("lineEdit_f"));
        lineEdit_f->setMinimumSize(QSize(121, 31));
        lineEdit_f->setMaximumSize(QSize(121, 31));
        lineEdit_f->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 10pt \"Arial Black\";"));
        lineEdit_f->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_f, 3, 1, 1, 2);

        pushButton_calibration = new QPushButton(tab);
        pushButton_calibration->setObjectName(QStringLiteral("pushButton_calibration"));
        pushButton_calibration->setMinimumSize(QSize(71, 31));
        pushButton_calibration->setMaximumSize(QSize(72, 16777215));
        pushButton_calibration->setStyleSheet(QLatin1String("QPushButton{border-radius: 10px}\n"
"\n"
"QPushButton::!hover{\n"
"background-color: rgb(105, 165, 90)}\n"
"\n"
"QPushButton::hover{\n"
"background-color: rgb(76, 120, 65)}\n"
""));

        gridLayout_2->addWidget(pushButton_calibration, 3, 7, 1, 1);

        label_text_7 = new QLabel(tab);
        label_text_7->setObjectName(QStringLiteral("label_text_7"));
        label_text_7->setMinimumSize(QSize(90, 30));
        label_text_7->setStyleSheet(QLatin1String("background-color: rgb(76, 120, 65);\n"
"font: 87 10pt \"Arial Black\";\n"
"border-radius: 10px;"));
        label_text_7->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_text_7, 4, 0, 1, 1);

        lineEdit_bodyWeight = new QLineEdit(tab);
        lineEdit_bodyWeight->setObjectName(QStringLiteral("lineEdit_bodyWeight"));
        lineEdit_bodyWeight->setMinimumSize(QSize(121, 31));
        lineEdit_bodyWeight->setMaximumSize(QSize(121, 31));
        lineEdit_bodyWeight->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 10pt \"Arial Black\";"));
        lineEdit_bodyWeight->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_bodyWeight, 4, 1, 1, 2);

        label_text_5 = new QLabel(tab);
        label_text_5->setObjectName(QStringLiteral("label_text_5"));
        label_text_5->setStyleSheet(QLatin1String("\n"
"font: 87 10pt \"Arial Black\";\n"
"border-radius: 10px;"));
        label_text_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_text_5, 4, 5, 1, 1);

        lcdNumber_force = new QLCDNumber(tab);
        lcdNumber_force->setObjectName(QStringLiteral("lcdNumber_force"));
        lcdNumber_force->setMinimumSize(QSize(131, 31));
        lcdNumber_force->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(lcdNumber_force, 4, 6, 1, 2);

        label_text_6 = new QLabel(tab);
        label_text_6->setObjectName(QStringLiteral("label_text_6"));
        label_text_6->setStyleSheet(QLatin1String("\n"
"font: 87 10pt \"Arial Black\";\n"
"border-radius: 10px;"));
        label_text_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_text_6, 4, 8, 1, 1);

        lcdNumber_M = new QLCDNumber(tab);
        lcdNumber_M->setObjectName(QStringLiteral("lcdNumber_M"));
        lcdNumber_M->setMinimumSize(QSize(81, 31));
        lcdNumber_M->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(lcdNumber_M, 4, 9, 1, 1);

        lcdNumber_M_2 = new QLCDNumber(tab);
        lcdNumber_M_2->setObjectName(QStringLiteral("lcdNumber_M_2"));
        lcdNumber_M_2->setMinimumSize(QSize(81, 31));
        lcdNumber_M_2->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(lcdNumber_M_2, 4, 10, 1, 1);

        lcdNumber_M_3 = new QLCDNumber(tab);
        lcdNumber_M_3->setObjectName(QStringLiteral("lcdNumber_M_3"));
        lcdNumber_M_3->setMinimumSize(QSize(81, 31));
        lcdNumber_M_3->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(lcdNumber_M_3, 4, 11, 1, 1);

        pushButton_StartRec = new QPushButton(tab);
        pushButton_StartRec->setObjectName(QStringLiteral("pushButton_StartRec"));
        pushButton_StartRec->setMinimumSize(QSize(71, 31));
        pushButton_StartRec->setStyleSheet(QLatin1String("QPushButton{border-radius: 10px}\n"
"\n"
"QPushButton::!hover{\n"
"background-color: rgb(105, 165, 90)}\n"
"\n"
"QPushButton::hover{\n"
"background-color: rgb(76, 120, 65)}"));

        gridLayout_2->addWidget(pushButton_StartRec, 2, 9, 1, 1);

        pushButton_StopRec = new QPushButton(tab);
        pushButton_StopRec->setObjectName(QStringLiteral("pushButton_StopRec"));
        pushButton_StopRec->setMinimumSize(QSize(71, 31));
        pushButton_StopRec->setStyleSheet(QLatin1String("QPushButton{border-radius: 10px}\n"
"\n"
"QPushButton::!hover{background-color: rgb(189, 0, 0)}\n"
"\n"
"\n"
"QPushButton::hover{\n"
"	background-color: rgb(148, 0, 0)}"));

        gridLayout_2->addWidget(pushButton_StopRec, 3, 9, 1, 1);

        tabWidget->addTab(tab, QString());
        widget_2->raise();
        saveImageButton->raise();
        saveImageButton_2->raise();
        lineEdit_f->raise();
        checkBox->raise();
        lineEdit_bagX->raise();
        lineEdit_bagY->raise();
        lineEdit_bagZ->raise();
        lineEdit_bodyWeight->raise();
        lcdNumber_force->raise();
        lcdNumber_M->raise();
        label_text_5->raise();
        label_text_6->raise();
        lcdNumber_M_2->raise();
        lcdNumber_M_3->raise();
        lineEdit_subjectName->raise();
        label_text_7->raise();
        label_text_2->raise();
        pushButton_StartRec->raise();
        pushButton_ready->raise();
        pushButton_StopRec->raise();
        pushButton_calibration->raise();
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
        chartscrollArea_3->setGeometry(QRect(150, 360, 751, 171));
        chartscrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 749, 169));
        chartscrollArea_3->setWidget(scrollAreaWidgetContents_3);
        pushButton_openrecord = new QPushButton(tab_2);
        pushButton_openrecord->setObjectName(QStringLiteral("pushButton_openrecord"));
        pushButton_openrecord->setGeometry(QRect(950, 70, 70, 30));
        pushButton_openrecord->setStyleSheet(QLatin1String("QPushButton{border-radius: 10px}\n"
"\n"
"QPushButton::!hover{\n"
"background-color: rgb(105, 165, 90)}\n"
"\n"
"QPushButton::hover{\n"
"background-color: rgb(76, 120, 65)}\n"
""));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 2, 0, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1018, 23));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);
        QObject::connect(listWidget_alljoint, SIGNAL(currentRowChanged(int)), MainWindowClass, SLOT(ListCurChange(int)));
        QObject::connect(pushButton_StartRec, SIGNAL(clicked()), MainWindowClass, SLOT(startRec()));
        QObject::connect(lineEdit_bodyWeight, SIGNAL(textChanged(QString)), MainWindowClass, SLOT(LineEdit_bodyWeight(QString)));
        QObject::connect(lineEdit_bagX, SIGNAL(textChanged(QString)), MainWindowClass, SLOT(LineEdit_bagX(QString)));
        QObject::connect(lineEdit_bagZ, SIGNAL(textChanged(QString)), MainWindowClass, SLOT(LineEdit_bagZ(QString)));
        QObject::connect(pushButton_StopRec, SIGNAL(clicked()), MainWindowClass, SLOT(stopRec()));
        QObject::connect(lineEdit_bagY, SIGNAL(textChanged(QString)), MainWindowClass, SLOT(LineEdit_bagY(QString)));
        QObject::connect(lineEdit_f, SIGNAL(textChanged(QString)), MainWindowClass, SLOT(LineEdit_f(QString)));
        QObject::connect(checkBox, SIGNAL(clicked(bool)), MainWindowClass, SLOT(bagSelect(bool)));
        QObject::connect(lineEdit_subjectName, SIGNAL(textEdited(QString)), MainWindowClass, SLOT(LineEdit_subjName(QString)));
        QObject::connect(checkBox_2, SIGNAL(clicked(bool)), MainWindowClass, SLOT(SimpleMode(bool)));
        QObject::connect(pushButton_ready, SIGNAL(clicked()), MainWindowClass, SLOT(ready4Rec()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", nullptr));
        saveImageButton_2->setText(QApplication::translate("MainWindowClass", "STOP", nullptr));
        saveImageButton->setText(QApplication::translate("MainWindowClass", "SAVE", nullptr));

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

        colorwindow->setText(QString());
        label_text_4->setText(QApplication::translate("MainWindowClass", "Chosed Joint Angle", nullptr));
        checkBox_2->setText(QApplication::translate("MainWindowClass", "Simple Mode", nullptr));
        checkBox->setText(QApplication::translate("MainWindowClass", "Force Position", nullptr));
        lineEdit_subjectName->setText(QString());
        pushButton_ready->setText(QApplication::translate("MainWindowClass", "Comfirm", nullptr));
        label_text_2->setText(QApplication::translate("MainWindowClass", "Force Magnitude(KG)", nullptr));
        lineEdit_f->setText(QString());
        pushButton_calibration->setText(QApplication::translate("MainWindowClass", "Calibration", nullptr));
        label_text_7->setText(QApplication::translate("MainWindowClass", "Body Weight(KG)", nullptr));
        label_text_5->setText(QApplication::translate("MainWindowClass", "F ->", nullptr));
        label_text_6->setText(QApplication::translate("MainWindowClass", "M ->", nullptr));
        pushButton_StartRec->setText(QApplication::translate("MainWindowClass", "StartREC", nullptr));
        pushButton_StopRec->setText(QApplication::translate("MainWindowClass", "StopREC", nullptr));
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
