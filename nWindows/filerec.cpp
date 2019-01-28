#include "filerec.h"
#include "myKinect.h"
#include <io.h>
#include <direct.h>
#define PATH_DELIMITER '\\'
bool createDirectory(const std::string folder) {
	std::string folder_builder;
	std::string sub;
	sub.reserve(folder.size());
	for (auto it = folder.begin(); it != folder.end(); ++it) {
		//cout << *(folder.end()-1) << endl;
		const char c = *it;
		sub.push_back(c);
		if (c == PATH_DELIMITER || it == folder.end() - 1) {
			folder_builder.append(sub);
			if (0 != ::_access(folder_builder.c_str(), 0)) {
				// this folder not exist
				if (0 != ::_mkdir(folder_builder.c_str())) {
					// create failed
					return false;
				}
			}
			sub.clear();
		}
	}
	return true;
}

FileREC::FileREC( QObject *parent )
	: QObject(parent)
{
	m_subName = new char[20];
	fileTimeRec.start();
	//jointsDatafile.open(,);
}

FileREC::FileREC(char* subjName, QObject *parent) : QObject(parent) 
{
	m_subName = subjName;
	
	char  *a = "_Position.csv";
	std::string  ac = std::string(subjName) + std::string(a);
	//拼接positionfilename
	//strcpy(m_fileName, ac.c_str());
	jointsPositionfile.open(ac.c_str(), std::ios::app);


	char  *b = "_Orient.csv";
	std::string  bc = std::string(subjName) + std::string(b);
	//strcpy(m_fileName, bc.c_str());
	jointsOrientfile.open(bc.c_str(), std::ios::app);
	fileTimeRec.start();
}

FileREC::~FileREC()
{
	if (jointsOrientfile.is_open())
	{
		jointsPositionfile.close();
		jointsOrientfile.close();
	}
	
	
	delete[]m_subName;
}

void FileREC::setfilename(char * subjname)
{
	createDirectory(".\\Record");
	m_subName = subjname;
	
	char  *a = "_Position.csv";
	std::string  ac = std::string(".\\Record\\") + std::string(subjname) + std::string(a);
	//拼接positionfilename
	jointsPositionfile.open(ac.c_str(), std::ios::app);


	char  *b = "_Orient.csv";
	std::string  bc = std::string(".\\Record\\") + std::string(subjname) + std::string(b);
	//strcpy(m_fileName, bc.c_str());
	jointsOrientfile.open(bc.c_str(), std::ios::app);
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

//设置文本文件的标题
void FileREC::setfilehead()
{
	if (jointsPositionfile.is_open())
	{
		//标题行
		jointsPositionfile << "# " << "frame " << "," << "time " << "," << "JointType " << "," << "TrackingState " << "," << "X" << "," << "Y" << "," << "Z" << std::endl;
	}
	if (jointsOrientfile.is_open())
	{
		//标题行
		jointsOrientfile << "# " << "frame " << "," << "time " << "," << "JointType " << "," << "x " << "," << "y" << "," << "z" << "," << "w" << std::endl;
	
	}
}

void FileREC::closefile()
{
	jointsPositionfile.close();
	jointsOrientfile.close();
}

void FileREC::Orient2angelFile()
{
	//建立新的文件_Angle.csv
	char  *angstr = "_Angle.csv";
	std::string  fn = std::string(m_subName) + std::string(angstr);
	std::ofstream jointsAnglefile;
	jointsAnglefile.open(fn.c_str(), std::ios::app);
	if (jointsAnglefile.is_open()){
		//标题行
		jointsAnglefile << "# " << "frame " << "," << "time " << "," << "JointType " << "," << "x " << "," << "y" << "," << "z"  << std::endl;
	}
	//从orient.csv读取data
	char  *b = "_Orient.csv";
	std::string  filename = std::string(".\\Record\\")+std::string(m_subName) + std::string(b);
	QFile * p_file = new QFile(QString::fromStdString(filename));
	if (!p_file->open(QIODevice::ReadOnly)) {
		qDebug() << "cant read joint file" << endl;
	}
	QTextStream	*p_stream = new QTextStream(p_file);

	p_stream->seek(0);//seek可以把文件流指针移到想要的位置

	//存下整个表
	Eigen::Vector4f quats;
	Eigen::Vector3f ang;
	while (!p_stream->atEnd())
	{
		QString fetures = p_stream->readLine();
		QStringList blocks = fetures.split(",", QString::SkipEmptyParts);
		if (fetures.startsWith("#"))
		{
			continue;
		}
		quats[0] = blocks[3].toFloat();
		quats[1] = blocks[4].toFloat();
		quats[2] = blocks[5].toFloat();
		quats[3] = blocks[6].toFloat();
		ang = myKinect::QuaternionToEuler(quats);

		jointsAnglefile << blocks[0].toInt() << "," << blocks[1].toFloat()/1000.0 << "," << blocks[2].toInt() << "," << ang.x() << "," << ang.y() << "," << ang.z()  << std::endl;
	}
	jointsAnglefile.close();
}

//When filetimer time out, call processfile, 每隔一定时间记录一个frame，间隔时间由filetimer设定
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
			/*文件输出格式在此修改*/
			//取消注释来启用
			/*jointsDatafile << "frame: " << frameNum << "  ,  " << fileTimeRec.elapsed() << std::endl;
			jointsDatafile << "JointType: " << joint.JointType  << std::endl;
			jointsDatafile << "TrackingState: " << joint.TrackingState << std::endl;
			jointsDatafile << "position: " << joint.Position.X << " , " << joint.Position.Y << " , " << joint.Position.Z << std::endl;
			jointsDatafile << " --------------------------------------------------------------------------" << std::endl;*/

			/*txt格式
			 --------------------------------------------------------------------------
			frame: 1  ,  995
			JointType: 3
			TrackingState: 2
			position: 0.595964 , 0.588852 , 1.98885
			--------------------------------------------------------------------------
			*/

			//csv格式
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


