#include "vtktimercallback.h"


//from extern 
FileREC *pSender = new FileREC();
OBJ::Obj *p_obj = new OBJ::Obj();
int jointSelected;
float force;
float bodyWeight;
float bagX;
float bagY;
float bagZ;

bool bag;
bool isOffMode{false};
int n_frame{0};
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
	

	updatePosition();

	
	updateForcePosition();

	updateCOMPosition();

	//==test==
	
	if (isOffMode)
	{
		if (p_obj!=nullptr)
		{
			if (p_obj->getJoints().size()>0)
			{
				updateXYZ(p_obj->getJoints()[n_frame]);
			}
			if (p_obj->getSegments().size() > 0)
			{
				updateCOMXYZ(p_obj->getCOMs(p_obj->getSegments()[n_frame]));
			}
			if (p_obj->getForcePosi().size()>0 && p_obj->getSubjInfo().bag == true)
			{
				updateForceXYZ(p_obj->getForcePosi()[n_frame]);
			}
			
		}
			
	}
	else if (pSender->jointPositions().empty() || pSender->segCOMs().empty())
	{
		//std::cout << "wait for data" << std::endl;
	}
	else
	{
		updateXYZ(pSender->jointPositions());
		updateCOMXYZ(pSender->segCOMs());
		//updateForcePosition
		if (bag)
		{
			//设置力量的位置
			Eigen::Vector3f pforce{ pSender->jointPositions()[1].jointPosition.x() - bagX ,
				pSender->jointPositions()[1].jointPosition.y() - bagZ,
				pSender->jointPositions()[1].jointPosition.z() + bagY };
			updateForceXYZ(pforce);
		}
		else
		{
			Eigen::Vector3f pforce{ pSender->jointPositions()[jointSelected].jointPosition.x()
				, pSender->jointPositions()[jointSelected].jointPosition.y()
				, pSender->jointPositions()[jointSelected].jointPosition.z() };
			updateForceXYZ(pforce);
		}
		
	}
	//std::cout << x << "," << y << "," << z << endl;
	vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::SafeDownCast(caller);
	iren->SetInteractorStyle(nullptr);
	iren->GetRenderWindow()->Render();
}

void vtkTimerCallback::updateXYZ(const OBJ::Joints& joints)
{
	
	m_joints = joints;
	 
}

void vtkTimerCallback::updateCOMXYZ(const std::array<Eigen::Vector3f, 13> &coms)
{
	m_COMs = coms;
}

void vtkTimerCallback::updateForceXYZ(const Eigen::Vector3f pf)
{
	m_Pforce = pf;
}


void vtkTimerCallback::updatePosition()
{
	for (int i = 0; i < 25; i++)
	{
		actor_joints[i]->SetPosition(m_joints[i].jointPosition.x()*1000, m_joints[i].jointPosition.y()*1000, m_joints[i].jointPosition.z()*1000);
	}
}

void vtkTimerCallback::updateCOMPosition()
{
	for (int i = 0; i < 13; i++)
	{
		actor_COMs[i]->SetPosition(m_COMs[i].x() * 1000, m_COMs[i].y() * 1000, m_COMs[i].z() * 1000);
	}
}

void vtkTimerCallback::updateForcePosition()
{
	actor_arrow->SetPosition(m_Pforce.x() * 1000, m_Pforce.y() * 1000, m_Pforce.z() * 1000);
}


