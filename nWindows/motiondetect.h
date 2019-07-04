#pragma once
#include "obj.h"

class MotionDetect
{
public:
	MotionDetect();
	~MotionDetect();
	//由左脚ankle之坐标y值判断脚在最上和最下之帧的帧数
	static std::vector<int> getExtremeFrame(const std::vector<OBJ::Joints> & jframes);
	//借由获得之极值帧数切分出各个Cycle
	
};

