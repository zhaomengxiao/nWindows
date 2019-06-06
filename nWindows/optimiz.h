#pragma once

#include <dlib/global_optimization.h>
#include <obj.h>
#include <dlib/geometry.h>
namespace OPT{
	//空间向量
	typedef dlib::vector<double, 3> vec;
	typedef dlib::matrix<double, 0, 1> column_vector;

	//执行对一帧的最佳化
	void optSingleF(const OBJ::Joints &joints);
	//math
	vec subtract(const OBJ::Joint &A, const OBJ::Joint &B);
	double norm(vec v);
	
	//const func, 放入find_min中作为要最小化的目标函数
	double cfun_Trunk(const column_vector &x);
	double cfun_Leg_L(const column_vector &x);
	double cfun_Leg_R(const column_vector &x);
	vec subtract(const OBJ::Joint &A, const OBJ::Joint &B);
}


