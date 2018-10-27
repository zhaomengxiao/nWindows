#include "mainwindow.h"
#include "imagewindow.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>
#include <thread>
//vtk
#include <vtkSphereSource.h>
#include <vtkCubeSource.h>
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
#include "vtkAutoInit.h" 

#include "filerec.h"
VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2

VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);


FileREC *pSender = new FileREC();

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
};

class Sphere
{
public:
	Sphere(float x, float y, float z, float r) :m_x(x), m_y(y), m_z(z), m_r(r)
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
//callback_vtk
class vtkTimerCallback2 : public vtkCommand
{
public:
	static vtkTimerCallback2 *New()
	{
		vtkTimerCallback2 *cb = new vtkTimerCallback2;
		cb->TimerCount = 0;
		return cb;
	}

	virtual void Execute(vtkObject *caller, unsigned long eventId,
		void * vtkNotUsed(callData))
	{
		if (vtkCommand::TimerEvent == eventId)
		{
			++this->TimerCount;
		}
		//std::cout << this->TimerCount << std::endl;
		actor_wrist_R->SetPosition(m_x_10, m_y_10, m_z_10);
		actor_elbow_R->SetPosition(m_x_09, m_y_09, m_z_09);
		actor_wrist_L->SetPosition(m_x_06, m_y_06, m_z_06);
		actor_elbow_L->SetPosition(m_x_05, m_y_05, m_z_05);
		//==test==
		if (pSender->record().empty())
		{
			std::cout << "wait for data" << std::endl;
		}
		else
		{
			if (pSender->record()[10].TrackingState == 2)
			{
				m_x_10 = pSender->record()[10].Position.X * 1000;
				m_y_10 = pSender->record()[10].Position.Y * 1000;
				m_z_10 = pSender->record()[10].Position.Z * 1000;
			}
			if (pSender->record()[9].TrackingState == 2)
			{
				m_x_09 = pSender->record()[9].Position.X * 1000;
				m_y_09 = pSender->record()[9].Position.Y * 1000;
				m_z_09 = pSender->record()[9].Position.Z * 1000;
			}
			if (pSender->record()[6].TrackingState == 2)
			{
				m_x_06 = pSender->record()[6].Position.X * 1000;
				m_y_06 = pSender->record()[6].Position.Y * 1000;
				m_z_06 = pSender->record()[6].Position.Z * 1000;
			}
			if (pSender->record()[5].TrackingState == 2)
			{
				m_x_05 = pSender->record()[5].Position.X * 1000;
				m_y_05 = pSender->record()[5].Position.Y * 1000;
				m_z_05 = pSender->record()[5].Position.Z * 1000;
			}


		}
		//std::cout << x << "," << y << "," << z << endl;
		vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::SafeDownCast(caller);
		iren->GetRenderWindow()->Render();
	}

private:
	int TimerCount;
	float m_x_10{  }, m_y_10{  }, m_z_10{  };//wrist_R
	float m_x_09{  }, m_y_09{  }, m_z_09{  };//elbow_R
	float m_x_06{  }, m_y_06{  }, m_z_06{  };//wrist_L
	float m_x_05{  }, m_y_05{  }, m_z_05{  };//elbow_L

public:
	//Right forearm and hand
	vtkSmartPointer<vtkActor> actor_wrist_R;
	vtkSmartPointer<vtkActor> actor_elbow_R;
	vtkSmartPointer<vtkActor> actor_wrist_L;
	vtkSmartPointer<vtkActor> actor_elbow_L;
};

int ballrenderer()
{
	// Create a sphere
	//++++++
	Sphere wrist_R(-100, 0, 600, 30);
	Sphere wrist_L( 100, 0, 600, 30);
	Sphere elbow_R(-50, 0, 600, 30);
	Sphere elbow_L( 50, 0, 600, 30);
	//++++++
	//==以下内容已封装入Sphere中=======================
	//vtkSmartPointer<vtkSphereSource> sphereSource =
	//	vtkSmartPointer<vtkSphereSource>::New();
	//sphereSource->SetCenter(0, 0, 600);
	//sphereSource->SetRadius(30);
	//sphereSource->Update();

	// Create a box for camera
	vtkSmartPointer<vtkCubeSource> cameraSource =
		vtkSmartPointer<vtkCubeSource>::New();
	cameraSource->SetCenter(0, 0, -30);
	cameraSource->SetXLength(150.0);
	cameraSource->SetYLength(60.0);
	cameraSource->SetZLength(60.0);
	cameraSource->Update();

	// Create a mapper and actor
	//vtkSmartPointer<vtkPolyDataMapper> mapper_sphere =
	//	vtkSmartPointer<vtkPolyDataMapper>::New();
	vtkSmartPointer<vtkPolyDataMapper> mapper_camera =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	//mapper_sphere->SetInputConnection(sphereSource->GetOutputPort());
	mapper_camera->SetInputConnection(cameraSource->GetOutputPort());
	//vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
	vtkSmartPointer<vtkActor> actor_camera = vtkSmartPointer<vtkActor>::New();
	//actor->SetMapper(mapper_sphere);
	actor_camera->SetMapper(mapper_camera);

	// Create a renderer, render window, and interactor
	vtkSmartPointer<vtkRenderer> renderer =
		vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkRenderWindow> renderWindow =
		vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->AddRenderer(renderer);
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
		vtkSmartPointer<vtkRenderWindowInteractor>::New();
	renderWindowInteractor->SetRenderWindow(renderWindow);

	

	// Add the actor to the scene
	//++++++
	renderer->AddActor(wrist_R.Actor());
	renderer->AddActor(wrist_L.Actor());
	renderer->AddActor(elbow_R.Actor());
	renderer->AddActor(elbow_L.Actor());
	//++++++
	renderer->AddActor(actor_camera);
	//画坐标轴
	vtkSmartPointer<vtkAxesActor> axes =
		vtkSmartPointer<vtkAxesActor>::New();
	axes->SetPosition(0, 0, 0);
	axes->SetTotalLength(150, 150, 150);
	renderer->AddActor(axes);
	renderer->ResetCamera();

	renderer->SetBackground(.1, .2, .3); // Background color white

	// Render and interact
	renderWindow->Render();

	// Initialize must be called prior to creating timer events.
	renderWindowInteractor->Initialize();

	// Sign up to receive TimerEvent
	vtkSmartPointer<vtkTimerCallback2> cb =
		vtkSmartPointer<vtkTimerCallback2>::New();
	//++++++
	cb->actor_wrist_R = wrist_R.Actor();
	cb->actor_wrist_L = wrist_L.Actor();
	cb->actor_elbow_R = elbow_R.Actor();
	cb->actor_elbow_L = elbow_L.Actor();
	//++++++
	renderWindowInteractor->AddObserver(vtkCommand::TimerEvent, cb);

	int timerId = renderWindowInteractor->CreateRepeatingTimer(33);
	//std::cout << "timerId: " << timerId << std::endl;
	

	// Start the interaction and timer
	renderWindowInteractor->Start();

	return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
	//3d渲染
	std::thread rendtheBall(ballrenderer);
	rendtheBall.detach();
	
	
	//窗口界面
	QApplication a(argc, argv);
	//QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312")); //设置编码
	
	MainWindow w;
	ImageWindow iw;
	if (iw.exec() == QDialog::Accepted) {
		w.show();
		return a.exec();
	}
	
	else return 0;
}
