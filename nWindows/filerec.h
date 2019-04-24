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
	QString m_trailName;

	void creatFiles(QString trailName, QString path);
	//Update
	void updateJoints(Joint jointdate[JointType_Count]);
	void updateOrientations(JointOrientation Orientdata[JointType_Count]);
	void updateSegCOM(std::array<Eigen::Vector3f, 13>& segCOMdata);
	void updateJointAngles(std::array<float, 9>& JointAngleData);
	//����ؽ�λ��
	std::vector<Joint> jointPositions();
	//����ؽ���ת����Ԫ����
	std::vector<JointOrientation> JointOrientations();
	//���segCOMλ��
	std::array<Eigen::Vector3f,13> segCOMs();
	//���4�������ɶȹؽڽǶ�
	std::array<float, 9> JointAngles();
	//���cali�Ƕȵ���Ѷ
	CaliData caliAngle;


	void setfilehead();
	void closefile();
	//����Ԫ�����ĵ�ת���ɹؽڽǶȵ��ĵ�
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
	//�̹߳���
	
	bool m_runStatus{true};
public:
	QTimer *filetimer;
	void start();
	void stop();
};
