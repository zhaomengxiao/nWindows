#pragma once
//VTK
#include "vtkshape.h"
#include "vtktimercallback.h"
#include <array>
#include <thread>

class VTK
{
public:
	VTK();
	~VTK();
	friend class MainWindow;
private:
	//source
	vtkShape::Arrow arrow;
	vtkShape::Camera camera;
	std::array<vtkShape::Sphere, 13> COMSphere;
	std::array<vtkShape::Sphere, 25> jointsSphere;
	//pipline
	//vtkSmartPointer<vtkPolyDataMapper> p_mapper;
	//vtkSmartPointer<vtkActor> p_actor;
	vtkSmartPointer<vtkRenderer> p_renderer;
	vtkSmartPointer<vtkRenderWindow> p_renderWindow;
	vtkSmartPointer<vtkRenderWindowInteractor> p_renderWindowInteractor;
	//callbackfunc
	
	vtkSmartPointer<vtkTimerCallback> cb;
	
public:
	vtkSmartPointer<vtkRenderWindow> RenderWindow();
	
	
	void setPipline();
	void setCamera();
	void addActor();
	void initialize();
	int setCallback();
	void rend();
};

