#include "vtk.h"



VTK::VTK(){	
}


VTK::~VTK(){
}



void VTK::addActor()
{
	//画坐标轴
	vtkSmartPointer<vtkAxesActor> axes =
		vtkSmartPointer<vtkAxesActor>::New();
	axes->SetPosition(0, 0, 0);
	axes->SetTotalLength(500, 500, 500);
	this->p_renderer->AddActor(axes);
	//com 为红色
	for (int i = 0; i < 13; i++)
	{
		COMSphere[i].Actor()->GetProperty()->SetColor(1, 0, 0);
	}
	// Add the actor to the scene
	//this->p_renderer->AddActor(this->p_actor);
	this->p_renderer->AddActor(arrow.Actor());
	for (int i = 0; i < 13; i++)
	{
		this->p_renderer->AddActor(COMSphere[i].Actor());
	}
	for (int i = 0; i < 25; i++)
	{
		this->p_renderer->AddActor(jointsSphere[i].Actor());
	}
	p_renderer->AddActor(camera.Actor());
	p_renderer->SetBackground(.1, .2, .3); // Background color green
	p_renderer->ResetCamera();
}

void VTK::setPipline()
{
	// Create a renderer, render window, and interactor
	p_renderer = vtkRenderer::New();
	p_renderWindow = vtkRenderWindow::New();
	p_renderWindow->AddRenderer(this->p_renderer);
	p_renderWindow->SetSize(900, 600);
	
}

void VTK::setCamera()
{
	//相机设置
	vtkSmartPointer<vtkCamera>myCamera = vtkSmartPointer<vtkCamera>::New();
	myCamera->SetClippingRange(0.0475, 2.3786); //这些值随便设置的，为了演示用法而已
	myCamera->SetFocalPoint(0.0573, -0.2134, -0.0523);
	myCamera->SetPosition(0.3245, -0.1139, -0.2932);
	myCamera->ComputeViewPlaneNormal();
	myCamera->SetViewUp(-0.2234, 0.9983, 0.0345);
	p_renderer->SetActiveCamera(myCamera);
	p_renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	p_renderWindowInteractor->SetRenderWindow(p_renderWindow);
	
}

int VTK::setCallback()
{
	cb = vtkSmartPointer<vtkTimerCallback>::New();
	//force arrow
	cb->actor_arrow = arrow.Actor();
	//COM
	for (int i = 0; i < 13; i++)
	{
		cb->actor_COMs[i] = COMSphere[i].Actor();
	}
	//joint center
	for (int i = 0; i < 25; i++)
	{
		cb->actor_joints[i] = jointsSphere[i].Actor();
	}
	//+++^^^add more cb sign up above^^^+++

	p_renderWindowInteractor->AddObserver(vtkCommand::TimerEvent, cb);
	int timerId = p_renderWindowInteractor->CreateRepeatingTimer(33);

	p_renderWindowInteractor->Start();
	return EXIT_SUCCESS;
}

void VTK::rend()
{	
	setPipline();
	setCamera();
	addActor();
	initialize();
	setCallback();	
}
void VTK::rendcali()
{
	setPipline();
	setCamera();
	initialize();
}
vtkSmartPointer<vtkRenderWindow> VTK::RenderWindow()
{
	return p_renderWindow;
}

void VTK::initialize()
{

	p_renderWindow->Render();
	p_renderWindowInteractor->Initialize();
}
