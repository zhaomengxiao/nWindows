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
	OBJ::Segs m_Segs;
	OBJ::OptJoints m_optJoints;
private:
	void updateXYZ(const OBJ::Joints &joints);
	void updateCOMXYZ(const std::array<Eigen::Vector3f,13> &coms);
	void updateForceXYZ(const Eigen::Vector3f pf);
	void updateSegsXYZ(const OBJ::Segs &segs);
	void updateOptSegXYZ(const OBJ::OptJoints &optjoints);
public:
	std::array<vtkSmartPointer<vtkActor>, 25> actor_joints;
	std::array<vtkSmartPointer<vtkActor>, 13> actor_COMs;
	
	std::array< vtkSmartPointer<vtkLineSource>, 13> source_Segs;
	std::array< vtkSmartPointer<vtkLineSource>, 2> source_Coords_axisX;
	std::array< vtkSmartPointer<vtkLineSource>, 2> source_Coords_axisY;
	std::array< vtkSmartPointer<vtkLineSource>, 2> source_Coords_axisZ;
	std::array< vtkSmartPointer<vtkLineSource>, 4> source_OptSegs;

	vtkSmartPointer<vtkActor> actor_arrow;
	
	//+++
	void updatePosition();
	void updateCOMPosition(); 
	void updateForcePosition();
	void updateSegPosition();
	void updateCoords();
	void updateOptPosition();
	//void calcSpinebaseFMwithBag(); 

};

