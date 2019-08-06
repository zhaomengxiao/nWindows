#include "obj.h"


using namespace OBJ;

//Joint
OBJ::Joint::Joint()
{
}

OBJ::Joint::~Joint()
{
}
OBJ::Joint::Joint(JointType jt, float x, float y, float z, TrackingState ts)
{
	jointType = jt;
	jointPosition<< x,y,z;
	trackingState = ts;
}

void OBJ::Joint::print()
{
	std::cout << jointType << "  ,  " << trackingState << "  ,  " << std::endl;
	std::cout << jointPosition << std::endl;
}

std::array<float, 3> OBJ::Joint::subtract(const OBJ::Joint & r)
{
	std::array<float, 3> res{ this->jointPosition.x() - r.jointPosition.x(), this->jointPosition.y() - r.jointPosition.y(), this->jointPosition.z() - r.jointPosition.z() };
	return res;
}

Eigen::Vector3f OBJ::Joint::Pg2l(const coordSys & lcoord)
{
	Eigen::Vector3f pointG = this->jointPosition;
	Eigen::Vector3f pointL = (lcoord.R).transpose()*(pointG - lcoord.V);
	return pointL;
}

//Segment
Segment::Segment()
{
}


Segment::~Segment()
{
}

Segment::Segment(const OBJ::Joint& jp,const OBJ::Joint& jd,const SegType& st, const SubjInfo & subjinfo)
{
	
	Jproximal = jp;
	Jdistal = jd;
	
	SegmentType = st;
	//设定trackingState
	if (jp.trackingState == 2 && jd.trackingState == 2)
	{
		trackingState = TrackingState(2);
	}
	else if (jp.trackingState == 0 && jd.trackingState == 0)
	{
		trackingState = TrackingState(0);
	}
	else
	{
		trackingState = TrackingState(1);
	}
	//设定肢段质量mass(kg)
	float w = subjinfo.weight;
	switch (SegmentType)
	{
	case SegType_LeftThigh://thigh
		mass = w*0.1;
		break;
	case SegType_RightThigh://thigh
		mass = w * 0.1;
		break;
	case SegType_LeftShank://shank
		mass = w * 0.0465;
		break;
	case SegType_RightShank://shank
		mass = w * 0.0465;
		break;
	case SegType_LeftFoot://foot
		mass = w * 0.0145;
		break;
	case SegType_RightFoot://foot
		mass = w * 0.0145;
		break;
	case SegType_LeftUpperArm://Upper arm
		mass = w * 0.028;
		break;
	case SegType_RightUpperArm://Upper arm
		mass = w * 0.028;
		break;
	case SegType_LeftForArmHand://forearm and hand
		mass = w * 0.022;
		break;
	case SegType_RightForArmHand://forearm and hand
		mass = w * 0.022;
		break;
	case SegType_Pelvis://Pelvis
		mass = w * 0.142;
		break;
	case SegType_ThoraxAbdomen://Thorax and abdomen
		mass = w * 0.355;
		break;
	case SegType_HeadNeck://Head and neck
		mass = w * 0.081;
		break;
	default:
		break;
	}
	//设定肢段长度length(cm)
	/*length = sqrt(pow((Jdistal.jointPosition.x() - Jproximal.jointPosition.x()), 2) + pow((Jdistal.jointPosition.y() - Jproximal.jointPosition.y()), 2)
		+ pow((Jdistal.jointPosition.z() - Jproximal.jointPosition.z()), 2))*100.0;*/
	length = (Jdistal.jointPosition - Jproximal.jointPosition).norm()*100;
}

OBJ::Segment::Segment(const Joint & jp, const Joint & jd, const SegType & st)
{
	Jproximal = jp;
	Jdistal = jd;

	SegmentType = st;
	//设定trackingState
	if (jp.trackingState == 2 && jd.trackingState == 2)
	{
		trackingState = TrackingState(2);
	}
	else if (jp.trackingState == 0 && jd.trackingState == 0)
	{
		trackingState = TrackingState(0);
	}
	else
	{
		trackingState = TrackingState(1);
	}
	//设定肢段长度length(cm)
	/*length = sqrt(pow((Jdistal.jointPosition.x() - Jproximal.jointPosition.x()), 2) + pow((Jdistal.jointPosition.y() - Jproximal.jointPosition.y()), 2)
		+ pow((Jdistal.jointPosition.z() - Jproximal.jointPosition.z()), 2))*100.0;*/
	length = (Jdistal.jointPosition - Jproximal.jointPosition).norm() * 100;
	//设定COM
	Eigen::Vector3f coordP{ Jproximal.jointPosition };
	Eigen::Vector3f coordD{ Jdistal.jointPosition };
	switch (SegmentType)
	{
	case SegType_LeftThigh://thigh
		segCOM = coordP + (coordD - coordP)* 0.433;
		break;
	case SegType_RightThigh://thigh
		segCOM = coordP + (coordD - coordP) * 0.433;
		break;
	case SegType_LeftShank://shank
		segCOM = coordP + (coordD - coordP) * 0.433;
		break;
	case SegType_RightShank://shank
		segCOM = coordP + (coordD - coordP) * 0.433;
		break;
	case SegType_LeftFoot://foot
		segCOM = coordP + (coordD - coordP) * 0.5;
		break;
	case SegType_RightFoot://foot
		segCOM = coordP + (coordD - coordP) * 0.5;
		break;
	case SegType_LeftUpperArm://Upper arm
		segCOM = coordP + (coordD - coordP) * 0.436;
		break;
	case SegType_RightUpperArm://Upper arm
		segCOM = coordP + (coordD - coordP) * 0.436;
		break;
	case SegType_LeftForArmHand://forearm and hand
		segCOM = coordP + (coordD - coordP) * 0.682;
		break;
	case SegType_RightForArmHand://forearm and hand
		segCOM = coordP + (coordD - coordP) * 0.682;
		break;
	case SegType_Pelvis://Pelvis
		segCOM = coordP + (coordD - coordP) * 0.105;
		break;
	case SegType_ThoraxAbdomen://Thorax and abdomen
		segCOM = coordP + (coordD - coordP) * 0.63;
		break;
	case SegType_HeadNeck://Head and neck
		segCOM = coordP + (coordD - coordP) * 1.0;
		break;
	default:
		break;
	}

	rCOM2D = coordD - segCOM;
	rCOM2P = coordP - segCOM;

}

