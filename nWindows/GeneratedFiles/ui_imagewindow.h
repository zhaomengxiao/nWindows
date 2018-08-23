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
        widget->setGeometry(QRect(320, 270, 81, 81));
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
        widget_2->setGeometry(QRect(130, 270, 81, 81));
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
        graphicsView->setGeometry(QRect(40, 120, 441, 51));
        label = new QLabel(ImageWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 400, 511, 41));
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
        label->setStyleSheet(QStringLiteral(""));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(ImageWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 60, 381, 171));
        QFont font2;
        font2.setFamily(QStringLiteral("Niagara Solid"));
        font2.setPointSize(71);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        font2.setStrikeOut(false);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);
        graphicsView->raise();
        label->raise();
        widget->raise();
        widget_2->raise();
        label_2->raise();

        retranslateUi(ImageWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), ImageWindow, SLOT(accept()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), ImageWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(ImageWindow);
    } // setupUi

    void retranslateUi(QWidget *ImageWindow)
    {
        ImageWindow->setWindowTitle(QApplication::translate("ImageWindow", "ImageWindow", nullptr));
        pushButton_2->setText(QString());
        pushButton->setText(QString());
        label->setText(QApplication::translate("ImageWindow", "OEMAL\302\256", nullptr));
        label_2->setText(QApplication::translate("ImageWindow", "Motion Capture", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageWindow: public Ui_ImageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEWINDOW_H
