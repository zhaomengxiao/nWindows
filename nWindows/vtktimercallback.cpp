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

	updateSegPosition();
	updateCoords();
	updateOptPosition();
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
				updateSegsXYZ(p_obj->getSegments()[n_frame]); //TODO:seg可以整合显示
			}
			if (p_obj->getForcePosi().size()>0 && p_obj->getSubjInfo().bag == true)
			{
				updateForceXYZ(p_obj->getForcePosi()[n_frame]);
			}
			if (p_obj->getOptJ().size() > 0)
			{
				updateOptSegXYZ(p_obj->getOptJ()[n_frame]);
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

void vtkTimerCallback::updateSegsXYZ(const OBJ::Segs & segs)
{
	m_Segs = segs;
}

void vtkTimerCallback::updateOptSegXYZ(const OBJ::OptJoints & optjoints)
{
	m_optJoints = optjoints;
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

void vtkTimerCallback::updateSegPosition()
{
	for (int i = 0; i < 13; i++)
	{
		
		source_Segs[i]->SetPoint1(
			m_Segs[i].Jdistal.jointPosition.x() * 1000,
			m_Segs[i].Jdistal.jointPosition.y() * 1000,
			m_Segs[i].Jdistal.jointPosition.z() * 1000
		);
		
		source_Segs[i]->SetPoint2(
			m_Segs[i].Jproximal.jointPosition.x() * 1000,
			m_Segs[i].Jproximal.jointPosition.y() * 1000,
			m_Segs[i].Jproximal.jointPosition.z() * 1000
		);
		source_Segs[i]->Update();

	}
}

void vtkTimerCallback::updateCoords()
{
	for (int i = 0; i < 2; i++)
	{

		source_Coords_axisX[i]->SetPoint1(
			m_Segs[10 + i].Jdistal.jointPosition.x() * 1000,
			m_Segs[10 + i].Jdistal.jointPosition.y() * 1000,
			m_Segs[10 + i].Jdistal.jointPosition.z() * 1000
		);
		source_Coords_axisX[i]->SetPoint2(
			(m_Segs[10 + i].Jdistal.jointPosition.x() * 1000 + m_Segs[10+i].lcoord.axis_x.x() * 300) ,
			(m_Segs[10 + i].Jdistal.jointPosition.y() * 1000 + m_Segs[10+i].lcoord.axis_x.y() * 300) ,
			(m_Segs[10 + i].Jdistal.jointPosition.z() * 1000 + m_Segs[10+i].lcoord.axis_x.z() * 300)
		);
		source_Coords_axisX[i]->Update();

		source_Coords_axisY[i]->SetPoint1(
			m_Segs[10 + i].Jdistal.jointPosition.x() * 1000,
			m_Segs[10+i].Jdistal.jointPosition.y() * 1000,
			m_Segs[10+i].Jdistal.jointPosition.z() * 1000
		);
		source_Coords_axisY[i]->SetPoint2(
			(m_Segs[10+i].Jdistal.jointPosition.x() * 1000 + m_Segs[10+i].lcoord.axis_y.x() * 300),
			(m_Segs[10+i].Jdistal.jointPosition.y() * 1000 + m_Segs[10+i].lcoord.axis_y.y() * 300),
			(m_Segs[10+i].Jdistal.jointPosition.z() * 1000 + m_Segs[10+i].lcoord.axis_y.z() * 300)
		);
		source_Coords_axisY[i]->Update();

		source_Coords_axisZ[i]->SetPoint1(
			m_Segs[10+i].Jdistal.jointPosition.x() * 1000,
			m_Segs[10+i].Jdistal.jointPosition.y() * 1000,
			m_Segs[10+i].Jdistal.jointPosition.z() * 1000
		);
		source_Coords_axisZ[i]->SetPoint2(
			(m_Segs[10+i].Jdistal.jointPosition.x() * 1000 + m_Segs[10+i].lcoord.axis_z.x() * 300),
			(m_Segs[10+i].Jdistal.jointPosition.y() * 1000 + m_Segs[10+i].lcoord.axis_z.y() * 300),
			(m_Segs[10+i].Jdistal.jointPosition.z() * 1000 + m_Segs[10+i].lcoord.axis_z.z() * 300)
		);
		source_Coords_axisZ[i]->Update();

	}
}

void vtkTimerCallback::updateOptPosition()
{
	source_OptSegs[0]->SetPoint1(
		m_optJoints[0].x() * 1000,
		m_optJoints[0].y() * 1000,
		m_optJoints[0].z() * 1000
	);

	source_OptSegs[0]->SetPoint2(
		m_optJoints[2].x() * 1000,
		m_optJoints[2].y() * 1000,
		m_optJoints[2].z() * 1000
	);

	source_OptSegs[1]->SetPoint1(
		m_optJoints[2].x() * 1000,
		m_optJoints[2].y() * 1000,
		m_optJoints[2].z() * 1000
	);

	source_OptSegs[1]->SetPoint2(
		m_optJoints[3].x() * 1000,
		m_optJoints[3].y() * 1000,
		m_optJoints[3].z() * 1000
	);

	source_OptSegs[2]->SetPoint1(
		m_optJoints[1].x() * 1000,
		m_optJoints[1].y() * 1000,
		m_optJoints[1].z() * 1000
	);

	source_OptSegs[2]->SetPoint2(
		m_optJoints[4].x() * 1000,
		m_optJoints[4].y() * 1000,
		m_optJoints[4].z() * 1000
	);

	source_OptSegs[3]->SetPoint1(
		m_optJoints[4].x() * 1000,
		m_optJoints[4].y() * 1000,
		m_optJoints[4].z() * 1000
	);

	source_OptSegs[3]->SetPoint2(
		m_optJoints[5].x() * 1000,
		m_optJoints[5].y() * 1000,
		m_optJoints[5].z() * 1000
	);
	source_Segs[0]->Update();
	source_Segs[1]->Update();
	source_Segs[2]->Update();
	source_Segs[3]->Update();
}


