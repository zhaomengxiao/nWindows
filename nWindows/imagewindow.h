#pragma once

#include <QDialog>
#include "ui_ImageWindow.h"

class ImageWindow : public QDialog
{
	Q_OBJECT

public:
	ImageWindow(QDialog *parent = 0);
	~ImageWindow();

private:
	Ui::ImageWindow ui;
};
