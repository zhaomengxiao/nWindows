#pragma once

#include <QObject>
#include <qthread.h>
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
	~FileREC();

public slots:
	void processfile();

public:
	std::vector<Joint> record();
	void updateJoints(Joint jointdate[JointType_Count]);
	
	std::array<Eigen::Vector3f,13> segCOM();
	void updateSegCOM(std::array<Eigen::Vector3f, 13> segCOMdata);

private:
	//const char* m_fileName;
	std::ofstream jointsDatafile{"test.txt", std::ios::app };
	std::vector<Joint> jointdata_saved;
	std::array<Eigen::Vector3f,13> segCOM_saved;
	QTime fileTimeRec;
	int frameNum{0};
};