void Segment::calSegCOM()
{
	
	Eigen::Vector3f coordP{ Jproximal.jointPosition };
	Eigen::Vector3f coordD{ Jdistal.jointPosition };
	switch (SegmentType)
	{
	case SegType_LeftThigh://thigh
		segCOM = coordP + (coordD - coordP)* 0.433;
		break;
	case SegType_RightThigh://thigh
		segCOM = coordP + (coordD - coordP) * 0.433;
		break;
	case SegType_LeftShank://shank
		segCOM = coordP + (coordD - coordP) * 0.433;
		break;
	case SegType_RightShank://shank
		segCOM = coordP + (coordD - coordP) * 0.433;
		break;
	case SegType_LeftFoot://foot
		segCOM = coordP + (coordD - coordP) * 0.5;
		break;
	case SegType_RightFoot://foot
		segCOM = coordP + (coordD - coordP) * 0.5;
		break;
	case SegType_LeftUpperArm://Upper arm
		segCOM = coordP + (coordD - coordP) * 0.436;
		break;
	case SegType_RightUpperArm://Upper arm
		segCOM = coordP + (coordD - coordP) * 0.436;
		break;
	case SegType_LeftForArmHand://forearm and hand
		segCOM = coordP + (coordD - coordP) * 0.682;
		break;
	case SegType_RightForArmHand://forearm and hand
		segCOM = coordP + (coordD - coordP) * 0.682;
		break;
	case SegType_Pelvis://Pelvis
		segCOM = coordP + (coordD - coordP) * 0.105;
		break;
	case SegType_ThoraxAbdomen://Thorax and abdomen
		segCOM = coordP + (coordD - coordP) * 0.63;
		break;
	case SegType_HeadNeck://Head and neck
		segCOM = coordP + (coordD - coordP) * 1.0;
		break;
	default:
		break;
	}
}

void OBJ::Segment::calSegL()
{
	length = sqrt(pow((Jdistal.jointPosition.x() - Jproximal.jointPosition.x()), 2) + pow((Jdistal.jointPosition.y() - Jproximal.jointPosition.y()), 2)
		+ pow((Jdistal.jointPosition.z() - Jproximal.jointPosition.z()), 2));
}

void OBJ::Segment::calSegMass(const SubjInfo & subjinfo)
{
	//设定肢段质量m(kg)
	float w = subjinfo.weight;
	switch (SegmentType)
	{
	case SegType_LeftThigh://thigh
		mass = w * 0.1;
		break;
	case SegType_RightThigh://thigh
		mass = w * 0.1;
		break;
	case SegType_LeftShank://shank
		mass = w * 0.0465;
		break;
	case  SegType_RightShank://shank
		mass = w * 0.0465;
		break;
	case SegType_LeftFoot://foot
		mass = w * 0.0145;
		break;
	case SegType_RightFoot://foot
		mass = w * 0.0145;
		break;
	case SegType_LeftUpperArm://Upper arm
		mass = w * 0.028;
		break;
	case SegType_RightUpperArm://Upper arm
		mass = w * 0.028;
		break;
	case SegType_LeftForArmHand://forearm and hand
		mass = w * 0.022;
		break;
	case SegType_RightForArmHand://forearm and hand
		mass = w * 0.022;
		break;
	case SegType_Pelvis://Pelvis
		mass = w * 0.142;
		break;
	case SegType_ThoraxAbdomen://Thorax and abdomen
		mass = w * 0.355;
		break;
	case SegType_HeadNeck://Head and neck
		mass = w * 0.081;
		break;
	default:
		break;
	}
}


//Obj
Obj::Obj()
{
}

Obj::~Obj()
{
}

Obj::Obj(const std::vector<Joints>& frames_j)
{
	m_framesJ = frames_j;
	//build segments

}

void OBJ::Obj::calTraject_Ankle()
{
	try
	{
		//從Ankle Fit 得到的圓方程轉換到0-360的 z ，y 坐標 (z 是橫軸、深度 /y 是縱軸、高度
		Trajectory_Ankle.reserve(361);
		
		Trajectory_Hip.reserve(361);
		for (int i = 0; i < 361; i++)
		{
			double valueZ = ankleCircle.radius * cos(double(270 - i) / 180.0*PI) + ankleCircle.centerX;
			double valueY = ankleCircle.radius * sin(double(270 - i) / 180.0*PI) + ankleCircle.centerY;

			Trajectory_Ankle.push_back(Eigen::Vector3d(0.0, valueY, valueZ));
		}
	}
	catch (const std::exception& e)
	{
		qDebug() << e.what() << endl;
	}
	

	
}

