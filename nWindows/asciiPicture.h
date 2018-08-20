#pragma once

#include <String>
#include <QtWidgets/QMainWindow>
#include <QAction>
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QTimer>

//opencv include

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class asciiPicture
{
public:
	asciiPicture();
	~asciiPicture();

public:
	cv::Mat inputRGB;
private:
	std::string ascii;
	cv::Mat gray;
	cv::Mat background;
public:
	cv::Mat RGB2GRAY();
	void Picture2ascii();
	cv::Mat newImage();
	
};

