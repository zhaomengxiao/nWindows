#include "filerec.h"

FileREC::FileREC( QObject *parent )
	: QObject(parent)
{
	fileTimeRec.start();
	//jointsDatafile.open(,);
}

FileREC::~FileREC()
{
	jointsDatafile.close();
}

void FileREC::updateJoints(Joint jointdata[JointType_Count])
{
	jointdata_saved.reserve(JointType_Count);
	jointdata_saved.clear();
	jointdata_saved.assign(&jointdata[0], &jointdata[JointType_Count]);
}

std::vector<Joint> FileREC::record()
{
	return jointdata_saved;
}

void FileREC::processfile() {
	frameNum++;
	//qDebug() << "process()" << QThread::currentThreadId();
	if (!jointsDatafile.is_open()){
		std::cout << "failed to open data file." << std::endl;
		return;
	}
	for (auto joint : jointdata_saved)
	{
		if (joint.TrackingState ==TrackingState_Tracked )
		{
			jointsDatafile << "frame: " << frameNum << "  ,  " << fileTimeRec.elapsed() << std::endl;
			jointsDatafile << "JointType: " << joint.JointType  << std::endl;
			jointsDatafile << "TrackingState: " << joint.TrackingState << std::endl;
			jointsDatafile << "position: " << joint.Position.X << " , " << joint.Position.Y << " , " << joint.Position.Z << std::endl;
			jointsDatafile << " --------------------------------------------------------------------------" << std::endl;
		}
	}
}