void OBJ::Obj::calTraject_Knee()
{
	std::vector<double> vecX;
	std::vector<double> vecY;
	vecX.reserve(m_nFrames);
	vecY.reserve(m_nFrames);

	double maxZ = m_framesJ[0][JointType_KneeLeft].jointPosition.z();
	double minZ = m_framesJ[0][JointType_KneeLeft].jointPosition.z();
	int maxZframe = 0;
	int minZframe = 0;
	for (int i = 0; i < m_framesJ.size(); i++)
	{
		double valueZ = m_framesJ[i][JointType_KneeLeft].jointPosition.z();
		double valueY = m_framesJ[i][JointType_KneeLeft].jointPosition.y();
		vecX.push_back(valueZ);
		vecY.push_back(valueY);
		//取得軌跡兩端的端點
		if (valueZ > maxZ){
			maxZ = valueZ;
			maxZframe = i;
		}
		if (valueZ < minZ) {
			minZ = valueZ;
			minZframe = i;
		}
	}
	std::vector<double> polyP = myMath::polyfit(vecX, vecY, 5);

	std::vector<double> polyX;
	double left = m_framesJ[minZframe][JointType_KneeLeft].jointPosition.z()-0.01;
	double right = m_framesJ[maxZframe][JointType_KneeLeft].jointPosition.z();
	double tmp = left;
	int n = 0;
	while (tmp < right )
	{
		polyX.push_back(tmp);
		n++;
		tmp += ((right - left)/180);
	}
	Trajectory_Knee.clear();
	Trajectory_Knee.reserve(polyX.size()*2);
	std::vector <Eigen::Vector3d> halfTraj_b;
	halfTraj_b.reserve(polyX.size());
	std::vector<double> polyRes = myMath::polyRes(polyP, polyX);
	for (int i = 0; i < polyX.size(); i++)
	{
		halfTraj_b.push_back(Eigen::Vector3d( 0.0, polyRes[i], polyX[i])); //後半的軌跡
	}
	std::reverse(halfTraj_b.begin(), halfTraj_b.end()); //halfTraj_f
	Trajectory_Knee.insert(Trajectory_Knee.end(), halfTraj_b.begin(), halfTraj_b.end());
	std::reverse(halfTraj_b.begin(), halfTraj_b.end()); //halftraj_b
	Trajectory_Knee.insert(Trajectory_Knee.end(), halfTraj_b.begin() + 1, halfTraj_b.end());
	qDebug() << "Trajectory_Knee.size: " <<Trajectory_Knee.size() << endl;
}

void OBJ::Obj::calTraject_Hip()
{
	////取所有數據的平均點
	Eigen::Vector3d aveHip{0.0,0.0,0.0};
	for (auto joints:m_framesJ)
	{
		aveHip = aveHip + 
			Eigen::Vector3d(double(joints[JointType_HipLeft].jointPosition.x()),
				double(joints[JointType_HipLeft].jointPosition.y()), 
				double(joints[JointType_HipLeft].jointPosition.z()));
	}
	aveHip = aveHip / double(m_framesJ.size());
	Trajectory_Hip.clear();
	Trajectory_Hip.reserve(361);
	for (int i = 0; i < 361; i++)
	{
		Trajectory_Hip.push_back(aveHip);
	}
	qDebug() << "Hip.y"<<aveHip.y()<<"Hip.z"<< aveHip.z() << endl;
}

void OBJ::Obj::buildModelJframes()
{

}

CycleAngles OBJ::Obj::calJointAngle(coordSys coord_pelvis, Eigen::Vector3d hip, Eigen::Vector3d knee, Eigen::Vector3d ankle)
{
	//Knee angle
	Eigen::Vector3d vector1(hip-knee);
	Eigen::Vector3d vector2(ankle - knee);

	double normv1 = vector1.norm();
	double normv2 = vector2.norm();
	double costheta_Knee = vector1.dot(vector2) / (normv1*normv2);
	double angle_Knee = RadianToDegree(acos(costheta_Knee));

	//hip angle
	//Eigen::Vector3f pD_l = Pg2l(knee, coord_pelvis);
	//Eigen::Vector3f pP_l = Pg2l(seg.Jproximal, coord_pelvis);
	/*Eigen::Vector3d vec1 = knee - hip;
	Eigen::Vector3d vec2 = coord_pelvis.axis_z;

	double costheta_hip = (vec1.dot(vec2)) / (vec1.norm()*vec2.norm());
	double angle_Hip = RadianToDegree(acos(costheta_hip));*/
	
	

	return CycleAngles{ 0.0 , angle_Knee,0.0 };
}

double OBJ::Obj::calKneeAngle(Eigen::Vector3d hip, Eigen::Vector3d knee, Eigen::Vector3d ankle)
{
	//Knee angle
	Eigen::Vector3d vector1(hip - knee);
	Eigen::Vector3d vector2(ankle - knee);

	double normv1 = vector1.norm();
	double normv2 = vector2.norm();
	double costheta_Knee = vector1.dot(vector2) / (normv1*normv2);
	double angle_Knee = RadianToDegree(acos(costheta_Knee));

	return angle_Knee;
}

void OBJ::Obj::calCycleAngles()
{
	cycleAngleframes.reserve(361);
	for (int i = 0; i < 361; i++)
	{
		CycleAngles angles{ 0.0,180.0 - calKneeAngle(Trajectory_Hip[i], Trajectory_Knee[i], Trajectory_Ankle[i]),0.0 };
		cycleAngleframes.push_back(angles);
	}
	
}
 
