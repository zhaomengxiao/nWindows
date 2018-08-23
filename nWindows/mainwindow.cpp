#include "mainwindow.h"
//a function that turn cvMat file into QImage
QImage  Mat2QImage(cv::Mat cvImg);
//组装区
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//顯示中文亂碼解決實例
	ui.pushButton->setText(QString::fromLocal8Bit("显示图片"));
	
	//设置背景色
	this->setStyleSheet("background-color:#464652;color:#E8E8E8");
	//this->setStyleSheet("");
	//建立菜单步骤
	/****************************************

	* Qt中创建菜单和工具栏需要如下步骤：

	* 1. 建立行为Aciton

	* 2. 创建菜单并使它与一个行为关联

	* 3. 创建工具条并使它与一个行为关联

	*****************************************/
	createAction();
	createMenu();
	connectSignalSlot();
	
	
	
	
}



/*------------------------------------------*
******----------界面function-------------****
*------------------------------------------*/

//新建多个action
void MainWindow::createAction()
{
	//打开图片
	fileOpenImage = new QAction(this);
	fileOpenImage->setText(QString::fromLocal8Bit("打开图片"));
	fileOpenImage->setStatusTip("open a picture from file.");
	fileOpenImage->setShortcut(QKeySequence("Ctrl+8")); //随意指定快捷方式
	QIcon openImageIcon(":/myimages/Resources/Filenew.png");
	fileOpenImage->setIcon(openImageIcon);													//ui.mainToolBar->addAction(fileOpenImage);           //工具条
	//打开视频
	fileOpenVedio = new QAction(this);
	fileOpenVedio->setText(QString::fromLocal8Bit("打开视频"));
	fileOpenVedio->setStatusTip("open a video from camera.");
	fileOpenVedio->setShortcut(QKeySequence("Ctrl+9")); //随意指定快捷方式
	QIcon opencameraIcon(":/myimages/Resources/camera.png");
	fileOpenVedio->setIcon(opencameraIcon);
	//显示骨骼
	showSkeleton = new QAction(this);
	showSkeleton->setText(QString::fromLocal8Bit("显示骨骼"));
	showSkeleton->setStatusTip("show basic skeleton.");
	showSkeleton->setShortcut(QKeySequence("Ctrl+1")); //随意指定快捷方式
	QIcon showskeletonIcon(":/myimages/Resources/camera.png");
	showSkeleton->setIcon(showskeletonIcon);

}

//把建立好的action添加到Menu中
void MainWindow::createMenu()
{
	
	fileMenu = menuBar()->addMenu(QString::fromLocal8Bit("文件"));

	fileMenu->addAction(fileOpenImage);
	fileMenu->addAction(fileOpenVedio);

	fileMenu = menuBar()->addMenu(QString::fromLocal8Bit("动作捕捉"));
	fileMenu->addAction(showSkeleton);
	
}

//链接信号和槽
void MainWindow::connectSignalSlot()
{

	connect(fileOpenImage, SIGNAL(triggered()), 
		this, SLOT(fileOpenImage_clicked()));
	connect(fileOpenVedio, SIGNAL(triggered()),
		this, SLOT(fileOpenVedio_clicked()));
	connect(showSkeleton, SIGNAL(triggered()),
		this, SLOT(showSkeleton_clicked()));


	videotimer = new QTimer;
	connect(videotimer, SIGNAL(timeout()),this,SLOT(updateVideoFrame()));
	skeletontimer = new QTimer;
	connect(skeletontimer, SIGNAL(timeout()), this, SLOT(updateSkeletonFrame()));
	
	connect(ui.saveImageButton, SIGNAL(clicked()),
		this, SLOT(on_saveImageButton_clicked()));
}




/*------------------------------------------*
******----------功能function-------------****
*------------------------------------------*/

//功能1.从文件夹页面选择图像打开
void MainWindow::fileOpenImage_clicked()
{
	//定义文件对话框类
	QFileDialog *fileDialog = new QFileDialog(this);

	//定义文件对话框标题
	fileDialog->setWindowTitle(QString::fromLocal8Bit("打开图片"));

	//设置默认文件路径
	fileDialog->setDirectory(".");

	//设置文件过滤器
	fileDialog->setNameFilter(tr("Images(*.png *.jpg *.jpeg *.bmp)"));

	//设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
	fileDialog->setFileMode(QFileDialog::ExistingFiles);

	//设置视图模式
	fileDialog->setViewMode(QFileDialog::Detail);

	//打印所有选择的文件的路径
	QStringList fileNames;

	if (fileDialog->exec())
	{
		fileNames = fileDialog->selectedFiles();
	}

	for (auto tmp: fileNames) {
		qDebug() << tmp << endl;
		//show image
		//Qstring 转为char* 才能喂给cv::imread
		image = cv::imread(tmp.toStdString().data());
		QImage qImage = Mat2QImage(image);

		ui.colorwindow->setPixmap(QPixmap::fromImage(qImage));

	}
		
		
}

