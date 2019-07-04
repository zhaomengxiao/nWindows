#pragma once
#include "obj.h"


typedef std::vector<OBJ::Joints> jframes;
typedef std::vector<OBJ::JointAngles> jAngleframes;
typedef std::vector<std::vector<OBJ::Joints>> cycles_joints;
typedef std::vector<std::vector<OBJ::JointAngles>> cycles_jAngles;
typedef std::vector<std::vector<double>> stdMatd;

class Cycle
{
private:
	jframes				m_jframes;	
	cycles_joints		m_cycles_joints;
	jAngleframes		m_jAngleframes;
	cycles_jAngles		m_cycles_jAngles;
	stdMatd				m_norframeMark;

	stdMatd				m_plotdata;
	stdMatd				m_plfP_plotdata;
	std::vector<double> m_aveP_plotdata;
	std::vector<double> m_meanSqErr;
public:
	std::vector<int>    splitFrames;
public:
	Cycle();
	~Cycle();
	Cycle(const OBJ::Obj & obj);
	
	
	//�����ankle֮����yֵ�жϽ������Ϻ�����֮֡��֡��
	static std::vector<int> getExtremeFrame(const std::vector<OBJ::Joints> & jframes,int rpm);
	//���ɻ��֮��ֵ֡���зֳ�����Cycle,ȥ��ͷβ
	cycles_joints getCycle_joints(const jframes & jframes);
	cycles_jAngles getCycle_Angles(const jAngleframes & jframes);
	static double normalize(int n, int framenumber);
	static stdMatd calNorFrameMark(const cycles_joints & cycs);
	//��cycle��������ȡָ���ؽ�֮ĳһά��������ϳ���ֵ������������ͻ�ͼ
	static stdMatd extractMatdata(const cycles_joints & cycs, JointType jt, QString xyz);
	static stdMatd extractMatdata(const cycles_jAngles &cycs);//�ӹؽڽǶ��г��Knee
	//��polyFit֮�����м���ƽ��֮����
	static std::vector<double> calAvePara(const stdMatd & paraMat);
	//��polyfit֮���������ƽ�������м��㷽��
	static std::vector<double> calMeanSqErr(const stdMatd & paraMat, std::vector<double> aveP);
	//Get
	const jframes	getJframes();
	const jAngleframes getJAngleframes();
	const cycles_joints	getCycles_Joints();
	const cycles_jAngles getCycles_Angle();
	const stdMatd	getNorFrameMark();
	const stdMatd	getLeftAnkleY();
	const stdMatd	getPlfPara();
	const std::vector<double> getAvePara();
	const std::vector<double> getMeanSqErr();
	//Set
	//���û��Ƶ����ϣ�����1.�ؽڣ�2.�����ᣬ3.fit�̶�
	void setPlotpart(JointType jt, QString xyz, int n);
	void setPlotMat(int n);
	//math
	std::vector<double> polyfit(std::vector<double> x, std::vector<double> y, int n);
	stdMatd polyfit(stdMatd matx, stdMatd maty, int n);
	//type trans
	Eigen::VectorXd stdVector_2_VectorXd(std::vector<double> vec);
	std::vector<double> VectorXd_2_stdVector(Eigen::VectorXd v);
};

