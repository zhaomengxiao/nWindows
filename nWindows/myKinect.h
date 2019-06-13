#pragma once
#include <Kinect.h>
#include <iostream>
#include <fstream>
//opencv include
//#include <OpenNI.h>
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
	//kinect 2.0 ����ȿռ�ĸ�*���� 424 * 512���ڹ�������˵��
	static const int        cDepthWidth { 512 };//c++ 11
	static const int        cDepthHeight{ 424 };
	
	
	//
public:
	myKinect();
	~myKinect();

public:
	HRESULT                 InitializeDefaultSensor();//���ڳ�ʼ��kinect
	cv::Mat					getDepthImg();//ȡ�����ͼ
	cv::Mat					getSkeletonImg();//ȡ�ù���ͼ
	void                    Update();//��ùǼܡ�������ֵͼ�������Ϣ
	
	
	//����COM
	void					SegCOM(Eigen::Vector3f &segcom, Joint &jointP, Joint &jointD, const int &segNum);
	Eigen::Vector3f			BodyCOM(Eigen::Vector3f & thighcom_L, Eigen::Vector3f & thighcom_R, Eigen::Vector3f & shankcom_L, Eigen::Vector3f & shankcom_R, Eigen::Vector3f & footcom_L, Eigen::Vector3f & footcom_R, Eigen::Vector3f & upperArmCom_L, Eigen::Vector3f & upperArmCom_R, Eigen::Vector3f & fArmHand_L, Eigen::Vector3f & fArmHand_R, Eigen::Vector3f & Pelvis, Eigen::Vector3f & ThoraxAbdomen, Eigen::Vector3f & Headneck);
	
	Eigen::Vector3f			myCOM; //����COM������ʾ
	Eigen::Vector3f			thighcom_L, thighcom_R, shankcom_L, shankcom_R, footcom_L, footcom_R,upperArmCom_L, upperArmCom_R, fArmHand_L, fArmHand_R,Pelvis, ThoraxAbdomen, Headneck;
	
	
	//============��������===========
	Joint joints[JointType_Count]; //����ؽ���Ϣ
	//std::array < Joint, JointType_Count> joints_array;
	//522
	//JointOrientation JointOrientations[JointType_Count];//�洢�ؽ���ת
	std::array<Eigen::Vector3f, 13> segCOMs;//����13��֫����������

	
	int jointnumber = 0;
	std::ofstream csvfile;//�������csv�ĵ�
	bool isAvailable();//todo
private:
	IKinectSensor *			m_pKinectSensor;	//kinectԴ
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


