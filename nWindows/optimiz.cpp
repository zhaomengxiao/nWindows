#include "optimiz.h"

//from extern 
OBJ::CaliInfo *p_optParameters = new  OBJ::CaliInfo();

using namespace OPT;

void OPT::optSingleF(const OBJ::Joints &joints)
{
#pragma region Pelvis Opt

	vec hipLeft_local = OPT::subtract(joints[JointType_HipLeft], joints[JointType_SpineMid]);
	vec hipRight_local = OPT::subtract(joints[JointType_HipRight], joints[JointType_SpineMid]);
	vec shoulderLeft_local = OPT::subtract(joints[JointType_ShoulderLeft], joints[JointType_SpineMid]);
	vec shoulderRight_local = OPT::subtract(joints[JointType_ShoulderRight], joints[JointType_SpineMid]);

	column_vector  pelvis_OptVar = {
		hipLeft_local.x(), hipLeft_local.y(), hipLeft_local.z(),
		hipRight_local.x(), hipRight_local.y(), hipRight_local.z()
		/*,shoulderLeft_local.x(), shoulderLeft_local.y(), shoulderLeft_local.z(),
		shoulderRight_local.x(), shoulderRight_local.y(), shoulderRight_local.z()*/
	};
	std::cout << "Pelvis Opt:\n";
	std::cout << "start point:\n" << pelvis_OptVar << std::endl;

	dlib::find_min_using_approximate_derivatives(dlib::bfgs_search_strategy(),
		dlib::objective_delta_stop_strategy(1e-7),
		cfun_Trunk, pelvis_OptVar, 0);
	std::cout << "opt solution:\n" << pelvis_OptVar << std::endl;
#pragma endregion
	
#pragma region Leg_left opt

	vec kneeLeft_local = OPT::subtract(joints[JointType_KneeLeft], joints[JointType_HipLeft]);
	vec ankleLeft_local = OPT::subtract(joints[JointType_AnkleLeft], joints[JointType_HipLeft]);
	
	column_vector  Leg_left_OptVar = {
		kneeLeft_local.x(), kneeLeft_local.y(), kneeLeft_local.z(),
		ankleLeft_local.x(), ankleLeft_local.y(), ankleLeft_local.z(),
	};
	std::cout << "Leg_left Opt:\n";
	std::cout << "start point:\n" << Leg_left_OptVar << std::endl;

	dlib::find_min_using_approximate_derivatives(dlib::bfgs_search_strategy(),
		dlib::objective_delta_stop_strategy(1e-7),
		cfun_Leg_L, Leg_left_OptVar, 0);
	std::cout << "opt solution:\n" << Leg_left_OptVar << std::endl;
#pragma endregion

#pragma region Leg_right opt

	vec kneeRight_local = OPT::subtract(joints[JointType_KneeRight], joints[JointType_HipRight]);
	vec ankleRight_local = OPT::subtract(joints[JointType_AnkleRight], joints[JointType_HipLeft]);

	column_vector  Leg_right_OptVar = {
		kneeRight_local.x(), kneeRight_local.y(), kneeRight_local.z(),
		ankleRight_local.x(), ankleRight_local.y(), ankleRight_local.z()
	};
	std::cout << "Leg_right Opt:\n";
	std::cout << "start point:\n" << Leg_right_OptVar << std::endl;

	dlib::find_min_using_approximate_derivatives(dlib::bfgs_search_strategy(),
		dlib::objective_delta_stop_strategy(1e-7),
		cfun_Leg_R, Leg_right_OptVar, 0);
	std::cout << "opt solution:\n" << Leg_right_OptVar << std::endl;
#pragma endregion

}

dlib::vector<double, 3> OPT::subtract(const OBJ::Joint & A,const OBJ::Joint & B)
{
	vec res(A.jointPosition.x()- B.jointPosition.x(), A.jointPosition.y() - B.jointPosition.y(), A.jointPosition.z() - B.jointPosition.z());
	
	return res;
}

double OPT::norm(vec v)
{
	return sqrtf(v.x()*v.x() + v.y()*v.y() + v.y()*v.y());
}
double OPT::cfun_Trunk(const column_vector &x)
{
	vec _a{ x(0)*100.0,x(1)*100.0 ,x(2)*100.0 };
	vec _b{ x(3)*100.0,x(4)*100.0 ,x(5)*100.0 };
	
	double _length = OPT::norm(_a.cross(_b)) / 2.0 ;
	double length = p_optParameters->SegL[OBJ::SegType_Pelvis];
	double err = (_length - length)*(_length - length);

	return err;
}

double OPT::cfun_Leg_L(const column_vector & x)
{
	double _thighLength = (x(0)) * (x(0)) +
						  (x(1)) * (x(1)) +
						  (x(2)) * (x(2));
	_thighLength = sqrt(_thighLength)*100.0;
	double _shankLength = (x(3) - x(0)) * (x(3) - x(0)) +
						  (x(4) - x(1)) * (x(4) - x(1)) +
						  (x(5) - x(2)) * (x(5) - x(2));
	_shankLength = sqrt(_shankLength)*100.0;
	
	double thighLength = p_optParameters->SegL[OBJ::SegType_LeftThigh];
	double shankLength = p_optParameters->SegL[OBJ::SegType_LeftShank];

	double err = (_thighLength - thighLength)*(_thighLength - thighLength)
		       + (_shankLength - shankLength)*(_shankLength - shankLength);
	return err;
}

double OPT::cfun_Leg_R(const column_vector & x)
{
	double _thighLength = (x(0)) * (x(0)) +
		(x(1)) * (x(1)) +
		(x(2)) * (x(2));
	_thighLength = sqrt(_thighLength)*100.0;
	double _shankLength = (x(3) - x(0)) * (x(3) - x(0)) +
		(x(4) - x(1)) * (x(4) - x(1)) +
		(x(5) - x(2)) * (x(5) - x(2));
	_shankLength = sqrt(_shankLength)*100.0;

	double thighLength = p_optParameters->SegL[OBJ::SegType_RightThigh];
	double shankLength = p_optParameters->SegL[OBJ::SegType_RightShank];

	double err = (_thighLength - thighLength)*(_thighLength - thighLength)
		+ (_shankLength - shankLength)*(_shankLength - shankLength);
	return err;
}
