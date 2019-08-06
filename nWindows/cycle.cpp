#include "cycle.h"



Cycle::Cycle()
{
}


Cycle::~Cycle()
{
}

Cycle::Cycle(const OBJ::Obj & obj, QString filtorOpt)
{
	m_jframes = obj.getJoints();
	if (filtorOpt == "filt")
	{
		splitFrames = getExtremeFrame(obj.getJoints_filted(), obj.RPM);
		m_cycles_joints = calCycle_joints(obj.getJoints_filted());
		m_cycles_jAngles = calCycle_Angles(obj.getJointAngles_filted());
	}
	else if (filtorOpt == "opt")
	{
		splitFrames = getExtremeFrame(obj.getJoints_filted(), obj.RPM);
		m_cycles_joints = calCycle_joints(obj.getJoints_opted());
		m_cycles_jAngles = calCycle_Angles(obj.getJointAngles_opted());
	}
	else if (filtorOpt == "raw") {
		splitFrames = getExtremeFrame(obj.getJoints_filted(), obj.RPM);
		m_cycles_joints = calCycle_joints(obj.getJoints());
		m_cycles_jAngles = calCycle_Angles(obj.getJointAngles());
	}
	else {
		qDebug() << "Cycle construct Error: NO fit data type/raw/opt/filt" << endl;
	}
	
	
	
	m_norframeMark = calNorFrameMark(m_cycles_joints);
}

std::vector<int> Cycle::getExtremeFrame(const std::vector<OBJ::Joints>& jframes, int rpm)
{
	int minframeNum = int(60.0 / rpm * 20.0) - int(300/rpm);
	std::vector<int> res;
	float old_footy = jframes[0][JointType_AnkleLeft].jointPosition.y();
	float new_footy = jframes[1][JointType_AnkleLeft].jointPosition.y();
	float slop = new_footy - old_footy;
	for (int i = 2; i < jframes.size(); i++)
	{
		//计算左脚的foot的y坐标的斜率
		old_footy = jframes[i - 1][JointType_AnkleLeft].jointPosition.y();
		new_footy = jframes[i][JointType_AnkleLeft].jointPosition.y();
		float new_slop = new_footy - old_footy;
		//记录斜率
		if (new_slop > 0 && slop < 0)//如果斜率符号改变就是高点和低点。
		{
			//判断是否太靠近 RPM30一般40帧左右，RPM60 20帧 RPM75 
			if (res.empty())
			{
				res.push_back(i);
			}
			else
			{
				if (i - res.back() > minframeNum)
				{
					if (i>2)
					{
						res.push_back(i-2);
					}
					else
					{
						res.push_back(i);
					}
					
				}
			}
			
		}
		slop = new_slop;
	}
	return res;
}

std::vector<std::vector<OBJ::Joints>> Cycle::calCycle_joints(const jframes & jf)
{
	
	cycles_joints res;
	res.reserve(splitFrames.size());
	for (int i = 0; i < splitFrames.size() - 1; i++)
	{
		res.push_back(std::vector<OBJ::Joints>(jf.begin() + splitFrames[i], jf.begin() + splitFrames[i + 1]));
	}
	if (res.size() >3)
	{
		std::vector<std::vector<OBJ::Joints>> cutoff = std::vector<std::vector<OBJ::Joints>>(res.begin() + 1, res.end() - 1);
		return cutoff;
	}
	return res;
	
	
}
cycles_jAngles Cycle::calCycle_Angles(const jAngleframes & jAf)
{
	cycles_jAngles res;
	res.reserve(splitFrames.size());
	for (int i = 0; i < splitFrames.size() - 1; i++)
	{
		res.push_back(jAngleframes(jAf.begin() + splitFrames[i], jAf.begin() + splitFrames[i + 1]));
	}
	if (res.size() > 3)
	{
		cycles_jAngles cutoff = cycles_jAngles(res.begin() + 1, res.end() - 1);
		return cutoff;
	}
	return res;
}
//把数据点分布到0-360
double Cycle::normalize(int n, int framenumber)
{
	return double(n) / double(framenumber)*360.0;
}

stdMatd Cycle::calNorFrameMark(const cycles_joints & cycs)
{
	stdMatd res;
	res.reserve(cycs.size());
	std::vector<double> frameMarks;
	for (auto cycle:cycs)
	{
		frameMarks.clear();
		frameMarks.reserve(cycle.size());
		int frameNumber = cycle.size();
		for (int i = 0; i < cycle.size(); i++)
		{
			frameMarks.push_back(normalize(i, frameNumber));
		}
		res.push_back(frameMarks);
	}
	return res;
}

