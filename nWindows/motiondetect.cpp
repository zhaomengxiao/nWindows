#include "motiondetect.h"



MotionDetect::MotionDetect()
{
}


MotionDetect::~MotionDetect()
{
}

std::vector<int> MotionDetect::getExtremeFrame(const std::vector<OBJ::Joints>& jframes)
{
	std::vector<int> res;
	float old_footy = jframes[0][JointType_AnkleLeft].jointPosition.y();
	float new_footy = jframes[1][JointType_AnkleLeft].jointPosition.y();
	float slop = new_footy - old_footy;
	for (int i = 2; i < jframes.size(); i++)
	{
		//计算左脚的foot的y坐标的斜率
		old_footy = jframes[i-1][JointType_AnkleLeft].jointPosition.y();
		new_footy = jframes[i][JointType_AnkleLeft].jointPosition.y();
		float new_slop = new_footy - old_footy;
		//记录斜率
		if (new_slop > 0 && slop < 0)//如果斜率符号改变就是高点和低点。
		{
			res.push_back(i);
		}
		slop = new_slop;
	}
	return res;
}


