#pragma once
//vtk
#include <vtkSphereSource.h>
#include <vtkCubeSource.h>
#include <vtkArrowSource.h>
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
		Arrow()
		{
			// Create a sphere
			arrowSource =
				vtkSmartPointer<vtkArrowSource>::New();
			arrowSource->SetShaftRadius(0.05);
			arrowSource->SetTipRadius(0.1);
			arrowSource->SetTipLength(0.3);
			arrowSource->SetInvert(1);


			arrowSource->Update();


			vtkSmartPointer<vtkPolyDataMapper> mapper =
				vtkSmartPointer<vtkPolyDataMapper>::New();
			mapper->SetInputConnection(arrowSource->GetOutputPort());

			actor =
				vtkSmartPointer<vtkActor>::New();
			actor->SetMapper(mapper);
			actor->GetProperty()->SetColor(1, 0, 0);//red
			actor->SetPosition(0, 0, 1500);
			actor->SetScale(200);
			actor->RotateZ(90);
		};
		Arrow(float TipLength) : m_TipLength(TipLength)
		{
			// Create a sphere
			arrowSource =
				vtkSmartPointer<vtkArrowSource>::New();
			arrowSource->SetShaftRadius(30);
			arrowSource->SetTipLength(TipLength);
			arrowSource->SetTipRadius(15);

			arrowSource->Update();
			vtkSmartPointer<vtkPolyDataMapper> mapper =
				vtkSmartPointer<vtkPolyDataMapper>::New();
			mapper->SetInputConnection(arrowSource->GetOutputPort());

			actor =
				vtkSmartPointer<vtkActor>::New();
			actor->SetMapper(mapper);
			actor->GetProperty()->SetColor(1, 0, 0);//red
			actor->SetPosition(-100, -100, 1500);
		};
		~Arrow() {};
	public:
		vtkSmartPointer<vtkActor> Actor() {
			return actor;
		}
	private:
		float m_TipLength{};
		vtkSmartPointer<vtkArrowSource> arrowSource;
		vtkSmartPointer<vtkActor> actor;
	public:


	};

	class Sphere
	{
	public:
		Sphere()
		{
			// Create a sphere
			sphereSource =
				vtkSmartPointer<vtkSphereSource>::New();
			//sphereSource->SetCenter(m_x, m_y, m_z);
			sphereSource->SetRadius(m_r);
			// Make the surface smooth.
			sphereSource->SetPhiResolution(100);
			sphereSource->SetThetaResolution(100);
			vtkSmartPointer<vtkPolyDataMapper> mapper =
				vtkSmartPointer<vtkPolyDataMapper>::New();
			mapper->SetInputConnection(sphereSource->GetOutputPort());

			actor =
				vtkSmartPointer<vtkActor>::New();
			actor->SetMapper(mapper);
			actor->GetProperty()->SetColor(0, 1, 0);
			actor->SetPosition(0, 0, 1500);
		};
		Sphere(float r, char color) : m_r(r)
		{
			// Create a sphere
			sphereSource =
				vtkSmartPointer<vtkSphereSource>::New();
			//sphereSource->SetCenter(x, y, z);
			sphereSource->SetRadius(r);
			// Make the surface smooth.
			sphereSource->SetPhiResolution(100);
			sphereSource->SetThetaResolution(100);
			vtkSmartPointer<vtkPolyDataMapper> mapper =
				vtkSmartPointer<vtkPolyDataMapper>::New();
			mapper->SetInputConnection(sphereSource->GetOutputPort());

			actor =
				vtkSmartPointer<vtkActor>::New();
			actor->SetMapper(mapper);
			if (color == 'r')
			{
				actor->GetProperty()->SetColor(1, 0, 0);
			}
			if (color == 'g')
			{
				actor->GetProperty()->SetColor(0, 1, 0);
			}
			if (color == 'b')
			{
				actor->GetProperty()->SetColor(0, 0, 1);
			}
			actor->SetPosition(0, 0, 1500);
		};
		~Sphere() {};
	public:
		vtkSmartPointer<vtkActor> Actor() {
			return actor;
		}
	private:

		float m_r{ 30 };
		vtkSmartPointer<vtkSphereSource> sphereSource;
		vtkSmartPointer<vtkActor> actor;
	public:


	};

	class Camera
	{
	public:
		Camera()
		{
			// Create a sphere
			cameraSource =
				vtkSmartPointer<vtkCubeSource>::New();
			cameraSource->SetCenter(0, 0, -30);
			cameraSource->SetXLength(150.0);
			cameraSource->SetYLength(60.0);
			cameraSource->SetZLength(60.0);
			cameraSource->Update();


			vtkSmartPointer<vtkPolyDataMapper> mapper =
				vtkSmartPointer<vtkPolyDataMapper>::New();
			mapper->SetInputConnection(cameraSource->GetOutputPort());

			actor =
				vtkSmartPointer<vtkActor>::New();
			actor->SetMapper(mapper);
		};
		~Camera() {};

	private:
		vtkSmartPointer<vtkCubeSource> cameraSource;
		vtkSmartPointer<vtkActor> actor;
	
	public:
		vtkSmartPointer<vtkActor> Actor() {
			return actor;
		}
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