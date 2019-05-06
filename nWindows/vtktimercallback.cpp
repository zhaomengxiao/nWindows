#include "vtktimercallback.h"

#include "filerec.h"
//from extern 
FileREC *pSender = new FileREC();
int jointSelected;
float force;
float bodyWeight;
float bagX;
float bagY;
float bagZ;
bool bag;

//extern
extern float F_spinebase;
extern Eigen::Vector3f M_spinebase;



vtkTimerCallback * vtkTimerCallback::New()
{
	vtkTimerCallback *cb = new vtkTimerCallback;
	cb->TimerCount = 0;
	return cb;
}

void vtkTimerCallback::Execute(vtkObject * caller, unsigned long eventId, void * vtkNotUsed)
{
	if (vtkCommand::TimerEvent == eventId)
	{
		++this->TimerCount;
	}
	//std::cout << this->TimerCount << std::endl;
	//actor_wrist_R->SetPosition   (m_X[10], m_Y[10], m_Z[10]);


	for (int i = 0; i < 25; i++)
	{
		if (actor_joints[i] != NULL)
		{
			updatePosition(i);
		}


	}

	if (actor_arrow != NULL)
	{
		actor_arrow->SetPosition(m_fx, m_fy, m_fz);
	}

	for (int i = 0; i < 13; i++)
	{
		if (actor_COMs[i] != NULL)
		{
			updateCOMPosition(i);
		}
	}

	//==test==
	if (pSender->jointPositions().empty() || pSender->segCOMs().empty())
	{
		//std::cout << "wait for data" << std::endl;
	}
	else
	{
		for (int i = 0; i < 25; i++)
		{
			updateXYZ(i);
		}

		for (int i = 0; i < 13; i++) {
			updateCOMXYZ(i);
		}

		//updateForcePosition
		if (bag)
		{
			m_fx = pSender->jointPositions()[1].Position.X * 1000 + bagX;
			m_fy = pSender->jointPositions()[1].Position.Y * 1000 + bagY;
			m_fz = pSender->jointPositions()[1].Position.Z * 1000 + bagZ;
			calcSpinebaseFMwithBag();
		}
		else
		{
			m_fx = pSender->jointPositions()[jointSelected].Position.X * 1000;
			m_fy = pSender->jointPositions()[jointSelected].Position.Y * 1000;
			m_fz = pSender->jointPositions()[jointSelected].Position.Z * 1000;
		}



	}
	//std::cout << x << "," << y << "," << z << endl;
	vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::SafeDownCast(caller);
	iren->GetRenderWindow()->Render();
}

void vtkTimerCallback::updateXYZ(int jointNumber)
{
	if (pSender->jointPositions()[jointNumber].TrackingState == 2)
	{
		m_X[jointNumber] = pSender->jointPositions()[jointNumber].Position.X * 1000;
		m_Y[jointNumber] = pSender->jointPositions()[jointNumber].Position.Y * 1000;
		m_Z[jointNumber] = pSender->jointPositions()[jointNumber].Position.Z * 1000;
	}
	else
	{
		m_X[jointNumber] = 0;
		m_Y[jointNumber] = 0;
		m_Z[jointNumber] = 0;
	}
}

void vtkTimerCallback::updateCOMXYZ(int segNumber)
{
	m_COM_x[segNumber] = pSender->segCOMs()[segNumber].x() * 1000;
	m_COM_y[segNumber] = pSender->segCOMs()[segNumber].y() * 1000;
	m_COM_z[segNumber] = pSender->segCOMs()[segNumber].z() * 1000;
	m_COMs[segNumber] = pSender->segCOMs()[segNumber];
}

void vtkTimerCallback::updatePosition(int jointNumber)
{
	actor_joints[jointNumber]->SetPosition(m_X[jointNumber], m_Y[jointNumber], m_Z[jointNumber]);
}

void vtkTimerCallback::updateCOMPosition(int segNumber)
{
	actor_COMs[segNumber]->SetPosition(m_COM_x[segNumber], m_COM_y[segNumber], m_COM_z[segNumber]);
}

//计算脊椎关节受力和力矩
void vtkTimerCallback::calcSpinebaseFMwithBag()
{
	F_spinebase = bodyWeight * (0.081 + 0.142 + 0.355 + 0.028 * 2 + 0.022 * 2)*9.8 + force * 9.8;

	Eigen::Vector3f thigh_M(0, 0, -0.1*9.8 *bodyWeight), shank_M(0, 0, -0.0465*9.8 *bodyWeight), foot_M(0, 0, -0.0145*9.8 *bodyWeight),
		upperArm_M(0, 0, -0.028 *9.8 *bodyWeight), fArmhand_M(0, 0, -0.022*9.8 *bodyWeight), Pelvis_M(0, 0, -0.142*9.8 *bodyWeight), ThoraxAbdomen_M(0, 0, -0.355*9.8 *bodyWeight),
		Headneck_M(0, 0, -0.081*9.8 *bodyWeight);
	Eigen::Vector3f fPosition(m_fx / 1000, m_fy / 1000, m_fz / 1000);
	Eigen::Vector3f vforce(0, 0, -force * 9.8);
	Eigen::Vector3f spinebaseXYZ(m_X[0] / 1000, m_Y[0] / 1000, m_Z[0] / 1000);
	M_spinebase = ((m_COMs[6] - spinebaseXYZ).cross(upperArm_M) + (m_COMs[7] - spinebaseXYZ).cross(upperArm_M)
		+ (m_COMs[8] - spinebaseXYZ).cross(fArmhand_M) + (m_COMs[9] - spinebaseXYZ).cross(fArmhand_M)
		+ (m_COMs[10] - spinebaseXYZ).cross(Pelvis_M) + (m_COMs[11] - spinebaseXYZ).cross(ThoraxAbdomen_M)
		+ (m_COMs[12] - spinebaseXYZ).cross(Headneck_M)) + (fPosition - spinebaseXYZ).cross(vforce);

}
