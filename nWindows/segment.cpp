#include "segment.h"



Segment::Segment()
{
}


Segment::~Segment()
{
}

void Segment::calSegCOM(Eigen::Vector3f &segcom, Joint &jointP, Joint &jointD, const int &segNum)
{
	
	Eigen::Vector3f coordP(jointP.Position.X, jointP.Position.Y, jointP.Position.Z);
	Eigen::Vector3f coordD(jointD.Position.X, jointD.Position.Y, jointD.Position.Z);
	switch (segNum)
	{
	case 0://thigh
		segcom = coordP + (coordD - coordP)* 0.433;
		break;
	case 1://shank
		segcom = coordP + (coordD - coordP) * 0.433;
		break;
	case 2://foot
		segcom = coordP + (coordD - coordP) * 0.5;
		break;
	case 3://Upper arm
		segcom = coordP + (coordD - coordP) * 0.436;
		break;
	case 4://forearm and hand
		segcom = coordP + (coordD - coordP) * 0.682;
		break;
	case 5://Pelvis
		segcom = coordP + (coordD - coordP) * 0.105;
		break;
	case 6://Thorax and abdomen
		segcom = coordP + (coordD - coordP) * 0.63;
		break;
	case 7://Head and neck
		segcom = coordP + (coordD - coordP) * 1.0;
		break;
	default:
		break;
	}
}
