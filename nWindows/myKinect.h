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
struct coordSys {
	Eigen::Vector3f axis_x{ 0,0,0 };
	Eigen::Vector3f axis_y{ 0,0,0 };
	Eigen::Vector3f axis_z{ 0,0,0 };
	Eigen::Matrix3f R;
	Eigen::Vector3f V;
};

class myKinect
{
private:
	//kinect 2.0 ����ȿռ�ĸ�*���� 424 * 512���ڹ�������˵��
	static const int        cDepthWidth { 512 };//c++ 11
	static const int        cDepthHeight{ 424 };
	//��ת�Ƕ����ݴ洢
	//Eigen::Vector4f quat;
	Eigen::Vector4f quatshow;
	//Eigen::Quaternion egQuat;
	Eigen::Vector3f angles;//changed f
	
	//
public:
	myKinect();
	~myKinect();

public:
	HRESULT                 InitializeDefaultSensor();//���ڳ�ʼ��kinect
	cv::Mat					getDepthImg();//ȡ�����ͼ
	cv::Mat					getSkeletonImg();//ȡ�ù���ͼ
	void                    Update();//��ùǼܡ�������ֵͼ�������Ϣ
	//����ؽڽǶ�
	static double			RadianToDegree(double angle);
	float norm(std::vector<float> v);
	//����ϵ����

	//upper trunk coordinats
	coordSys UpTkcoord;
	//�ؽڽǶ�
	//1d
	float KneeAgR{ 0.0 }, KneeAgL{ 0.0 }, ElbowAgR{ 0.0 }, ElbowAgL{ 0.0 };
	float SpineAg{ 0.0 };
	float NeckbfAg{ 0.0 }, NecklrAg{ 0.0 };
	float ShoulderAgR{ 0.0 }, ShoulderAgL{ 0.0 };
	float ShoulderABD_R{ 0.0 }, ShoulderFE_R{ 0.0 };
	static Eigen::Vector3f  QuaternionToEuler(Eigen::Vector4f &quat);
	//����COM
	void					SegCOM(Eigen::Vector3f &segcom, Joint &jointP, Joint &jointD, const int &segNum);
	Eigen::Vector3f			BodyCOM(Eigen::Vector3f & thighcom_L, Eigen::Vector3f & thighcom_R, Eigen::Vector3f & shankcom_L, Eigen::Vector3f & shankcom_R, Eigen::Vector3f & footcom_L, Eigen::Vector3f & footcom_R, Eigen::Vector3f & upperArmCom_L, Eigen::Vector3f & upperArmCom_R, Eigen::Vector3f & fArmHand_L, Eigen::Vector3f & fArmHand_R, Eigen::Vector3f & Pelvis, Eigen::Vector3f & ThoraxAbdomen, Eigen::Vector3f & Headneck);
	
	Eigen::Vector3f			myCOM; //����COM������ʾ
	Eigen::Vector3f			thighcom_L, thighcom_R, shankcom_L, shankcom_R, footcom_L, footcom_R,upperArmCom_L, upperArmCom_R, fArmHand_L, fArmHand_R,Pelvis, ThoraxAbdomen, Headneck;
	
	//Eigen::Vector3f angles2;
	//============��������===========
	Joint joints[JointType_Count]; //����ؽ���Ϣ
	JointOrientation JointOrientations[JointType_Count];//�洢�ؽ���ת
	std::array<Eigen::Vector3f, 13> segCOMs;//����13��֫����������
	std::array<float, 9> JointAngles{-190,-190,-190,-190,-190,-190,-190,0,0 };//����4�������ɶȹؽڽǶ�
	

	/*JointAngles[0] = ElbowAgR;
	JointAngles[1] = ElbowAgL;
	JointAngles[2] = KneeAgR;
	JointAngles[3] = KneeAgL;
	JointAngles[4] = SpineAg;
	JointAngles[5] = ShoulderAgR;
	JointAngles[6] = ShoulderAgL;
	JointAngles[7] = NeckbfAg;
	JointAngles[8] = NecklrAg;*/
	
	
	//3d

	float getAngle_x();
	float getAngle_y();
	float getAngle_z();
	//Return degrees (0-360) from radians
	
	int jointnumber = 0;
	std::ofstream csvfile;//�������csv�ĵ�
	bool isAvailable();//todo
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
	//����һά�ĹؽڽǶ�
	float CalJangle3j(const Joint* pJoints,  JointType joint0, JointType joint1, JointType joint2);

	//����shoulder������ƽ��ĽǶ�
	float CalShodAbd_R();
	float CalShodFE_R();
	float CalShodAbd_L();
	//����uppertunk��local����ϵ
	void CalcoordupTunkR();

	//����ϵת�� 
	Eigen::Vector3f Pg2l(Joint& P,coordSys& lcoord);
	//��ʾͼ���Mat
	cv::Mat skeletonImg;
	cv::Mat depthImg;
	
};


