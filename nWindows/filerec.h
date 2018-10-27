#pragma once

#include <QObject>
#include <qthread.h>
#include <qdebug.h>
#include <fstream>
#include <Kinect.h>
#include <iostream>
#include <vector>
#include <Qtime>
class FileREC : public QObject
{
	Q_OBJECT

public:
	FileREC(QObject *parent =0);
	~FileREC();

public slots:
	void processfile();

public:
	void updateJoints(Joint jointdate[JointType_Count]);
	std::vector<Joint> record();

private:
	//const char* m_fileName;
	std::ofstream jointsDatafile{"test.txt", std::ios::app };
	std::vector<Joint> jointdata_saved;
	QTime fileTimeRec;
	int frameNum{0};
};
