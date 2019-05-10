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
	//近端关节
	Joint Jproximal;
	//远端关节点
	Joint Jdistal;

	//local坐标系
	coordSys local;
	
	//惯性参数
	//肢段质量
	float mass;
	//肢段的质量中心
	Eigen::Vector3f segcom;

private:
	//计算segCOM_ /Dampster
	void calSegCOM(Eigen::Vector3f &segcom, Joint &jointP, Joint &jointD, const int &segNum);
};

