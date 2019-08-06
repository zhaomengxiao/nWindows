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
#include "obj.h"
#include "myKinect.h"
#include <io.h>
#include <direct.h>

//设定是否打印更多Debug资讯，
//#define _Debug

#ifdef _Debug
#define Dbg(...) qDebug() << (__VA_ARGS__) << endl
#else
#define Dbg(...)
#endif

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
	void ReadFileProgress(int f);
public slots:
	void processfile();

public:
	void setSubjInfo(SubjInfo &subj);
	void creatDir();
	QString m_subjpath;
	QString m_trailName{"0"};
	int frameNum{ 0 };
	void creatFiles(QString trailName, QString path);
	//Update
	void updateJoints(Joint jointdate[JointType_Count]);
	void updateSegCOM(std::array<Eigen::Vector3f, 13>& segCOMdata);
	//void updateJointAngles(std::array<float, 9>& JointAngleData);
	//输出关节位置
	OBJ::Joints jointPositions();
	//输出segCOM位置
	std::array<Eigen::Vector3f,13> segCOMs();
	//设定幁率
	int framerate{25};
	//设定文件头
	void setfilehead();
	void closefile();
private:
	SubjInfo m_subjinfo;
	//char* m_subName ;
	std::string path_subjInfo{"null"};
	std::ofstream subjinfofile;
	std::ofstream jointsPositionfile;
	std::ofstream jointsOrientfile;
	std::ofstream jointsAnglefile;
	OBJ::Joints jointPosition_saved;
	std::array<Eigen::Vector3f,13> segCOM_saved;

	QTime fileTimeRec;
	
	//线程管理
	
	bool m_runStatus{true};
public:
	QTimer *filetimer;
	void start();
	void stop();
	
	//把文件数据转换到obj
	void readTrail(OBJ::Obj &obj);
	void readSubjInfo(OBJ::Obj &obj);
	void readCali(OBJ::Obj &obj);
	static std::vector<double> readViconAngle(QString filepath);
	//把obj中的内容转到csv文件
	void writeTrialAngle(OBJ::Obj &obj);
	void writeMoment(OBJ::Obj &obj);
	//把Kinect的Joint数据转为自己的OBJ::Joint
	OBJ::Joint KinectJ_2_ObjJ(const Joint &joint);
};
