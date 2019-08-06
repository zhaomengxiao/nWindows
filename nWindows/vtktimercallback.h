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
	OBJ::Joints m_joints_opted;
	std::array<Eigen::Vector3f, 13> m_COMs;
	std::array<Eigen::Vector3f, 13> m_COMs_opted;
	Eigen::Vector3f m_Pforce;
	OBJ::Segs m_Segs;
	OBJ::Segs m_Segs_opted;
private:
	void updateXYZ(const OBJ::Joints &joints);
	void updateCOMXYZ(const std::array<Eigen::Vector3f,13> &coms);
	void updateForceXYZ(const Eigen::Vector3f pf);
	void updateSegsXYZ(const OBJ::Segs &segs);
	
	void updateXYZ_opted(const OBJ::Joints &joints_opted);
	void updateCOMXYZ_opted(const std::array<Eigen::Vector3f, 13> &coms);
	void updateSegsXYZ_opted(const OBJ::Segs &segs);

public:
	std::array<vtkSmartPointer<vtkActor>, 25> actor_joints;
	std::array<vtkSmartPointer<vtkActor>, 25> actor_joints_opted;
	std::array<vtkSmartPointer<vtkActor>, 13> actor_COMs;
	std::array<vtkSmartPointer<vtkActor>, 13> actor_COMs_opted;

	std::array< vtkSmartPointer<vtkLineSource>, 13> source_Segs;
	std::array< vtkSmartPointer<vtkLineSource>, 13> source_Segs_opted;
	
	std::array< vtkSmartPointer<vtkLineSource>, 2> source_Coords_axisX;
	std::array< vtkSmartPointer<vtkLineSource>, 2> source_Coords_axisY;
	std::array< vtkSmartPointer<vtkLineSource>, 2> source_Coords_axisZ;
	//std::array< vtkSmartPointer<vtkLineSource>, 4> source_OptSegs;

	vtkSmartPointer<vtkActor> actor_arrow;
	
	//+++
	void updatePosition();
	void updatePosition_opted();
	void updateCOMPosition(); 
	void updateCOMPosition_opted();
	void updateForcePosition();
	void updateSegPosition();
	void updateSegPosition_opted();
	void updateCoords();
	//void updateOptPosition();
	//void calcSpinebaseFMwithBag(); 

};

