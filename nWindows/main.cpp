#include "mainwindow.h"
#include "imagewindow.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>
#include <thread>
#include <array>
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

#include "filerec.h"
VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2

VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);

//from extern 
FileREC *pSender = new FileREC();
int jointSelected;
float force ;
float bodyWeight;
float bagX ;
float bagY ;
float bagZ ;
bool bag ;

//extern
extern float F_spinebase;
extern Eigen::Vector3f M_spinebase;

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
	Arrow( float TipLength) : m_TipLength(TipLength)
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
	Sphere(float r,char color) : m_r(r)
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

	float m_r{30};
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
		//actor_wrist_R->SetPosition   (m_X[10], m_Y[10], m_Z[10]);


		for (int i = 0; i < 25; i++)
		{
			if (actor_joints[i]!= NULL)
			{
				updatePosition(i);
			}
			
			
		}

		if (actor_arrow != NULL)
		{
			actor_arrow->SetPosition(m_fx, m_fy, m_fz);
		}

		for (int i = 0; i < 13; i++)
		{
			if (actor_COMs[i] != NULL)
			{
				updateCOMPosition(i);
			}
		}

		//==test==
		if (pSender->jointPositions().empty()||pSender->segCOMs().empty())
		{
			//std::cout << "wait for data" << std::endl;
		}
		else
		{
			for (int i = 0; i < 25; i++)
			{
				updateXYZ(i);
			}
			
			for (int i = 0; i < 13; i++) {
				updateCOMXYZ(i);
			}

			//updateForcePosition
			if (bag)
			{
				m_fx = pSender->jointPositions()[1].Position.X * 1000 + bagX;
				m_fy = pSender->jointPositions()[1].Position.Y * 1000 + bagY;
				m_fz = pSender->jointPositions()[1].Position.Z * 1000 + bagZ;
				calcSpinebaseFMwithBag();
			}
			else
			{
				m_fx = pSender->jointPositions()[jointSelected].Position.X * 1000;
				m_fy = pSender->jointPositions()[jointSelected].Position.Y * 1000;
				m_fz = pSender->jointPositions()[jointSelected].Position.Z * 1000;
			}
			


		}
		//std::cout << x << "," << y << "," << z << endl;
		vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::SafeDownCast(caller);
		iren->GetRenderWindow()->Render();
	}

private:
	int TimerCount;

	std::array<float, 25> m_X{0};
	std::array<float, 25> m_Y{0};
	std::array<float, 25> m_Z{1500};
	//float m_COM_x{0}, m_COM_y{0}, m_COM_z{1500};
	std::array<float, 13> m_COM_x{ 0 };
	std::array<float, 13> m_COM_y{ 0 };
	std::array<float, 13> m_COM_z{ 0 };
	std::array<Eigen::Vector3f, 13> m_COMs{ };
	float m_fx, m_fy, m_fz;

	void updateXYZ(int jointNumber) {
		if (pSender->jointPositions()[jointNumber].TrackingState == 2)
		{
			m_X[jointNumber] = pSender->jointPositions()[jointNumber].Position.X * 1000;
			m_Y[jointNumber] = pSender->jointPositions()[jointNumber].Position.Y * 1000;
			m_Z[jointNumber] = pSender->jointPositions()[jointNumber].Position.Z * 1000;
		}
	}
	void updateCOMXYZ(int segNumber) {
		m_COM_x[segNumber] = pSender->segCOMs()[segNumber].x() * 1000;
		m_COM_y[segNumber] = pSender->segCOMs()[segNumber].y() * 1000;
		m_COM_z[segNumber] = pSender->segCOMs()[segNumber].z() * 1000;
		m_COMs[segNumber] =  pSender->segCOMs()[segNumber];
	}



	


