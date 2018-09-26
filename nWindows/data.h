#pragma once
#include <vector>
#include <string>


struct AngleFrame
{
	float x;
	float y;
	float z;
	double time;
};

std::vector<AngleFrame> angleStream{};
std::vector<Eigen::Vector4d> quatstream[25];