#pragma once
#include <Kinect.h>
#include <Eigen\Dense>
struct coordSys {
	Eigen::Vector3f axis_x{ 0,0,0 };
	Eigen::Vector3f axis_y{ 0,0,0 };
	Eigen::Vector3f axis_z{ 0,0,0 };
	Eigen::Matrix3f R;
	Eigen::Vector3f V;
};

class Segment
{
public:
	Segment();
	~Segment();

private:
	//���˹ؽ�
	Joint Jproximal;
	//Զ�˹ؽڵ�
	Joint Jdistal;

	//local����ϵ
	coordSys local;
	
	//���Բ���
	//֫������
	float mass;
	//֫�ε���������
	Eigen::Vector3f segcom;

private:
	//����segCOM_ /Dampster
	void calSegCOM(Eigen::Vector3f &segcom, Joint &jointP, Joint &jointD, const int &segNum);
};

