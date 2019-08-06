#include "filerec.h"

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
	fileTimeRec.start();
}

FileREC::FileREC(char* subjName, QObject *parent) : QObject(parent) 
{
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
	path_subjInfo = (m_subjpath + s).toStdString();
	subjinfofile.open(path_subjInfo.c_str(), std::ios::app);
	
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
}

void FileREC::updateJoints(Joint jointdata[JointType_Count])
{
	for (int i = 0; i < JointType_Count; i++)
	{
		jointPosition_saved[i] = KinectJ_2_ObjJ(jointdata[i]);
	}
}

OBJ::Joints FileREC::jointPositions()
{
	return jointPosition_saved;
}


std::array<Eigen::Vector3f, 13> FileREC::segCOMs()
{
	return segCOM_saved;
}

void FileREC::updateSegCOM(std::array<Eigen::Vector3f, 13>& segCOMdata)
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
}

void FileREC::closefile()
{
	jointsPositionfile.close();
}

//void FileREC::Orient2angelFile()
//{
//	//建立新的文件_Angle.csv
//	char  *angstr = "_Angle.csv";
//	std::string  fn = std::string(m_subName) + std::string(angstr);
//	std::ofstream jointsAnglefile;
//	jointsAnglefile.open(fn.c_str(), std::ios::app);
//	if (jointsAnglefile.is_open()){
//		//标题行
//		jointsAnglefile << "# " << "frame " << "," << "time " << "," << "JointType " << "," << "x " << "," << "y" << "," << "z"  << std::endl;
//	}
//	//从orient.csv读取data
//	char  *b = "_Orient.csv";
//	std::string  filename = std::string(".\\Record\\")+std::string(m_subName) + std::string(b);
//	QFile * p_file = new QFile(QString::fromStdString(filename));
//	if (!p_file->open(QIODevice::ReadOnly)) {
//		qDebug() << "cant read joint file" << endl;
//	}
//	QTextStream	*p_stream = new QTextStream(p_file);
//
//	p_stream->seek(0);//seek可以把文件流指针移到想要的位置
//
//	//存下整个表
//	Eigen::Vector4f quats;
//	Eigen::Vector3f ang;
//	while (!p_stream->atEnd())
//	{
//		QString fetures = p_stream->readLine();
//		QStringList blocks = fetures.split(",", QString::SkipEmptyParts);
//		if (fetures.startsWith("#"))
//		{
//			continue;
//		}
//		quats[0] = blocks[3].toFloat();
//		quats[1] = blocks[4].toFloat();
//		quats[2] = blocks[5].toFloat();
//		quats[3] = blocks[6].toFloat();
//		ang = myKinect::QuaternionToEuler(quats);
//
//		jointsAnglefile << blocks[0].toInt() << "," << blocks[1].toFloat()/1000.0 << "," << blocks[2].toInt() << "," << ang.x() << "," << ang.y() << "," << ang.z()  << std::endl;
//	}
//	jointsAnglefile.close();
//	p_file->close();
//}


void FileREC::start()
{
	frameNum = 0;
	//设置幁率frame rate here
	connect(filetimer, SIGNAL(timeout()), this, SLOT(processfile()));
	filetimer->start(1000.0/framerate);
	fileTimeRec.restart();
}

void FileREC::stop()
{
	frameNum = 0;
	disconnect(filetimer, SIGNAL(timeout()), this, SLOT(processfile()));
	filetimer->stop();
}

#pragma region ReadFile

