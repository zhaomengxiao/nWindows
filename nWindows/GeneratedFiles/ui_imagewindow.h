/********************************************************************************
** Form generated from reading UI file 'imagewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEWINDOW_H
#define UI_IMAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageWindow
{
public:
    QWidget *widget;
    QPushButton *pushButton_2;
    QWidget *widget_2;
    QPushButton *pushButton;
    QGraphicsView *graphicsView;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QGraphicsView *graphicsView_2;
    QGraphicsView *graphicsView_3;
    QGraphicsView *graphicsView_4;

    void setupUi(QWidget *ImageWindow)
    {
        if (ImageWindow->objectName().isEmpty())
            ImageWindow->setObjectName(QStringLiteral("ImageWindow"));
        ImageWindow->resize(532, 469);
        QFont font;
        font.setPointSize(10);
        ImageWindow->setFont(font);
        ImageWindow->setStyleSheet(QLatin1String("QWidget{background-color:#464652;color:#E8E8E8}\n"
"\n"
""));
        widget = new QWidget(ImageWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(290, 290, 81, 81));
        widget->setStyleSheet(QLatin1String("QWidget{border-radius: 15px;background-color: qlineargradient(spread:reflect, x1:1, y1:1, x2:1, y2:0.495, stop:0 rgba(161, 159, 159, 255), stop:0.460227 rgba(92, 92, 108, 241))}\n"
"\n"
"QWidget::!hover{\n"
"background-color: qlineargradient(spread:reflect, x1:1, y1:1, x2:1, y2:0.495, stop:0 rgba(161, 159, 159, 255), stop:0.460227 rgba(92, 92, 108, 241))}\n"
"\n"
"QWidget::hover{\n"
"background-color:qlineargradient(spread:reflect, x1:1, y1:1, x2:1, y2:0.495, stop:0 rgba(161, 159, 159, 255), stop:0.460227 rgba(44, 44, 51, 241))}\n"
""));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 10, 61, 61));
        pushButton_2->setStyleSheet(QLatin1String("image: url(:/myimages/Resources/return.png);\n"
"border-radius:30px;\n"
"background-color: qlineargradient(spread:reflect, x1:1, y1:0.5, x2:1, y2:0.017, stop:0 rgba(161, 161, 161, 255), stop:1 rgba(70, 70, 82, 255));"));
        widget_2 = new QWidget(ImageWindow);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(150, 290, 81, 81));
        widget_2->setStyleSheet(QLatin1String("QWidget{border-radius: 15px;background-color: qlineargradient(spread:reflect, x1:1, y1:1, x2:1, y2:0.495, stop:0 rgba(161, 159, 159, 255), stop:0.460227 rgba(92, 92, 108, 241))}\n"
"\n"
"QWidget::!hover{\n"
"background-color: qlineargradient(spread:reflect, x1:1, y1:1, x2:1, y2:0.495, stop:0 rgba(161, 159, 159, 255), stop:0.460227 rgba(92, 92, 108, 241))}\n"
"\n"
"QWidget::hover{\n"
"background-color:qlineargradient(spread:reflect, x1:1, y1:1, x2:1, y2:0.495, stop:0 rgba(161, 159, 159, 255), stop:0.460227 rgba(44, 44, 51, 241))}\n"
""));
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 61, 61));
        pushButton->setStyleSheet(QLatin1String("image: url(:/myimages/Resources/nextstep.png);\n"
"border-radius:30px;\n"
"background-color: qlineargradient(spread:reflect, x1:1, y1:0.5, x2:1, y2:0.017, stop:0 rgba(161, 161, 161, 255), stop:1 rgba(70, 70, 82, 255));"));
        pushButton->setFlat(false);
        graphicsView = new QGraphicsView(ImageWindow);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(100, 140, 321, 81));
        label = new QLabel(ImageWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-10, 400, 551, 41));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QStringLiteral("Franklin Gothic Medium Cond"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setMouseTracking(false);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(ImageWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 140, 291, 81));
        QFont font2;
        font2.setFamily(QStringLiteral("Niagara Solid"));
        font2.setPointSize(71);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        font2.setStrikeOut(false);
        label_2->setFont(font2);
        label_2->setStyleSheet(QStringLiteral(""));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(ImageWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(340, 130, 41, 41));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font1);
        label_3->setMouseTracking(false);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAutoFillBackground(false);
        label_3->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        label_3->setAlignment(Qt::AlignCenter);
        graphicsView_2 = new QGraphicsView(ImageWindow);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(-270, -40, 550, 550));
        graphicsView_2->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"\n"
"border-image: url(:/myimages/Resources/enford-logo-01darkgray.png);"));
        graphicsView_3 = new QGraphicsView(ImageWindow);
        graphicsView_3->setObjectName(QStringLiteral("graphicsView_3"));
        graphicsView_3->setGeometry(QRect(70, 20, 101, 31));
        graphicsView_3->setStyleSheet(QLatin1String("\n"
"border-image: url(:/myimages/Resources/enford-logo-02dark.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        graphicsView_4 = new QGraphicsView(ImageWindow);
        graphicsView_4->setObjectName(QStringLiteral("graphicsView_4"));
        graphicsView_4->setGeometry(QRect(10, 10, 60, 60));
        graphicsView_4->setStyleSheet(QLatin1String("border-image: url(:/myimages/Resources/enford-logo-01.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        graphicsView_2->raise();
        graphicsView_3->raise();
        graphicsView->raise();
        label->raise();
        widget->raise();
        widget_2->raise();
        label_2->raise();
        label_3->raise();
        graphicsView_4->raise();

        retranslateUi(ImageWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), ImageWindow, SLOT(accept()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), ImageWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(ImageWindow);
    } // setupUi

    void retranslateUi(QWidget *ImageWindow)
    {
        ImageWindow->setWindowTitle(QApplication::translate("ImageWindow", "Welcome", nullptr));
        pushButton_2->setText(QString());
        pushButton->setText(QString());
        label->setText(QApplication::translate("ImageWindow", " a kinect-based motion analysis system -  Enford International Co.,Ltd", nullptr));
        label_2->setText(QApplication::translate("ImageWindow", "KineMAS", nullptr));
        label_3->setText(QApplication::translate("ImageWindow", "TM", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageWindow: public Ui_ImageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEWINDOW_H
