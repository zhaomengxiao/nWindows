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
#include <Eigen\Dense>

class FileREC : public QObject
{
	Q_OBJECT

public:
	FileREC(QObject *parent =0);
	FileREC(char* subjName , QObject *parent = 0);
	~FileREC();

public slots:
	void processfile();

public:
	void setfilename(char* fanme);
	void updateJoints(Joint jointdate[JointType_Count]);
	void updateOrientations(JointOrientation Orientdata[JointType_Count]);
	void updateSegCOM(std::array<Eigen::Vector3f, 13> segCOMdata);
	//����ؽ�λ��
	std::vector<Joint> jointPositions();
	//����ؽ���ת����Ԫ����
	std::vector<JointOrientation> JointOrientations();
	//���segCOMλ��
	std::array<Eigen::Vector3f,13> segCOMs();

	void setfilehead();
	void closefile();
	//����Ԫ�����ĵ�ת���ɹؽڽǶȵ��ĵ�
	void Orient2angelFile();
private:
	char* m_subName ;
	std::ofstream jointsPositionfile;
	std::ofstream jointsOrientfile;
	std::vector<Joint> jointPosition_saved;
	std::vector<JointOrientation> JointOrientation_saved;
	std::array<Eigen::Vector3f,13> segCOM_saved;
	QTime fileTimeRec;
	int frameNum{0};
};