public:
	////Right arm and hand
	//vtkSmartPointer<vtkActor> actor_wrist_R;
	//vtkSmartPointer<vtkActor> actor_elbow_R;
	//vtkSmartPointer<vtkActor> actor_shoulder_R;
	////Left arm and hand
	//vtkSmartPointer<vtkActor> actor_wrist_L;
	//vtkSmartPointer<vtkActor> actor_elbow_L;
	//vtkSmartPointer<vtkActor> actor_shoulder_L;
	////spine
	//vtkSmartPointer<vtkActor> actor_spinebase;
	//vtkSmartPointer<vtkActor> actor_spineShoulder;
	//+++
	std::array<vtkSmartPointer<vtkActor>, 25> actor_joints{};
	std::array<vtkSmartPointer<vtkActor>, 13> actor_COMs{};
	vtkSmartPointer<vtkActor> actor_arrow;
	//+++
	void updatePosition(int jointNumber) {
		actor_joints[jointNumber]->SetPosition(m_X[jointNumber], m_Y[jointNumber], m_Z[jointNumber]);
	}
	void updateCOMPosition(int segNumber) {
		actor_COMs[segNumber]->SetPosition(m_COM_x[segNumber], m_COM_y[segNumber], m_COM_z[segNumber]);
	}

	void calcSpinebaseFMwithBag() {
		F_spinebase = bodyWeight * (0.081 + 0.142 + 0.355 + 0.028 * 2 + 0.022 * 2)*9.8 + force *9.8;
		
		Eigen::Vector3f thigh_M(0, 0, -0.1*9.8 *bodyWeight), shank_M(0, 0, -0.0465*9.8 *bodyWeight), foot_M(0, 0, -0.0145*9.8 *bodyWeight),
			upperArm_M(0, 0, -0.028 *9.8 *bodyWeight), fArmhand_M(0, 0, -0.022*9.8 *bodyWeight), Pelvis_M(0, 0, -0.142*9.8 *bodyWeight), ThoraxAbdomen_M(0, 0, -0.355*9.8 *bodyWeight),
			Headneck_M(0, 0, -0.081*9.8 *bodyWeight);
		Eigen::Vector3f fPosition(m_fx/1000, m_fy/1000, m_fz/1000);
		Eigen::Vector3f vforce(0, 0, -force * 9.8);
		Eigen::Vector3f spinebaseXYZ(m_X[0]/1000, m_Y[0]/1000, m_Z[0]/1000);
		M_spinebase = ((m_COMs[6]- spinebaseXYZ).cross(upperArm_M)+ (m_COMs[7] - spinebaseXYZ).cross(upperArm_M)
			+ (m_COMs[8] - spinebaseXYZ).cross(fArmhand_M) + (m_COMs[9] - spinebaseXYZ).cross(fArmhand_M)
			+ (m_COMs[10] - spinebaseXYZ).cross(Pelvis_M) + (m_COMs[11] - spinebaseXYZ).cross(ThoraxAbdomen_M)
			+ (m_COMs[12] - spinebaseXYZ).cross(Headneck_M)) + (fPosition - spinebaseXYZ).cross(vforce) ;


	}
};

int ballrenderer()
{
	// Create a sphere
	//++++++
	//Sphere wrist_R(-100, 0, 1000, 30);
	//Sphere wrist_L( 100, 0, 1000, 30);
	//Sphere elbow_R(-50, 0, 1000, 30);
	//Sphere elbow_L( 50, 0, 1000, 30);
	//Sphere shoulder_R(-10, 0, 1000, 30);
	//Sphere shoulder_L( 10, 0, 1000, 30);
	//Sphere spinebase(0, -100, 1000, 50);
	//Sphere spineShoulder(0,0, 1000, 50);
	//++++++
	Arrow arrow;
	std::array<Sphere, 13> COMSphere;
	std::array<Sphere, 25> jointsSphere;

	//com 为红色
	for (int i = 0; i < 13; i++)
	{
		COMSphere[i].Actor()->GetProperty()->SetColor(1, 0, 0);
	}
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
	renderWindow->SetSize(900, 600);

	//相机设置
	vtkSmartPointer<vtkCamera>myCamera = vtkSmartPointer<vtkCamera>::New();
	myCamera->SetClippingRange(0.0475, 2.3786); //这些值随便设置的，为了演示用法而已
	myCamera->SetFocalPoint(0.0573, -0.2134, -0.0523);
	myCamera->SetPosition(0.3245, -0.1139, -0.2932);
	myCamera->ComputeViewPlaneNormal();
	myCamera->SetViewUp(-0.2234, 0.9983, 0.0345);
	renderer->SetActiveCamera(myCamera);
	
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
		vtkSmartPointer<vtkRenderWindowInteractor>::New();
	renderWindowInteractor->SetRenderWindow(renderWindow);
	
	

	// Add the actor to the scene
	//++++++
	//exp:renderer->AddActor(wrist_R.Actor());

	renderer->AddActor(arrow.Actor());
	//renderer->AddActor(rArmCOM.Actor());
	for (int i = 0; i < 13; i++)
	{
		renderer->AddActor(COMSphere[i].Actor());
	}
	for (int i = 0; i < 25; i++)
	{
		renderer->AddActor(jointsSphere[i].Actor());
	}

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
	//exp:cb->actor_wrist_R = wrist_R.Actor();
	//	  cb->actor_wrist_L = wrist_L.Actor();
	//	  cb->actor_elbow_R = elbow_R.Actor();
	cb->actor_arrow = arrow.Actor();
	//cb->actor_rArmCOM = rArmCOM.Actor();
	for (int i = 0; i < 13; i++)
	{
		cb->actor_COMs[i] = COMSphere[i].Actor();
	}
	for (int i = 0; i < 25; i++)
	{
		cb->actor_joints[i] = jointsSphere[i].Actor();
	}
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
