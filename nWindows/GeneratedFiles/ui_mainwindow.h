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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *saveImageButton;
    QTabWidget *tabWidget;
    QWidget *tab_view;
    QWidget *widget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *colorwindow;
    QLabel *depthwindow;
    QWidget *tab_table;
    QTableView *tableView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1630, 704);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(530, 160, 75, 23));
        saveImageButton = new QPushButton(centralWidget);
        saveImageButton->setObjectName(QStringLiteral("saveImageButton"));
        saveImageButton->setGeometry(QRect(530, 190, 75, 23));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 1611, 761));
        tabWidget->setSizeIncrement(QSize(0, 0));
        tab_view = new QWidget();
        tab_view->setObjectName(QStringLiteral("tab_view"));
        tab_view->setCursor(QCursor(Qt::CrossCursor));
        widget = new QWidget(tab_view);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 1021, 541));
        horizontalLayoutWidget = new QWidget(widget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 1001, 631));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        colorwindow = new QLabel(horizontalLayoutWidget);
        colorwindow->setObjectName(QStringLiteral("colorwindow"));
        colorwindow->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(colorwindow);

        depthwindow = new QLabel(horizontalLayoutWidget);
        depthwindow->setObjectName(QStringLiteral("depthwindow"));

        horizontalLayout->addWidget(depthwindow);

        tabWidget->addTab(tab_view, QString());
        tab_table = new QWidget();
        tab_table->setObjectName(QStringLiteral("tab_table"));
        tableView = new QTableView(tab_table);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(105, 51, 891, 511));
        tabWidget->addTab(tab_table, QString());
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1630, 23));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("MainWindowClass", "\345\216\273\350\203\214", nullptr));
        saveImageButton->setText(QApplication::translate("MainWindowClass", "\344\277\235\345\255\230", nullptr));
        colorwindow->setText(QString());
        depthwindow->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_view), QApplication::translate("MainWindowClass", "Skeleton View", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_table), QApplication::translate("MainWindowClass", "Joint Angle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
