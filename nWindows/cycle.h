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
	
	
	//由左脚ankle之坐标y值判断脚在最上和最下之帧的帧数
	static std::vector<int> getExtremeFrame(const std::vector<OBJ::Joints> & jframes,int rpm);
	//借由获得之极值帧数切分出各个Cycle,去掉头尾
	cycles_joints calCycle_joints(const jframes & jframes);
	cycles_jAngles calCycle_Angles(const jAngleframes & jframes);
	
	static double normalize(int n, int framenumber);
	static stdMatd calNorFrameMark(const cycles_joints & cycs);
	//从cycle矩阵中提取指定关节之某一维度资料组合成数值矩阵用于运算和绘图
	static stdMatd extractMatdata(const cycles_joints & cycs, JointType jt, QString xyz);
	static stdMatd extractMatdata(const cycles_jAngles &cycs, OBJ::JAngleType jAt,QString xyz);//从关节角度中抽出Knee
	//从polyFit之矩阵中计算平均之曲线
	static std::vector<double> calAvePara(const stdMatd & paraMat);
	//从polyfit之参数矩阵和平均参数中计算方差
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
	//设置绘制的资料，输入1.关节，2.坐标轴，3.fit程度
	void setPlotpart(JointType jt, QString xyz, int n);
	void setPlotMat(OBJ::JAngleType jAt, QString xyz, int n);
	
	
	
	static stdMatd polyfit(stdMatd matx, stdMatd maty, int n);
	//type trans
	
	
};