void OBJ::Obj::setJoints(const std::vector<Joints> &frames_j)
{
	m_nFrames = frames_j.size();
	m_framesJ.clear();
	m_framesJ.reserve(m_nFrames);
	m_framesJ = frames_j;
}

void OBJ::Obj::setJoints_filted(const std::vector<Joints>& frames_J_filted)
{
	m_framesJ_filted = frames_J_filted;
}

void OBJ::Obj::setSegments(const std::vector<Segs>& frames_S)
{
	m_framesS = frames_S;
}

void OBJ::Obj::setSegments_filted(const std::vector<Segs>& frames_S)
{
	m_framesS_filted = frames_S;
}

void OBJ::Obj::setSegments_opted(const std::vector<Segs>& frames_S_opted)
{
	m_framesS_opted = frames_S_opted;
}

void OBJ::Obj::setJointAngles(std::vector<Angles>& frames_JA)
{
	m_JointAngles = frames_JA;
}

void OBJ::Obj::setJointAngles_opted(std::vector<Angles>& frames_JA)
{
	m_JointAngles_opted = frames_JA;
}



void OBJ::Obj::setJoints_opted(const std::vector<Joints>& frames_J_opted)
{
	m_framesJ_opted = frames_J_opted;
}


std::vector<Segs> Obj::buildSegments(const std::vector<Joints> &frames_J)
{
	std::vector<Segs> frames_Seg;
	frames_Seg.clear();
	frames_Seg.reserve(frames_J.size());
	Segs segments;
	for (auto joints : frames_J)
	{
		
		segments[SegType_LeftThigh] = Segment{ joints[JointType_HipLeft] ,joints[JointType_KneeLeft],SegType_LeftThigh };
		segments[SegType_RightThigh] = Segment{ joints[JointType_HipRight] ,joints[JointType_KneeRight],SegType_RightThigh };
		segments[SegType_LeftShank] = Segment{ joints[JointType_KneeLeft] ,joints[JointType_AnkleLeft],SegType_LeftShank };
		segments[SegType_RightShank] = Segment{ joints[JointType_KneeRight] ,joints[JointType_AnkleRight],SegType_RightShank };
		segments[SegType_LeftFoot] = Segment{ joints[JointType_AnkleLeft] ,joints[JointType_FootLeft],SegType_LeftFoot };
		segments[SegType_RightFoot] = Segment{ joints[JointType_AnkleRight] ,joints[JointType_FootRight],SegType_RightFoot };

		segments[SegType_LeftUpperArm] = Segment{ joints[JointType_ShoulderLeft] ,joints[JointType_ElbowLeft],SegType_LeftUpperArm };
		segments[SegType_RightUpperArm] = Segment{ joints[JointType_ShoulderRight] ,joints[JointType_ElbowRight],SegType_RightUpperArm };
		segments[SegType_LeftForArmHand] = Segment{ joints[JointType_ElbowLeft] ,joints[JointType_WristLeft],SegType_LeftForArmHand };
		segments[SegType_RightForArmHand] = Segment{ joints[JointType_ElbowRight] ,joints[JointType_WristRight],SegType_RightForArmHand };

		segments[SegType_Pelvis] = cSegment{ joints[JointType_SpineMid] ,joints[JointType_SpineBase],joints[JointType_HipLeft],joints[JointType_HipRight],SegType_Pelvis };
		segments[SegType_ThoraxAbdomen] = cSegment{ joints[JointType_SpineMid] ,joints[JointType_SpineShoulder],joints[JointType_ShoulderLeft],joints[JointType_ShoulderRight],SegType_ThoraxAbdomen };
		segments[SegType_HeadNeck] = Segment{ joints[JointType_SpineShoulder] ,joints[JointType_Head],SegType_HeadNeck };

		frames_Seg.push_back(segments);
	}
	std::cout << "get Seged" << std::endl;

	return frames_Seg;
}
Segs OBJ::Obj::buildSegments(const Joints& joints)
{
	Segs segments;

	segments[SegType_LeftThigh] = Segment{ joints[JointType_HipLeft] ,joints[JointType_KneeLeft],SegType_LeftThigh };
	segments[SegType_RightThigh] = Segment{ joints[JointType_HipRight] ,joints[JointType_KneeRight],SegType_RightThigh };
	segments[SegType_LeftShank] = Segment{ joints[JointType_KneeLeft] ,joints[JointType_AnkleLeft],SegType_LeftShank };
	segments[SegType_RightShank] = Segment{ joints[JointType_KneeRight] ,joints[JointType_AnkleRight],SegType_RightShank };
	segments[SegType_LeftFoot] = Segment{ joints[JointType_AnkleLeft] ,joints[JointType_FootLeft],SegType_LeftFoot };
	segments[SegType_RightFoot] = Segment{ joints[JointType_AnkleRight] ,joints[JointType_FootRight],SegType_RightFoot };

	segments[SegType_LeftUpperArm] = Segment{ joints[JointType_ShoulderLeft] ,joints[JointType_ElbowLeft],SegType_LeftUpperArm };
	segments[SegType_RightUpperArm] = Segment{ joints[JointType_ShoulderRight] ,joints[JointType_ElbowRight],SegType_RightUpperArm };
	segments[SegType_LeftForArmHand] = Segment{ joints[JointType_ElbowLeft] ,joints[JointType_WristLeft],SegType_LeftForArmHand };
	segments[SegType_RightForArmHand] = Segment{ joints[JointType_ElbowRight] ,joints[JointType_WristRight],SegType_RightForArmHand };

	segments[SegType_Pelvis] = cSegment{ joints[JointType_SpineMid] ,joints[JointType_SpineBase],joints[JointType_HipLeft],joints[JointType_HipRight],SegType_Pelvis };
	segments[SegType_ThoraxAbdomen] = cSegment{ joints[JointType_SpineShoulder] ,joints[JointType_SpineMid],joints[JointType_ShoulderLeft],joints[JointType_ShoulderRight],SegType_ThoraxAbdomen };
	segments[SegType_HeadNeck] = Segment{ joints[JointType_Head] ,joints[JointType_SpineShoulder],SegType_HeadNeck };


	return segments;
}


