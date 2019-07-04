#pragma once

#include <QtWidgets/QMainWindow>
#include <QAction>
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QTimer>
#include <QLayout>
#include <QTreeWidget>
#include <QProgressBar>  
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <qdesktopservices.h>
#include <qprocess.h>
//charts
#include <QtCharts/qchartview.h>
#include <QtCharts\qlineseries.h>
#include <QDateTime>
#include "linechart.h"


//class
#include "camera.h"
#include "myKinect.h"
#include "filerec.h"
#include "optimiz.h"
#include "filter.h"
#include "cycle.h"
//h
#include <math.h>
#include <fstream>

//vtk
#include "vtk.h"


QT_CHARTS_USE_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();
	friend class VTK;
private://**私有成员变量**
	Ui::MainWindowClass ui;
	
	//新建两个菜单项 文件和编辑；
	QMenu *fileMenu;
	QMenu *editMenu;

	QAction *fileOpenImage;
	QAction *fileOpenVedio;
	QAction *showSkeleton;

	//显示图片用
	cv::Mat image;
	//存储去背的图片
	cv::Mat backmoveimage;
	QString tmp;
//	cv::Vec3b rand ;
	//显示视频用
	//Xtion2
	QTimer *videotimer;
	camera *myCamera;
	QLabel *showdepthimage_label;
	QLabel *showcolorimage_label;
	QPushButton *opencamera_button;
	QPushButton *closecamera_button;
	//Kinect2
	QTimer *skeletontimer;
	myKinect *mykinect = NULL;//默认设置为NULL,可以判断是否初始化，不判断会有空指针的问题。
	//Kinect skeleton
	//显示图表
	/*Chart *chart = NULL;*/
	int recTime{0};
	//others
	QTimer *lcdtimer;
	QTimer *rectimer;
	QTimer *lapsetimer;
	QTime lapsed;
	//countDown time
	int countDown{0};
	//timelapse time
	int tLapse;


	//保存数据到文件
	//FileREC *recorder = NULL;
	//QTimer *filetimer;
	QThread *thread;
	
	//vtk scene
	VTK *scene;

	//文件目录
	QTreeWidgetItem * root;
	QString rootPath;
public:
	//int drawVTKscene();   //绘制3d场景
private://**私有函数**
	//界面
	void createAction();   //创建动作
	void createMenu();     //创建菜单
	void connectSignalSlot(); //链接信号和槽
	
	//功能
private slots:
	void on_pushButton_calibration_clicked();
	void fileOpenImage_clicked();
	void fileOpenVedio_clicked();
	void showSkeleton_clicked();
	void updateVideoFrame();
	void updateSkeletonFrame();
	void updateLCDnumber_date();
	void updateLCDnumber_RecTime();
	void stopCamera();
	void startCamera();
	void on_saveImageButton_clicked();
	//面板数据输入
	void ListCurChange(int row);
	void LineEdit_f(QString str);
	void LineEdit_bodyWeight(QString str);
	void LineEdit_bagX(QString str);
	void LineEdit_bagY(QString str);
	void LineEdit_bagZ(QString str);
	void LineEdit_subjName(QString str);
	void bagSelect(bool);
	void SimpleMode(bool);
	void OffMode(bool);
	void Nframe(int i);
	void SetCD(int t);
	void ResetCD();
	void SetLT(QString str);
	//记录数据流程控制
	void ready4Rec();
	void releaseOKbutton();
	void newTrail();
	void startRec();
	void stopRec();
	void timeLapse();
	void oneLapse();
	void caliSaved();
	//522
	//void calSubcaliAngle(); 

	//filerec 发送之信号槽
	void error_openfile();
	void readFileProgress(int f);
	//文件预览界面
	void Click(QTreeWidgetItem *item);
	void DoubleClick(QTreeWidgetItem *item);
	void Expend(QTreeWidgetItem *item);
	void UpdateDir();
	QFileInfoList allFile(QTreeWidgetItem *item,QString path);

	//处理已收录的数据
	void readRec();
};