//从Obj中设定的路径读取一个trail
void FileREC::readTrail(OBJ::Obj &obj)
{
	//
	std::string  pt = (obj.path_trail).toStdString();

	QFile * p_file = new QFile(QString::fromStdString(pt));
	if (!p_file->open(QIODevice::ReadOnly)) {
		qDebug() << "cant read joint file" << endl;
		return;
	}
	QTextStream	*p_stream = new QTextStream(p_file);

	p_stream->seek(0);//seek可以把文件流指针移到想要的位置
	QString fetures = p_stream->readLine(); //跳过第一行标题

	//存下整个表
	int frame{ 1 };
	std::vector<std::array<OBJ::Joint, JointType_Count>> frames_joint;
	while (!p_stream->atEnd())
	{


		//qDebug() << "reading" << endl;
		Dbg("reading");
		//qDebug() << frame << endl;
		Dbg(frame);
		emit ReadFileProgress(frame);
		std::array<OBJ::Joint, JointType_Count> joints;
		for (int i = 0; i < JointType_Count; i++)
		{
			fetures = p_stream->readLine();
			QStringList blocks = fetures.split(",", QString::SkipEmptyParts);

			if (i != blocks[2].toInt())
			{
				joints[i] = OBJ::Joint{ JointType(i),0,0,0,TrackingState(0) };
				++i;
				joints[i] = OBJ::Joint{ JointType(blocks[2].toInt()),blocks[4].toFloat(),blocks[5].toFloat(),blocks[6].toFloat(),TrackingState(blocks[3].toInt()) };
				qDebug() << "missing joint: " << i << "  ,at frame: " << frame << endl;
			}
			else
			{
				joints[i] = OBJ::Joint{ JointType(blocks[2].toInt()),blocks[4].toFloat(),blocks[5].toFloat(),blocks[6].toFloat(),TrackingState(blocks[3].toInt()) };

			}


		}
		frame++;
		/*for (OBJ::Joint i : joints)
		{
			i.print();
		}*/

		frames_joint.push_back(joints); //!fix :这里预先分配frames数效率更高

	}

	qDebug() << "read rec finish" << endl;
	obj.setJoints(frames_joint);
	obj.setSegments(obj.buildSegments(frames_joint));
	obj.calTrailJointAngle();
	p_file->close();

	//如果有vicon data 读取
	obj.viconAngleData_HipL = readViconAngle(obj.path_ViconAngle_HipL);
	obj.viconAngleData_KneeL = readViconAngle(obj.path_ViconAngle_KneeL);
	obj.viconAngleData_AnkleL = readViconAngle(obj.path_ViconAngle_AnkleL);
}
//设定Obj的subject info 和 calibration
void FileREC::readSubjInfo(OBJ::Obj &obj)
{
	//设定用户资料
	std::string  ps = (obj.path_subjInfo).toStdString();

	QFile * p_file = new QFile(QString::fromStdString(ps));
	if (!p_file->open(QIODevice::ReadOnly)) {
		qDebug() << "cant read SubjInfo file!" << endl;
	}
	QTextStream	*p_stream = new QTextStream(p_file);

	p_stream->seek(0);//seek可以把文件流指针移到想要的位置
	QString fetures = p_stream->readLine(); //跳过第一行标题
	//存下整个表
	fetures = p_stream->readLine();
	QStringList blocks = fetures.split(",", QString::SkipEmptyParts);
	obj.setSubjInfo(SubjInfo{ blocks[0],blocks[1],blocks[2],blocks[3].toInt(),
		blocks[4].toFloat(),blocks[5].toFloat(),blocks[6].toFloat(),
		blocks[7].toFloat(),blocks[8].toFloat(),blocks[9].toFloat() });
	p_file->close();

	qDebug() << "SubjInfo loaded" << endl;
}

void FileREC::readCali(OBJ::Obj & obj)
{
	//读取校准档
	std::string  pc = (obj.path_cali).toStdString();

	QFile * p_file = new QFile(QString::fromStdString(pc));
	if (!p_file->open(QIODevice::ReadOnly)) {
		qDebug() << "cant read cali file!" << endl;
	}
	QTextStream	*p_stream = new QTextStream(p_file);

	p_stream->seek(0);//seek可以把文件流指针移到想要的位置
	QString fetures = p_stream->readLine(); //跳过第一行标题
	//存下整个表
	int frame{ 1 };
	std::vector<std::array<OBJ::Joint, JointType_Count>> frames_joint;
	while (!p_stream->atEnd())
	{


		//qDebug() << "reading cali file" << endl;
		Dbg("reading cali file");
		//qDebug() << frame << endl;
		Dbg(frame);
		std::array<OBJ::Joint, JointType_Count> joints;
		for (int i = 0; i < JointType_Count; i++)
		{
			fetures = p_stream->readLine();
			QStringList blocks = fetures.split(",", QString::SkipEmptyParts);
			if (blocks[2].toInt() < 0) //关节点未侦测到
			{
				joints[i] = OBJ::Joint{ JointType(i),0,0,0,TrackingState(0) };
			}
			else if (i != blocks[2].toInt())//缺点
			{
				joints[i] = OBJ::Joint{ JointType(i),0,0,0,TrackingState(0) };
				++i;
				joints[i] = OBJ::Joint{ JointType(blocks[2].toInt()),blocks[4].toFloat(),blocks[5].toFloat(),blocks[6].toFloat(),TrackingState(blocks[3].toInt()) };
				//qDebug() << "missing joint" << endl;
				Dbg("missing joint");
			}
			else 
			{
				joints[i] = OBJ::Joint{ JointType(blocks[2].toInt()),blocks[4].toFloat(),blocks[5].toFloat(),blocks[6].toFloat(),TrackingState(blocks[3].toInt()) };

			}
			
		}
		frame++;

		frames_joint.push_back(joints); //!fix :这里预先分配frames数效率更高

	}

	qDebug() << "read cali finish" << endl;
	obj.cali_JointFrames = frames_joint;
	obj.cali();
	p_file->close();
}

