#pragma once
//vtk
#include <vtkSphereSource.h>
#include <vtkCubeSource.h>
#include <vtkArrowSource.h>
#include <vtkLineSource.h>
#include <vtkAxesActor.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkNamedColors.h>
#include <vtkProperty.h>
#include <vtkCamera.h>
#include "vtkAutoInit.h" 


VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2

VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);

namespace vtkShape {
	class Arrow
	{
	public:
		Arrow();
		
		Arrow(float TipLength);
		
		~Arrow();
	public:
		vtkSmartPointer<vtkActor> Actor();
	private:
		float m_TipLength{};
		vtkSmartPointer<vtkArrowSource> arrowSource;
		vtkSmartPointer<vtkActor> actor;
	public:


	};

	class Sphere
	{
	public:
		Sphere();
		Sphere(float r, char color);
		~Sphere();
	public:
		vtkSmartPointer<vtkActor> Actor();
	private:

		float m_r{ 30 };
		vtkSmartPointer<vtkSphereSource> sphereSource;
		vtkSmartPointer<vtkActor> actor;
	public:


	};

	class Camera
	{
	public:
		Camera();
		~Camera();

	private:
		vtkSmartPointer<vtkCubeSource> cameraSource;
		vtkSmartPointer<vtkActor> actor;
	
	public:
		vtkSmartPointer<vtkActor> Actor();
	};
	
	class Line
	{
	public:
		Line();
		Line(float width, char color);
		~Line();

	private:
		vtkSmartPointer<vtkLineSource> lineSource;
		vtkSmartPointer<vtkActor> actor;

	public:
		vtkSmartPointer<vtkActor> Actor();
		vtkSmartPointer<vtkLineSource> LineSource();
	};

	class Coord
	{
	public:
		Coord();
		~Coord();

	private:
	private:
		vtkSmartPointer<vtkLineSource> lineSource_axisX;
		vtkSmartPointer<vtkLineSource> lineSource_axisY;
		vtkSmartPointer<vtkLineSource> lineSource_axisZ;
		vtkSmartPointer<vtkActor> actor_axisX;
		vtkSmartPointer<vtkActor> actor_axisY;
		vtkSmartPointer<vtkActor> actor_axisZ;

	public:
		vtkSmartPointer<vtkActor> Actor_axisX();
		vtkSmartPointer<vtkActor> Actor_axisY();
		vtkSmartPointer<vtkActor> Actor_axisZ();
		vtkSmartPointer<vtkLineSource> LineSource_axisX();
		vtkSmartPointer<vtkLineSource> LineSource_axisY();
		vtkSmartPointer<vtkLineSource> LineSource_axisZ();

	};


	
	/*class VTKsegment
	{
	public:
		VTKsegment();
		~VTKsegment();

	private:

	};

	VTKsegment::VTKsegment()
	{
	}

	VTKsegment::~VTKsegment()
	{
	}*/
}