void OBJ::Obj::setFilePath(QString path)
{
	path_ford = path;
	path_subjInfo = path +"SubjInfo.csv";
	path_cali = path + "cali_Position.csv";
}

void OBJ::Obj::addtrail(QString trailname)
{
	trailName = trailname;
	path_trail = path_ford + trailname + "_Position.csv";
	path_angle = path_ford + trailname + "_Angles.csv";
	path_moment = path_ford + trailname + "_Moment.csv";
	path_ViconAngle_HipL = path_ford + trailname + "_ViconAngle_HipL.csv";
	path_ViconAngle_KneeL = path_ford + trailname + "_ViconAngle_KneeL.csv";
	path_ViconAngle_AnkleL = path_ford + trailname + "_ViconAngle_AnkleL.csv";
}


float OBJ::Obj::calJointAngle(const Segment &sP,const Segment &sD)
{
	


	// If we can't find either of these joints, exit
	if ((sP.trackingState == TrackingState_NotTracked) || (sD.trackingState == TrackingState_NotTracked) )
	{
		return 0.0;
	}

	std::array<float, 3> vector1
	{ sP.Jproximal.jointPosition.x() - sP.Jdistal.jointPosition.x() , sP.Jproximal.jointPosition.y() - sP.Jdistal.jointPosition.y() , sP.Jproximal.jointPosition.z() - sP.Jdistal.jointPosition.z() };
	std::array<float, 3> vector2
	{ sD.Jdistal.jointPosition.x() - sD.Jproximal.jointPosition.x() , sD.Jdistal.jointPosition.y() - sD.Jproximal.jointPosition.y() , sD.Jdistal.jointPosition.z() - sD.Jproximal.jointPosition.z() };



	float normv1 = norm(vector1);
	float normv2 = norm(vector2);
	float costheta = dot(vector1, vector2) / (normv1*normv2);
	float theta = RadianToDegree(acos(costheta));

	return theta;

}

float OBJ::Obj::calJointAngle(const Segment & seg, const coordSys & coord)
{
	Eigen::Vector3f pD_l = Pg2l(seg.Jdistal, coord);
	Eigen::Vector3f pP_l = Pg2l(seg.Jproximal, coord);
	Eigen::Vector3f vec1 = pD_l - pP_l;
	Eigen::Vector3f vec2 = coord.axis_z;

	float costheta = (vec1.dot(vec2)) / (vec1.norm()*vec2.norm());
	float theta = RadianToDegree(acos(costheta));
	return theta;
}

Angles OBJ::Obj::calAllJointAngles(const Segs &segments)
{
	Angles ja;
	ja[JAngleType_ElbowL].Angle_x = calJointAngle(segments[SegType_LeftUpperArm], segments[SegType_LeftForArmHand]);
	ja[JAngleType_ElbowR].Angle_x = calJointAngle(segments[SegType_RightUpperArm], segments[SegType_RightForArmHand]);
	ja[JAngleType_KneeL].Angle_x  = 180.0 - calJointAngle(segments[SegType_LeftThigh], segments[SegType_LeftShank]);
	ja[JAngleType_KneeR].Angle_x  = 180.0 - calJointAngle(segments[SegType_RightThigh], segments[SegType_RightShank]);
	ja[JAngleType_Spine].Angle_x = calJointAngle(segments[SegType_ThoraxAbdomen], segments[SegType_Pelvis]);
	ja[JAngleType_ShouderL].Angle_x = calJointAngle(segments[SegType_ThoraxAbdomen], segments[SegType_LeftUpperArm]);
	ja[JAngleType_ShouderR].Angle_x = calJointAngle(segments[SegType_ThoraxAbdomen], segments[SegType_RightUpperArm]);
	ja[JAngleType_HipL].Angle_x = calJointAngle(segments[SegType_LeftThigh], segments[SegType_Pelvis].lcoord);
	ja[JAngleType_HipR].Angle_x = calJointAngle(segments[SegType_RightThigh], segments[SegType_Pelvis].lcoord);
	ja[JAngleType_AnkleL].Angle_x = -110.0 + calJointAngle(segments[SegType_LeftFoot], segments[SegType_LeftShank]);
	ja[JAngleType_AnkleR].Angle_x = -110.0 + calJointAngle(segments[SegType_RightFoot], segments[SegType_RightShank]);
	return ja;
}

std::vector<Angles> OBJ::Obj::calAllJointAngles(const std::vector<Segs>& frames_S)
{
	std::vector<Angles> op;
	op.clear();
	op.reserve(frames_S.size());

	for (auto segments:frames_S)
	{
		op.push_back(calAllJointAngles(segments));
	}
	return op;
}

