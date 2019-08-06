#pragma once
#include <Eigen\Dense>
//#include "vtk.h"
#include <iostream>
#include <qstring.h>
#include <qdebug.h>
#include <array>
#include <vector>
#include <math.h>
#include <Kinect.h>
#include "myMath.h"
#define PI 3.14159265

//struct coordSys {
//	Eigen::Vector3f axis_x{ 0,0,0 };
//	Eigen::Vector3f axis_y{ 0,0,0 };
//	Eigen::Vector3f axis_z{ 0,0,0 };
//	Eigen::Matrix3f R;
//	Eigen::Vector3f V;
//};


#pragma region Math
float dot(std::array<float, 3> v1, std::array<float, 3> v2);
std::array<float, 3> cross(std::array<float, 3> A, std::array<float, 3> B);

float norm(std::array<float, 3> v);
float RadianToDegree(float angle);


#pragma endregion


struct SubjInfo {
	QString subjname	{ "null" };
	QString gender		{ "null" };
	QString preside		{ "null" };
	int		age			{ 0 };
	float	height		{ 0.0 };
	float	weight		{ 0.0 };
	float	bagWeight	{ 0.0 };
	Eigen::Vector3f bagPosi{ 0.0,0.0,0.0 };
	bool	bag			{ true };

	SubjInfo();
	SubjInfo(QString sn, QString gd, QString ps, int a, float h, float w, float bw, float x, float y, float z):
		subjname(sn),gender(gd),preside(ps),age(a),height(h),weight(w),bagWeight(bw)
	{
		bagPosi = Eigen::Vector3f{ x,y,z };
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
		qDebug() << "bagPosi: " << bagPosi.x() << "," << bagPosi.y() << "," << bagPosi.z() << endl;
		qDebug() << "bagWeight: "	<< bagWeight	<< endl;
		qDebug() << "isbag: "		<< bag			<< endl;
	}
};



namespace OBJ 
{
	//包含读取Cali文件后计算得到之资料
	

	
	struct coordSys {
		Eigen::Vector3f axis_x{ 0,0,0 };
		Eigen::Vector3f axis_y{ 0,0,0 };
		Eigen::Vector3f axis_z{ 0,0,0 };
		Eigen::Matrix3f R;
		Eigen::Vector3f V;

		void print();
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
	
	enum JAngleType {
		JAngleType_KneeR	= 0,
		JAngleType_KneeL	= 1,
		JAngleType_HipR		= 2,
		JAngleType_HipL		= 3,
		JAngleType_ElbowR	= 4,
		JAngleType_ElbowL	= 5,
		JAngleType_Spine	= 6,
		JAngleType_ShouderR = 7,
		JAngleType_ShouderL = 8,
		JAngleType_AnkleR   = 9,
		JAngleType_AnkleL   = 10,
		JAngleType_Count = (JAngleType_AnkleL + 1)
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
		std::array<float, 3> subtract(const OBJ::Joint & r);
		Eigen::Vector3f Pg2l(const coordSys& lcoord);
	};

	struct JointAngle
	{
		JAngleType jAngleType;
		float Angle_x;
		float Angle_y;
		float Angle_z;

	public:
		JointAngle operator+(const JointAngle& b)
		{
			JointAngle ja;
			ja.Angle_x = this->Angle_x + b.Angle_x;
			ja.Angle_y = this->Angle_y + b.Angle_y;
			ja.Angle_z = this->Angle_z + b.Angle_z;
			
			return ja;
		}

		JointAngle operator-(const JointAngle& b)
		{
			JointAngle ja;
			ja.Angle_x = this->Angle_x - b.Angle_x;
			ja.Angle_y = this->Angle_y - b.Angle_y;
			ja.Angle_z = this->Angle_z - b.Angle_z;

			return ja;
		}

		JointAngle operator/(int b)
		{
			if (b == 0)
			{
				qDebug() << "cant divide 0" << endl;
			}
			JointAngle ja;
			ja.Angle_x = this->Angle_x / b;
			ja.Angle_y = this->Angle_y / b;
			ja.Angle_z = this->Angle_z / b;
			return ja;
		}
	}; 
	

	
	
