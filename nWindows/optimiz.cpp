#include "optimiz.h"

//from extern 
//OBJ::CaliInfo *p_optParameters = new  OBJ::CaliInfo();

using namespace OPT;

OBJ::Joints OPT::optSingleF(const OBJ::Obj &obj,int frameNum)
{
#pragma region Pelvis Opt

	//vec hipLeft_local = OPT::subtract(joints[JointType_HipLeft], joints[JointType_SpineMid]);
	//vec hipRight_local = OPT::subtract(joints[JointType_HipRight], joints[JointType_SpineMid]);
	//vec shoulderLeft_local = OPT::subtract(joints[JointType_ShoulderLeft], joints[JointType_SpineMid]);
	//vec shoulderRight_local = OPT::subtract(joints[JointType_ShoulderRight], joints[JointType_SpineMid]);

	//column_vector  pelvis_OptVar = {
	//	hipLeft_local.x(), hipLeft_local.y(), hipLeft_local.z(),
	//	hipRight_local.x(), hipRight_local.y(), hipRight_local.z()
	//	/*,shoulderLeft_local.x(), shoulderLeft_local.y(), shoulderLeft_local.z(),
	//	shoulderRight_local.x(), shoulderRight_local.y(), shoulderRight_local.z()*/
	//};
	//std::cout << "Pelvis Opt:\n";
	//std::cout << "start point:\n" << pelvis_OptVar << std::endl;

	//dlib::find_min_using_approximate_derivatives(dlib::bfgs_search_strategy(),
	//	dlib::objective_delta_stop_strategy(1e-7),
	//	cfun_Trunk, pelvis_OptVar, 0);
	//std::cout << "opt solution:\n" << pelvis_OptVar << std::endl;
#pragma endregion
	#pragma region 取得最佳化需要之参数（来自subj cali 之4个肢段的长度）
	double L1 = obj.getCaliInfo().SegL[OBJ::SegType_LeftThigh];
	double L2 = obj.getCaliInfo().SegL[OBJ::SegType_LeftShank];
	double L3 = obj.getCaliInfo().SegL[OBJ::SegType_RightThigh];
	double L4 = obj.getCaliInfo().SegL[OBJ::SegType_RightShank];
	std::cout << "seg length:" << L1 << "," << L2 << "," << L3 << "," << L4 << std::endl;
	#pragma endregion

	#pragma region 取得下肢相对于pelvis之局部坐标用于最佳化(已平滑过的动作)
	OBJ::coordSys lcoord_pelvis = obj.getSegments()[frameNum][OBJ::SegType_Pelvis].lcoord;
	Eigen::Vector3f HipLeft_local = OBJ::Obj::Pg2l(obj.getJoints_filted()[frameNum][JointType_HipLeft], lcoord_pelvis);
	Eigen::Vector3f HipRight_local = OBJ::Obj::Pg2l(obj.getJoints_filted()[frameNum][JointType_HipRight], lcoord_pelvis);
	Eigen::Vector3f KneeLeft_local = OBJ::Obj::Pg2l(obj.getJoints_filted()[frameNum][JointType_KneeLeft], lcoord_pelvis);
	Eigen::Vector3f KneeRight_local = OBJ::Obj::Pg2l(obj.getJoints_filted()[frameNum][JointType_KneeRight], lcoord_pelvis);
	Eigen::Vector3f AnkleLeft_local = OBJ::Obj::Pg2l(obj.getJoints_filted()[frameNum][JointType_AnkleLeft], lcoord_pelvis);
	Eigen::Vector3f AnkleRight_local = OBJ::Obj::Pg2l(obj.getJoints_filted()[frameNum][JointType_AnkleRight], lcoord_pelvis);
	#pragma endregion

	//Cost function to minimize (lambda function)
	auto cfun_4Link = [&](double Y, double Z, double theta1, double theta2, double theta3, double theta4)
	{
		#pragma region _y0,_z0,_y1,_z1,_y2,_z2,_y3,_z3,_y4,_z4
		double _y0 = HipLeft_local.y();
		double _z0 = HipLeft_local.z();
		double _y1 = KneeLeft_local.y();
		double _z1 = KneeLeft_local.z();
		double _y2 = AnkleLeft_local.y();
		double _z2 = AnkleLeft_local.z();

		double _y3 = KneeRight_local.y();
		double _z3 = KneeRight_local.z();
		double _y4 = AnkleRight_local.y();
		double _z4 = AnkleRight_local.z();
		#pragma endregion

		

		#pragma region y0,y1, y2, y3, y4, z0,z1, z2, z3, z4
		double y0, y1, y2, y3, y4, z0, z1, z2, z3, z4;
		y0 = Y;
		z0 = Z;

		y1 = (L1 * sin(theta1)) + Y;
		z1 = (-L1 * cos(theta1)) + Z;
		y2 = (y1 + L2 * sin(theta2)) + Y;
		z2 = (z1 - L2 * cos(theta2)) + Z;

		y3 = (L3 * sin(theta3)) + Y;
		z3 = (-L3 * cos(theta3)) + Z;
		y4 = (y3 + L4 * sin(theta4)) + Y;
		z4 = (z3 - L4 * cos(theta4)) + Z;
		#pragma endregion

		double cost{ 0.0 };
		double w0{ 0.2 }, w1{ 0.3 }, w2{ 0.1 }, w3{ 0.3 }, w4{ 0.1 };  //w0 hip w1 w3 knee w2 w4 ankle  不准的点weighting低
		cost = (w0*((_y0 - y0)*(_y0 - y0) + (_z0 - z0)*(_z0 - z0))
			+ w1 * ((_y1 - y1)*(_y1 - y1) + (_z1 - z1)*(_z1 - z1))
			+ w2 * ((_y2 - y2)*(_y2 - y2) + (_z2 - z2)*(_z2 - z2))
			+ w3 * ((_y3 - y3)*(_y3 - y3) + (_z3 - z3)*(_z3 - z3))
			+ w4 * ((_y4 - y4)*(_y4 - y4) + (_z4 - z4)*(_z4 - z4))) * 10000;

		return cost;
	};


	// To optimize this difficult function all we need to do is call
	// find_min_global()
	auto result = dlib::find_min_global(cfun_4Link,
		{ -0.001,-0.001,-PI / 2.0 , -PI / 2.0,-PI / 2.0,-PI / 2.0 }, // lower bounds
		{ 0.001,0.001,PI / 2.0,PI / 2.0,PI / 2.0,PI / 2.0 }, // upper bounds
		dlib::max_function_calls(150));

	//std::cout.precision(5);
	//// These cout statements will show that find_min_global() found the
	//// globally optimal solution to 9 digits of precision:
	//std::cout << "complex holder table function solution y (should be -21.9210397): " << result.y << endl;
	//std::cout << "complex holder table function solution x:\n" << result.x *180.0 / PI << endl;

	//计算opt后之global坐标
	double Y_opt = result.x(0);
	double Z_opt = result.x(1);
	double t1 = result.x(2);
	double t2 = result.x(3);
	double t3 = result.x(4);
	double t4 = result.x(5);

	double y0_opt, y1_opt, y2_opt, y3_opt, y4_opt, z0_opt, z1_opt, z2_opt, z3_opt, z4_opt;
	
	y0_opt = Y_opt;
	z0_opt = Z_opt;
	y1_opt = (L1 * sin(t1))+Y_opt;
	z1_opt = (-L1 * cos(t1))+Z_opt;
	y2_opt = (y1_opt + L2 * sin(t2)) + Y_opt;
	z2_opt = (z1_opt - L2 * cos(t2)) + Z_opt;

	y3_opt = (L3 * sin(t3)) + Y_opt;
	z3_opt = (-L3 * cos(t3)) + Z_opt;
	y4_opt = (y3_opt + L4 * sin(t4)) + Y_opt;
	z4_opt = (z3_opt - L4 * cos(t4)) + Z_opt;

	Eigen::Vector3f HipLeft_local_opt{ HipLeft_local.x(),float(y0_opt),float(z0_opt) };
	Eigen::Vector3f HipRight_local_opt{ HipRight_local.x(),float(y0_opt),float(z0_opt) };
	Eigen::Vector3f KneeLeft_local_opt{ KneeLeft_local.x(),float(y1_opt),float(z1_opt) };
	Eigen::Vector3f AnkleLeft_local_opt{ AnkleLeft_local.x(),float(y2_opt),float(z2_opt) };
	Eigen::Vector3f KneeRight_local_opt{ KneeRight_local.x(),float(y3_opt),float(z3_opt) };
	Eigen::Vector3f AnkleRight_local_opt{ AnkleRight_local.x(),float(y4_opt),float(z4_opt) };

	Eigen::Vector3f HipLeft_g_opt = OBJ::Obj::Pl2g(HipLeft_local_opt, lcoord_pelvis);
	Eigen::Vector3f HipRight_g_opt = OBJ::Obj::Pl2g(HipRight_local_opt, lcoord_pelvis);
	Eigen::Vector3f KneeLeft_g_opt = OBJ::Obj::Pl2g(KneeLeft_local_opt, lcoord_pelvis);
	Eigen::Vector3f AnkleLeft_g_opt = OBJ::Obj::Pl2g(AnkleLeft_local_opt, lcoord_pelvis);
	Eigen::Vector3f KneeRight_g_opt = OBJ::Obj::Pl2g(KneeRight_local_opt, lcoord_pelvis);
	Eigen::Vector3f AnkleRight_g_opt = OBJ::Obj::Pl2g(AnkleRight_local_opt, lcoord_pelvis);

	OBJ::Joints res;
	res = obj.getJoints_filted()[frameNum];
	
	res[JointType_HipLeft].jointPosition = HipLeft_g_opt;
	res[JointType_HipRight].jointPosition = HipRight_g_opt;
	res[JointType_KneeLeft].jointPosition = KneeLeft_g_opt;
	res[JointType_KneeRight].jointPosition = KneeRight_g_opt;
	res[JointType_AnkleLeft].jointPosition = AnkleLeft_g_opt;
	res[JointType_AnkleRight].jointPosition = AnkleRight_g_opt;
	//OBJ::OptJoints res{ HipLeft_g_opt,HipRight_g_opt,KneeLeft_g_opt ,AnkleLeft_g_opt ,KneeRight_g_opt ,AnkleRight_g_opt };
	return  res;
}

std::vector<OBJ::Joints> OPT::Optframes(const OBJ::Obj & obj)
{
	//std::vector<OBJ::OptJoints> res{ unsigned __int64( obj.getFrameNumber())};
	std::vector<OBJ::Joints> res{ unsigned __int64(obj.getFrameNumber()) };

	dlib::parallel_for(0, obj.getFrameNumber(), [&](int i) {
		// The i variable is the loop counter as in a normal for loop.  So we simply need
		// to place the body of the for loop right here and we get the same behavior.  The
		// range for the for loop is determined by the 1nd and 2rd arguments to
		// parallel_for().  This way of calling parallel_for() will use a number of threads
		// that is appropriate for your hardware.  See the parallel_for() documentation for
		// other options.
		res[i] = optSingleF(obj, i);
	});

	return res;
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
