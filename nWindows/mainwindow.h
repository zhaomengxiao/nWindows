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
	myKinect *mykinect = NULL;//Ĭ������ΪNULL,�����ж��Ƿ��ʼ�������жϻ��п�ָ������⡣
	//Kinect skeleton
	//��ʾͼ��
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


	//�������ݵ��ļ�
	//FileREC *recorder = NULL;
	//QTimer *filetimer;
	QThread *thread;
	
	//vtk scene
	VTK *scene;

	//�ļ�Ŀ¼
	QTreeWidgetItem * root;
	QString rootPath;
public:
	//int drawVTKscene();   //����3d����
private://**˽�к���**
	//����
	void createAction();   //��������
	void createMenu();     //�����˵�
	void connectSignalSlot(); //�����źźͲ�
	
	//����
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
	//�����������
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
	//��¼�������̿���
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

	//filerec ����֮�źŲ�
	void error_openfile();
	void readFileProgress(int f);
	//�ļ�Ԥ������
	void Click(QTreeWidgetItem *item);
	void DoubleClick(QTreeWidgetItem *item);
	void Expend(QTreeWidgetItem *item);
	void UpdateDir();
	QFileInfoList allFile(QTreeWidgetItem *item,QString path);

	//��������¼������
	void readRec();
};