void OBJ::Obj::calJointForce(Segment & seg, Eigen::Vector3f fd)
{
	seg.Fd = fd;
	Eigen::Vector3f g = Eigen::Vector3f(0.0, -9.8, 0.0);
	seg.Fp = seg.mass * seg.segCOMAcc - seg.Fd - seg.mass * g;
	
}

void OBJ::Obj::calLeftLimbJointForce(std::vector<Segs>& nframeSegs,std::vector<Eigen::Vector3f> exForces)//左下肢
{
	int nframe = 0;
	for (auto segs : nframeSegs)
	{
		calJointForce(segs[SegType_LeftFoot], exForces[nframe]);
		calJointForce(segs[SegType_LeftShank], segs[SegType_LeftFoot].Fp);
		calJointForce(segs[SegType_LeftThigh], segs[SegType_LeftShank].Fp);
		nframe++;
	}
}

void OBJ::Obj::calCOMAcc(std::vector<Segs> & nframeSegs)
{

	for (int nSeg = 0; nSeg < nframeSegs[0].size(); nSeg++)
	{
		std::vector<double> nfCOM_x(nframeSegs.size());
		std::vector<double> nfCOM_y(nframeSegs.size());
		std::vector<double> nfCOM_z(nframeSegs.size());
		for (int nframe = 0; nframe < nframeSegs.size(); nframe++)
		{
			nfCOM_x[nframe] = double(nframeSegs[nframe][nSeg].segCOM.x());
			nfCOM_y[nframe] = double(nframeSegs[nframe][nSeg].segCOM.y());
			nfCOM_z[nframe] = double(nframeSegs[nframe][nSeg].segCOM.z());
		}
		//ployfit
		std::vector<double> xAxis(nframeSegs.size());
		for (int i = 0; i < nframeSegs.size(); i++)
		{
			xAxis[i] = double(i);
		}
		std::vector<double> P_x	= myMath::polyfit(xAxis, nfCOM_x, 8);
		std::vector<double> P_y = myMath::polyfit(xAxis, nfCOM_y, 8);
		std::vector<double> P_z = myMath::polyfit(xAxis, nfCOM_z, 8);


		std::vector<double> dP_x = myMath::polyDer(P_x, 2); //對COM位置做兩次微分，得加速度
		std::vector<double> dP_y = myMath::polyDer(P_y, 2);
		std::vector<double> dP_z = myMath::polyDer(P_z, 2);

		//把ployfit得到的多項式還原到數據點
		std::vector<double> nfCOMacc_x = myMath::polyRes(dP_x, xAxis);
		std::vector<double> nfCOMacc_y = myMath::polyRes(dP_y, xAxis);
		std::vector<double> nfCOMacc_z = myMath::polyRes(dP_z, xAxis);
		//把COM加速度塞回Segs中
		for (int nframe = 0; nframe < nframeSegs.size(); nframe++)
		{
			nframeSegs[nframe][nSeg].segCOMAcc.x() = nfCOMacc_x[nframe];
			nframeSegs[nframe][nSeg].segCOMAcc.y() = nfCOMacc_y[nframe];
			nframeSegs[nframe][nSeg].segCOMAcc.z() = nfCOMacc_z[nframe];
		}
	}
	qDebug() << "segCOMacc seted" << endl;
}



coordSys OBJ::Obj::calCoordupTunkR(const Joints &joints)
{
	Eigen::Vector3f pShoulderR = joints[JointType_ShoulderRight].jointPosition;
	Eigen::Vector3f pShoulderL = joints[JointType_ShoulderLeft].jointPosition;
	Eigen::Vector3f pSpineMid = joints[JointType_SpineMid].jointPosition;
	
	coordSys UpTkcoord;
	UpTkcoord.axis_x = (pShoulderR - pShoulderL) / (pShoulderR - pShoulderL).norm();
	UpTkcoord.axis_y = UpTkcoord.axis_x.cross(pShoulderR - pSpineMid) / UpTkcoord.axis_x.cross(pShoulderR - pSpineMid).norm();
	UpTkcoord.axis_z = UpTkcoord.axis_x.cross(UpTkcoord.axis_y);
	Eigen::Matrix3f rot;
	Eigen::Vector3f vec;
	rot << UpTkcoord.axis_x, UpTkcoord.axis_y, UpTkcoord.axis_z;
	vec << pShoulderR;
	UpTkcoord.R = rot;
	UpTkcoord.V = vec;

	return UpTkcoord;
}

coordSys OBJ::Obj::calCoordPelvisR(const Joints & joints)
{
	Eigen::Vector3f pHipR = joints[JointType_HipRight].jointPosition;
	Eigen::Vector3f pHipL = joints[JointType_HipLeft].jointPosition;
	Eigen::Vector3f pSpineMid = joints[JointType_SpineMid].jointPosition;

	coordSys PelvisCoord;
	PelvisCoord.axis_x = (pHipR - pHipL) / (pHipR - pHipL).norm();
	PelvisCoord.axis_y = PelvisCoord.axis_x.cross(pHipR - pSpineMid) / PelvisCoord.axis_x.cross(pHipR - pSpineMid).norm();
	PelvisCoord.axis_z = PelvisCoord.axis_x.cross(PelvisCoord.axis_y);
	Eigen::Matrix3f rot;
	Eigen::Vector3f vec;
	rot << PelvisCoord.axis_x, PelvisCoord.axis_y, PelvisCoord.axis_z;
	vec << pHipR;
	PelvisCoord.R = rot;
	PelvisCoord.V = vec;

	return PelvisCoord;
}

