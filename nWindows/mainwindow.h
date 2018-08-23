#pragma once

#include <QtWidgets/QMainWindow>
#include <QAction>
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QTimer>
#include <QLayout>
//include <QtCharts>
//opencv include
#include <OpenNI.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//openni include

//class
#include "camera.h"
#include "myKinect.h"
//cpp
#include <math.h>
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();
	 
private://**˽�г�Ա����**
	Ui::MainWindowClass ui;
	
	//�½������˵��� �ļ��ͱ༭��
	QMenu *fileMenu;
	QMenu *editMenu;

	QAction *fileOpenImage;
	QAction *fileOpenVedio;
	QAction *showSkeleton;

	//��ʾͼƬ��
	cv::Mat image;
	//�洢ȥ����ͼƬ
	cv::Mat backmoveimage;
	QString tmp;
//	cv::Vec3b rand ;
	//��ʾ��Ƶ��
	//Xtion2
	QTimer *videotimer;
	camera *myCamera;
	QLabel *showdepthimage_label;
	QLabel *showcolorimage_label;
	QPushButton *opencamera_button;
	QPushButton *closecamera_button;
	//Kinect2
	QTimer *skeletontimer;
	myKinect *mykinect;
private://**˽�к���**
	//����
	void createAction();   //��������
	void createMenu();     //�����˵�
	void connectSignalSlot(); //�����źźͲ�
	//����
	
private slots:
	void on_pushButton_clicked();
	void fileOpenImage_clicked();
	void fileOpenVedio_clicked();
	void showSkeleton_clicked();
	void updateVideoFrame();
	void updateSkeletonFrame();
	void stopCamera();
	void startCamera();
	void on_saveImageButton_clicked();
};