	class Segment
	{
	public:
		Segment();
		~Segment();
		Segment(const Joint& jp, const Joint& jd,const SegType& st,const SubjInfo & subjinfo); //初始化带有肢段质量
		Segment(const Joint& jp, const Joint& jd, const SegType& st); 
	public:
		SegType SegmentType;
		//近端关节
		Joint	Jproximal;
		//远端关节点
		Joint	Jdistal;
		TrackingState trackingState;
		//局部坐标系
		coordSys lcoord;
		//惯性参数
		float H;
		float dH;
		//肢段长度
		float	length;
		//肢段质量
		float	mass;
		//肢段的质量中心
		Eigen::Vector3f segCOM;
		Eigen::Vector3f segCOMAcc; //每個剛體之質量中心加速度
		Eigen::Vector3f rCOM2P; //從肢段質心至近端的向量
		Eigen::Vector3f rCOM2D; //從肢段質心至遠端的向量（單位：m）
		Eigen::Vector3f Fd; //关节远端受力（單位：N） 
		Eigen::Vector3f Fp; //关节近端受力

		
	public:
		//计算segCOM_ /Dampster
		void calSegCOM();
		//计算肢段长度
		virtual void calSegL();
		void calSegMass(const SubjInfo & subjinfo);
	};
	
	class cSegment :public Segment
	{
	public:
		cSegment(const Joint& jp, const Joint& jd, const Joint& jl, const Joint& jr, SegType st);
	private:
		//近端关节
		Joint	Jleft;
		//远端关节点
		Joint	Jright;

	public:
		virtual void calSegL();
		virtual void calLocalCoord();
	};

	
	

	//一个frame的关节资讯
	typedef std::array<OBJ::Joint, JointType_Count> Joints;
	//一个frame的肢段资讯
	typedef std::array<OBJ::Segment, OBJ::SegType_Count> Segs;
	typedef std::array< Eigen::Vector3f, 6> OptJoints;
	typedef std::array< OBJ::JointAngle, OBJ::JAngleType_Count> Angles;
	typedef std::array<double,3> CycleAngles;
	struct CaliInfo
	{
		Angles caliJA;//初始角度
		float		caliH;//Kinect计算得之身高
		std::array<float, SegType_Count> SegL; //Kinect 计算得之肢段长度
	};

	struct Circle{
		double centerX;
		double centerY;
		double radius;
	};

	class Obj
	{
	public:
		Obj();
		~Obj();
		Obj(const std::vector<Joints>& frames_j);
	public:
		QString trailName;
		QString path_ford;  //包含受试者资料的文件夹的路径
		QString path_cali;	
		QString path_subjInfo;
		QString path_trail;
		QString path_angle;
		QString path_moment;
		//vicon data
		QString path_ViconAngle_HipL;
		QString path_ViconAngle_KneeL;
		QString path_ViconAngle_AnkleL;
		std::vector<double> viconAngleData_HipL;
		std::vector<double> viconAngleData_KneeL;
		std::vector<double> viconAngleData_AnkleL;

		std::vector<Joints> cali_JointFrames;
		std::vector<Segs> cali_SegFrames;
		int RPM;
		
		//Fit data
		Circle ankleCircle;
		std::vector<Eigen::Vector3d> Trajectory_Ankle;
		std::vector<Eigen::Vector3d> Trajectory_Knee;
		std::vector<Eigen::Vector3d> Trajectory_Hip;
		std::vector<CycleAngles> cycleAngleframes;

		void calTraject_Ankle();
		void calTraject_Knee();
		void calTraject_Hip();

		void buildModelJframes();
		void buildModelSegFrames();

		CycleAngles calJointAngle(coordSys pelvis, Eigen::Vector3d hip, Eigen::Vector3d knee, Eigen::Vector3d ankle);
		double calKneeAngle(Eigen::Vector3d hip, Eigen::Vector3d knee, Eigen::Vector3d ankle);
		void calCycleAngles();
	private:
		
	
		//受试者资讯
		SubjInfo m_subjInfo;
		//calibration得到之资讯
		CaliInfo m_caliInfo;
		//储存从文件读取到的关节点信息
		std::vector<Joints>			m_framesJ;
		