Eigen::Vector3f OBJ::Obj::Pg2l(const Joint & Pg, const coordSys & lcoord)
{
	Eigen::Vector3f pointG = Pg.jointPosition;
	Eigen::Vector3f pointL = (lcoord.R).transpose()*(pointG - lcoord.V);
	return pointL;
}

Eigen::Vector3f OBJ::Obj::Pl2g(Eigen::Vector3f Pl, const coordSys & lcoord)
{
	Eigen::Vector3f pointG = lcoord.R*Pl + lcoord.V;
	return pointG;
}

void OBJ::Obj::cali()
{
	if (cali_JointFrames.empty())
	{
		qDebug() << "Error: no cali_JointFrames" << endl;
	}
	else
	{
		#pragma region 计算初始关节角度

		cali_SegFrames = buildSegments(cali_JointFrames);
		std::vector<Angles> allJointAngles;
		Angles ja;
		for (auto segments : cali_SegFrames)
		{
			ja = calAllJointAngles(segments);
			allJointAngles.push_back(ja);
		}
		Angles sumJA;
		for (auto jointAngles : allJointAngles)
		{
			for (int i = 0; i < JAngleType_Count; i++)
			{
				sumJA[i] = sumJA[i] + jointAngles[i];
			}
		}
		for (int i = 0; i < JAngleType_Count; i++)
		{
			sumJA[i] = sumJA[i] / allJointAngles.size();
		}
		m_caliInfo.caliJA = sumJA;

		#pragma endregion

		#pragma region 计算身高
		float sumH{0.0};
		for (auto joints:cali_JointFrames)
		{
			sumH = sumH + (joints[JointType_Head].jointPosition.y() - joints[JointType_FootLeft].jointPosition.y());
		}
		sumH = sumH / cali_JointFrames.size();

		m_caliInfo.caliH = sumH;
		#pragma endregion

		#pragma region 计算肢段长度
		std::array<float, SegType_Count> sumSegL;
		sumSegL.fill(0.0);
		for (auto segs:cali_SegFrames)
		{
			for (int i = 0; i < SegType_Count; ++i)
			{
				segs[i].calSegL();
				sumSegL[i] += segs[i].length;
			}
		}
		
		for (int i = 0; i < SegType_Count; ++i)
		{
			sumSegL[i] = sumSegL[i] / cali_SegFrames.size();
		}
		m_caliInfo.SegL = sumSegL;
		#pragma endregion


	}
	
}

void OBJ::Obj::calTrailJointAngle()
{
	m_JointAngles = calAllJointAngles(m_framesS);
}



void OBJ::Obj::calJointAngles_filted()
{
	if (!m_framesS_filted.empty())
	{
		m_JointAngles_filted = calAllJointAngles(m_framesS_filted);
	}
	else
	{
		qDebug() << "no filted Seg frames" << endl;
	}
	
}

void OBJ::Obj::calJointAngles_opted()
{
	if (!m_framesS_filted.empty())
	{
		m_JointAngles_opted = calAllJointAngles(m_framesS_opted);
	}
	else
	{
		qDebug() << "no opted Seg frames" << endl;
	}
}

//计算脊椎关节受力和力矩
void OBJ::Obj::calcSpinebaseFMwithBag()
{
	m_fp_g.clear();
	m_fp_g.reserve(m_nFrames);
	m_moments.clear();
	m_moments.reserve(m_nFrames);
	for (int i = 0; i < m_nFrames; i++)
	{
		float F_spinebase = m_subjInfo.weight * (0.081 + 0.142 + 0.355 + 0.028 * 2 + 0.022 * 2)*9.8 + m_subjInfo.bagWeight * 9.8;
		OBJ::coordSys coordtrunk;
		coordtrunk =calCoordupTunkR(m_framesJ[i]);
		Eigen::Vector3f thigh_M(0, -0.1*9.8 *m_subjInfo.weight, 0), shank_M(0, -0.0465*9.8 *m_subjInfo.weight, 0), foot_M(0, -0.0145*9.8 *m_subjInfo.weight, 0),
			upperArm_M(0, -0.028 *9.8 *m_subjInfo.weight, 0), fArmhand_M(0, -0.022*9.8 *m_subjInfo.weight, 0), Pelvis_M(0, -0.142*9.8 *m_subjInfo.weight, 0), ThoraxAbdomen_M(0, -0.355*9.8 *m_subjInfo.weight, 0),
			Headneck_M(0, -0.081*9.8 *m_subjInfo.weight, 0);

		// 计算bag位置
		Eigen::Vector3f Pbag{ m_subjInfo.bagPosi };//從subjinfo输入
		Eigen::Vector3f Pbaglocal = m_framesJ[i][JointType_SpineMid].Pg2l(coordtrunk) + Pbag;
		Eigen::Vector3f PbagG = Pl2g(Pbaglocal, coordtrunk);
		

		Eigen::Vector3f vforce(0, -m_subjInfo.bagWeight * 9.8,0);//bagweight:KG
		Eigen::Vector3f spinebaseXYZ = m_framesJ[i][JointType_SpineBase].jointPosition;
		Eigen::Vector3f M_spinebase = ((m_framesS[i][SegType_LeftUpperArm].segCOM - spinebaseXYZ).cross(upperArm_M) 
			+ (m_framesS[i][SegType_RightUpperArm].segCOM - spinebaseXYZ).cross(upperArm_M)
			+ (m_framesS[i][SegType_LeftForArmHand].segCOM - spinebaseXYZ).cross(fArmhand_M) 
			+ (m_framesS[i][SegType_RightForArmHand].segCOM - spinebaseXYZ).cross(fArmhand_M)
			+ (m_framesS[i][SegType_ThoraxAbdomen].segCOM - spinebaseXYZ).cross(ThoraxAbdomen_M)
			+ (m_framesS[i][SegType_HeadNeck].segCOM - spinebaseXYZ).cross(Headneck_M)) 
			+ (PbagG - spinebaseXYZ).cross(vforce);
		m_fp_g.push_back(PbagG);
		m_moments.push_back(M_spinebase);
	}
}

