#pragma once
#include "filerec.h"
#include "obj.h"
#include <vtkCommand.h>
#include <vtkshape.h>
#include <array>
#include <Eigen\Dense>


//#include "mainwindow.h"
class vtkTimerCallback :
	public vtkCommand
{
public:
	static vtkTimerCallback *New();
	virtual void Execute(vtkObject *caller, unsigned long eventId,
		void * vtkNotUsed(callData));
private:
	int TimerCount;
	OBJ::Joints m_joints;
	std::array<Eigen::Vector3f, 13> m_COMs;
	Eigen::Vector3f m_Pforce;
private:
	void updateXYZ(const OBJ::Joints &joints);
	void updateCOMXYZ(const std::array<Eigen::Vector3f,13> &coms);
	void updateForceXYZ(const Eigen::Vector3f pf);
public:
	std::array<vtkSmartPointer<vtkActor>, 25> actor_joints{};
	std::array<vtkSmartPointer<vtkActor>, 13> actor_COMs{};
	vtkSmartPointer<vtkActor> actor_arrow;
	
	//+++
	void updatePosition();
	void updateCOMPosition(); 
	void updateForcePosition();
	//void calcSpinebaseFMwithBag(); 

};