std::vector<double> FileREC::readViconAngle(QString filepath)
{
	std::vector<double> res;
	QFile * p_file = new QFile(filepath);
	if (!p_file->open(QIODevice::ReadOnly)) {
		qDebug() << "cant read SubjInfo file!" << endl;
		return res;
	}
	QTextStream	*p_stream = new QTextStream(p_file);

	p_stream->seek(0);//seek可以把文件流指针移到想要的位置
	//存下整个表
	while (!p_stream->atEnd())
	{
		QString fetures = p_stream->readLine();
		//QStringList blocks = fetures.split(",", QString::SkipEmptyParts);
		res.push_back(fetures.toDouble());	
	}
	p_file->close();
	qDebug() << "vicon angle loaded" << endl;
	return res;
}
void FileREC::writeTrialAngle(OBJ::Obj & obj)
{
	//新建csv文件
	/*QString  a = "_Angle.csv";
	std::string  ac = (path + trailName + a).toStdString();
	jointsAnglefile.open(ac.c_str(), std::ios::app); */
	std::ofstream jointsAnglefile;
	
	jointsAnglefile.open(obj.path_angle.toStdString(), std::ios::ate);
	//设置jointAngles文件的标题

	if (jointsAnglefile.is_open()) {
		//标题行
		jointsAnglefile << "# " << "frame " << "," << "ElbowR " << "," << "ElbowL " << "," << "KneeR" << "," << "KneeL" << "," << "ShouderR" << "," << "ShouderL" << "," << "Spine" << std::endl;
	}
	else
	{
		emit Error_openfile();
		return;
	}
	int frameNum{ 0 };
	//写入角度
	for (auto frame : obj.getJointAngles())
	{
		frameNum++;
		//扣除了初始角度
		jointsAnglefile << frameNum << "," << (obj.getCaliInfo().caliJA[OBJ::JAngleType_ElbowR] - frame[OBJ::JAngleType_ElbowR]).Angle_x << ","
			<< (obj.getCaliInfo().caliJA[OBJ::JAngleType_ElbowL] - frame[OBJ::JAngleType_ElbowL]).Angle_x << "," 
			<< (obj.getCaliInfo().caliJA[OBJ::JAngleType_KneeR] - frame[OBJ::JAngleType_KneeR]).Angle_x << ","
			<< (obj.getCaliInfo().caliJA[OBJ::JAngleType_KneeL] - frame[OBJ::JAngleType_KneeL]).Angle_x << "," 
			<< (obj.getCaliInfo().caliJA[OBJ::JAngleType_ShouderR] - frame[OBJ::JAngleType_ShouderR]).Angle_x << ","
			<< (obj.getCaliInfo().caliJA[OBJ::JAngleType_ShouderL] - frame[OBJ::JAngleType_ShouderL]).Angle_x << "," 
			<< (obj.getCaliInfo().caliJA[OBJ::JAngleType_Spine] - frame[OBJ::JAngleType_Spine]).Angle_x << std::endl;
	}
	jointsAnglefile.close();

}
void FileREC::writeMoment(OBJ::Obj & obj)
{
	//新建csv文件
	std::ofstream sBaseMomentfile;
	sBaseMomentfile.open(obj.path_moment.toStdString(), std::ios::ate);
	//设置jointAngles文件的标题

	if (sBaseMomentfile.is_open()) {
		//标题行
		sBaseMomentfile << "# " << "frame " << "," << "X " << "," << "Y " << "," << "Z" << std::endl;
	}
	else
	{
		emit Error_openfile();
		return;
	}
	int frameNum{ 0 };
	//写入角度
	for (auto frame : obj.getMoments())
	{
		frameNum++;
		//扣除了初始角度
		sBaseMomentfile << frameNum << "," << frame.x() << ","
			<< frame.y() << "," << frame.z() << std::endl;
	}
	sBaseMomentfile.close();
}
OBJ::Joint FileREC::KinectJ_2_ObjJ(const Joint & joint)
{
	OBJ::Joint res{ joint.JointType ,joint.Position.X, joint.Position.Y, joint.Position.Z ,joint.TrackingState };
	return res;
}
#pragma endregion




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
		//
		if (joint.trackingState != TrackingState_NotTracked)
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
			jointsPositionfile << frameNum << "," << fileTimeRec.elapsed() << "," << joint.jointType << "," << joint.trackingState << "," << joint.jointPosition.x() << "," << joint.jointPosition.y() << "," << joint.jointPosition.z() << std::endl;

		}
		else
		{
			//未捕捉点xyz设为000，后续计算应注意
			jointsPositionfile << frameNum << "," << fileTimeRec.elapsed() << "," << joint.jointType << "," << joint.trackingState << "," << 0 << "," << 0 << "," << 0 << std::endl;

		}
	}
}


