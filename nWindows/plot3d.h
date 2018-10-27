#pragma once
//vtk
#include <vtkCubeSource.h>
#include <vtkAxesActor.h>
#pragma once
#include <vtkSphereSource.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkNamedColors.h>
#include <vtkProperty.h>

#include <string>
#include "vtkAutoInit.h" 

VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2

VTK_MODULE_INIT(vtkInteractionStyle);

class Sphere
{
public:
	Sphere(float x, float y, float z, float r):m_x(x),m_y(y),m_z(z),m_r(r)
	{
		// Create a sphere
		sphereSource =
			vtkSmartPointer<vtkSphereSource>::New();
		sphereSource->SetCenter(x, y, z);
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
		actor->GetProperty()->SetColor(0, 1, 0);
	};
	~Sphere() {};
public:
	static void initRender() {
		vtkSmartPointer<vtkRenderer> renderer =
			vtkSmartPointer<vtkRenderer>::New();
		vtkSmartPointer<vtkRenderWindow> renderWindow =
			vtkSmartPointer<vtkRenderWindow>::New();
		renderWindow->SetWindowName("render");
		renderWindow->AddRenderer(renderer);
		vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
			vtkSmartPointer<vtkRenderWindowInteractor>::New();
		renderWindowInteractor->SetRenderWindow(renderWindow);

		//renderer->AddActor(actor);
		//renderer->SetBackground(1, 1, 1);

		//renderWindow->Render();
		//renderWindowInteractor->Start();
	};
	vtkSmartPointer<vtkActor> Actor() {
		return actor;
	}
private:
	float m_x;
	float m_y;
	float m_z;
	float m_r;
	vtkSmartPointer<vtkSphereSource> sphereSource;
	vtkSmartPointer<vtkActor> actor;
public:
	
	
};




class Plot3d
{
public:
	Plot3d();
	~Plot3d();
};

