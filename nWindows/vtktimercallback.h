#pragma once
#include "filerec.h"
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


	std::array<Joint, 25> m_joints;
	std::array<float, 13> m_COM_x;
	std::array<float, 13> m_COM_y;
	std::array<float, 13> m_COM_z;
	std::array<Eigen::Vector3f, 13> m_COMs{ };
	float m_fx, m_fy, m_fz;
private:
	void updateXYZ(const std::array<Joint, 25> &joints);
	void updateCOMXYZ(int segNumber);

public:
	std::array<vtkSmartPointer<vtkActor>, 25> actor_joints{};
	std::array<vtkSmartPointer<vtkActor>, 13> actor_COMs{};
	vtkSmartPointer<vtkActor> actor_arrow;
	
	//+++
	void updatePosition();
	void updateCOMPosition(int segNumber); 

	void calcSpinebaseFMwithBag(); 

};