SubjInfo OBJ::Obj::getSubjInfo()
{
	if (m_subjInfo.subjname =="null")
	{
		qDebug() << "Error: no sujInfo stored" << endl;
	}
	return m_subjInfo;
}

CaliInfo OBJ::Obj::getCaliInfo() const
{
	return m_caliInfo;
}

std::vector<Joints> OBJ::Obj::getJoints() const
{
	return m_framesJ;
}

std::vector<Joints> OBJ::Obj::getJoints_filted() const
{
	return m_framesJ_filted;
}

std::vector<Joints> OBJ::Obj::getJoints_opted() const
{
	return m_framesJ_opted;
}

std::vector<Segs> OBJ::Obj::getSegments() const
{
	return m_framesS;
}

std::vector<Segs> OBJ::Obj::getSegments_filted() const
{
	return m_framesS_filted;
}

std::vector<Segs> OBJ::Obj::getSegments_opted() const
{
	return m_framesS_opted;
}

std::vector<Angles> OBJ::Obj::getJointAngles() const
{
	return m_JointAngles;
}

std::vector<Angles> OBJ::Obj::getJointAngles_filted() const
{
	return m_JointAngles_filted;
}

std::vector<Angles> OBJ::Obj::getJointAngles_opted() const
{
	return m_JointAngles_opted;
}

std::vector<Eigen::Vector3f> OBJ::Obj::getMoments()
{
	return m_moments;
}

std::array<Eigen::Vector3f, 13> OBJ::Obj::getCOMs(const Segs & segs)
{
	std::array<Eigen::Vector3f, 13> coms;
	for (int i = 0; i < 13; i++)
	{
		coms[i] = segs[i].segCOM;
	}
	return coms;
}

int OBJ::Obj::getFrameNumber()const
{
	return m_nFrames;
}

std::vector<Eigen::Vector3f> OBJ::Obj::getForcePosi()
{
	return m_fp_g;
}

void OBJ::Obj::setSubjInfo(SubjInfo & subjinfo)
{
	m_subjInfo = subjinfo;
}

SubjInfo::SubjInfo()
{
}

SubjInfo::~SubjInfo()
{
}

float dot(std::array<float, 3> v1, std::array<float, 3> v2)
{
	return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

std::array<float, 3> cross(std::array<float, 3> A, std::array<float, 3> B)
{
	std::array<float, 3> C{ A[1] * B[2] - A[2] * B[1] ,-A[0] * B[2] + A[2] * B[0], A[0] * B[1] - A[1] * B[0] };
	return C;
}

float norm(std::array<float, 3> v)
{
	return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

float RadianToDegree(float angle)
{
	return angle * (180.0 / PI);
}

OBJ::cSegment::cSegment(const Joint & jp, const Joint & jd, const Joint & jl, const Joint & jr, SegType st)
{
	Jdistal = jd;
	Jproximal = jp;
	Jleft = jl;
	Jright = jr;

	SegmentType = st;

	if (jp.trackingState == 2 && jd.trackingState == 2 && jl.trackingState == 2 && jr.trackingState == 2)
	{
		trackingState = TrackingState(2);
	}
	else if (jp.trackingState == 0 || jd.trackingState == 0 || jl.trackingState == 0 || jr.trackingState == 0)
	{
		trackingState = TrackingState(0);
	}
	else
	{
		trackingState = TrackingState(1);
	}

	calLocalCoord();
}

void OBJ::cSegment::calSegL()
{
	std::array<float, 3> left_local = Jleft.subtract(Jproximal);
	std::array<float, 3> right_local = Jright.subtract(Jproximal);
	for (auto i : left_local)
	{
		i = i * 100.0;
	}
	for (auto i : right_local)
	{
		i = i * 100.0;
	}
	length = norm(cross(left_local, right_local)) / 2.0;
}

void OBJ::cSegment::calLocalCoord()
{
	Eigen::Vector3f pShoulderR = Jright.jointPosition;
	Eigen::Vector3f pShoulderL = Jleft.jointPosition;
	Eigen::Vector3f pSpineMid = Jproximal.jointPosition;

	coordSys localCoord;
	localCoord.axis_x = (pShoulderR - pShoulderL) / (pShoulderR - pShoulderL).norm();
	localCoord.axis_y = localCoord.axis_x.cross(pShoulderR - pSpineMid) / localCoord.axis_x.cross(pShoulderR - pSpineMid).norm();
	localCoord.axis_z = localCoord.axis_x.cross(localCoord.axis_y);
	Eigen::Matrix3f rot;
	Eigen::Vector3f vec;
	rot << localCoord.axis_x, localCoord.axis_y, localCoord.axis_z;
	vec << pShoulderR;
	localCoord.R = rot;
	localCoord.V = vec;

	lcoord = localCoord;
}

void OBJ::coordSys::print()
{
	std::cout << axis_x << std::endl;
	std::cout << axis_y << std::endl;
	std::cout << axis_z << std::endl;
	std::cout << V << std::endl;
}
