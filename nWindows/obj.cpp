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
		segcom = coordP + (coordD - coordP)* 0.433;
		break;
	case SegType_RightThigh://thigh
		segcom = coordP + (coordD - coordP) * 0.433;
		break;
	case SegType_LeftShank://shank
		segcom = coordP + (coordD - coordP) * 0.433;
		break;
	case SegType_RightShank://shank
		segcom = coordP + (coordD - coordP) * 0.433;
		break;
	case SegType_LeftFoot://foot
		segcom = coordP + (coordD - coordP) * 0.5;
		break;
	case SegType_RightFoot://foot
		segcom = coordP + (coordD - coordP) * 0.5;
		break;
	case SegType_LeftUpperArm://Upper arm
		segcom = coordP + (coordD - coordP) * 0.436;
		break;
	case SegType_RightUpperArm://Upper arm
		segcom = coordP + (coordD - coordP) * 0.436;
		break;
	case SegType_LeftForArmHand://forearm and hand
		segcom = coordP + (coordD - coordP) * 0.682;
		break;
	case SegType_RightForArmHand://forearm and hand
		segcom = coordP + (coordD - coordP) * 0.682;
		break;
	case SegType_Pelvis://Pelvis
		segcom = coordP + (coordD - coordP) * 0.105;
		break;
	case SegType_ThoraxAbdomen://Thorax and abdomen
		segcom = coordP + (coordD - coordP) * 0.63;
		break;
	case SegType_HeadNeck://Head and neck
		segcom = coordP + (coordD - coordP) * 1.0;
		break;
	default:
		break;
	}
}

void Segment::calSegCOM()
{
	
	Eigen::Vector3f coordP{ Jproximal.jointPosition };
	Eigen::Vector3f coordD{ Jdistal.jointPosition };
	switch (SegmentType)
	{
	case SegType_LeftThigh://thigh
		segcom = coordP + (coordD - coordP)* 0.433;
		break;
	case SegType_RightThigh://thigh
		segcom = coordP + (coordD - coordP) * 0.433;
		break;
	case SegType_LeftShank://shank
		segcom = coordP + (coordD - coordP) * 0.433;
		break;
	case SegType_RightShank://shank
		segcom = coordP + (coordD - coordP) * 0.433;
		break;
	case SegType_LeftFoot://foot
		segcom = coordP + (coordD - coordP) * 0.5;
		break;
	case SegType_RightFoot://foot
		segcom = coordP + (coordD - coordP) * 0.5;
		break;
	case SegType_LeftUpperArm://Upper arm
		segcom = coordP + (coordD - coordP) * 0.436;
		break;
	case SegType_RightUpperArm://Upper arm
		segcom = coordP + (coordD - coordP) * 0.436;
		break;
	case SegType_LeftForArmHand://forearm and hand
		segcom = coordP + (coordD - coordP) * 0.682;
		break;
	case SegType_RightForArmHand://forearm and hand
		segcom = coordP + (coordD - coordP) * 0.682;
		break;
	case SegType_Pelvis://Pelvis
		segcom = coordP + (coordD - coordP) * 0.105;
		break;
	case SegType_ThoraxAbdomen://Thorax and abdomen
		segcom = coordP + (coordD - coordP) * 0.63;
		break;
	case SegType_HeadNeck://Head and neck
		segcom = coordP + (coordD - coordP) * 1.0;
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

void OBJ::Obj::setJointAngles(std::vector<JointAngles>& frames_JA)
{
	m_2dJointAngles = frames_JA;
}

void OBJ::Obj::setJointAngles(const std::vector<Segs> &frames_S)
{
	
}

void OBJ::Obj::setOptJoints(const std::vector<OptJoints>& frames_optJ)
{
	m_framesOptJ = frames_optJ;
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
	path_trail = path_ford + trailname + "_Position.csv";
	path_angle = path_ford + trailname + "_Angles.csv";
	path_moment = path_ford + trailname + "_Moment.csv";
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

JointAngles OBJ::Obj::calAllJointAngles(const Segs &segments)
{
	JointAngles ja;
	ja.ElbowL = calJointAngle(segments[SegType_LeftUpperArm], segments[SegType_LeftForArmHand]);
	ja.ElbowR = calJointAngle(segments[SegType_RightUpperArm], segments[SegType_RightForArmHand]);
	ja.KneeL  = calJointAngle(segments[SegType_LeftThigh], segments[SegType_LeftShank]);
	ja.KneeR  = calJointAngle(segments[SegType_RightThigh], segments[SegType_RightShank]);
	ja.Spine = calJointAngle(segments[SegType_ThoraxAbdomen], segments[SegType_Pelvis]);
	ja.ShouderL = calJointAngle(segments[SegType_ThoraxAbdomen], segments[SegType_LeftUpperArm]);
	ja.ShouderR = calJointAngle(segments[SegType_ThoraxAbdomen], segments[SegType_RightUpperArm]);
	return ja;
}

std::vector<JointAngles> OBJ::Obj::calAllJointAngles(const std::vector<Segs>& frames_S)
{
	std::vector<JointAngles> op;
	op.clear();
	op.reserve(frames_S.size());

	for (auto segments:frames_S)
	{
		op.push_back(calAllJointAngles(segments));
	}
	return op;
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
		std::vector<JointAngles> allJointAngles;
		JointAngles ja;
		for (auto segments : cali_SegFrames)
		{
			ja = calAllJointAngles(segments);
			allJointAngles.push_back(ja);
		}
		JointAngles sumJA;
		for (auto jointAngles : allJointAngles)
		{
			sumJA = sumJA + jointAngles;
		}
		sumJA = sumJA / allJointAngles.size();
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
	m_2dJointAngles = calAllJointAngles(m_framesS);
}



void OBJ::Obj::calJointAngles_filted()
{
	if (!m_framesS_filted.empty())
	{
		m_2dJointAngles_filted = calAllJointAngles(m_framesS_filted);
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
		m_2dJointAngles_opted = calAllJointAngles(m_framesS_opted);
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
		Eigen::Vector3f M_spinebase = ((m_framesS[i][SegType_LeftUpperArm].segcom - spinebaseXYZ).cross(upperArm_M) 
			+ (m_framesS[i][SegType_RightUpperArm].segcom - spinebaseXYZ).cross(upperArm_M)
			+ (m_framesS[i][SegType_LeftForArmHand].segcom - spinebaseXYZ).cross(fArmhand_M) 
			+ (m_framesS[i][SegType_RightForArmHand].segcom - spinebaseXYZ).cross(fArmhand_M)
			+ (m_framesS[i][SegType_ThoraxAbdomen].segcom - spinebaseXYZ).cross(ThoraxAbdomen_M)
			+ (m_framesS[i][SegType_HeadNeck].segcom - spinebaseXYZ).cross(Headneck_M)) 
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

std::vector<JointAngles> OBJ::Obj::getJointAngles() const
{
	return m_2dJointAngles;
}

std::vector<JointAngles> OBJ::Obj::getJointAngles_filted() const
{
	return m_2dJointAngles_filted;
}

std::vector<JointAngles> OBJ::Obj::getJointAngles_opted() const
{
	return m_2dJointAngles_opted;
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
		coms[i] = segs[i].segcom;
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

std::vector<OptJoints> OBJ::Obj::getOptJ() const
{
	return m_framesOptJ;
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
