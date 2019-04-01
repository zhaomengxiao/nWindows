#pragma once
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

	std::array<float, 25> m_X{ 0 };
	std::array<float, 25> m_Y{ 0 };
	std::array<float, 25> m_Z{ 1500 };

	std::array<float, 13> m_COM_x{ 0 };
	std::array<float, 13> m_COM_y{ 0 };
	std::array<float, 13> m_COM_z{ 0 };
	std::array<Eigen::Vector3f, 13> m_COMs{ };
	float m_fx, m_fy, m_fz;
private:
	void updateXYZ(int jointNumber);
	void updateCOMXYZ(int segNumber);

public:
	std::array<vtkSmartPointer<vtkActor>, 25> actor_joints{};
	std::array<vtkSmartPointer<vtkActor>, 13> actor_COMs{};
	vtkSmartPointer<vtkActor> actor_arrow;
	
	//+++
	void updatePosition(int jointNumber); 
	void updateCOMPosition(int segNumber); 

	void calcSpinebaseFMwithBag(); 

};

