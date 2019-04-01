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
#include <QtWidgets/QHBoxLayout>
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
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QWidget *LCDwidget_3;
    QGridLayout *gridLayout_5;
    QCheckBox *checkBox;
    QLineEdit *lineEdit_bagX;
    QLineEdit *lineEdit_bagY;
    QLineEdit *lineEdit_bagZ;
    QLabel *label_text_2;
    QLineEdit *lineEdit_f;
    QLabel *label_text_7;
    QLineEdit *lineEdit_bodyWeight;
    QPushButton *saveImageButton_2;
    QPushButton *saveImageButton;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget_alljoint;
    QLabel *colorwindow;
    QWidget *LCDwidget;
    QGridLayout *gridLayout_3;
    QCheckBox *checkBox_2;
    QLabel *label_6;
    QLabel *label;
    QLCDNumber *lcdNumber_Neckfb;
    QLCDNumber *lcdNumber_ElbowR;
    QLabel *label_7;
    QLabel *label_2;
    QLCDNumber *lcdNumber_Necklr;
    QLCDNumber *lcdNumber_ElbowL;
    QLabel *label_9;
    QLabel *label_4;
    QLCDNumber *lcdNumber_ShoulderR;
    QLCDNumber *lcdNumber_KneeR;
    QLabel *label_8;
    QLabel *label_3;
    QLCDNumber *lcdNumber_ShoulderL;
    QLCDNumber *lcdNumber_KneeL;
    QLabel *label_5;
    QLCDNumber *lcdNumber_Spine;
    QWidget *LCDwidget_4;
    QGridLayout *gridLayout_6;
    QLabel *label_text_5;
    QLCDNumber *lcdNumber_force;
    QLCDNumber *lcdNumber_M;
    QLCDNumber *lcdNumber_M_2;
    QLabel *label_text_6;
    QLCDNumber *lcdNumber_M_3;
    QWidget *LCDwidget_2;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_subjectName;
    QPushButton *pushButton_calibration;
    QPushButton *pushButton_ready;
    QPushButton *pushButton_StartRec;
    QPushButton *pushButton_StopRec;
    QSpacerItem *horizontalSpacer;
    QWidget *tab_3;
    QVTKWidget *qvtkWidget;
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
        MainWindowClass->resize(1181, 765);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral("background-color:#464652;color:#E8E8E8"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
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
        LCDwidget_3 = new QWidget(tab);
        LCDwidget_3->setObjectName(QStringLiteral("LCDwidget_3"));
        sizePolicy.setHeightForWidth(LCDwidget_3->sizePolicy().hasHeightForWidth());
        LCDwidget_3->setSizePolicy(sizePolicy);
        LCDwidget_3->setMinimumSize(QSize(500, 110));
        LCDwidget_3->setStyleSheet(QLatin1String("QWidget{border-radius: 10px}\n"
"\n"
"QWidget::!hover{\n"
"background-color: rgb(59, 65, 72);\n"
"}\n"
"\n"
"\n"
"QWidget::hover{\n"
"background-color: rgb(59, 65, 72)}"));
        gridLayout_5 = new QGridLayout(LCDwidget_3);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        checkBox = new QCheckBox(LCDwidget_3);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy1);
        checkBox->setMinimumSize(QSize(160, 30));
        checkBox->setStyleSheet(QLatin1String("background-color: rgb(76, 120, 65);\n"
"font: 87 10pt \"Arial Black\";\n"
"border-radius: 10px;"));

        gridLayout_5->addWidget(checkBox, 0, 0, 1, 1);

        lineEdit_bagX = new QLineEdit(LCDwidget_3);
        lineEdit_bagX->setObjectName(QStringLiteral("lineEdit_bagX"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_bagX->sizePolicy().hasHeightForWidth());
        lineEdit_bagX->setSizePolicy(sizePolicy2);
        lineEdit_bagX->setMinimumSize(QSize(40, 30));
        lineEdit_bagX->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 10pt \"Arial Black\";"));
        lineEdit_bagX->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lineEdit_bagX, 0, 1, 1, 1);

        lineEdit_bagY = new QLineEdit(LCDwidget_3);
        lineEdit_bagY->setObjectName(QStringLiteral("lineEdit_bagY"));
        sizePolicy2.setHeightForWidth(lineEdit_bagY->sizePolicy().hasHeightForWidth());
        lineEdit_bagY->setSizePolicy(sizePolicy2);
        lineEdit_bagY->setMinimumSize(QSize(80, 30));
        lineEdit_bagY->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 10pt \"Arial Black\";"));
        lineEdit_bagY->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lineEdit_bagY, 0, 2, 1, 1);

        lineEdit_bagZ = new QLineEdit(LCDwidget_3);
        lineEdit_bagZ->setObjectName(QStringLiteral("lineEdit_bagZ"));
        sizePolicy2.setHeightForWidth(lineEdit_bagZ->sizePolicy().hasHeightForWidth());
        lineEdit_bagZ->setSizePolicy(sizePolicy2);
        lineEdit_bagZ->setMinimumSize(QSize(80, 30));
        lineEdit_bagZ->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 10pt \"Arial Black\";"));
        lineEdit_bagZ->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lineEdit_bagZ, 0, 3, 1, 1);

        label_text_2 = new QLabel(LCDwidget_3);
        label_text_2->setObjectName(QStringLiteral("label_text_2"));
        sizePolicy1.setHeightForWidth(label_text_2->sizePolicy().hasHeightForWidth());
        label_text_2->setSizePolicy(sizePolicy1);
        label_text_2->setMinimumSize(QSize(160, 30));
        label_text_2->setStyleSheet(QLatin1String("background-color: rgb(76, 120, 65);\n"
"font: 87 10pt \"Arial Black\";\n"
"border-radius: 10px;"));
        label_text_2->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_text_2, 1, 0, 1, 1);

        lineEdit_f = new QLineEdit(LCDwidget_3);
        lineEdit_f->setObjectName(QStringLiteral("lineEdit_f"));
        sizePolicy2.setHeightForWidth(lineEdit_f->sizePolicy().hasHeightForWidth());
        lineEdit_f->setSizePolicy(sizePolicy2);
        lineEdit_f->setMinimumSize(QSize(80, 31));
        lineEdit_f->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 10pt \"Arial Black\";"));
        lineEdit_f->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lineEdit_f, 1, 1, 1, 1);

        label_text_7 = new QLabel(LCDwidget_3);
        label_text_7->setObjectName(QStringLiteral("label_text_7"));
        sizePolicy1.setHeightForWidth(label_text_7->sizePolicy().hasHeightForWidth());
        label_text_7->setSizePolicy(sizePolicy1);
        label_text_7->setMinimumSize(QSize(160, 30));
        label_text_7->setStyleSheet(QLatin1String("background-color: rgb(76, 120, 65);\n"
"font: 87 10pt \"Arial Black\";\n"
"border-radius: 10px;"));
        label_text_7->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_text_7, 2, 0, 1, 1);

        lineEdit_bodyWeight = new QLineEdit(LCDwidget_3);
        lineEdit_bodyWeight->setObjectName(QStringLiteral("lineEdit_bodyWeight"));
        sizePolicy2.setHeightForWidth(lineEdit_bodyWeight->sizePolicy().hasHeightForWidth());
        lineEdit_bodyWeight->setSizePolicy(sizePolicy2);
        lineEdit_bodyWeight->setMinimumSize(QSize(80, 31));
        lineEdit_bodyWeight->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 10pt \"Arial Black\";"));
        lineEdit_bodyWeight->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lineEdit_bodyWeight, 2, 1, 1, 1);


        gridLayout_2->addWidget(LCDwidget_3, 2, 0, 1, 2);

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

        widget_2 = new QWidget(tab);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(1100, 435));
        widget_2->setStyleSheet(QLatin1String("background-color: rgb(59, 65, 72);\n"
"border-radius: 20px"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
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
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(listWidget_alljoint->sizePolicy().hasHeightForWidth());
        listWidget_alljoint->setSizePolicy(sizePolicy3);
        listWidget_alljoint->setMinimumSize(QSize(160, 420));
        QFont font;
        font.setPointSize(12);
        listWidget_alljoint->setFont(font);
        listWidget_alljoint->setStyleSheet(QLatin1String("background-color: rgb(76, 120, 65);\n"
"border-radius:10px;"));

        horizontalLayout->addWidget(listWidget_alljoint, 0, Qt::AlignLeft);

        colorwindow = new QLabel(widget_2);
        colorwindow->setObjectName(QStringLiteral("colorwindow"));
        sizePolicy.setHeightForWidth(colorwindow->sizePolicy().hasHeightForWidth());
        colorwindow->setSizePolicy(sizePolicy);
        colorwindow->setMinimumSize(QSize(512, 424));
        colorwindow->setStyleSheet(QStringLiteral("background-color: rgb(100, 104, 97);"));

        horizontalLayout->addWidget(colorwindow);

        LCDwidget = new QWidget(widget_2);
        LCDwidget->setObjectName(QStringLiteral("LCDwidget"));
        LCDwidget->setMinimumSize(QSize(400, 400));
        LCDwidget->setMaximumSize(QSize(200, 16777215));
        LCDwidget->setBaseSize(QSize(400, 400));
        LCDwidget->setStyleSheet(QLatin1String("QWidget{border-radius: 10px}\n"
"\n"
"QWidget::!hover{\n"
"background-color: rgb(76, 120, 65)}\n"
"\n"
"QWidget::hover{\n"
"background-color: rgb(76, 120, 65)}"));
        gridLayout_3 = new QGridLayout(LCDwidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        checkBox_2 = new QCheckBox(LCDwidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        sizePolicy2.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy2);
        checkBox_2->setMinimumSize(QSize(141, 16));

        gridLayout_3->addWidget(checkBox_2, 0, 0, 1, 1);

        label_6 = new QLabel(LCDwidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        label = new QLabel(LCDwidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 1, 1, 1, 1);

        lcdNumber_Neckfb = new QLCDNumber(LCDwidget);
        lcdNumber_Neckfb->setObjectName(QStringLiteral("lcdNumber_Neckfb"));
        lcdNumber_Neckfb->setMinimumSize(QSize(161, 40));
        lcdNumber_Neckfb->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(lcdNumber_Neckfb, 2, 0, 1, 1);

        lcdNumber_ElbowR = new QLCDNumber(LCDwidget);
        lcdNumber_ElbowR->setObjectName(QStringLiteral("lcdNumber_ElbowR"));
        lcdNumber_ElbowR->setMinimumSize(QSize(161, 40));
        lcdNumber_ElbowR->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(lcdNumber_ElbowR, 2, 1, 1, 1);

        label_7 = new QLabel(LCDwidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 3, 0, 1, 1);

        label_2 = new QLabel(LCDwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 3, 1, 1, 1);

        lcdNumber_Necklr = new QLCDNumber(LCDwidget);
        lcdNumber_Necklr->setObjectName(QStringLiteral("lcdNumber_Necklr"));
        lcdNumber_Necklr->setMinimumSize(QSize(161, 40));
        lcdNumber_Necklr->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(lcdNumber_Necklr, 4, 0, 1, 1);

        lcdNumber_ElbowL = new QLCDNumber(LCDwidget);
        lcdNumber_ElbowL->setObjectName(QStringLiteral("lcdNumber_ElbowL"));
        lcdNumber_ElbowL->setMinimumSize(QSize(161, 40));
        lcdNumber_ElbowL->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(lcdNumber_ElbowL, 4, 1, 1, 1);

        label_9 = new QLabel(LCDwidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_3->addWidget(label_9, 5, 0, 1, 1);

        label_4 = new QLabel(LCDwidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 5, 1, 1, 1);

        lcdNumber_ShoulderR = new QLCDNumber(LCDwidget);
        lcdNumber_ShoulderR->setObjectName(QStringLiteral("lcdNumber_ShoulderR"));
        lcdNumber_ShoulderR->setMinimumSize(QSize(161, 40));
        lcdNumber_ShoulderR->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(lcdNumber_ShoulderR, 6, 0, 1, 1);

        lcdNumber_KneeR = new QLCDNumber(LCDwidget);
        lcdNumber_KneeR->setObjectName(QStringLiteral("lcdNumber_KneeR"));
        lcdNumber_KneeR->setMinimumSize(QSize(161, 40));
        lcdNumber_KneeR->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(lcdNumber_KneeR, 6, 1, 1, 1);

        label_8 = new QLabel(LCDwidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_3->addWidget(label_8, 7, 0, 1, 1);

        label_3 = new QLabel(LCDwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 7, 1, 1, 1);

        lcdNumber_ShoulderL = new QLCDNumber(LCDwidget);
        lcdNumber_ShoulderL->setObjectName(QStringLiteral("lcdNumber_ShoulderL"));
        lcdNumber_ShoulderL->setMinimumSize(QSize(161, 40));
        lcdNumber_ShoulderL->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(lcdNumber_ShoulderL, 8, 0, 1, 1);

        lcdNumber_KneeL = new QLCDNumber(LCDwidget);
        lcdNumber_KneeL->setObjectName(QStringLiteral("lcdNumber_KneeL"));
        lcdNumber_KneeL->setMinimumSize(QSize(161, 40));
        lcdNumber_KneeL->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(lcdNumber_KneeL, 8, 1, 1, 1);

        label_5 = new QLabel(LCDwidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 9, 0, 1, 1);

        lcdNumber_Spine = new QLCDNumber(LCDwidget);
        lcdNumber_Spine->setObjectName(QStringLiteral("lcdNumber_Spine"));
        lcdNumber_Spine->setMinimumSize(QSize(161, 40));
        lcdNumber_Spine->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(lcdNumber_Spine, 10, 0, 1, 1);


        horizontalLayout->addWidget(LCDwidget);


        gridLayout_2->addWidget(widget_2, 1, 0, 1, 4);

        LCDwidget_4 = new QWidget(tab);
        LCDwidget_4->setObjectName(QStringLiteral("LCDwidget_4"));
        sizePolicy3.setHeightForWidth(LCDwidget_4->sizePolicy().hasHeightForWidth());
        LCDwidget_4->setSizePolicy(sizePolicy3);
        LCDwidget_4->setMinimumSize(QSize(0, 0));
        LCDwidget_4->setBaseSize(QSize(400, 400));
        LCDwidget_4->setStyleSheet(QLatin1String("QWidget{border-radius: 10px}\n"
"\n"
"QWidget::!hover{\n"
"background-color: rgb(59, 65, 72);\n"
"}\n"
"\n"
"\n"
"QWidget::hover{\n"
"background-color: rgb(59, 65, 72)}"));
        gridLayout_6 = new QGridLayout(LCDwidget_4);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_text_5 = new QLabel(LCDwidget_4);
        label_text_5->setObjectName(QStringLiteral("label_text_5"));
        label_text_5->setStyleSheet(QLatin1String("\n"
"font: 87 10pt \"Arial Black\";\n"
"border-radius: 10px;"));
        label_text_5->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_text_5, 0, 0, 1, 1);

        lcdNumber_force = new QLCDNumber(LCDwidget_4);
        lcdNumber_force->setObjectName(QStringLiteral("lcdNumber_force"));
        lcdNumber_force->setMinimumSize(QSize(131, 31));
        lcdNumber_force->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_6->addWidget(lcdNumber_force, 0, 1, 1, 1);

        lcdNumber_M = new QLCDNumber(LCDwidget_4);
        lcdNumber_M->setObjectName(QStringLiteral("lcdNumber_M"));
        lcdNumber_M->setMinimumSize(QSize(81, 31));
        lcdNumber_M->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_6->addWidget(lcdNumber_M, 0, 3, 1, 1);

        lcdNumber_M_2 = new QLCDNumber(LCDwidget_4);
        lcdNumber_M_2->setObjectName(QStringLiteral("lcdNumber_M_2"));
        lcdNumber_M_2->setMinimumSize(QSize(81, 31));
        lcdNumber_M_2->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_6->addWidget(lcdNumber_M_2, 0, 4, 1, 1);

        label_text_6 = new QLabel(LCDwidget_4);
        label_text_6->setObjectName(QStringLiteral("label_text_6"));
        label_text_6->setStyleSheet(QLatin1String("\n"
"font: 87 10pt \"Arial Black\";\n"
"border-radius: 10px;"));
        label_text_6->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_text_6, 0, 2, 1, 1);

        lcdNumber_M_3 = new QLCDNumber(LCDwidget_4);
        lcdNumber_M_3->setObjectName(QStringLiteral("lcdNumber_M_3"));
        lcdNumber_M_3->setMinimumSize(QSize(81, 31));
        lcdNumber_M_3->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_6->addWidget(lcdNumber_M_3, 0, 5, 1, 1);


        gridLayout_2->addWidget(LCDwidget_4, 3, 3, 1, 1);

        LCDwidget_2 = new QWidget(tab);
        LCDwidget_2->setObjectName(QStringLiteral("LCDwidget_2"));
        sizePolicy3.setHeightForWidth(LCDwidget_2->sizePolicy().hasHeightForWidth());
        LCDwidget_2->setSizePolicy(sizePolicy3);
        LCDwidget_2->setMinimumSize(QSize(300, 100));
        LCDwidget_2->setBaseSize(QSize(400, 400));
        LCDwidget_2->setStyleSheet(QLatin1String("QWidget{border-radius: 10px}\n"
"\n"
"QWidget::!hover{\n"
"background-color: rgb(59, 65, 72);\n"
"}\n"
"\n"
"\n"
"QWidget::hover{\n"
"background-color: rgb(59, 65, 72)}"));
        gridLayout_4 = new QGridLayout(LCDwidget_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lineEdit_subjectName = new QLineEdit(LCDwidget_2);
        lineEdit_subjectName->setObjectName(QStringLiteral("lineEdit_subjectName"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(5);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lineEdit_subjectName->sizePolicy().hasHeightForWidth());
        lineEdit_subjectName->setSizePolicy(sizePolicy4);
        lineEdit_subjectName->setMinimumSize(QSize(100, 31));
        lineEdit_subjectName->setMaximumSize(QSize(140, 16777215));
        lineEdit_subjectName->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 10pt \"Arial Black\";"));
        lineEdit_subjectName->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lineEdit_subjectName, 0, 1, 1, 1);

        pushButton_calibration = new QPushButton(LCDwidget_2);
        pushButton_calibration->setObjectName(QStringLiteral("pushButton_calibration"));
        sizePolicy2.setHeightForWidth(pushButton_calibration->sizePolicy().hasHeightForWidth());
        pushButton_calibration->setSizePolicy(sizePolicy2);
        pushButton_calibration->setMinimumSize(QSize(71, 31));
        pushButton_calibration->setStyleSheet(QLatin1String("QPushButton{border-radius: 10px}\n"
"\n"
"QPushButton::!hover{\n"
"background-color: rgb(105, 165, 90)}\n"
"\n"
"QPushButton::hover{\n"
"background-color: rgb(76, 120, 65)}\n"
""));

        gridLayout_4->addWidget(pushButton_calibration, 1, 2, 1, 1);

        pushButton_ready = new QPushButton(LCDwidget_2);
        pushButton_ready->setObjectName(QStringLiteral("pushButton_ready"));
        sizePolicy2.setHeightForWidth(pushButton_ready->sizePolicy().hasHeightForWidth());
        pushButton_ready->setSizePolicy(sizePolicy2);
        pushButton_ready->setMinimumSize(QSize(71, 31));
        pushButton_ready->setStyleSheet(QLatin1String("QPushButton{border-radius: 10px}\n"
"\n"
"QPushButton::!hover{\n"
"background-color: rgb(105, 165, 90)}\n"
"\n"
"QPushButton::hover{\n"
"background-color: rgb(76, 120, 65)}\n"
""));

        gridLayout_4->addWidget(pushButton_ready, 0, 2, 1, 1);

        pushButton_StartRec = new QPushButton(LCDwidget_2);
        pushButton_StartRec->setObjectName(QStringLiteral("pushButton_StartRec"));
        sizePolicy2.setHeightForWidth(pushButton_StartRec->sizePolicy().hasHeightForWidth());
        pushButton_StartRec->setSizePolicy(sizePolicy2);
        pushButton_StartRec->setMinimumSize(QSize(71, 31));
        pushButton_StartRec->setStyleSheet(QLatin1String("QPushButton{border-radius: 10px}\n"
"\n"
"QPushButton::!hover{\n"
"background-color: rgb(105, 165, 90)}\n"
"\n"
"QPushButton::hover{\n"
"background-color: rgb(76, 120, 65)}"));

        gridLayout_4->addWidget(pushButton_StartRec, 0, 3, 1, 1);

        pushButton_StopRec = new QPushButton(LCDwidget_2);
        pushButton_StopRec->setObjectName(QStringLiteral("pushButton_StopRec"));
        sizePolicy2.setHeightForWidth(pushButton_StopRec->sizePolicy().hasHeightForWidth());
        pushButton_StopRec->setSizePolicy(sizePolicy2);
        pushButton_StopRec->setMinimumSize(QSize(71, 31));
        pushButton_StopRec->setStyleSheet(QLatin1String("QPushButton{border-radius: 10px}\n"
"\n"
"QPushButton::!hover{background-color: rgb(189, 0, 0)}\n"
"\n"
"\n"
"QPushButton::hover{\n"
"	background-color: rgb(148, 0, 0)}"));

        gridLayout_4->addWidget(pushButton_StopRec, 1, 3, 1, 1);


        gridLayout_2->addWidget(LCDwidget_2, 2, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(150, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 2, 1, 1);

        tabWidget->addTab(tab, QString());
        LCDwidget_2->raise();
        widget_2->raise();
        saveImageButton_2->raise();
        saveImageButton->raise();
        LCDwidget_3->raise();
        LCDwidget_4->raise();
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        qvtkWidget = new QVTKWidget(tab_3);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(30, 30, 1031, 561));
        tabWidget->addTab(tab_3, QString());
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
        menuBar->setGeometry(QRect(0, 0, 1181, 23));
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

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", nullptr));
        checkBox->setText(QApplication::translate("MainWindowClass", "Force Position", nullptr));
        label_text_2->setText(QApplication::translate("MainWindowClass", "Force Magnitude(KG)", nullptr));
        lineEdit_f->setText(QString());
        label_text_7->setText(QApplication::translate("MainWindowClass", "Body Weight(KG)", nullptr));
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
        checkBox_2->setText(QApplication::translate("MainWindowClass", "Show joint angle", nullptr));
        label_6->setText(QApplication::translate("MainWindowClass", "Neck F/b tilt", nullptr));
        label->setText(QApplication::translate("MainWindowClass", "ElbowR", nullptr));
        label_7->setText(QApplication::translate("MainWindowClass", "Neck l/r tilt", nullptr));
        label_2->setText(QApplication::translate("MainWindowClass", "ElbowL", nullptr));
        label_9->setText(QApplication::translate("MainWindowClass", "ShoulderR", nullptr));
        label_4->setText(QApplication::translate("MainWindowClass", "KneeR", nullptr));
        label_8->setText(QApplication::translate("MainWindowClass", "ShoulderL", nullptr));
        label_3->setText(QApplication::translate("MainWindowClass", "KneeL", nullptr));
        label_5->setText(QApplication::translate("MainWindowClass", "Spine", nullptr));
        label_text_5->setText(QApplication::translate("MainWindowClass", "F ->", nullptr));
        label_text_6->setText(QApplication::translate("MainWindowClass", "M ->", nullptr));
        lineEdit_subjectName->setText(QApplication::translate("MainWindowClass", "Username_Here", nullptr));
        pushButton_calibration->setText(QApplication::translate("MainWindowClass", "Calibration", nullptr));
        pushButton_ready->setText(QApplication::translate("MainWindowClass", "Comfirm", nullptr));
        pushButton_StartRec->setText(QApplication::translate("MainWindowClass", "StartREC", nullptr));
        pushButton_StopRec->setText(QApplication::translate("MainWindowClass", "StopREC", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindowClass", "View", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindowClass", "\351\241\265", nullptr));
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
