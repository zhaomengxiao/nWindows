#include "vtkshape.h"

vtkShape::Arrow::Arrow()
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
}

vtkShape::Arrow::Arrow(float TipLength) : m_TipLength(TipLength)
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
}

vtkShape::Arrow::~Arrow()
{
}

vtkSmartPointer<vtkActor> vtkShape::Arrow::Actor()
{
	return actor;
}

vtkShape::Sphere::Sphere()
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
}

vtkShape::Sphere::Sphere(float r, char color) : m_r(r)
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
	else
	{
		actor->GetProperty()->SetColor(0, 0, 0);
		std::cout << "Sphere only can set to rgb,default 000" << std::endl;
	}
	actor->SetPosition(0, 0, 1500);
}

vtkShape::Sphere::~Sphere()
{
}

vtkSmartPointer<vtkActor> vtkShape::Sphere::Actor()
{
	return actor;
}

vtkShape::Camera::Camera()
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
}

vtkShape::Camera::~Camera()
{
}

vtkSmartPointer<vtkActor> vtkShape::Camera::Actor()
{
	return actor;
}

vtkShape::Line::Line()
{
	// Create a line
	lineSource =
		vtkSmartPointer<vtkLineSource>::New();
	lineSource->SetPoint1(1000, 1000, 1000);
	lineSource->SetPoint2(0, 0, 0);
	lineSource->Update();

	//visualize
	vtkSmartPointer<vtkPolyDataMapper> mapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputConnection(lineSource->GetOutputPort());
	actor =
		vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);
	actor->GetProperty()->SetLineWidth(4);
	actor->GetProperty()->SetColor(0, 1, 0);//默认绿色直线
}

vtkShape::Line::Line(float width, char color)
{
	// Create a line
	lineSource =
		vtkSmartPointer<vtkLineSource>::New();
	lineSource->SetPoint1(0, 0, 1000);
	lineSource->SetPoint2(0, 0, 0);
	lineSource->Update();

	//visualize
	vtkSmartPointer<vtkPolyDataMapper> mapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputConnection(lineSource->GetOutputPort());
	vtkSmartPointer<vtkActor> actor =
		vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);
	actor->GetProperty()->SetLineWidth(width);
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
	else
	{
		actor->GetProperty()->SetColor(0, 0, 0);
		std::cout << "Line only can set to rgb,default 000" << std::endl;
	}
}

vtkShape::Line::~Line()
{
}

vtkSmartPointer<vtkActor> vtkShape::Line::Actor()
{
	return actor;
}

vtkSmartPointer<vtkLineSource> vtkShape::Line::LineSource()
{
	return lineSource;
}

vtkShape::Coord::Coord()
{
	// Create 3 line
	lineSource_axisX =
		vtkSmartPointer<vtkLineSource>::New();
	lineSource_axisX->SetPoint1(500, 0, 0);
	lineSource_axisX->SetPoint2(0, 0, 0);
	lineSource_axisX->Update();

	lineSource_axisY =
		vtkSmartPointer<vtkLineSource>::New();
	lineSource_axisY->SetPoint1(0, 500, 0);
	lineSource_axisY->SetPoint2(0, 0, 0);
	lineSource_axisY->Update();

	lineSource_axisZ =
		vtkSmartPointer<vtkLineSource>::New();
	lineSource_axisZ->SetPoint1(0, 0, 500);
	lineSource_axisZ->SetPoint2(0, 0, 0);
	lineSource_axisZ->Update();
	//visualize
	vtkSmartPointer<vtkPolyDataMapper> mapper_x =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper_x->SetInputConnection(lineSource_axisX->GetOutputPort());

	vtkSmartPointer<vtkPolyDataMapper> mapper_y =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper_y->SetInputConnection(lineSource_axisY->GetOutputPort());

	vtkSmartPointer<vtkPolyDataMapper> mapper_z =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper_z->SetInputConnection(lineSource_axisZ->GetOutputPort());

	actor_axisX = vtkSmartPointer<vtkActor>::New();
	actor_axisX->SetMapper(mapper_x);
	actor_axisX->GetProperty()->SetLineWidth(2);
	actor_axisX->GetProperty()->SetColor(1, 0, 0);

	actor_axisY = vtkSmartPointer<vtkActor>::New();
	actor_axisY->SetMapper(mapper_y);
	actor_axisY->GetProperty()->SetLineWidth(2);
	actor_axisY->GetProperty()->SetColor(0, 1, 0);

	actor_axisZ = vtkSmartPointer<vtkActor>::New();
	actor_axisZ->SetMapper(mapper_z);
	actor_axisZ->GetProperty()->SetLineWidth(2);
	actor_axisZ->GetProperty()->SetColor(0, 0, 1);
}

vtkShape::Coord::~Coord()
{
}



vtkSmartPointer<vtkActor> vtkShape::Coord::Actor_axisX()
{
	return actor_axisX;
}

vtkSmartPointer<vtkActor> vtkShape::Coord::Actor_axisY()
{
	return actor_axisY;
}

vtkSmartPointer<vtkActor> vtkShape::Coord::Actor_axisZ()
{
	return actor_axisZ;
}

vtkSmartPointer<vtkLineSource> vtkShape::Coord::LineSource_axisX()
{
	return lineSource_axisX;
}

vtkSmartPointer<vtkLineSource> vtkShape::Coord::LineSource_axisY()
{
	return lineSource_axisY;
}

vtkSmartPointer<vtkLineSource> vtkShape::Coord::LineSource_axisZ()
{
	return lineSource_axisZ;
}
