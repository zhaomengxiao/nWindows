#include "obj.h"


using namespace OBJ;

//Joint
Joint::Joint()
{
}

Joint::~Joint()
{
}
Joint::Joint(JointType jt, float x, float y, float z, TrackingState ts)
{
	jointType = jt;
	jointPosition<< x,y,z;
	trackingState = ts;
}

void Joint::print()
{
	std::cout << jointType << "  ,  " << trackingState << "  ,  " << std::endl;
	std::cout << jointPosition << std::endl;
}

std::array<float, 3> OBJ::Joint::subtract(const OBJ::Joint & r)
{
	std::array<float, 3> res{ this->jointPosition.x() - r.jointPosition.x(), this->jointPosition.y() - r.jointPosition.y(), this->jointPosition.z() - r.jointPosition.z() };
	return res;
}

//Segment
Segment::Segment()
{
}


Segment::~Segment()
{
}

Segment::Segment(const Joint& jp,const Joint& jd, SegType st)
{
	Jproximal = jp;
	Jdistal = jd;
	
	SegmentType = st;
	
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

}

void Segment::calSegCOM(Eigen::Vector3f &segcom,const Joint &jointP,const Joint &jointD, const int &segNum)
{
	
	//Eigen::Vector3f coordP(jointP.Position.X, jointP.Position.Y, jointP.Position.Z);
	//Eigen::Vector3f coordD(jointD.Position.X, jointD.Position.Y, jointD.Position.Z);
	//switch (segNum)
	//{
	//case 0://thigh
	//	segcom = coordP + (coordD - coordP)* 0.433;
	//	break;
	//case 1://shank
	//	segcom = coordP + (coordD - coordP) * 0.433;
	//	break;
	//case 2://foot
	//	segcom = coordP + (coordD - coordP) * 0.5;
	//	break;
	//case 3://Upper arm
	//	segcom = coordP + (coordD - coordP) * 0.436;
	//	break;
	//case 4://forearm and hand
	//	segcom = coordP + (coordD - coordP) * 0.682;
	//	break;
	//case 5://Pelvis
	//	segcom = coordP + (coordD - coordP) * 0.105;
	//	break;
	//case 6://Thorax and abdomen
	//	segcom = coordP + (coordD - coordP) * 0.63;
	//	break;
	//case 7://Head and neck
	//	segcom = coordP + (coordD - coordP) * 1.0;
	//	break;
	//default:
	//	break;
	//}
}

void OBJ::Segment::calSegL()
{
	length = sqrt(pow((Jdistal.jointPosition.x() - Jproximal.jointPosition.x()), 2) + pow((Jdistal.jointPosition.y() - Jproximal.jointPosition.y()), 2)
		+ pow((Jdistal.jointPosition.z() - Jproximal.jointPosition.z()), 2))*100.0;
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

void OBJ::Obj::setSegments(const std::vector<Segs>& frames_S)
{
	m_framesS = frames_S;
}

void OBJ::Obj::setJointAngles(std::vector<JointAngles>& frames_JA)
{
	m_2dJointAngles = frames_JA;
}

void OBJ::Obj::setJointAngles(const std::vector<Segs> &frames_S)
{
	
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

SubjInfo OBJ::Obj::getSubjInfo()
{
	if (m_subjInfo.subjname =="null")
	{
		qDebug() << "Error: no sujInfo stored" << endl;
	}
	return m_subjInfo;
}

CaliInfo OBJ::Obj::getCaliInfo()
{
	return m_caliInfo;
}

std::vector<Joints> OBJ::Obj::getJoints() const
{
	return m_framesJ;
}

std::vector<Segs> OBJ::Obj::getSegments() const
{
	return m_framesS;
}

std::vector<JointAngles> OBJ::Obj::getJointAngles()
{
	return m_2dJointAngles;
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

double RadianToDegree(double angle)
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