stdMatd Cycle::extractMatdata(const cycles_joints & cycs, JointType jt, QString xyz)
{
	stdMatd res;
	res.reserve(cycs.size());
	std::vector<double> jointdata;
	for (auto cycle : cycs)
	{
		jointdata.clear();
		jointdata.reserve(cycle.size());
		for (int i = 0; i < cycle.size(); i++)
		{
			if (xyz == QString("x") || xyz == QString("X"))
			{
				jointdata.push_back(cycle[i][jt].jointPosition.x());
			}
			else if (xyz == QString("y") || xyz == QString("Y"))
			{
				jointdata.push_back(cycle[i][jt].jointPosition.y());
			}
			else if (xyz == QString("z") || xyz == QString("Z"))
			{
				jointdata.push_back(cycle[i][jt].jointPosition.z());
			}
			else
			{
				std::cout << "Error: extractJ1Ddata , need specify x y or z" << std::endl;
			}
			
		}
		res.push_back(jointdata);
	}
	return res;
}

stdMatd Cycle::extractMatdata(const cycles_jAngles & cycs, OBJ::JAngleType jAt, QString xyz)
{
	stdMatd res;
	res.reserve(cycs.size());
	std::vector<double> AngleData;
	for (auto cycle : cycs)
	{
		AngleData.clear();
		AngleData.reserve(cycle.size());
		for (int i = 0; i < cycle.size(); i++)
		{
			if (xyz == QString("x") || xyz == QString("X"))
			{
				AngleData.push_back(cycle[i][jAt].Angle_x);
			}
			else if (xyz == QString("y") || xyz == QString("Y"))
			{
				AngleData.push_back(cycle[i][jAt].Angle_y);
			}
			else
			{
				AngleData.push_back(cycle[i][jAt].Angle_z);
			}
			
		}
		res.push_back(AngleData);
	}
	return res;
}

std::vector<double> Cycle::calAvePara(const stdMatd & paraMat)
{
	if (!paraMat.empty())
	{
		std::vector<double> ave(paraMat[0].size(), 0);
		int n = 0;
		for (auto para : paraMat)
		{
			n++;
			for (int i = 0; i < para.size(); i++)
			{
				ave[i] += para[i];
			}
		}
		for (int i = 0; i < ave.size(); i++)
		{
			ave[i] = ave[i] / n;
		}
		return ave;
	}
	else
	{
		qDebug() << "paraMat is empty" << endl;
	}
	
}

std::vector<double> Cycle::calMeanSqErr(const stdMatd & paraMat, std::vector<double> aveP)
{
	std::vector<double> res(361, 0);
	for (int i = 0; i < 361; i++)
	{
		int N = 0;
		for (auto para : paraMat)
		{
			N++;
			double y_value = 0;
			double y_value_ave = 0;
			
			for (int n = 0; n < para.size(); n++)
			{
				y_value += pow(i, n)*para[n];
			}
			
			for (int n = 0; n < aveP.size(); n++)
			{
				y_value_ave += pow(i, n)*aveP[n];
			}
			res[i] += (y_value - y_value_ave)*(y_value - y_value_ave);
		}
		res[i] = sqrt(res[i] / N);
	}
	return res;
}



const jframes Cycle::getJframes()
{
	return m_jframes;
}

const jAngleframes Cycle::getJAngleframes()
{
	return m_jAngleframes;
}

const cycles_joints Cycle::getCycles_Joints()
{
	return m_cycles_joints;
}

const cycles_jAngles Cycle::getCycles_Angle()
{
	return m_cycles_jAngles;
}

const stdMatd Cycle::getNorFrameMark()
{
	return m_norframeMark;
}

const stdMatd Cycle::getDataMat()
{
	return m_plotdata;
}

const stdMatd Cycle::getPlfPara()
{
	return m_plfP_plotdata;
}

const std::vector<double> Cycle::getAvePara()
{
	return m_aveP_plotdata;
}

const std::vector<double> Cycle::getMeanSqErr()
{
	return m_meanSqErr;
}

void Cycle::setPlotpart(JointType jt, QString xyz, int n)
{
	m_plotdata = extractMatdata(m_cycles_joints, jt, xyz);

	m_plfP_plotdata = polyfit(m_norframeMark, m_plotdata, n);

	m_aveP_plotdata = calAvePara(m_plfP_plotdata);

	m_meanSqErr = calMeanSqErr(m_plfP_plotdata, m_aveP_plotdata);
}

void Cycle::setPlotMat(OBJ::JAngleType jAt, QString xyz, int n)
{
	m_plotdata = extractMatdata(m_cycles_jAngles, jAt, xyz);

	m_plfP_plotdata = polyfit(m_norframeMark, m_plotdata, n);

	m_aveP_plotdata = calAvePara(m_plfP_plotdata);

	m_meanSqErr = calMeanSqErr(m_plfP_plotdata, m_aveP_plotdata);
}

stdMatd Cycle::polyfit(stdMatd matx, stdMatd maty, int n)
{
	stdMatd res;
	res.reserve(matx.size());
	for (int i = 0; i < matx.size(); i++)
	{
		std::vector<double> x(matx[i]);
		std::vector<double> y(maty[i]);
		std::vector<double> p = myMath::polyfit(x, y, n);
		res.push_back(p);
	}
	return res;
}

