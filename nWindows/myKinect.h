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
	//kinect 2.0 ����ȿռ�ĸ�*���� 424 * 512���ڹ�������˵��
	static const int        cDepthWidth = 512;
	static const int        cDepthHeight = 424;
public:
	myKinect();
	~myKinect();
	void                    Update();//��ùǼܡ�������ֵͼ�������Ϣ
	double					AngleBetweenTowVectors(Eigen::Vector3d vector_A, Eigen::Vector3d vector_B);//����ؽڽǶ�
	HRESULT                 InitializeDefaultSensor();//���ڳ�ʼ��kinect
	cv::Mat					getDepthImg();//ȡ�����ͼ
	cv::Mat					getSkeletonImg();//ȡ�ù���ͼ
private:
	IKinectSensor * m_pKinectSensor;//kinectԴ
	ICoordinateMapper*      m_pCoordinateMapper;//��������任
	IBodyFrameReader*       m_pBodyFrameReader;//���ڹǼ����ݶ�ȡ
	IDepthFrameReader*      m_pDepthFrameReader;//����������ݶ�ȡ
	IBodyIndexFrameReader*  m_pBodyIndexFrameReader;//���ڱ�����ֵͼ��ȡ

													//ͨ����õ�����Ϣ���ѹǼܺͱ�����ֵͼ������
	void ProcessBody(int nBodyCount, IBody** ppBodies);
	//���Ǽܺ���
	void DrawBone(const Joint* pJoints, const DepthSpacePoint* depthSpacePosition, JointType joint0, JointType joint1);
	//���ֵ�״̬����
	void DrawHandState(const DepthSpacePoint depthSpacePosition, HandState handState);
	
	//��ʾͼ���Mat
	cv::Mat skeletonImg;
	cv::Mat depthImg;
};


