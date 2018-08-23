#include "imagewindow.h"

ImageWindow::ImageWindow(QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setStyleSheet("background-color:#464652;color:#E8E8E8");


}

ImageWindow::~ImageWindow()
{
}
