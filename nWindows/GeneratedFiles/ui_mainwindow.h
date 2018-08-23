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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *saveImageButton;
    QWidget *widget_2;
    QLabel *depthwindow;
    QLabel *colorwindow;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1269, 679);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1130, 110, 75, 23));
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(105, 165, 90);"));
        saveImageButton = new QPushButton(centralWidget);
        saveImageButton->setObjectName(QStringLiteral("saveImageButton"));
        saveImageButton->setGeometry(QRect(1130, 150, 75, 23));
        saveImageButton->setStyleSheet(QStringLiteral("background-color: rgb(105, 165, 90);"));
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(40, 110, 1032, 430));
        widget_2->setStyleSheet(QStringLiteral("background-color: rgb(59, 65, 72);"));
        depthwindow = new QLabel(widget_2);
        depthwindow->setObjectName(QStringLiteral("depthwindow"));
        depthwindow->setGeometry(QRect(2, 2, 512, 424));
        depthwindow->setStyleSheet(QStringLiteral("background-color: rgb(100, 104, 97);"));
        colorwindow = new QLabel(widget_2);
        colorwindow->setObjectName(QStringLiteral("colorwindow"));
        colorwindow->setGeometry(QRect(516, 2, 512, 424));
        colorwindow->setStyleSheet(QStringLiteral("background-color: rgb(100, 104, 97);"));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1269, 23));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("MainWindowClass", "\345\216\273\350\203\214", nullptr));
        saveImageButton->setText(QApplication::translate("MainWindowClass", "\344\277\235\345\255\230", nullptr));
        depthwindow->setText(QString());
        colorwindow->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
