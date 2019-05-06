/*********************************************************************************
  *Copyright(C),National Taiwan University , OEMAL 
  *FileName:  filerec.h
  *Author:   ZHAO YOUJUN
  *Version:  1.00
  *Date:	 2018/11/22
  *Description:  
  *Others:  //其他内容说明
  *Function List:  //主要函数列表，每条记录应包含函数名及功能简要说明
	 1. updateJoints(Joint jointdate[JointType_Count]){
			在mainwaidow.cpp中的 [ updateSkeletonFrame() ] 从kinect传入Joint资料并且存下来;
			}
	 2. updateSegCOM(std::array<Eigen::Vector3f, 13> segCOMdata){
			在mainwaidow.cpp中的 [ updateSkeletonFrame() ] 从kinect传入segCOMdata资料并且存下来;
			}
	 3. updateJotAngle(std::array<Eigen::Vector3f, 13> segCOMdata){
			在mainwaidow.cpp中的 [ updateSkeletonFrame() ] 从kinect传入segCOMdata资料并且存下来;
			}
	 4. slot[processfile()]{
			When *filetimer* time out, call *processfile*, 每隔一定时间记录一个frame，间隔时间由filetimer设定;
			}
  *History:  //修改历史记录列表，每条修改记录应包含修改日期、修改者及修改内容简介
	 1.Date:
	   Author:
	   Modification:
	 2.…………
	   __            __            __            __            __
     /  /\         /  /\         /  /\         /  /\         /  /\
    /  /::\       /  /::\       /  /::|       /  /::\       /  /:/
   /  /:/\:\     /  /:/\:\     /  /:|:|      /  /:/\:\     /  /:/ 
  /  /:/  \:\   /  /::\ \:\   /  /:/|:|__   /  /::\ \:\   /  /:/  
 /__/:/ \__\:\ /__/:/\:\ \:\ /__/:/_|::::\ /__/:/\:\_\:\ /__/:/   
 \  \:\ /  /:/ \  \:\ \:\_\/ \__\/  /~~/:/ \__\/  \:\/:/ \  \:\   
  \  \:\  /:/   \  \:\ \:\         /  /:/       \__\::/   \  \:\  
   \  \:\/:/     \  \:\_\/        /  /:/        /  /:/     \  \:\ 
    \  \::/       \  \:\         /__/:/        /__/:/       \  \:\
     \__\/         \__\/         \__\/         \__\/         \__\/
**********************************************************************************/



#pragma once

#include <QObject>
#include <qthread.h>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <qdebug.h>
#include <fstream>
#include <Kinect.h>
#include <iostream>
#include <vector>
#include <array>
#include <Qtime>
#include <qtimer.h>
#include <Eigen\Dense>
struct CaliData
{
	int KneeR{0};
	int KneeL{0};
	int ElbowR{ 0 };
	int ElbowL{ 0 };
	float Spine{ 0.0};
	int ShouderR{ 0 };
	int ShouderL{ 0 };
};

struct SubjInfo {
	QString subjname{"null"};
	QString gender{"null"};
	QString preside{ "null" };
	int age{ 0 };
	float height{ 0.0 };
	float weight{ 0.0 };
	float bagWeight{ 0.0 };
	std::vector<float> bagPosi{ 0.0,0.0,0.0 };
	bool bag{ false };

	

	void print() {
		qDebug() << "subjname: " << subjname << endl;
		qDebug() << "gender: " << gender << endl;
		qDebug() << "age: " << age << endl;
		qDebug() << "height: " << height << endl;
		qDebug() << "weight: " << weight << endl;
		qDebug() << "bagPosi: " << bagPosi << endl;
		qDebug() << "bagWeight: " << bagWeight << endl;
		qDebug() << "isbag: " << bag << endl;
	}
};

class FileREC : public QObject
{
	Q_OBJECT

public:
	FileREC(QObject *parent =0);
	FileREC(char* subjName , QObject *parent = 0);
	~FileREC();
signals:
	void Recording();
	void Error_openfile();
public slots:
	void processfile();

public:
	void setSubjInfo(SubjInfo &subj);
	void creatDir();
	QString m_subjpath;
	QString m_trailName{"0"};

	void creatFiles(QString trailName, QString path);
	//Update
	void updateJoints(Joint jointdate[JointType_Count]);
	void updateOrientations(JointOrientation Orientdata[JointType_Count]);
	void updateSegCOM(std::array<Eigen::Vector3f, 13>& segCOMdata);
	void updateJointAngles(std::array<float, 9>& JointAngleData);
	//输出关节位置
	std::vector<Joint> jointPositions();
	//输出关节旋转（四元数）
	std::vector<JointOrientation> JointOrientations();
	//输出segCOM位置
	std::array<Eigen::Vector3f,13> segCOMs();
	//输出4个单自由度关节角度
	std::array<float, 9> JointAngles();
	//输出cali角度的资讯
	CaliData caliAngle;
	//设定幁率
	int framerate{25};
	//设定文件头
	void setfilehead();
	void closefile();
	//把四元数的文档转换成关节角度的文档
	void Orient2angelFile();
	void CalSubcaliAngle();
private:
	SubjInfo m_subjinfo;
	char* m_subName ;
	std::ofstream subjinfofile;
	std::ofstream jointsPositionfile;
	std::ofstream jointsOrientfile;
	std::ofstream jointsAnglefile;
	std::vector<Joint> jointPosition_saved;
	std::vector<JointOrientation> JointOrientation_saved;
	std::array<Eigen::Vector3f,13> segCOM_saved;
	std::array<float, 9> JointAngle_saved;
	QTime fileTimeRec;
	int frameNum{0};
	//线程管理
	
	bool m_runStatus{true};
public:
	QTimer *filetimer;
	void start();
	void stop();
};
