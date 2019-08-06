#pragma once
#include "obj.h"


typedef std::vector<OBJ::Joints> jframes;
typedef std::vector<OBJ::Angles> jAngleframes;
typedef std::vector<std::vector<OBJ::Joints>> cycles_joints;
typedef std::vector<std::vector<OBJ::Angles>> cycles_jAngles;
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
	Cycle(const OBJ::Obj & obj,QString filtorOpt);
	
	
	//�����ankle֮����yֵ�жϽ������Ϻ�����֮֡��֡��
	static std::vector<int> getExtremeFrame(const std::vector<OBJ::Joints> & jframes,int rpm);
	//���ɻ��֮��ֵ֡���зֳ�����Cycle,ȥ��ͷβ
	cycles_joints calCycle_joints(const jframes & jframes);
	cycles_jAngles calCycle_Angles(const jAngleframes & jframes);
	
	static double normalize(int n, int framenumber);
	static stdMatd calNorFrameMark(const cycles_joints & cycs);
	//��cycle��������ȡָ���ؽ�֮ĳһά��������ϳ���ֵ������������ͻ�ͼ
	static stdMatd extractMatdata(const cycles_joints & cycs, JointType jt, QString xyz);
	static stdMatd extractMatdata(const cycles_jAngles &cycs, OBJ::JAngleType jAt,QString xyz);//�ӹؽڽǶ��г��Knee
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
	const stdMatd	getDataMat();
	const stdMatd	getPlfPara();
	const std::vector<double> getAvePara();
	const std::vector<double> getMeanSqErr();
	//Set
	//���û��Ƶ����ϣ�����1.�ؽڣ�2.�����ᣬ3.fit�̶�
	void setPlotpart(JointType jt, QString xyz, int n);
	void setPlotMat(OBJ::JAngleType jAt, QString xyz, int n);
	
	
	
	static stdMatd polyfit(stdMatd matx, stdMatd maty, int n);
	//type trans
	
	
};

