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
	////命名文件并打开
	//m_subName = subjName;
	//
	//char  *a = "_Position.csv";
	//std::string  ac = std::string(subjName) + std::string(a);
	////拼接positionfilename
	////strcpy(m_fileName, ac.c_str());
	//jointsPositionfile.open(ac.c_str(), std::ios::app);


	//char  *b = "_Orient.csv";
	//std::string  bc = std::string(subjName) + std::string(b);
	////strcpy(m_fileName, bc.c_str());
	//jointsOrientfile.open(bc.c_str(), std::ios::app);

	//char  *c = "_4Angle.csv";
	//std::string  cc = std::string(subjName) + std::string(c);
	////strcpy(m_fileName, bc.c_str());
	//jointsAnglefile.open(cc.c_str(), std::ios::app);
	
	
	//开始计时
	fileTimeRec.start();


}

FileREC::~FileREC()
{
	if (jointsOrientfile.is_open())
	{
		jointsPositionfile.close();
		jointsOrientfile.close();
		jointsAnglefile.close();
		subjinfofile.close();
	}
	
	
	delete[]m_subName;
}

void FileREC::setSubjInfo(SubjInfo & subj)
{
	m_subjinfo = subj;
	
	
}

void FileREC::creatDir()
{
	createDirectory(".\\Record");
	QDateTime dateTime = QDateTime::currentDateTime();

	QString dateDir = dateTime.toString("yyyy-MM-dd");
	QString dir = ".\\Record\\" + dateDir + "\\" + this->m_subjinfo.subjname;
	
	m_subjpath = dir + "\\";
	createDirectory(dir.toStdString());


	//储存subjinfo
	QString s = "SubjInfo.csv";
	std::string sc = (m_subjpath + s).toStdString();
	subjinfofile.open(sc.c_str(), std::ios::app);
	
	if (subjinfofile.is_open())
	{
		//标题行
		subjinfofile << "Subject Name " << "," << "Gender " << "," << "Preferred Side "
			<< "," << "age " << "," << "Height" << "," << "Weight" << "," << "Bag Weight" << "," << "Bag Position" << std::endl;
		subjinfofile << m_subjinfo.subjname.toStdString() << "," << m_subjinfo.gender.toStdString() << "," << m_subjinfo.preside.toStdString()
			<< "," << m_subjinfo.age << "," << m_subjinfo.height << "," << m_subjinfo.weight << "," << m_subjinfo.bagWeight << "," << m_subjinfo.bagPosi[0] << "," << m_subjinfo.bagPosi[1] << "," << m_subjinfo.bagPosi[2] << std::endl;
		qDebug() << "subjInfo saved" << endl;
	}
	else
	{
		qDebug() << "can't open subjinfofile" << endl;
	}
	subjinfofile.close();
}

