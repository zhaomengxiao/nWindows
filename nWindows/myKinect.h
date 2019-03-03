#pragma once
#include <Kinect.h>
#include <iostream>
#include <fstream>
//opencv include
#include <OpenNI.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//Eigen (vector and matrix)
#include <Eigen\Dense>
#include <math.h>
#include <vector>
#include <array>
#define PI 3.14159265
//h


// Safe release for interfaces

template<class Interface>

inline void SafeRelease(Interface *& pInterfaceToRelease)

{

	if (pInterfaceToRelease != NULL)

	{
		pInterfaceToRelease->Release();
		pInterfaceToRelease = NULL;
	}

}

class myKinect
{
private:
	//kinect 2.0 的深度空间的高*宽是 424 * 512，在官网上有说明
	static const int        cDepthWidth { 512 };//c++ 11
	static const int        cDepthHeight{ 424 };
	//旋转角度数据存储
	//Eigen::Vector4f quat;
	Eigen::Vector4f quatshow;
	Eigen::Vector3f angles;//changed f
	//
public:
	myKinect();
	~myKinect();

public:
	HRESULT                 InitializeDefaultSensor();//用于初始化kinect
	cv::Mat					getDepthImg();//取得深度图
	cv::Mat					getSkeletonImg();//取得骨骼图
	void                    Update();//获得骨架、背景二值图和深度信息
	//计算关节角度
	static double			RadianToDegree(double angle);
	float norm(std::vector<float> v);
	//关节角度
	//1d
	float KneeAgR{ 0.0 }, KneeAgL{ 0.0 }, ElbowAgR{ 0.0 }, ElbowAgL{ 0.0 };
	static Eigen::Vector3f  QuaternionToEuler(Eigen::Vector4f &quat);
	//计算COM
	void					SegCOM(Eigen::Vector3f &segcom, Joint &jointP, Joint &jointD, const int &segNum);
	Eigen::Vector3f			BodyCOM(Eigen::Vector3f & thighcom_L, Eigen::Vector3f & thighcom_R, Eigen::Vector3f & shankcom_L, Eigen::Vector3f & shankcom_R, Eigen::Vector3f & footcom_L, Eigen::Vector3f & footcom_R, Eigen::Vector3f & upperArmCom_L, Eigen::Vector3f & upperArmCom_R, Eigen::Vector3f & fArmHand_L, Eigen::Vector3f & fArmHand_R, Eigen::Vector3f & Pelvis, Eigen::Vector3f & ThoraxAbdomen, Eigen::Vector3f & Headneck);
	
	Eigen::Vector3f			myCOM; //传出COM用于显示
	Eigen::Vector3f			thighcom_L, thighcom_R, shankcom_L, shankcom_R, footcom_L, footcom_R,upperArmCom_L, upperArmCom_R, fArmHand_L, fArmHand_R,Pelvis, ThoraxAbdomen, Headneck;
	
	
	//============传出数据===========
	Joint joints[JointType_Count]; //储存关节信息
	JointOrientation JointOrientations[JointType_Count];//存储关节旋转
	std::array<Eigen::Vector3f, 13> segCOMs;//储存13个肢段质量中心
	std::array<float, 4> JointAngles{-190,-190,-190,-190 };//储存4个单自由度关节角度
	//JointAngles[0] = ElbowAgR;
	//JointAngles[1] = ElbowAgL;
	//JointAngles[2] = KneeAgR;
	//JointAngles[3] = KneeAgL;
	
	
	
	//3d

	float getAngle_x();
	float getAngle_y();
	float getAngle_z();
	//Return degrees (0-360) from radians
	
	int jointnumber = 0;
	std::ofstream csvfile;//用于输出csv文档
	bool isAvailable();//todo
private:
	IKinectSensor * m_pKinectSensor;//kinect源
	ICoordinateMapper*      m_pCoordinateMapper;//用于坐标变换
	IBodyFrameReader*       m_pBodyFrameReader;//用于骨架数据读取
	IDepthFrameReader*      m_pDepthFrameReader;//用于深度数据读取
	IBodyIndexFrameReader*  m_pBodyIndexFrameReader;//用于背景二值图读取
													//通过获得到的信息，把骨架和背景二值图画出来
	void ProcessBody(int nBodyCount, IBody** ppBodies);
	//画骨架函数
	void DrawBone(const Joint* pJoints, const DepthSpacePoint* depthSpacePosition, JointType joint0, JointType joint1);
	//画手的状态函数
	void DrawHandState(const DepthSpacePoint depthSpacePosition, HandState handState);
	//计算一维的关节角度
	float CalJangle1(const Joint* pJoints,  JointType joint0, JointType joint1, JointType joint2);
	//显示图像的Mat
	cv::Mat skeletonImg;
	cv::Mat depthImg;
	
};


