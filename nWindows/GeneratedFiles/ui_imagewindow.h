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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageWindow
{
public:
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_2;
    QGraphicsView *graphicsView;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;

    void setupUi(QWidget *ImageWindow)
    {
        if (ImageWindow->objectName().isEmpty())
            ImageWindow->setObjectName(QStringLiteral("ImageWindow"));
        ImageWindow->resize(359, 290);
        QFont font;
        font.setPointSize(10);
        ImageWindow->setFont(font);
        gridLayout_3 = new QGridLayout(ImageWindow);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 2, 2, 1, 1);

        verticalSpacer = new QSpacerItem(288, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 2, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(1, 1, 1, 1);
        pushButton = new QPushButton(ImageWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(ImageWindow);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 1, 1, 1);

        label = new QLabel(ImageWindow);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QStringLiteral("Freestyle Script"));
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setMouseTracking(false);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAutoFillBackground(false);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 3, 0, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(278, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(278, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 4, 0, 1, 3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        graphicsView = new QGraphicsView(ImageWindow);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout_2->addWidget(graphicsView, 3, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 3, 1, 1, 1);

        label_2 = new QLabel(ImageWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font2;
        font2.setFamily(QStringLiteral("Niagara Solid"));
        font2.setPointSize(43);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        font2.setStrikeOut(false);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 4, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 2, 3);


        retranslateUi(ImageWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), ImageWindow, SLOT(accept()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), ImageWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(ImageWindow);
    } // setupUi

    void retranslateUi(QWidget *ImageWindow)
    {
        ImageWindow->setWindowTitle(QApplication::translate("ImageWindow", "ImageWindow", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        label->setText(QApplication::translate("ImageWindow", "half-time double-tea", nullptr));
        label_2->setText(QApplication::translate("ImageWindow", "SIMPLE EDITOR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageWindow: public Ui_ImageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEWINDOW_H