		//将关节点信息整理为肢段信息
		std::vector<Segs>			m_framesS;
		
		
		//从肢段信息计算二维关节的角度
		std::vector<Angles>	m_JointAngles;
		std::vector<Angles>	m_JointAngles_filted;
		std::vector<Angles>	m_JointAngles_opted;
		//腰部所受外力产生之力矩
		std::vector<Eigen::Vector3f> m_moments;
		//局部坐标系
		coordSys m_trunkCoord;
		//帧数
		int m_nFrames{ 0 };
		//储存外力资讯
		std::vector<Eigen::Vector3f> m_fp_g;
		//储存filter后的资料
		std::vector<Joints>			m_framesJ_filted;	//储存filter之后的关节点信息
		std::vector<Segs>			m_framesS_filted;	//储存filter之后的肢段
		//储存最佳化后之资料
		//std::vector<OptJoints>		m_framesOptJ;
		std::vector<Joints>			m_framesJ_opted;	//储存opt之后的关节点信息
		std::vector<Segs>			m_framesS_opted;	//储存opt之后的肢段
		
	public:


		#pragma region Get
		SubjInfo getSubjInfo();
		CaliInfo getCaliInfo()const;
		
		std::vector<Joints> getJoints()const;
		std::vector<Joints> getJoints_filted()const;
		std::vector<Joints> getJoints_opted()const;
		
		std::vector<Segs> getSegments()const;
		std::vector<Segs> getSegments_filted()const;
		std::vector<Segs> getSegments_opted()const;
		
		std::vector<Angles> getJointAngles()const;
		std::vector<Angles> getJointAngles_filted()const;
		std::vector<Angles> getJointAngles_opted()const;
		std::vector<Eigen::Vector3f> getMoments();
		std::array<Eigen::Vector3f, 13> getCOMs(const Segs & segs);
		int getFrameNumber()const;
		std::vector<Eigen::Vector3f> getForcePosi();

		#pragma endregion
		
		#pragma region Set
		void setSubjInfo(SubjInfo &subjinfo);
		void setJoints(const std::vector<Joints> &frames_J);
		void setJoints_filted(const std::vector<Joints> &frames_J_filted);
		void setJoints_opted(const std::vector<Joints> &frames_J_opted);
		void setSegments(const std::vector<Segs> &frames_S);
		void setSegments_filted(const std::vector<Segs> &frames_S);
		void setSegments_opted(const std::vector<Segs> &frames_S_opted);
		void setJointAngles(std::vector<Angles> &frames_JA);
		void setJointAngles_opted(std::vector<Angles> &frames_JA);
		
		//void setOptJoints(const std::vector<OptJoints> &frames_optJ);
		
		#pragma endregion

		
		
		//从关节资料建立以肢段为单位的资料，既可以输入单帧的Joints，也可以输入所有帧。
		std::vector<Segs> buildSegments(const std::vector<Joints> &frames_J);
		Segs buildSegments(const Joints &joints);
		//输入受试者资料夹的路径，一旦输入会抓取cali的路径和subjInfo的路径,并建立其他档案的路径
		void setFilePath(QString path);
		//输入实验trail的名称，读取trail的关节位置档案并且计算关节角度。
		void addtrail(QString trailname);
		
		//计算两个肢段间的平面角度
		float calJointAngle(const Segment &sA,const Segment &sB);
		//计算一个肢段与一个局部坐标系之z轴之交角
		float calJointAngle(const Segment &seg, const coordSys &coord);
		//计算所有关节角度，可以输入一帧也可以输入多帧
		Angles calAllJointAngles(const Segs &segments); //1 frame
		std::vector<Angles> calAllJointAngles(const std::vector<Segs> &frames_S); //n frame
		//计算近端关节受力
		void calJointForce(Segment &seg, Eigen::Vector3f fd);
		void calLeftLimbJointForce(std::vector<Segs> & nframeSegs,std::vector<Eigen::Vector3f> exForces);
		void calCOMAcc(std::vector<Segs> & nframeSegs);
		//建立body坐标系
		coordSys calCoordupTunkR(const Joints &joints);
		coordSys calCoordPelvisR(const Joints &joints);
		static Eigen::Vector3f Pg2l(const Joint& Pg, const coordSys& lcoord);
		static Eigen::Vector3f Pl2g(Eigen::Vector3f Pl, const coordSys& lcoord);
		
		//操作
		void cali();
		void calTrailJointAngle();
		void calJointAngles_filted();
		void calJointAngles_opted();
		void calcSpinebaseFMwithBag();
	};

}