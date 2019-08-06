/*********************************************************************************
  *Copyright(C),National Taiwan University , OEMAL 
  *FileName:  filerec.h
  *Author:   ZHAO YOUJUN
  *Version:  1.00
  *Date:	 2018/11/22
  *Description:  
  *Others:  //��������˵��
  *Function List:  //��Ҫ�����б�ÿ����¼Ӧ���������������ܼ�Ҫ˵��
	 1. updateJoints(Joint jointdate[JointType_Count]){
			��mainwaidow.cpp�е� [ updateSkeletonFrame() ] ��kinect����Joint���ϲ��Ҵ�����;
			}
	 2. updateSegCOM(std::array<Eigen::Vector3f, 13> segCOMdata){
			��mainwaidow.cpp�е� [ updateSkeletonFrame() ] ��kinect����segCOMdata���ϲ��Ҵ�����;
			}
	 3. updateJotAngle(std::array<Eigen::Vector3f, 13> segCOMdata){
			��mainwaidow.cpp�е� [ updateSkeletonFrame() ] ��kinect����segCOMdata���ϲ��Ҵ�����;
			}
	 4. slot[processfile()]{
			When *filetimer* time out, call *processfile*, ÿ��һ��ʱ���¼һ��frame�����ʱ����filetimer�趨;
			}
  *History:  //�޸���ʷ��¼�б�ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸��߼��޸����ݼ��
	 1.Date:
	   Author:
	   Modification:
	 2.��������
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

//�趨�Ƿ��ӡ����Debug��Ѷ��
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
	//����ؽ�λ��
	OBJ::Joints jointPositions();
	//���segCOMλ��
	std::array<Eigen::Vector3f,13> segCOMs();
	//�趨����
	int framerate{25};
	//�趨�ļ�ͷ
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
	
	//�̹߳���
	
	bool m_runStatus{true};
public:
	QTimer *filetimer;
	void start();
	void stop();
	
	//���ļ�����ת����obj
	void readTrail(OBJ::Obj &obj);
	void readSubjInfo(OBJ::Obj &obj);
	void readCali(OBJ::Obj &obj);
	static std::vector<double> readViconAngle(QString filepath);
	//��obj�е�����ת��csv�ļ�
	void writeTrialAngle(OBJ::Obj &obj);
	void writeMoment(OBJ::Obj &obj);
	//��Kinect��Joint����תΪ�Լ���OBJ::Joint
	OBJ::Joint KinectJ_2_ObjJ(const Joint &joint);
};
