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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_userinput;
    QGridLayout *gridLayout_10;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_3;
    QGridLayout *gridLayout_9;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_ready;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget;
    QGridLayout *gridLayout_8;
    QLabel *label_10;
    QWidget *gridWidget;
    QGridLayout *gridLayout_7;
    QLabel *label_text_10;
    QLabel *label_text_11;
    QLabel *label_text_12;
    QLineEdit *lineEdit_gender;
    QLabel *label_text_13;
    QLabel *label_text_9;
    QLineEdit *lineEdit_height;
    QLineEdit *lineEdit_subjectName;
    QSpinBox *spinBox_age;
    QLabel *label_12;
    QLineEdit *lineEdit_bodyWeight;
    QLineEdit *lineEdit_preside;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_7;
    QWidget *LCDwidget_3;
    QGridLayout *gridLayout_5;
    QLabel *label_text_3;
    QLineEdit *lineEdit_bagZ;
    QLineEdit *lineEdit_bagY;
    QLabel *label_text_2;
    QLineEdit *lineEdit_bagX;
    QLineEdit *lineEdit_f;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QWidget *LCDwidget_2;
    QGridLayout *gridLayout_12;
    QFrame *frame;
    QGridLayout *gridLayout_11;
    QPushButton *pushButton_StartRec;
    QPushButton *pushButton_StopRec;
    QPushButton *pushButton_calibration;
    QWidget *LCDwidget_4;
    QGridLayout *gridLayout_6;
    QLCDNumber *lcdNumber_M;
    QLabel *label_text_5;
    QLabel *label_text_6;
    QLCDNumber *lcdNumber_force;
    QLCDNumber *lcdNumber_M_2;
    QLCDNumber *lcdNumber_M_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget_alljoint;
    QSpacerItem *horizontalSpacer_12;
    QLabel *colorwindow;
    QSpacerItem *horizontalSpacer_13;
    QWidget *LCDwidget;
    QGridLayout *gridLayout_3;
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
    QCheckBox *checkBox_2;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_recording;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_11;
    QLineEdit *lineEdit_trailname;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_openrecord;
    QSpacerItem *horizontalSpacer_11;
    QTreeWidget *treeWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1305, 859);
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
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QLatin1String("QTabBar::tab{\n"
"             border-top-left-radius: 4px;\n"
"             border-top-right-radius: 4px;\n"
"             min-width:100px; min-height:25px;\n"
"\n"
"	background-color: rgb(0, 85, 0);\n"
"             }\n"
"QTabBar::tab:!selected { margin-top: 0px; margin-left: 30;}\n"
"QTabBar::tab:selected {color: white}\n"
"QTabBar::tab:hover:!selected {color: rgb(0, 170, 127); }\n"
"\n"
"QTabBar::tab:selected {margin-left: 30;\n"
"background-color: rgb(0, 39, 0);\n"
"}\n"
"\n"
"\n"
""));
        tabWidget->setIconSize(QSize(16, 16));
        tabWidget->setElideMode(Qt::ElideLeft);
        tab_userinput = new QWidget();
        tab_userinput->setObjectName(QStringLiteral("tab_userinput"));
        gridLayout_10 = new QGridLayout(tab_userinput);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_2, 0, 1, 3, 1);

        checkBox = new QCheckBox(tab_userinput);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy1);
        checkBox->setMinimumSize(QSize(500, 30));
        checkBox->setMaximumSize(QSize(500, 50));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(10);
        checkBox->setFont(font1);
        checkBox->setStyleSheet(QLatin1String("background-color: rgb(0, 85, 0);\n"
"font: 87 20pt \"Arial\";\n"
"border-radius: 10px;"));

        gridLayout_10->addWidget(checkBox, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(298, 209, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer, 2, 2, 1, 2);

        widget_3 = new QWidget(tab_userinput);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy2);
        widget_3->setMinimumSize(QSize(40, 60));
        widget_3->setStyleSheet(QLatin1String("QWidget{border-radius: 10px}\n"
"\n"
"QWidget::!hover{\n"
"background-color: rgb(59, 65, 72);\n"
"}\n"
"\n"
"\n"
"QWidget::hover{\n"
"background-color: rgb(59, 65, 72)}"));
        gridLayout_9 = new QGridLayout(widget_3);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(150, 15, 150, 15);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        pushButton_ready = new QPushButton(widget_3);
        pushButton_ready->setObjectName(QStringLiteral("pushButton_ready"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_ready->sizePolicy().hasHeightForWidth());
        pushButton_ready->setSizePolicy(sizePolicy3);
        pushButton_ready->setMinimumSize(QSize(100, 50));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial Black"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_ready->setFont(font2);
        pushButton_ready->setStyleSheet(QLatin1String("QPushButton{border-radius: 10px}\n"
"\n"
"\n"
"QPushButton::!hover{\n"
"background-color: rgb(105, 165, 90)}\n"
"\n"
"QPushButton::hover{\n"
"background-color: rgb(76, 120, 65)}\n"
""));

        gridLayout_9->addWidget(pushButton_ready, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_6, 0, 2, 1, 1);


        gridLayout_10->addWidget(widget_3, 3, 0, 1, 4);

        widget = new QWidget(tab_userinput);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setMinimumSize(QSize(200, 200));
        widget->setStyleSheet(QLatin1String("QWidget{border-radius: 10px}\n"
"\n"
"QWidget::!hover{\n"
"background-color: rgb(59, 65, 72);\n"
"}\n"
"\n"
"\n"
"QWidget::hover{\n"
"background-color: rgb(59, 65, 72)}"));
        gridLayout_8 = new QGridLayout(widget);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(40, 40, 40, 40);
        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setStyleSheet(QStringLiteral("image: url(:/myimages/Resources/user.jpg);"));

        gridLayout_8->addWidget(label_10, 0, 0, 1, 1);


        gridLayout_10->addWidget(widget, 0, 2, 1, 2);

        gridWidget = new QWidget(tab_userinput);
        gridWidget->setObjectName(QStringLiteral("gridWidget"));
        gridWidget->setStyleSheet(QLatin1String("QWidget{border-radius: 10px}\n"
"\n"
"QWidget::!hover{\n"
"background-color: rgb(59, 65, 72);\n"
"}\n"
"\n"
"\n"
"QWidget::hover{\n"
"background-color: rgb(59, 65, 72)}"));
        gridLayout_7 = new QGridLayout(gridWidget);
        gridLayout_7->setSpacing(20);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(9, 9, 9, 9);
        label_text_10 = new QLabel(gridWidget);
        label_text_10->setObjectName(QStringLiteral("label_text_10"));
        sizePolicy3.setHeightForWidth(label_text_10->sizePolicy().hasHeightForWidth());
        label_text_10->setSizePolicy(sizePolicy3);
        label_text_10->setMinimumSize(QSize(200, 50));
        label_text_10->setStyleSheet(QLatin1String("background-color: rgb(76, 120, 65);font: 20pt \"Arial\";\n"
"border-radius: 10px;"));
        label_text_10->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_text_10, 3, 2, 1, 1);

        label_text_11 = new QLabel(gridWidget);
        label_text_11->setObjectName(QStringLiteral("label_text_11"));
        sizePolicy2.setHeightForWidth(label_text_11->sizePolicy().hasHeightForWidth());
        label_text_11->setSizePolicy(sizePolicy2);
        label_text_11->setMinimumSize(QSize(200, 50));
        label_text_11->setStyleSheet(QLatin1String("background-color: rgb(76, 120, 65);\n"
"font: 20pt \"Arial\";\n"
"border-radius: 10px;"));
        label_text_11->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_text_11, 0, 2, 1, 1);

        label_text_12 = new QLabel(gridWidget);
        label_text_12->setObjectName(QStringLiteral("label_text_12"));
        sizePolicy3.setHeightForWidth(label_text_12->sizePolicy().hasHeightForWidth());
        label_text_12->setSizePolicy(sizePolicy3);
        label_text_12->setMinimumSize(QSize(200, 50));
        label_text_12->setStyleSheet(QLatin1String("background-color: rgb(76, 120, 65);\n"
"font: 20pt \"Arial\";\n"
"border-radius: 10px;"));
        label_text_12->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_text_12, 3, 1, 1, 1);

        lineEdit_gender = new QLineEdit(gridWidget);
        lineEdit_gender->setObjectName(QStringLiteral("lineEdit_gender"));
        sizePolicy3.setHeightForWidth(lineEdit_gender->sizePolicy().hasHeightForWidth());
        lineEdit_gender->setSizePolicy(sizePolicy3);
        lineEdit_gender->setMinimumSize(QSize(200, 31));
        lineEdit_gender->setMaximumSize(QSize(16777215, 60));
        lineEdit_gender->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 18pt \"Arial Black\";"));
        lineEdit_gender->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(lineEdit_gender, 1, 2, 1, 1);

        label_text_13 = new QLabel(gridWidget);
        label_text_13->setObjectName(QStringLiteral("label_text_13"));
        sizePolicy3.setHeightForWidth(label_text_13->sizePolicy().hasHeightForWidth());
        label_text_13->setSizePolicy(sizePolicy3);
        label_text_13->setMinimumSize(QSize(200, 50));
        label_text_13->setStyleSheet(QLatin1String("background-color: rgb(76, 120, 65);\n"
"font: 20pt \"Arial\";\n"
"border-radius: 10px;"));
        label_text_13->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_text_13, 0, 3, 1, 1);

        label_text_9 = new QLabel(gridWidget);
        label_text_9->setObjectName(QStringLiteral("label_text_9"));
        sizePolicy3.setHeightForWidth(label_text_9->sizePolicy().hasHeightForWidth());
        label_text_9->setSizePolicy(sizePolicy3);
        label_text_9->setMinimumSize(QSize(200, 50));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setPointSize(20);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        label_text_9->setFont(font3);
        label_text_9->setStyleSheet(QLatin1String("background-color: rgb(76, 120, 65);\n"
"font: 20pt \"Arial\";\n"
"border-radius: 10px;"));
        label_text_9->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_text_9, 0, 1, 1, 1);

        lineEdit_height = new QLineEdit(gridWidget);
        lineEdit_height->setObjectName(QStringLiteral("lineEdit_height"));
        sizePolicy3.setHeightForWidth(lineEdit_height->sizePolicy().hasHeightForWidth());
        lineEdit_height->setSizePolicy(sizePolicy3);
        lineEdit_height->setMinimumSize(QSize(200, 31));
        lineEdit_height->setMaximumSize(QSize(16777215, 60));
        lineEdit_height->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 18pt \"Arial Black\";"));
        lineEdit_height->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(lineEdit_height, 4, 1, 1, 1);

        lineEdit_subjectName = new QLineEdit(gridWidget);
        lineEdit_subjectName->setObjectName(QStringLiteral("lineEdit_subjectName"));
        sizePolicy3.setHeightForWidth(lineEdit_subjectName->sizePolicy().hasHeightForWidth());
        lineEdit_subjectName->setSizePolicy(sizePolicy3);
        lineEdit_subjectName->setMinimumSize(QSize(200, 31));
        lineEdit_subjectName->setMaximumSize(QSize(16777215, 60));
        lineEdit_subjectName->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 18pt \"Arial Black\";"));
        lineEdit_subjectName->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(lineEdit_subjectName, 1, 1, 1, 1);

        spinBox_age = new QSpinBox(gridWidget);
        spinBox_age->setObjectName(QStringLiteral("spinBox_age"));
        sizePolicy3.setHeightForWidth(spinBox_age->sizePolicy().hasHeightForWidth());
        spinBox_age->setSizePolicy(sizePolicy3);
        spinBox_age->setMinimumSize(QSize(200, 31));
        spinBox_age->setMaximumSize(QSize(16777215, 60));
        spinBox_age->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 18pt \"Arial Black\";"));
        spinBox_age->setButtonSymbols(QAbstractSpinBox::PlusMinus);

        gridLayout_7->addWidget(spinBox_age, 1, 3, 1, 1);

        label_12 = new QLabel(gridWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setStyleSheet(QLatin1String("background-color: rgb(76, 120, 65);font: 20pt \"Arial\";\n"
"border-radius: 10px;"));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_12, 3, 3, 1, 1);

        lineEdit_bodyWeight = new QLineEdit(gridWidget);
        lineEdit_bodyWeight->setObjectName(QStringLiteral("lineEdit_bodyWeight"));
        sizePolicy3.setHeightForWidth(lineEdit_bodyWeight->sizePolicy().hasHeightForWidth());
        lineEdit_bodyWeight->setSizePolicy(sizePolicy3);
        lineEdit_bodyWeight->setMinimumSize(QSize(200, 31));
        lineEdit_bodyWeight->setMaximumSize(QSize(16777215, 60));
        lineEdit_bodyWeight->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 18pt \"Arial Black\";"));
        lineEdit_bodyWeight->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(lineEdit_bodyWeight, 4, 2, 1, 1);

        lineEdit_preside = new QLineEdit(gridWidget);
        lineEdit_preside->setObjectName(QStringLiteral("lineEdit_preside"));
        lineEdit_preside->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 18pt \"Arial Black\";"));

        gridLayout_7->addWidget(lineEdit_preside, 4, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_2, 2, 2, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_8, 0, 4, 7, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_7, 0, 0, 7, 1);


        gridLayout_10->addWidget(gridWidget, 0, 0, 1, 1);

        LCDwidget_3 = new QWidget(tab_userinput);
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
        gridLayout_5->setSpacing(10);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(40, 40, 40, 40);
        label_text_3 = new QLabel(LCDwidget_3);
        label_text_3->setObjectName(QStringLiteral("label_text_3"));
        sizePolicy3.setHeightForWidth(label_text_3->sizePolicy().hasHeightForWidth());
        label_text_3->setSizePolicy(sizePolicy3);
        label_text_3->setMinimumSize(QSize(250, 30));
        label_text_3->setStyleSheet(QLatin1String("background-color: rgb(76, 120, 65);\n"
"font: 87 20pt \"Arial\";\n"
"border-radius: 10px;"));
        label_text_3->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_text_3, 1, 1, 1, 1);

        lineEdit_bagZ = new QLineEdit(LCDwidget_3);
        lineEdit_bagZ->setObjectName(QStringLiteral("lineEdit_bagZ"));
        sizePolicy3.setHeightForWidth(lineEdit_bagZ->sizePolicy().hasHeightForWidth());
        lineEdit_bagZ->setSizePolicy(sizePolicy3);
        lineEdit_bagZ->setMinimumSize(QSize(80, 30));
        lineEdit_bagZ->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 10pt \"Arial Black\";"));
        lineEdit_bagZ->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lineEdit_bagZ, 1, 4, 1, 1);

        lineEdit_bagY = new QLineEdit(LCDwidget_3);
        lineEdit_bagY->setObjectName(QStringLiteral("lineEdit_bagY"));
        sizePolicy3.setHeightForWidth(lineEdit_bagY->sizePolicy().hasHeightForWidth());
        lineEdit_bagY->setSizePolicy(sizePolicy3);
        lineEdit_bagY->setMinimumSize(QSize(80, 30));
        lineEdit_bagY->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 10pt \"Arial Black\";"));
        lineEdit_bagY->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lineEdit_bagY, 1, 3, 1, 1);

        label_text_2 = new QLabel(LCDwidget_3);
        label_text_2->setObjectName(QStringLiteral("label_text_2"));
        sizePolicy3.setHeightForWidth(label_text_2->sizePolicy().hasHeightForWidth());
        label_text_2->setSizePolicy(sizePolicy3);
        label_text_2->setMinimumSize(QSize(250, 30));
        label_text_2->setStyleSheet(QLatin1String("background-color: rgb(76, 120, 65);\n"
"font: 87 20pt \"Arial\";\n"
"border-radius: 10px;"));
        label_text_2->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_text_2, 2, 1, 1, 1);

        lineEdit_bagX = new QLineEdit(LCDwidget_3);
        lineEdit_bagX->setObjectName(QStringLiteral("lineEdit_bagX"));
        sizePolicy3.setHeightForWidth(lineEdit_bagX->sizePolicy().hasHeightForWidth());
        lineEdit_bagX->setSizePolicy(sizePolicy3);
        lineEdit_bagX->setMinimumSize(QSize(80, 30));
        lineEdit_bagX->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 10pt \"Arial Black\";"));
        lineEdit_bagX->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lineEdit_bagX, 1, 2, 1, 1);

        lineEdit_f = new QLineEdit(LCDwidget_3);
        lineEdit_f->setObjectName(QStringLiteral("lineEdit_f"));
        sizePolicy3.setHeightForWidth(lineEdit_f->sizePolicy().hasHeightForWidth());
        lineEdit_f->setSizePolicy(sizePolicy3);
        lineEdit_f->setMinimumSize(QSize(80, 30));
        lineEdit_f->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 10pt \"Arial Black\";"));
        lineEdit_f->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lineEdit_f, 2, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 1, 5, 2, 1);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_3, 0, 0, 1, 6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_3, 1, 0, 2, 1);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_4, 3, 0, 1, 6);


        gridLayout_10->addWidget(LCDwidget_3, 2, 0, 1, 1);

        QIcon icon;
        icon.addFile(QStringLiteral(":/myimages/Resources/user.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_userinput, icon, QString());
        widget_3->raise();
        widget->raise();
        gridWidget->raise();
        LCDwidget_3->raise();
        checkBox->raise();
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        LCDwidget_2 = new QWidget(tab);
        LCDwidget_2->setObjectName(QStringLiteral("LCDwidget_2"));
        sizePolicy2.setHeightForWidth(LCDwidget_2->sizePolicy().hasHeightForWidth());
        LCDwidget_2->setSizePolicy(sizePolicy2);
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
        gridLayout_12 = new QGridLayout(LCDwidget_2);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        frame = new QFrame(LCDwidget_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(200, 80));
        frame->setMaximumSize(QSize(200, 80));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Plain);
        gridLayout_11 = new QGridLayout(frame);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        pushButton_StartRec = new QPushButton(frame);
        pushButton_StartRec->setObjectName(QStringLiteral("pushButton_StartRec"));
        sizePolicy3.setHeightForWidth(pushButton_StartRec->sizePolicy().hasHeightForWidth());
        pushButton_StartRec->setSizePolicy(sizePolicy3);
        pushButton_StartRec->setMinimumSize(QSize(70, 70));
        pushButton_StartRec->setMaximumSize(QSize(70, 70));
        pushButton_StartRec->setStyleSheet(QLatin1String("QPushButton{border-radius: 35px\n"
"\n"
"}\n"
"\n"
"QPushButton::!hover{\n"
"background-color: rgb(105, 165, 90)}\n"
"\n"
"QPushButton::hover{\n"
"background-color: rgb(76, 120, 65)}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/myimages/Resources/luzhi.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_StartRec->setIcon(icon1);
        pushButton_StartRec->setIconSize(QSize(64, 64));
        pushButton_StartRec->setAutoExclusive(true);

        gridLayout_11->addWidget(pushButton_StartRec, 0, 1, 1, 1);

        pushButton_StopRec = new QPushButton(frame);
        pushButton_StopRec->setObjectName(QStringLiteral("pushButton_StopRec"));
        sizePolicy3.setHeightForWidth(pushButton_StopRec->sizePolicy().hasHeightForWidth());
        pushButton_StopRec->setSizePolicy(sizePolicy3);
        pushButton_StopRec->setMinimumSize(QSize(70, 70));
        pushButton_StopRec->setMaximumSize(QSize(70, 70));
        pushButton_StopRec->setStyleSheet(QLatin1String("QPushButton{border-radius: 35px}\n"
"\n"
"QPushButton::!hover{background-color: rgb(189, 0, 0)}\n"
"\n"
"\n"
"QPushButton::hover{\n"
"	background-color: rgb(148, 0, 0)}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/myimages/Resources/tingzhiluzhi.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_StopRec->setIcon(icon2);
        pushButton_StopRec->setIconSize(QSize(74, 74));
        pushButton_StopRec->setAutoExclusive(true);

        gridLayout_11->addWidget(pushButton_StopRec, 0, 2, 1, 1);


        gridLayout_12->addWidget(frame, 1, 1, 1, 1);

        pushButton_calibration = new QPushButton(LCDwidget_2);
        pushButton_calibration->setObjectName(QStringLiteral("pushButton_calibration"));
        sizePolicy3.setHeightForWidth(pushButton_calibration->sizePolicy().hasHeightForWidth());
        pushButton_calibration->setSizePolicy(sizePolicy3);
        pushButton_calibration->setMinimumSize(QSize(120, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        font4.setPointSize(16);
        pushButton_calibration->setFont(font4);
        pushButton_calibration->setStyleSheet(QLatin1String("QPushButton{border-radius: 10px}\n"
"\n"
"QPushButton::!hover{\n"
"background-color: rgb(105, 165, 90)}\n"
"\n"
"QPushButton::hover{\n"
"background-color: rgb(76, 120, 65)}\n"
""));

        gridLayout_12->addWidget(pushButton_calibration, 1, 0, 1, 1);


        gridLayout_2->addWidget(LCDwidget_2, 3, 4, 1, 1);

        LCDwidget_4 = new QWidget(tab);
        LCDwidget_4->setObjectName(QStringLiteral("LCDwidget_4"));
        sizePolicy2.setHeightForWidth(LCDwidget_4->sizePolicy().hasHeightForWidth());
        LCDwidget_4->setSizePolicy(sizePolicy2);
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
        lcdNumber_M = new QLCDNumber(LCDwidget_4);
        lcdNumber_M->setObjectName(QStringLiteral("lcdNumber_M"));
        lcdNumber_M->setMinimumSize(QSize(81, 31));
        lcdNumber_M->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_6->addWidget(lcdNumber_M, 0, 3, 1, 1);

        label_text_5 = new QLabel(LCDwidget_4);
        label_text_5->setObjectName(QStringLiteral("label_text_5"));
        label_text_5->setStyleSheet(QLatin1String("\n"
"font: 87 10pt \"Arial Black\";\n"
"border-radius: 10px;"));
        label_text_5->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_text_5, 0, 0, 1, 1);

        label_text_6 = new QLabel(LCDwidget_4);
        label_text_6->setObjectName(QStringLiteral("label_text_6"));
        label_text_6->setStyleSheet(QLatin1String("\n"
"font: 87 10pt \"Arial Black\";\n"
"border-radius: 10px;"));
        label_text_6->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_text_6, 0, 2, 1, 1);

        lcdNumber_force = new QLCDNumber(LCDwidget_4);
        lcdNumber_force->setObjectName(QStringLiteral("lcdNumber_force"));
        lcdNumber_force->setMinimumSize(QSize(131, 31));
        lcdNumber_force->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_6->addWidget(lcdNumber_force, 0, 1, 1, 1);

        lcdNumber_M_2 = new QLCDNumber(LCDwidget_4);
        lcdNumber_M_2->setObjectName(QStringLiteral("lcdNumber_M_2"));
        lcdNumber_M_2->setMinimumSize(QSize(81, 31));
        lcdNumber_M_2->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_6->addWidget(lcdNumber_M_2, 0, 4, 1, 1);

        lcdNumber_M_3 = new QLCDNumber(LCDwidget_4);
        lcdNumber_M_3->setObjectName(QStringLiteral("lcdNumber_M_3"));
        lcdNumber_M_3->setMinimumSize(QSize(81, 31));
        lcdNumber_M_3->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        gridLayout_6->addWidget(lcdNumber_M_3, 0, 5, 1, 1);


        gridLayout_2->addWidget(LCDwidget_4, 3, 2, 1, 1);

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
        sizePolicy2.setHeightForWidth(listWidget_alljoint->sizePolicy().hasHeightForWidth());
        listWidget_alljoint->setSizePolicy(sizePolicy2);
        listWidget_alljoint->setMinimumSize(QSize(160, 420));
        QFont font5;
        font5.setFamily(QStringLiteral("Arial"));
        font5.setPointSize(14);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        listWidget_alljoint->setFont(font5);
        listWidget_alljoint->setStyleSheet(QLatin1String("background-color: rgb(76, 120, 65);\n"
"font: 14pt \"Arial\";\n"
"border-radius:10px;"));

        horizontalLayout->addWidget(listWidget_alljoint);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_12);

        colorwindow = new QLabel(widget_2);
        colorwindow->setObjectName(QStringLiteral("colorwindow"));
        sizePolicy.setHeightForWidth(colorwindow->sizePolicy().hasHeightForWidth());
        colorwindow->setSizePolicy(sizePolicy);
        colorwindow->setMinimumSize(QSize(512, 424));
        colorwindow->setStyleSheet(QStringLiteral("background-color: rgb(100, 104, 97);"));

        horizontalLayout->addWidget(colorwindow);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_13);

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
"background-color: rgb(76, 120, 65)}\n"
"QWidget{font: 14pt \"Arial\";}\n"
""));
        gridLayout_3 = new QGridLayout(LCDwidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
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
        label_9->setStyleSheet(QStringLiteral(""));

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

        checkBox_2 = new QCheckBox(LCDwidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        sizePolicy3.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy3);
        checkBox_2->setMinimumSize(QSize(141, 16));
        checkBox_2->setStyleSheet(QStringLiteral("font: 20pt \"Arial\";"));

        gridLayout_3->addWidget(checkBox_2, 0, 0, 1, 2);


        horizontalLayout->addWidget(LCDwidget);


        gridLayout_2->addWidget(widget_2, 1, 0, 1, 5);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_9, 3, 0, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 3, 3, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 4, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 2, 2, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_14, 0, 1, 1, 4);

        label_recording = new QLabel(tab);
        label_recording->setObjectName(QStringLiteral("label_recording"));
        label_recording->setMinimumSize(QSize(50, 50));
        label_recording->setMaximumSize(QSize(50, 50));
        label_recording->setStyleSheet(QStringLiteral("border-image: url(:/myimages/Resources/recording.png);"));

        gridLayout_2->addWidget(label_recording, 0, 0, 1, 1);

        widget_4 = new QWidget(tab);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setStyleSheet(QLatin1String("QWidget{border-radius: 10px}\n"
"\n"
"QWidget::!hover{\n"
"background-color: rgb(76, 120, 65)}\n"
"\n"
"QWidget::hover{\n"
"background-color: rgb(76, 120, 65)}\n"
"QWidget{font: 14pt \"Arial\";}"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_11 = new QLabel(widget_4);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_2->addWidget(label_11);

        lineEdit_trailname = new QLineEdit(widget_4);
        lineEdit_trailname->setObjectName(QStringLiteral("lineEdit_trailname"));
        sizePolicy3.setHeightForWidth(lineEdit_trailname->sizePolicy().hasHeightForWidth());
        lineEdit_trailname->setSizePolicy(sizePolicy3);
        lineEdit_trailname->setMinimumSize(QSize(200, 31));
        lineEdit_trailname->setStyleSheet(QLatin1String("background-color: rgb(100, 104, 97);\n"
"border-radius: 10px;\n"
"font: 87 18pt \"Arial Black\";"));
        lineEdit_trailname->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit_trailname);


        gridLayout_2->addWidget(widget_4, 2, 3, 1, 2);

        QIcon icon3;
        icon3.addFile(QStringLiteral(":/myimages/Resources/sheyinji.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon3, QString());
        LCDwidget_2->raise();
        widget_2->raise();
        LCDwidget_4->raise();
        label_recording->raise();
        widget_4->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        pushButton_openrecord = new QPushButton(tab_2);
        pushButton_openrecord->setObjectName(QStringLiteral("pushButton_openrecord"));
        pushButton_openrecord->setMinimumSize(QSize(100, 30));
        QFont font6;
        font6.setFamily(QStringLiteral("Arial"));
        font6.setPointSize(14);
        pushButton_openrecord->setFont(font6);
        pushButton_openrecord->setStyleSheet(QLatin1String("QPushButton{border-radius: 10px}\n"
"\n"
"QPushButton::!hover{\n"
"background-color: rgb(105, 165, 90)}\n"
"\n"
"QPushButton::hover{\n"
"background-color: rgb(76, 120, 65)}\n"
""));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/tree/Resources/shuaxin.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_openrecord->setIcon(icon4);
        pushButton_openrecord->setFlat(false);

        gridLayout_4->addWidget(pushButton_openrecord, 0, 0, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_11, 0, 1, 1, 1);

        treeWidget = new QTreeWidget(tab_2);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setStyleSheet(QLatin1String("QTreeWidget{\n"
"	\n"
"	font: 75 20pt \"Arial\" ;\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: #FEFFF7;\n"
"	alternate-background-color: #CBE8D9;\n"
"}\n"
"\n"
"QTreeWidget::item:hover{\n"
"	background-color: #C5DAFF;\n"
"}\n"
"\n"
"QTreeWidget::item:selected{\n"
"	background-color: #DEBBE8;\n"
"}\n"
"QTreeWidget::branch{\n"
"	\n"
"	/*background-color: rgb(65, 48, 255);*/\n"
"}\n"
"\n"
" QTreeView::branch:has-siblings:!adjoins-item {\n"
"	\n"
"      border-image: url(:/tree/Resources/vline.png) 0;\n"
"  }\n"
"  QTreeView::branch:has-siblings:adjoins-item {\n"
"      border-image: url(:/tree/Resources/branch-more.png) 0;\n"
"  }\n"
"  QTreeView::branch:!has-children:!has-siblings:adjoins-item {\n"
"      border-image: url(:/tree/Resources/branch-end.png) 0;\n"
"  }\n"
"  QTreeView::branch:has-children:!has-siblings:closed,\n"
"  QTreeView::branch:closed:has-children:has-siblings {\n"
"          border-image: none; image: url(:/tree/Resources/branch-closed.png);\n"
"  }\n"
"  QTreeView::branch:open:has-child"
                        "ren:!has-siblings,\n"
"  QTreeView::branch:open:has-children:has-siblings  {\n"
"          border-image: none;\n"
"          image: url(:/tree/Resources/branch-open.png);\n"
"  }\n"
"QHeaderView::section{\n"
"	\n"
"	font: 75 20pt \"Arial\" ;\n"
"	color: rgb(0, 0, 0);\n"
"	background-color:  #FFE0D8;\n"
"	border:1px solid #C5DAFF;\n"
"\n"
"}\n"
"\n"
""));
        treeWidget->setAlternatingRowColors(true);
        treeWidget->setAnimated(true);

        gridLayout_4->addWidget(treeWidget, 1, 0, 1, 2);

        QIcon icon5;
        icon5.addFile(QStringLiteral(":/myimages/Resources/jilu.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_2, icon5, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1305, 23));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);
        QObject::connect(checkBox_2, SIGNAL(clicked(bool)), MainWindowClass, SLOT(SimpleMode(bool)));
        QObject::connect(pushButton_StartRec, SIGNAL(clicked()), MainWindowClass, SLOT(startRec()));
        QObject::connect(pushButton_StopRec, SIGNAL(clicked()), MainWindowClass, SLOT(stopRec()));
        QObject::connect(treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), MainWindowClass, SLOT(Click(QTreeWidgetItem*)));
        QObject::connect(treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), MainWindowClass, SLOT(DoubleClick(QTreeWidgetItem*)));
        QObject::connect(treeWidget, SIGNAL(itemExpanded(QTreeWidgetItem*)), MainWindowClass, SLOT(Expend(QTreeWidgetItem*)));
        QObject::connect(pushButton_ready, SIGNAL(clicked()), MainWindowClass, SLOT(ready4Rec()));
        QObject::connect(lineEdit_subjectName, SIGNAL(textChanged(QString)), MainWindowClass, SLOT(LineEdit_subjName(QString)));
        QObject::connect(lineEdit_subjectName, SIGNAL(textChanged(QString)), MainWindowClass, SLOT(releaseOKbutton()));
        QObject::connect(pushButton_StartRec, SIGNAL(clicked()), label_recording, SLOT(show()));
        QObject::connect(pushButton_StopRec, SIGNAL(clicked()), label_recording, SLOT(hide()));
        QObject::connect(pushButton_openrecord, SIGNAL(clicked()), MainWindowClass, SLOT(UpdateDir()));
        QObject::connect(listWidget_alljoint, SIGNAL(currentRowChanged(int)), MainWindowClass, SLOT(ListCurChange(int)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", nullptr));
        checkBox->setText(QApplication::translate("MainWindowClass", "Check if the user has a backpack", nullptr));
        pushButton_ready->setText(QApplication::translate("MainWindowClass", "SAVE", nullptr));
        label_10->setText(QString());
        label_text_10->setText(QApplication::translate("MainWindowClass", "Weight (kg)", nullptr));
        label_text_11->setText(QApplication::translate("MainWindowClass", "Gender", nullptr));
        label_text_12->setText(QApplication::translate("MainWindowClass", "Height (cm)", nullptr));
        label_text_13->setText(QApplication::translate("MainWindowClass", "Age", nullptr));
        label_text_9->setText(QApplication::translate("MainWindowClass", "User Name", nullptr));
        lineEdit_height->setText(QString());
        lineEdit_subjectName->setText(QString());
        label_12->setText(QApplication::translate("MainWindowClass", "Preference Side", nullptr));
        label_text_3->setText(QApplication::translate("MainWindowClass", "Bag Position (mm)", nullptr));
        lineEdit_bagZ->setText(QApplication::translate("MainWindowClass", "z", nullptr));
        lineEdit_bagY->setText(QApplication::translate("MainWindowClass", "y", nullptr));
        label_text_2->setText(QApplication::translate("MainWindowClass", "Bag Weight (kg)", nullptr));
        lineEdit_bagX->setText(QApplication::translate("MainWindowClass", "x", nullptr));
        lineEdit_f->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_userinput), QApplication::translate("MainWindowClass", "Userinfo ", nullptr));
        pushButton_StartRec->setText(QString());
        pushButton_StopRec->setText(QString());
        pushButton_calibration->setText(QApplication::translate("MainWindowClass", "Calibration", nullptr));
        label_text_5->setText(QApplication::translate("MainWindowClass", "F ->", nullptr));
        label_text_6->setText(QApplication::translate("MainWindowClass", "M ->", nullptr));

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
        label_6->setText(QApplication::translate("MainWindowClass", "Neck F/b tilt", nullptr));
        label->setText(QApplication::translate("MainWindowClass", "Right Elbow", nullptr));
        label_7->setText(QApplication::translate("MainWindowClass", "Neck l/r tilt", nullptr));
        label_2->setText(QApplication::translate("MainWindowClass", "Left Elbow", nullptr));
        label_9->setText(QApplication::translate("MainWindowClass", "Right Shoulder", nullptr));
        label_4->setText(QApplication::translate("MainWindowClass", "Right Knee", nullptr));
        label_8->setText(QApplication::translate("MainWindowClass", "Left Shoulder", nullptr));
        label_3->setText(QApplication::translate("MainWindowClass", "Left Knee", nullptr));
        label_5->setText(QApplication::translate("MainWindowClass", "Uper/Lower Trunk Angle", nullptr));
        checkBox_2->setText(QApplication::translate("MainWindowClass", "Show joint angles", nullptr));
        label_recording->setText(QString());
        label_11->setText(QApplication::translate("MainWindowClass", "Trail Name", nullptr));
        lineEdit_trailname->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindowClass", "Control Panel ", nullptr));
        pushButton_openrecord->setText(QApplication::translate("MainWindowClass", "Refresh", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindowClass", "Data Base", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindowClass", "Files", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
