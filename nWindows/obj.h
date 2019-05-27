#pragma once
#include <Eigen\Dense>
//#include "vtk.h"
#include <iostream>
#include <qstring.h>
#include <qdebug.h>
#include <array>
#include <vector>
#include <math.h>

#define PI 3.14159265

//struct coordSys {
//	Eigen::Vector3f axis_x{ 0,0,0 };
//	Eigen::Vector3f axis_y{ 0,0,0 };
//	Eigen::Vector3f axis_z{ 0,0,0 };
//	Eigen::Matrix3f R;
//	Eigen::Vector3f V;
//};


#pragma region Math
float dot(std::vector<float> v1, std::vector<float> v2);

float norm(std::vector<float> v);
double RadianToDegree(double angle);

#pragma endregion


struct SubjInfo {
	QString subjname	{ "null" };
	QString gender		{ "null" };
	QString preside		{ "null" };
	int		age			{ 0 };
	float	height		{ 0.0 };
	float	weight		{ 0.0 };
	float	bagWeight	{ 0.0 };
	std::vector<float> bagPosi{ 0.0,0.0,0.0 };
	bool	bag			{ true };

	SubjInfo();
	SubjInfo(QString sn, QString gd, QString ps, int a, float h, float w, float bw, float x, float y, float z):
		subjname(sn),gender(gd),preside(ps),age(a),height(h),weight(w),bagWeight(bw)
	{
		bagPosi = std::vector<float>{ x,y,z };
		if (bw == 0.0)
		{
			bag = false;
		}
	};
	~SubjInfo();

	void print() {
		qDebug() << "subjname: "	<< subjname		<< endl;
		qDebug() << "gender: "		<< gender		<< endl;
		qDebug() << "age: "			<< age			<< endl;
		qDebug() << "height: "		<< height		<< endl;
		qDebug() << "weight: "		<< weight		<< endl;
		qDebug() << "bagPosi: "		<< bagPosi		<< endl;
		qDebug() << "bagWeight: "	<< bagWeight	<< endl;
		qDebug() << "isbag: "		<< bag			<< endl;
	}
};



namespace OBJ 
{
	//包含读取Cali文件后计算得到之资料
	
	//包含所有的关节角度
	struct JointAngles
	{
		float		KneeR{ 0.0 };
		float		KneeL{ 0.0 };
		float		ElbowR{ 0.0 };
		float		ElbowL{ 0.0 };
		float		Spine{ 0.0 };
		float		ShouderR{ 0.0 };
		float		ShouderL{ 0.0 };

		JointAngles operator+(const JointAngles& b)
		{
			JointAngles ja;
			ja.KneeR = this->KneeR + b.KneeR;
			ja.KneeL = this->KneeL + b.KneeL;
			ja.ElbowR = this->ElbowR + b.ElbowR;
			ja.ElbowL = this->ElbowL + b.ElbowL;
			ja.Spine = this->Spine + b.Spine;
			ja.ShouderR = this->ShouderR + b.ShouderR;
			ja.ShouderL = this->ShouderL + b.ShouderL;
			return ja;
		}

		JointAngles operator-(const JointAngles& b)
		{
			JointAngles ja;
			ja.KneeR = this->KneeR - b.KneeR;
			ja.KneeL = this->KneeL - b.KneeL;
			ja.ElbowR = this->ElbowR - b.ElbowR;
			ja.ElbowL = this->ElbowL - b.ElbowL;
			ja.Spine = this->Spine - b.Spine;
			ja.ShouderR = this->ShouderR - b.ShouderR;
			ja.ShouderL = this->ShouderL - b.ShouderL;
			return ja;
		}

		JointAngles operator/(int b)
		{
			if (b == 0)
			{
				qDebug() << "cant divide 0" << endl;
			}
			JointAngles ja;
			ja.KneeR = this->KneeR / b;
			ja.KneeL = this->KneeL / b;
			ja.ElbowR = this->ElbowR / b;
			ja.ElbowL = this->ElbowL / b;
			ja.Spine = this->Spine / b;
			ja.ShouderR = this->ShouderR / b;
			ja.ShouderL = this->ShouderL / b;
			return ja;
		}

	};
	enum JointType
	{
		JointType_SpineBase = 0,
		JointType_SpineMid = 1,
		JointType_Neck = 2,
		JointType_Head = 3,
		JointType_ShoulderLeft = 4,
		JointType_ElbowLeft = 5,
		JointType_WristLeft = 6,
		JointType_HandLeft = 7,
		JointType_ShoulderRight = 8,
		JointType_ElbowRight = 9,
		JointType_WristRight = 10,
		JointType_HandRight = 11,
		JointType_HipLeft = 12,
		JointType_KneeLeft = 13,
		JointType_AnkleLeft = 14,
		JointType_FootLeft = 15,
		JointType_HipRight = 16,
		JointType_KneeRight = 17,
		JointType_AnkleRight = 18,
		JointType_FootRight = 19,
		JointType_SpineShoulder = 20,
		JointType_HandTipLeft = 21,
		JointType_ThumbLeft = 22,
		JointType_HandTipRight = 23,
		JointType_ThumbRight = 24,
		JointType_Count = (JointType_ThumbRight + 1)
	};

	


