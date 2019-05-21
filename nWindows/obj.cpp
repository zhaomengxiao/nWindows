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
		+ pow((Jdistal.jointPosition.z() - Jproximal.jointPosition.z()), 2));
}


//Obj
Obj::Obj()
{
}

Obj::~Obj()
{
}

Obj::Obj(const std::vector<std::array<Joint, JointType_Count>>& frames_j)
{
	m_framesJ = frames_j;
	//build segments

}
 
void OBJ::Obj::setJoints(const std::vector<std::array<Joint, JointType_Count>> &frames_j)
{
	m_nFrames = frames_j.size();
	m_framesJ.clear();
	m_framesJ.reserve(m_nFrames);
	m_framesJ = frames_j;
}

void OBJ::Obj::setSegments(const std::vector<std::array<Segment, SegType_Count>>& frames_S)
{
	m_framesS = frames_S;
}

void OBJ::Obj::setJointAngles(std::vector<JointAngles>& frames_JA)
{
	m_2dJointAngles = frames_JA;
}

void OBJ::Obj::setJointAngles(const std::vector<std::array<Segment, SegType_Count>> &frames_S)
{
	
}


std::vector<std::array<Segment, SegType_Count>> Obj::buildSegments(const std::vector<std::array<Joint, JointType_Count>> &frames_J)
{
	std::vector<std::array<Segment, SegType_Count>> frames_Seg;
	frames_Seg.clear();
	frames_Seg.reserve(frames_J.size());
	std::array<Segment, SegType_Count> segments;
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

		segments[SegType_Pelvis] = Segment{ joints[JointType_SpineMid] ,joints[JointType_SpineBase],SegType_Pelvis };
		segments[SegType_ThoraxAbdomen] = Segment{ joints[JointType_SpineShoulder] ,joints[JointType_SpineMid],SegType_ThoraxAbdomen };
		segments[SegType_HeadNeck] = Segment{ joints[JointType_Head] ,joints[JointType_SpineShoulder],SegType_HeadNeck };

		frames_Seg.push_back(segments);
	}
	std::cout << "get Seged" << std::endl;

	return frames_Seg;
}
std::array<Segment, SegType_Count> OBJ::Obj::buildSegments(const std::array<Joint, JointType_Count>& joints)
{
	std::array<Segment, SegType_Count> segments;

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

	segments[SegType_Pelvis] = Segment{ joints[JointType_SpineMid] ,joints[JointType_SpineBase],SegType_Pelvis };
	segments[SegType_ThoraxAbdomen] = Segment{ joints[JointType_SpineShoulder] ,joints[JointType_SpineMid],SegType_ThoraxAbdomen };
	segments[SegType_HeadNeck] = Segment{ joints[JointType_Head] ,joints[JointType_SpineShoulder],SegType_HeadNeck };


	return segments;
}


void OBJ::Obj::setFilePath(QString p_subInfo, QString p_cali)
{
	path_subjInfo = p_subInfo;
	path_cali = p_cali;
}

void OBJ::Obj::addtrail(QString p_trail)
{
	path_trail = p_trail;
}

float OBJ::Obj::calJointAngle(const Segment &sP,const Segment &sD)
{
	


	// If we can't find either of these joints, exit
	if ((sP.trackingState == TrackingState_NotTracked) || (sD.trackingState == TrackingState_NotTracked) )
	{
		return 0.0;
	}

	std::vector<float> vector1
	{ sP.Jproximal.jointPosition.x() - sP.Jdistal.jointPosition.x() , sP.Jproximal.jointPosition.y() - sP.Jdistal.jointPosition.y() , sP.Jproximal.jointPosition.z() - sP.Jdistal.jointPosition.z() };
	std::vector<float> vector2
	{ sD.Jdistal.jointPosition.x() - sD.Jproximal.jointPosition.x() , sD.Jdistal.jointPosition.y() - sD.Jproximal.jointPosition.y() , sD.Jdistal.jointPosition.z() - sD.Jproximal.jointPosition.z() };



	float normv1 = norm(vector1);
	float normv2 = norm(vector2);
	float costheta = dot(vector1, vector2) / (normv1*normv2);
	float theta = RadianToDegree(acos(costheta));

	return theta;

}

JointAngles OBJ::Obj::calAllJointAngles(const std::array<Segment, SegType_Count> &segments)
{
	JointAngles ja;
	ja.ElbowL = calJointAngle(segments[SegType_LeftUpperArm], segments[SegType_LeftForArmHand]);
	ja.ElbowR = calJointAngle(segments[SegType_RightUpperArm], segments[SegType_RightForArmHand]);
	ja.KneeL  = calJointAngle(segments[SegType_LeftThigh], segments[SegType_LeftShank]);
	ja.KneeR  = calJointAngle(segments[SegType_RightThigh], segments[SegType_RightShank]);
	ja.Spine = calJointAngle(segments[SegType_ThoraxAbdomen], segments[SegType_Pelvis]);
	return ja;
}

std::vector<JointAngles> OBJ::Obj::calAllJointAngles(const std::vector<std::array<Segment, SegType_Count>>& frames_S)
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

std::vector<std::array<Joint, JointType_Count>> OBJ::Obj::getJoints()
{
	return m_framesJ;
}

std::vector<std::array<Segment, SegType_Count>> OBJ::Obj::getSegments()
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

float dot(std::vector<float> v1, std::vector<float> v2)
{
	return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

float norm(std::vector<float> v)
{
	return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

double RadianToDegree(double angle)
{
	return angle * (180.0 / PI);
}
