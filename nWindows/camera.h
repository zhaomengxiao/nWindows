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
#include <OpenNI.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>


class camera
{
public:
	camera();
	~camera();
	void openCamera();
	void createStream();
	void showImage();
	void closeCamera();
	bool isnotclosed();
private:
	openni::Device mDevice;
	openni::VideoStream mDepthStream;
	openni::VideoStream mColorStream;
	openni::VideoMode mMode;
	openni::VideoFrameRef  mColorFrame;
	openni::VideoFrameRef  mDepthFrame;
	cv::Mat cImageRGB;
	cv::Mat mScaledDepth;
	int iMaxDepth;

public:
	QImage colorImage;
	QImage depthImage;
private:
	void warningBox(char* myMassage);
};

