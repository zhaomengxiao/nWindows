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
		//������ŵ�foot��y�����б��
		old_footy = jframes[i-1][JointType_AnkleLeft].jointPosition.y();
		new_footy = jframes[i][JointType_AnkleLeft].jointPosition.y();
		float new_slop = new_footy - old_footy;
		//��¼б��
		if (new_slop > 0 && slop < 0)//���б�ʷ��Ÿı���Ǹߵ�͵͵㡣
		{
			res.push_back(i);
		}
		slop = new_slop;
	}
	return res;
}


