#pragma once
#include "obj.h"

class MotionDetect
{
public:
	MotionDetect();
	~MotionDetect();
	//�����ankle֮����yֵ�жϽ������Ϻ�����֮֡��֡��
	static std::vector<int> getExtremeFrame(const std::vector<OBJ::Joints> & jframes);
	//���ɻ��֮��ֵ֡���зֳ�����Cycle
	
};