//功能2.从文件夹选择视频打开

//功能3.从摄像头获得图像
void MainWindow::fileOpenVedio_clicked()
{
	QMessageBox *massage = new QMessageBox(this);
	massage->setWindowFlag(Qt::FramelessWindowHint);
	massage->setWindowTitle("vedio");
	massage->setText(QString::fromLocal8Bit("注意！您将打开摄像头"));
	QIcon ok(":/myimages/Resources/checkcircle.png");
	//massage->setDefaultButton(icon)
	QPushButton *ok_button = new QPushButton(massage);
	ok_button->setIcon(ok);
	ok_button->setFlat(true);
	massage->addButton(ok_button, QMessageBox::AcceptRole);
	
	massage->setIconPixmap(QPixmap(":/myimages/Resources/warningcirclered.png").scaled(40,40));	 /*Qpixmap可以用scale调整大小*/
	massage->exec();
	//新建一个窗口
	QDialog *vediowindow = new QDialog(this);
	//vediowindow->setWindowFlag(f);
	//显示影像的label
	QLabel *showdepthimage_label = new QLabel(this);
	QLabel *showcolorimage_label = new QLabel(this);
	showdepthimage_label->setText(QString::fromLocal8Bit("打开摄像头"));
	showcolorimage_label->setText(QString::fromLocal8Bit("关闭摄像头"));

	//操作影像的按钮
	QPushButton *opencamera_button  = new QPushButton(this);
	QPushButton *closecamera_button = new QPushButton(this);
	//opencamera->setText(QString::fromLocal8Bit("打开摄像头"));
	QIcon opencameraIcon(":/myimages/Resources/camera.png");
	opencamera_button->setIcon(opencameraIcon);
	//closecamera->setText(QString::fromLocal8Bit("关闭摄像头"));
	QIcon closecameraIcon(":/myimages/Resources/poweroff.png");
	closecamera_button->setIcon(closecameraIcon);
	//去掉按钮边框
	opencamera_button->setFlat(true);
	closecamera_button->setFlat(true);
	//链接按钮
	connect(opencamera_button, SIGNAL(clicked()), this, SLOT(startCamera()));
	connect(closecamera_button, SIGNAL(clicked()), this, SLOT(stopCamera()));
	
	//opencamera->show();
	//layout管理
	QVBoxLayout *mainLayout = new QVBoxLayout;
	QHBoxLayout *imageLayout = new QHBoxLayout;
	QHBoxLayout *buttonLayout = new QHBoxLayout;

	vediowindow->setLayout(mainLayout);
	
	mainLayout->addLayout(buttonLayout);
	mainLayout->addLayout(imageLayout);

	buttonLayout->addWidget(opencamera_button);
	buttonLayout->addWidget(closecamera_button);
	imageLayout->addWidget(showdepthimage_label);
	imageLayout->addWidget(showcolorimage_label);
	
	vediowindow->show();
	
	myCamera = new camera();
	myCamera->openCamera(); // 打开摄像头，从摄像头中获取视频
	myCamera->createStream();//打开视频流
	videotimer->start(30);// 开始计时，超时则发出timeout()信号
	

}
//功能4.显示骨骼
void MainWindow::showSkeleton_clicked()
{
	mykinect = new myKinect();
	
	HRESULT hr = mykinect->InitializeDefaultSensor();
	if (SUCCEEDED(hr)) {
		skeletontimer->start(60);// 开始计时，超时则发出timeout()信号
	}
	else {
		std::cout << "kinect initialization failed!" << std::endl;
		system("pause");
	}

}
//更新视频帧
void MainWindow::updateVideoFrame()
{

	myCamera->showImage();
	//ui.label->setPixmap(QPixmap::fromImage(myCamera->colorImage));
	ui.colorwindow->setPixmap(QPixmap::fromImage(myCamera->colorImage));
	ui.depthwindow->setPixmap(QPixmap::fromImage(myCamera->depthImage));
	//this->showcolorimage_label->setPixmap(QPixmap::fromImage(myCamera->colorImage));
	//this->showdepthimage_label->setPixmap(QPixmap::fromImage(myCamera->depthImage));
}
//更新骨骼帧
void MainWindow::updateSkeletonFrame()
{
	mykinect->Update();
	mykinect->getDepthImg();
	mykinect->getSkeletonImg();
	QImage qdepthImage    = Mat2QImage(mykinect->getDepthImg());
	QImage qskeletonImage = Mat2QImage(mykinect->getSkeletonImg());
	//ui.label->setPixmap(QPixmap::fromImage(myCamera->colorImage));
	ui.colorwindow->setPixmap(QPixmap::fromImage(qskeletonImage));
	ui.depthwindow->setPixmap(QPixmap::fromImage(qdepthImage));
	//this->showcolorimage_label->setPixmap(QPixmap::fromImage(myCamera->colorImage));
	//this->showdepthimage_label->setPixmap(QPixmap::fromImage(myCamera->depthImage));
}