	enum TrackingState
	{
		TrackingState_NotTracked = 0,
		TrackingState_Inferred = 1,
		TrackingState_Tracked = 2
	};



	enum SegType {
		SegType_LeftThigh = 0,
		SegType_RightThigh = 1,
		SegType_LeftShank = 2,
		SegType_RightShank = 3,
		SegType_LeftFoot = 4,
		SegType_RightFoot = 5,
		SegType_LeftUpperArm = 6,
		SegType_RightUpperArm = 7,
		SegType_LeftForArmHand = 8,
		SegType_RightForArmHand = 9,
		SegType_Pelvis = 10,
		SegType_ThoraxAbdomen = 11,
		SegType_HeadNeck = 12,
		SegType_Count = (SegType_HeadNeck + 1)
	};
	
	class Joint
	{
	public:
		Joint();
		~Joint();
		Joint(JointType jt,float x,float y,float z, TrackingState ts);
	
	public:
		JointType		jointType;
		Eigen::Vector3f jointPosition; //相机空间坐标：x向右 y向上 z代表距离相机之深度距离
		TrackingState	trackingState;

	public:
		void print();
	};

	
	class Segment
	{
	public:
		Segment();
		~Segment();
		Segment(const Joint& jp, const Joint& jd, SegType st);
	public:
		SegType SegmentType;
		//近端关节
		Joint	Jproximal;
		//远端关节点
		Joint	Jdistal;
		TrackingState trackingState;
		//local坐标系
		//coordSys local;

		//惯性参数
		//肢段长度
		float	length;
		//肢段质量
		float	mass;
		//肢段的质量中心
		Eigen::Vector3f segcom;

	public:
		//计算segCOM_ /Dampster
		void calSegCOM(Eigen::Vector3f &segcom, const Joint &jointP, const Joint &jointD, const int &segNum);
		//计算肢段长度
		void calSegL();
	};

	struct CaliInfo
	{
		JointAngles caliJA;//初始角度
		float		caliH;//Kinect计算得之身高
		std::array<float, SegType_Count> SegL; //Kinect 计算得之肢段长度
	};
	class Obj
	{
	public:
		Obj();
		~Obj();
		Obj(const std::vector<std::array<Joint, JointType_Count>>& frames_j);
	public:
		QString path_ford;  //包含受试者资料的文件夹的路径
		QString path_cali;	
		QString path_subjInfo;
		QString path_trail;
		QString path_angle;
		std::vector<std::array<Joint, JointType_Count>> cali_JointFrames;
		std::vector<std::array<Segment, SegType_Count>> cali_SegFrames;

		//帧数
		int m_nFrames{ 0 };
	private:
		
	
		//受试者资讯
		SubjInfo m_subjInfo;
		//calibration得到之资讯
		CaliInfo m_caliInfo;
		//储存从文件读取到的关节点信息
		std::vector<std::array<Joint, JointType_Count>> m_framesJ;
		//将关节点信息整理为肢段信息
		std::vector<std::array<Segment, SegType_Count>> m_framesS;
		//从肢段信息计算二维关节的角度
		std::vector<JointAngles>						m_2dJointAngles;
		
	public:


		#pragma region Get
		SubjInfo getSubjInfo();
		CaliInfo getCaliInfo();
		std::vector<std::array<Joint, JointType_Count>> getJoints();
		std::vector<std::array<Segment, SegType_Count>> getSegments();
		std::vector<JointAngles> getJointAngles();
		#pragma endregion
		
		#pragma region Set
		void setSubjInfo(SubjInfo &subjinfo);
		void setJoints(const std::vector<std::array<Joint, JointType_Count>> &frames_J);
		void setSegments(const std::vector<std::array<Segment, SegType_Count>> &frames_S);
		void setJointAngles(std::vector<JointAngles> &frames_JA);
		void setJointAngles(const std::vector<std::array<Segment, SegType_Count>> &frames_S);
		#pragma endregion

		
		
		//从关节资料建立以肢段为单位的资料，既可以输入单帧的Joints，也可以输入所有帧。
		std::vector<std::array<Segment, SegType_Count>> buildSegments(const std::vector<std::array<Joint, JointType_Count>> &frames_J);
		std::array<Segment, SegType_Count> buildSegments(const std::array<Joint, JointType_Count> &joints);
		//输入受试者资料夹的路径，一旦输入会抓取cali的路径和subjInfo的路径,并建立其他档案的路径
		void setFilePath(QString path);
		//输入实验trail的名称，读取trail的关节位置档案并且计算关节角度。
		void addtrail(QString trailname);
		//计算两个肢段间的平面角度
		float calJointAngle(const Segment &sA,const Segment &sB);
		//计算所有关节角度，可以输入一帧也可以输入多帧
		JointAngles calAllJointAngles(const std::array<Segment, SegType_Count> &segments); //1 frame
		std::vector<JointAngles> calAllJointAngles(const std::vector<std::array<Segment, SegType_Count>> &frames_S); //n frame
		
		//操作
		void cali();
		void calTrailJointAngle();

	};

}