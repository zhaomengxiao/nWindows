#pragma once
#include <Kinect.h>
#include <iostream>
//opencv include
#include <OpenNI.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//Eigen (vector and matrix)
#include <Eigen\Dense>
#include <math.h>
#define PI 3.14159265
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
	static const int        cDepthWidth = 512;
	static const int        cDepthHeight = 424;
public:
	myKinect();
	~myKinect();
	void                    Update();//获得骨架、背景二值图和深度信息
	double					AngleBetweenTowVectors(Eigen::Vector3d vector_A, Eigen::Vector3d vector_B);//计算关节角度
	HRESULT                 InitializeDefaultSensor();//用于初始化kinect
	cv::Mat					getDepthImg();//取得深度图
	cv::Mat					getSkeletonImg();//取得骨骼图
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