void MainWindow::stopCamera()
{
	videotimer->stop();
	myCamera->closeCamera();
}

void MainWindow::startCamera()
{
	myCamera = new camera();
	myCamera->openCamera(); // 打开摄像头，从摄像头中获取视频
	myCamera->createStream();//打开视频流
	videotimer->start(30);// 开始计时，超时则发出timeout()信号
}
//保存图片
void MainWindow::on_saveImageButton_clicked()
{
	//std::string imagepath = tmp.toStdString().data();
	cv::imwrite("E:/backremoved.png", backmoveimage);
}





//预留按钮
void MainWindow::on_pushButton_clicked()
{
	//去背
	//image = cv::imread("E:\\learnOpenCV\\learnopencv-master\\learnopencv-master\\OpenPose\\example\\x64\\Release\\single.jpeg");
	//QImage qImage = Mat2QImage(image);

	//ui.colorwindow->setPixmap(QPixmap::fromImage(qImage));
	//cv::Mat backmoveimage(image);
	image.copyTo(backmoveimage);
	for (int row =0; row < backmoveimage.rows; row++) {
		for (int col=0; col < backmoveimage.cols; col++)
		{
			if(row !=0 && col !=0){
//				if (backmoveimage.at<cv::Vec3b>(1, 1)[0]-rand[0] <= backmoveimage.at<cv::Vec3b>(row, col)[0] && backmoveimage.at<cv::Vec3b>(row, col)[0] <= backmoveimage.at<cv::Vec3b>(1, 1)[0] + rand[0] &&
//					backmoveimage.at<cv::Vec3b>(1, 1)[1]-rand[1] <= backmoveimage.at<cv::Vec3b>(row, col)[1] && backmoveimage.at<cv::Vec3b>(row, col)[1] <= backmoveimage.at<cv::Vec3b>(1, 1)[1] + rand[1] &&
//					backmoveimage.at<cv::Vec3b>(1, 1)[2]-rand[2] <= backmoveimage.at<cv::Vec3b>(row, col)[2] && backmoveimage.at<cv::Vec3b>(row, col)[2] <= backmoveimage.at<cv::Vec3b>(1, 1)[2] + rand[2])
				if( std::abs(backmoveimage.at<cv::Vec3b>(0, 0)[0] - backmoveimage.at<cv::Vec3b>(row, col)[0] ) <= 3 &&
					abs(backmoveimage.at<cv::Vec3b>(0, 0)[1] - backmoveimage.at<cv::Vec3b>(row, col)[1] ) <= 3 &&
					abs(backmoveimage.at<cv::Vec3b>(0, 0)[2] - backmoveimage.at<cv::Vec3b>(row, col)[2] ) <= 3 )
				{
					backmoveimage.at<cv::Vec3b>(row, col)[0] = 0;
					backmoveimage.at<cv::Vec3b>(row, col)[1] = 0;
					backmoveimage.at<cv::Vec3b>(row, col)[2] = 0;
				}
			}
			
			
		}
	}
	cv::imshow("backmove", backmoveimage);
}
//关闭时清理内存使用
MainWindow::~MainWindow()
{
	///!!这里的内存释放still have problem（这是Openni使用Xtion2时的代码）!!(kinect2的内存管理比较好)

	//if(myCamera->isnotclosed()){ myCamera->closeCamera(); }
	//if (myCamera != NULL) {
	//	myCamera->closeCamera();
	//}
}