void FileREC::creatFiles(QString trailName, QString path)
{
	m_trailName = trailName;
	

	QString p = "_Position.csv";
	std::string  pc = (path + trailName + p).toStdString();
	jointsPositionfile.open(pc.c_str(), std::ios::app);


	QString o = "_Orient.csv";
	std::string  oc = (path + trailName + o).toStdString();
	jointsOrientfile.open(oc.c_str(), std::ios::app);

	QString  a = "_Angle.csv";
	std::string  ac = (path + trailName + a).toStdString();
	jointsAnglefile.open(ac.c_str(), std::ios::app);
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

void FileREC::updateSegCOM(std::array<Eigen::Vector3f, 13>& segCOMdata)
{
	segCOM_saved = segCOMdata;
}

void FileREC::updateJointAngles(std::array<float, 9>& JointAngleData)
{
	JointAngle_saved = JointAngleData;
}

std::array<float, 9> FileREC::JointAngles()
{
	return JointAngle_saved;
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
	if (jointsAnglefile.is_open())
	{
		//标题行
		jointsAnglefile << "# " << "frame " << "," << "time " << "," << "ElbowR " << "," << "ElbowL " << "," << "KneeR" << "," << "KneeL" << "," <<"Spine" << "," <<"ShouderR" << "," <<"ShouderL" << "," <<"Neckfb" << "," <<"Necklr"<<std::endl;

	}
}

void FileREC::closefile()
{
	jointsPositionfile.close();
	jointsOrientfile.close();
	jointsAnglefile.close();
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
	p_file->close();
}

void FileREC::CalSubcaliAngle()
{
	
	//从Subjname_cali_4Angle.csv读取data
	char  *b = "cali_Angle.csv";
	std::string  filename = m_subjpath.toStdString() + std::string(b);
	QFile * p_file = new QFile(QString::fromStdString(filename));
	if (!p_file->open(QIODevice::ReadOnly)) {
		qDebug()<< QString::fromStdString(filename) << "cant read cali_4Angle.csv file" << endl;
	}
	QTextStream	*p_stream = new QTextStream(p_file);

	p_stream->seek(0);//seek可以把文件流指针移到想要的位置

	//计算平均值
	float ElbowR_ave{ 0 };
	float ElbowL_ave{ 0 };
	float KneeR_ave{ 0 };
	float KneeL_ave{ 0 };
	float Spine_ave{ 0 };
	float ShoulderR_ave{ 0 };
	float ShoulderL_ave{ 0 };

	int num{ 0 };
	while (!p_stream->atEnd())
	{
		QString fetures = p_stream->readLine();
		QStringList blocks = fetures.split(",", QString::SkipEmptyParts);
		if (fetures.startsWith("#"))
		{
			continue;
		}
		if (blocks[2].toFloat() == 0 || blocks[3].toFloat() ==0 || blocks[4].toFloat() == 0 || blocks[5].toFloat() == 0 || blocks[6].toFloat() == 0 || blocks[7].toFloat() == 0 || blocks[8].toFloat() == 0)
		{
			continue;
		}
		if (blocks[0].toInt()<5)
		{
			continue;
		}
		ElbowR_ave += blocks[2].toFloat();
		ElbowL_ave += blocks[3].toFloat();
		KneeR_ave += blocks[4].toFloat();
		KneeL_ave += blocks[5].toFloat();
		Spine_ave += blocks[6].toFloat();
		ShoulderR_ave += blocks[7].toFloat();
		ShoulderL_ave += blocks[8].toFloat();
		num++;

		
	}
	ElbowR_ave /= num;
	ElbowL_ave /= num;
	KneeR_ave /= num;
	KneeL_ave /= num;
	Spine_ave /= num;
	ShoulderR_ave /= num;
	ShoulderL_ave /= num;

	caliAngle.ElbowR = -ElbowR_ave;
	caliAngle.ElbowL = -ElbowL_ave;
	caliAngle.KneeL = -KneeL_ave;
	caliAngle.KneeR = -KneeR_ave;
	caliAngle.Spine = -Spine_ave;
	caliAngle.ShouderR = -ShoulderR_ave;
	caliAngle.ShouderL = -ShoulderL_ave;
	qDebug() << "ave_angle" << caliAngle.ElbowR << caliAngle.ElbowL << caliAngle.KneeR << caliAngle.KneeL << caliAngle.Spine <<caliAngle.ShouderR<<caliAngle.ShouderL<< endl;
	p_file->close();
}

void FileREC::start()
{
	//设置幁率frame rate here
	connect(filetimer, SIGNAL(timeout()), this, SLOT(processfile()));
	filetimer->start(1000.0/framerate);
	
}

void FileREC::stop()
{
	disconnect(filetimer, SIGNAL(timeout()), this, SLOT(processfile()));
	filetimer->stop();
}

//When filetimer time out, call processfile, 每隔一定时间记录一个frame，间隔时间由filetimer设定
void FileREC::processfile() {
	qDebug() << "recording..." << endl;
	emit Recording();                                                                      
	frameNum++;
	//qDebug() << "process()" << QThread::currentThreadId();
	if (!jointsPositionfile.is_open()){
		std::cout << "failed to open jointsPositionfile." << std::endl;
		//断开处理链接
		disconnect(filetimer, SIGNAL(timeout()), this, SLOT(processfile()));
		//发送错误讯号
		emit Error_openfile();
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
		std::cout << "failed to open jointsOrientfile." << std::endl;
		//断开处理链接
		disconnect(filetimer, SIGNAL(timeout()), this, SLOT(processfile()));
		//发送错误讯号
		emit Error_openfile();
		return;
	}
	for (auto orient: JointOrientation_saved)
	{
		if (orient.JointType >= 0) {
			jointsOrientfile << frameNum << "," << fileTimeRec.elapsed() << "," << orient.JointType << ","  << orient.Orientation.x << "," << orient.Orientation.y << "," << orient.Orientation.z << "," << orient.Orientation.w << std::endl;
		}
	}

	if (!jointsAnglefile.is_open()) {
		std::cout << "failed to open jointsAnglefile." << std::endl;
		//断开处理链接
		disconnect(filetimer, SIGNAL(timeout()), this, SLOT(processfile()));
		//发送错误讯号
		emit Error_openfile();
		return;
	}
	if (JointAngle_saved[0]>-180 && JointAngle_saved[1] > -180 && JointAngle_saved[2] > -180 && JointAngle_saved[3] > -180 && JointAngle_saved[4] > -180)
	{
		jointsAnglefile << frameNum << "," << fileTimeRec.elapsed() << "," << caliAngle.ElbowR - JointAngle_saved[0] << "," << caliAngle.ElbowL - JointAngle_saved[1] << "," << caliAngle.KneeR - JointAngle_saved[2] << "," << caliAngle.KneeL - JointAngle_saved[3] << "," << caliAngle.Spine - JointAngle_saved[4] << "," << caliAngle.ShouderR - JointAngle_saved[5] << "," << caliAngle.ShouderL - JointAngle_saved[6] << "," << JointAngle_saved[7] << "," <<JointAngle_saved[8] <<std::endl;
	}
		

}


