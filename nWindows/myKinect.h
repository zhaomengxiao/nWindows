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
	Eigen::Vector4f quat;
	Eigen::Vector4f quatshow;
	Eigen::Vector3f angles;//changed f
	//
public:
	myKinect();
	~myKinect();
	void                    Update();//获得骨架、背景二值图和深度信息
	double					AngleBetweenTowVectors( JointType jointA, JointType jointB, JointType jointC);//计算关节角度
	Eigen::Vector3f         SegCOM(Eigen::Vector3f &segcom, Eigen::Vector3f &coordP, Eigen::Vector3f &coordD, int &segNum);
	Eigen::Vector3f			BodyCOM(Eigen::Vector3f & thighcom_L, Eigen::Vector3f & thighcom_R, Eigen::Vector3f & shankcom_L, Eigen::Vector3f & shankcom_R, Eigen::Vector3f & footcom_L, Eigen::Vector3f & footcom_R, Eigen::Vector3f & upperArmCom_L, Eigen::Vector3f & upperArmCom_R, Eigen::Vector3f & fArmHand_L, Eigen::Vector3f & fArmHand_R, Eigen::Vector3f & Pelvis, Eigen::Vector3f & ThoraxAbdomen, Eigen::Vector3f & Headneck);
	//计算COM
	HRESULT                 InitializeDefaultSensor();//用于初始化kinect
	cv::Mat					getDepthImg();//取得深度图
	cv::Mat					getSkeletonImg();//取得骨骼图
	static Eigen::Vector3f  QuaternionToEuler(Eigen::Vector4f &quat);
	std::vector<Eigen::Vector4f> quatstream;//保存quat数据

	float getAngle_x();//changed f
	float getAngle_y();//changed f
	float getAngle_z();//changed f
	//Return degrees (0->360) from radians
	static double RadianToDegree(double angle);
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
	
	//显示图像的Mat
	cv::Mat skeletonImg;
	cv::Mat depthImg;
};


