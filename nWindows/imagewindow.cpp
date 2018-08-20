#include "imagewindow.h"

ImageWindow::ImageWindow(QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setStyleSheet("background-color:#464652;color:#E8E8E8");
	QIcon nextIcon(":/myimages/Resources/nextstep.png");
	ui.pushButton->setIcon(nextIcon);
	QIcon returnIcon(":/myimages/Resources/return.png");
	ui.pushButton_2->setIcon(returnIcon);

}

ImageWindow::~ImageWindow()
{
}
