#include "filerec.h"

FileREC::FileREC( QObject *parent )
	: QObject(parent)
{
	fileTimeRec.start();
	//jointsDatafile.open(,);
}

FileREC::~FileREC()
{
	jointsPositionfile.close();
	jointsOrientfile.close();
}

void FileREC::updateJoints(Joint jointdata[JointType_Count])
{
	jointPosition_saved.reserve(JointType_Count);
	jointPosition_saved.clear();
	jointPosition_saved.assign(&jointdata[0], &jointdata[JointType_Count]);
}

void FileREC::updateOrientations(JointOrientation Orientdata[JointType_Count])
{
	JointOrientation_saved.reserve(JointType_Count);
	JointOrientation_saved.clear();
	JointOrientation_saved.assign(&Orientdata[0], &Orientdata[JointType_Count]);
}

std::vector<Joint> FileREC::jointPositions()
{
	return jointPosition_saved;
}

std::vector<JointOrientation> FileREC::JointOrientations()
{
	return JointOrientation_saved;
}

std::array<Eigen::Vector3f, 13> FileREC::segCOMs()
{
	return segCOM_saved;
}

void FileREC::updateSegCOM(std::array<Eigen::Vector3f, 13> segCOMdata)
{
	segCOM_saved = segCOMdata;
}

//�����ı��ļ��ı���
void FileREC::setfilehead()
{
	if (jointsPositionfile.is_open())
	{
		//������
		jointsPositionfile << "# " << "frame " << "," << "time " << "," << "JointType " << "," << "TrackingState " << "," << "X" << "," << "Y" << "," << "Z" << std::endl;
	}
	if (jointsOrientfile.is_open())
	{
		//������
		jointsPositionfile << "# " << "frame " << "," << "time " << "," << "JointType " << "," << "x " << "," << "y" << "," << "z" << "," << "w" << std::endl;
	
	}
}

//When filetimer time out, call processfile, ÿ��һ��ʱ���¼һ��frame�����ʱ����filetimer�趨
void FileREC::processfile() {
	frameNum++;
	//qDebug() << "process()" << QThread::currentThreadId();
	if (!jointsPositionfile.is_open()){
		std::cout << "failed to open data file." << std::endl;
		return;
	}
	
	for (auto joint : jointPosition_saved)
	{
		if (joint.TrackingState ==TrackingState_Tracked )
		{
			/*�ļ������ʽ�ڴ��޸�*/
			//ȡ��ע��������
			/*jointsDatafile << "frame: " << frameNum << "  ,  " << fileTimeRec.elapsed() << std::endl;
			jointsDatafile << "JointType: " << joint.JointType  << std::endl;
			jointsDatafile << "TrackingState: " << joint.TrackingState << std::endl;
			jointsDatafile << "position: " << joint.Position.X << " , " << joint.Position.Y << " , " << joint.Position.Z << std::endl;
			jointsDatafile << " --------------------------------------------------------------------------" << std::endl;*/

			/*txt��ʽ
			 --------------------------------------------------------------------------
			frame: 1  ,  995
			JointType: 3
			TrackingState: 2
			position: 0.595964 , 0.588852 , 1.98885
			--------------------------------------------------------------------------
			*/

			//csv��ʽ
			jointsPositionfile << frameNum << "," << fileTimeRec.elapsed() << "," << joint.JointType << "," << joint.TrackingState << "," << joint.Position.X << "," << joint.Position.Y << "," << joint.Position.Z << std::endl;

		}
	}

	if (!jointsOrientfile.is_open()) {
		std::cout << "failed to open data file." << std::endl;
		return;
	}
	for (auto orient: JointOrientation_saved)
	{
		if (orient.JointType >= 0) {
			jointsOrientfile << frameNum << "," << fileTimeRec.elapsed() << "," << orient.JointType << ","  << orient.Orientation.x << "," << orient.Orientation.y << "," << orient.Orientation.z << "," << orient.Orientation.w << std::endl;
		}
	}
}


