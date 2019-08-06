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
	

	// Add the actor to the scene
	//this->p_renderer->AddActor(this->p_actor);
	this->p_renderer->AddActor(arrow.Actor());
	for (int i = 0; i < 13; i++)
	{
		COMSphere[i].Actor()->GetProperty()->SetColor(1, 0, 0);//设置com 为红色
		this->p_renderer->AddActor(COMSphere[i].Actor());
	}
	for (int i = 0; i < 13; i++)
	{
		COMSphere_opted[i].Actor()->GetProperty()->SetColor(0, 0, 1);//设置comSphere的颜色
		this->p_renderer->AddActor(COMSphere_opted[i].Actor());
	}
	for (int i = 0; i < 25; i++)
	{
		this->p_renderer->AddActor(jointsSphere[i].Actor());
	}
	for (int i = 0; i < 25; i++)
	{
		this->p_renderer->AddActor(jointsSphere_opted[i].Actor());
	}
	for (int i = 0; i < 13; i++)
	{
		this->p_renderer->AddActor(SegLines[i].Actor());
	}
	for (int i = 0; i < 13; i++)
	{
		SegLines_opted[i].Actor()->GetProperty()->SetColor(1, 0, 0); //设置Seg_opt 的颜色
		this->p_renderer->AddActor(SegLines_opted[i].Actor());
	}
	for (int i = 0; i < 2; i++)
	{
		this->p_renderer->AddActor(Coords[i].Actor_axisX());
		this->p_renderer->AddActor(Coords[i].Actor_axisY());
		this->p_renderer->AddActor(Coords[i].Actor_axisZ());
	}
	/*for (int i = 0; i < 4; i++)
	{
		this->p_renderer->AddActor(OptSegLines[i].Actor());
		OptSegLines[i].Actor()->GetProperty()->SetColor(1, 0, 0);
	}*/
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
		cb->actor_COMs_opted[i] = COMSphere_opted[i].Actor();
	}
	//joint center
	for (int i = 0; i < 25; i++)
	{
		cb->actor_joints[i] = jointsSphere[i].Actor();
		cb->actor_joints_opted[i] = jointsSphere_opted[i].Actor();
	}
	//Segs
	for (int i = 0; i < 13; i++)
	{
		cb->source_Segs[i] = SegLines[i].LineSource();
		cb->source_Segs_opted[i] = SegLines_opted[i].LineSource();
	}

	for (int i = 0; i < Coords.size(); i++)
	{
		cb->source_Coords_axisX[i] = Coords[i].LineSource_axisX();
		cb->source_Coords_axisY[i] = Coords[i].LineSource_axisY();
		cb->source_Coords_axisZ[i] = Coords[i].LineSource_axisZ();

	}

	/*for (int i = 0; i < 4; i++)
	{
		cb->source_OptSegs[i] = OptSegLines[i].LineSource();
	}*/
	//+++^^^add more cb sign up above^^^+++

	p_renderWindowInteractor->AddObserver(vtkCommand::TimerEvent, cb);
	
	//设定更新帧率
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
