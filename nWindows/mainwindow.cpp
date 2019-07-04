#include "mainwindow.h"


//a function that turn cvMat file into QImage
QImage  Mat2QImage(cv::Mat cvImg);

//传出区
//===============================
extern FileREC *pSender ;
extern OBJ::CaliInfo *p_optParameters;
extern OBJ::Obj *p_obj;
extern int jointSelected;
extern float force;
extern float bodyWeight;
extern float bagX;
extern float bagY;
extern float bagZ;
extern bool bag;
extern bool isOffMode;
extern int n_frame;//传出滑动条的数值控制三维绘制第几帧
bool isSimpleMode{ false };

//bool isTimeLapseMode{ false };
char* subjName = new char[20];
QString qsubjname{"null"};
//================================
float F_spinebase;
Eigen::Vector3f M_spinebase;


//组装区
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//顯示中文亂碼解決實例
	//ui.pushButton->setText(QString::fromLocal8Bit("显示图片"));
	ui.label_recording->hide();
	ui.progressBar_tl->hide();
	//vtk场景绘制
	//drawVTKscene();
	//ui.qvtkWidget->SetRenderWindow(scene->p_renderWindow);
	std::thread t(&VTK::rend, VTK());
	t.detach();


	//文件预览界面
	//清理测试数据
	ui.treeWidget->clear();
	rootPath = ".\\Record";
	//ui.treeWidget->setColumnCount(3);
	//设置标题，设置四列
	ui.treeWidget->headerItem()->setText(0, QStringLiteral("File Record"));
	ui.treeWidget->headerItem()->setText(1, QStringLiteral("Path"));
	//ui.treeWidget->headerItem()->setText(5, "head4");
	root = new QTreeWidgetItem({ "Record",rootPath });
	ui.treeWidget->addTopLevelItem(root);
	//root->addChild(new QTreeWidgetItem); //加入一个空子节点，以激活展开功能
	////////////////////////////////////////////////////////////////////////////////////////
	allFile(root, rootPath);
	ui.treeWidget->setColumnWidth(0, 400);
	ui.LCDwidget->hide();
	//设置背景色
	//this->setStyleSheet("background-color:#464652;color:#E8E8E8");
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
	
	//显示系统时间
	lcdtimer->setInterval(1000);
	lcdtimer->start();
	rectimer->setInterval(1000);
	//延时摄影时间
	lapsetimer->setInterval(20000);
	
	//初始化pSender 放入thread
	pSender->filetimer = new QTimer(this);
	thread = new QThread(this);
	pSender->moveToThread(thread);
	
	thread->start();
}



/*------------------------------------------*
******----------界面function-------------****
*------------------------------------------*/

//新建多个action
void MainWindow::createAction()
{
	//打开图片
	fileOpenImage = new QAction(this);
	fileOpenImage->setText("Image");
	fileOpenImage->setStatusTip("open a picture from file.");
	fileOpenImage->setShortcut(QKeySequence("Ctrl+8")); //随意指定快捷方式
	QIcon openImageIcon(":/myimages/Resources/Filenew.png");
	fileOpenImage->setIcon(openImageIcon);													//ui.mainToolBar->addAction(fileOpenImage);           //工具条
	//打开视频
	fileOpenVedio = new QAction(this);
	fileOpenVedio->setText("Vedio");
	fileOpenVedio->setStatusTip("open a video from camera.");
	fileOpenVedio->setShortcut(QKeySequence("Ctrl+9")); //随意指定快捷方式
	QIcon opencameraIcon(":/myimages/Resources/camera.png");
	fileOpenVedio->setIcon(opencameraIcon);
	//显示骨骼
	showSkeleton = new QAction(this);
	showSkeleton->setText("Open camera");
	showSkeleton->setStatusTip("show 2d and vtk3d skeleton.");
	showSkeleton->setShortcut(QKeySequence("Ctrl+1")); //随意指定快捷方式
	QIcon showskeletonIcon(":/myimages/Resources/camera.png");
	showSkeleton->setIcon(showskeletonIcon);

}

//把建立好的action添加到Menu中
void MainWindow::createMenu()
{
	
	fileMenu = menuBar()->addMenu("file");

	fileMenu->addAction(fileOpenImage);
	fileMenu->addAction(fileOpenVedio);

	fileMenu = menuBar()->addMenu("MotionCap");
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
	
	lcdtimer = new QTimer;
	connect(lcdtimer, SIGNAL(timeout()), this, SLOT(updateLCDnumber_date()));
	
	rectimer = new QTimer;
	connect(rectimer, SIGNAL(timeout()), this, SLOT(updateLCDnumber_RecTime()));
	lapsetimer = new QTimer;
	connect(lapsetimer, SIGNAL(timeout()), this, SLOT(oneLapse()));
	connect(pSender, SIGNAL(Error_openfile()), this, SLOT(error_openfile()));
	connect(pSender, SIGNAL(ReadFileProgress(int)), this, SLOT(readFileProgress(int)));
}

//int MainWindow::drawVTKscene()
//{
//
//	return 0;
//}




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
		skeletontimer->start(120);// 开始计时，超时则发出timeout()信号
	
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
	//ui.depthwindow->setPixmap(QPixmap::fromImage(myCamera->depthImage));
	//this->showcolorimage_label->setPixmap(QPixmap::fromImage(myCamera->colorImage));
	//this->showdepthimage_label->setPixmap(QPixmap::fromImage(myCamera->depthImage));
}
//===============test 存储关节数据=================================

//更新骨骼帧
void MainWindow::updateSkeletonFrame()
{
	mykinect->Update();
	QImage qdepthImage    = Mat2QImage(mykinect->getDepthImg());
	QImage qskeletonImage = Mat2QImage(mykinect->getSkeletonImg());
	
	ui.colorwindow->setPixmap(QPixmap::fromImage(qskeletonImage));
	if (pSender !=NULL)
	{
		//把资料传到fierec类中储存并进行后续处理
		pSender->updateJoints(mykinect->joints);
		pSender->updateSegCOM(mykinect->segCOMs);	
	}
}

void MainWindow::updateLCDnumber_date()
{
	// 获取系统当前时间
	QDateTime dateTime = QDateTime::currentDateTime();
	// 设置能显示的位数
	ui.lcdNumber_date->setDigitCount(25);
	// 设置显示的模式为十进制
	ui.lcdNumber_date->setMode(QLCDNumber::Dec);
	// 设置显示外观
	ui.lcdNumber_date->setSegmentStyle(QLCDNumber::Flat);
	// 设置样式
	ui.lcdNumber_date->setStyleSheet("border: 1px solid green; color: black; background: silver;");
	// 显示的内容
	ui.lcdNumber_date->display(dateTime.toString("yyyy-MM-dd HH:mm:ss"));
}
void MainWindow::updateLCDnumber_RecTime()
{
	recTime++;
	ui.lcdNumber_RecTime->display(recTime);
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

//绘制曲线图
//void MainWindow::on_pushButton_openrecord_clicked()
//{
//	//画折线
//	///x
//	/*QGraphicsScene scene_x;
//	QSplineSeries *series_x = new QSplineSeries();
//	
//	series_x->setName("spline");
//	series_x->append(0, 13);
//	series_x->append(2, 18);
//	series_x->append(3, 20);
//	series_x->append(7, 60);
//	series_x->append(10, 50);
//	*series_x << QPointF(11, 10) << QPointF(13, 30) << QPointF(17, 60) << QPointF(18, 30) << QPointF(20, 20);
//	QChart *chart_x = new QChart();
//	chart_x->legend()->hide();
//	chart_x->addSeries(series_x);
//	chart_x->setTitle("x");
//	chart_x->createDefaultAxes();
//	chart_x->axisY()->setRange(10, 80);
//	
//	QChartView *mychartview_x = new QChartView();
//	mychartview_x->setChart(chart_x);
//	mychartview_x->setRenderHint(QPainter::Antialiasing);
//	mychartview_x->chart()->setTheme(QChart::ChartThemeBrownSand);
//	series_x->setPen(QPen(Qt::red, 1, Qt::SolidLine));
//	ui.chartscrollArea->setWidget(mychartview_x);
//	///y
//	QGraphicsScene scene_y;
//	QSplineSeries *series_y = new QSplineSeries();
//	
//	series_y->setName("spline");
//	series_y->append(0, 6);
//	series_y->append(2, 4);
//	series_y->append(3, 8);
//	series_y->append(7, 4);
//	series_y->append(10, 5);
//	*series_y << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
//	QChart *chart_y = new QChart();
//	chart_y->legend()->hide();
//	chart_y->addSeries(series_y);
//	chart_y->setTitle("y");
//	chart_y->createDefaultAxes();
//	chart_y->axisY()->setRange(0, 10);
//
//	QChartView *mychartview_y = new QChartView();
//	mychartview_y->setChart(chart_y);
//	mychartview_y->setRenderHint(QPainter::Antialiasing);
//	mychartview_y->chart()->setTheme(QChart::ChartThemeBrownSand);
//	series_y->setPen(QPen(Qt::green, 1, Qt::SolidLine));
//	ui.chartscrollArea_2->setWidget(mychartview_y);
//	///z
//	QGraphicsScene scene_z;
//	QSplineSeries *series_z = new QSplineSeries();
//	
//	series_z->setName("z");
//	series_z->append(0, 140);
//	series_z->append(2, 145);
//	series_z->append(3, 180);
//	series_z->append(7, 150);
//	series_z->append(10, 160);
//	*series_z << QPointF(11, 160) << QPointF(13, 130) << QPointF(17, 120) << QPointF(18, 100) << QPointF(20, 80);
//	QChart *chart_z = new QChart();
//	chart_z->legend()->hide();
//	chart_z->addSeries(series_z);
//	chart_z->setTitle("z");
//	chart_z->createDefaultAxes();
//	chart_z->axisY()->setRange(70, 180);
//
//	QChartView *mychartview_z = new QChartView();
//	mychartview_z->setChart(chart_z);
//	mychartview_z->setRenderHint(QPainter::Antialiasing);
//	mychartview_z->chart()->setTheme(QChart::ChartThemeBrownSand);
//	series_z->setPen(QPen(Qt::blue, 1, Qt::SolidLine));
//	ui.chartscrollArea_3->setWidget(mychartview_z);*/
//
//	//选择要打开的文件
//		//定义文件对话框类
//	QFileDialog *fileDialog = new QFileDialog(this);
//
//	//定义文件对话框标题
//	fileDialog->setWindowTitle("Select the file");
//
//	//设置默认文件路径
//	//fileDialog->setDirectory(".");
//
//	//设置文件过滤器
//	fileDialog->setNameFilter(tr("file(*.csv *.txt )"));
//
//	//设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
//	fileDialog->setFileMode(QFileDialog::ExistingFiles);
//
//	//设置视图模式
//	fileDialog->setViewMode(QFileDialog::Detail);
//
//	//打印所有选择的文件的路径
//	
//	QStringList fileNames;
//
//	if (fileDialog->exec())
//	{
//		fileNames = fileDialog->selectedFiles();
//	}
//	//qDebug() << fileNames[0] << endl;
//	/*for (auto tmp : fileNames) {
//		qDebug() << tmp << endl;
//
//	}*/
//	//=====read file=====
//	std::vector<double> frames;
//	std::vector<double> X,Y,Z;
//	QFile jointPosition("./jointsPosition.csv");
//	if (!jointPosition.open(QIODevice::ReadOnly )) {
//		qDebug() << "cant read joint file" << endl;
//	}
//
//	QTextStream stream(&jointPosition);
//	while (!stream.atEnd())
//	{
//		QString line = stream.readLine();
//		if (line.startsWith("#"))
//		{
//			continue;
//		}
//		
//		QStringList values = line.split(",", QString::SkipEmptyParts);
//		if (values[2].toInt() == 4)/*选择要画图的节点*/
//		{
//			frames.push_back(values[0].toDouble());
//			X.push_back(values[4].toDouble());
//			Y.push_back(values[5].toDouble());
//			Z.push_back(values[6].toDouble());
//		}
//		
//	}
//	/*std::vector<double> X{ 0,1,2,3,4 };
//	std::vector<double> Y{ 0,1,2,3,4 };*/
//	LineChart *chart_x = new LineChart();
//	chart_x->SetXY(frames, X);
//	chart_x->setTitle("Position_X");
//	chart_x->legend()->hide();
//	chart_x->setAnimationOptions(QChart::AllAnimations);
//	QChartView *mychartview = new QChartView();
//	mychartview->setChart(chart_x);
//	mychartview->setRenderHint(QPainter::Antialiasing);
//	ui.chartscrollArea->setWidget(mychartview);
//
	
//
//	LineChart *chart_z = new LineChart();
//	chart_z->SetXY(frames, Z);
//	chart_z->setTitle("Position_Z");
//	chart_z->legend()->hide();
//	chart_z->setAnimationOptions(QChart::AllAnimations);
//	QChartView *mychartview_z = new QChartView();
//	mychartview_z->setChart(chart_z);
//	mychartview_z->setRenderHint(QPainter::Antialiasing);
//	ui.chartscrollArea_3->setWidget(mychartview_z);
//}
//从列表选择想要查看的关节

void MainWindow::ListCurChange(int row)
{
	Dbg(row);
	if (mykinect != NULL) {
		mykinect->jointnumber = row;
		jointSelected = row;
	}
	
	else std::cout << "kinect not open" << endl;
}
//面板输入数据
void MainWindow::LineEdit_f(QString str)
{
	Dbg(str);
	force = str.toFloat();
}
void MainWindow::LineEdit_bodyWeight(QString str)
{
	Dbg(str);
	bodyWeight = str.toFloat();
}
void MainWindow::LineEdit_bagX(QString str)
{
	Dbg(str);
	bagX = str.toFloat();
}
void MainWindow::LineEdit_bagY(QString str)
{
	Dbg(str);
	bagY = str.toFloat();
}
void MainWindow::LineEdit_bagZ(QString str)
{
	Dbg(str);
	bagZ = - str.toFloat();
}
void MainWindow::bagSelect(bool i)
{
	Dbg(i);
	bag = i;
}

void MainWindow::SimpleMode(bool i)
{
	isSimpleMode = i;
	qDebug() << "SimpleMode: " << isSimpleMode << endl;
}

void MainWindow::OffMode(bool i)
{
	isOffMode = i;
	qDebug() << "OfflineMode: " << isOffMode << endl;
}

void MainWindow::Nframe(int i)
{
	n_frame = i;
	Dbg("N frame drawed: ");
	Dbg(n_frame);
}

void MainWindow::SetCD(int t)
{
	countDown = t;
	ui.statusBar->showMessage("CountDown Seted ", 2000);
	qDebug() <<"CountDown Seted: " << countDown << endl;
}
void MainWindow::ResetCD()
{
	ui.spinBox->setValue(0);
	ui.statusBar->showMessage("CD Reseted ", 2000);
	qDebug() << "CD Reseted: " << endl;
}
void MainWindow::SetLT(QString str)
{
	tLapse = str.toInt();
	qDebug() << "Set TimeLapes " << tLapse << " min" << endl;
}
void MainWindow::LineEdit_subjName(QString str)
{
	qDebug() << str << endl;
	qsubjname = str;
	strcpy(subjName, qsubjname.toStdString().c_str());
}


//存储joint数据 
void MainWindow::ready4Rec() {
	if (qsubjname == "null")
	{
		QMessageBox::warning(this, "Warning Message", "Key in subj Name first");
		return;
	}
	//记录subjinfo
	SubjInfo Paneldata;
	Paneldata.subjname = ui.lineEdit_subjectName->text();
	Paneldata.gender = ui.lineEdit_gender->text();
	Paneldata.age = ui.spinBox_age->text().toInt();
	Paneldata.height = ui.lineEdit_height->text().toFloat();
	Paneldata.weight = ui.lineEdit_bodyWeight->text().toFloat();
	Paneldata.preside = ui.lineEdit_preside->text();
	Paneldata.bagPosi[0] = ui.lineEdit_bagX->text().toFloat();
	Paneldata.bagPosi[1] = ui.lineEdit_bagY->text().toFloat();
	Paneldata.bagPosi[2] = ui.lineEdit_bagZ->text().toFloat();
	Paneldata.bagWeight = ui.lineEdit_f->text().toFloat();
	Paneldata.bag = ui.checkBox->isChecked();

	Paneldata.print();

	pSender->setSubjInfo(Paneldata);
	pSender->creatDir();
	
	
	qDebug() << "ready " << endl;
	ui.statusBar->showMessage("New Subject Created!", 2000);
	//按键不能按，直到更改username
	ui.pushButton_ready->setDisabled(true);
	ui.pushButton_ready->setStyleSheet("background-color: rgb(170, 0, 255);");
}

void MainWindow::releaseOKbutton()
{
	ui.pushButton_ready->setDisabled(false);
	ui.pushButton_ready->setStyleSheet("background-color: rgb(105, 165, 90);");
	ui.pushButton_calibration->setDisabled(false);
	ui.pushButton_calibration->setStyleSheet("background-color: rgb(105, 165, 90);");

}

void MainWindow::newTrail()
{
	//先关闭之前的file
	pSender->closefile();


	//新建file
	pSender->m_trailName = ui.lineEdit_trailname->text();
	pSender->creatFiles(pSender->m_trailName, pSender->m_subjpath);
	pSender->setfilehead();
	qDebug() << "New Trail Created" << endl;
	ui.statusBar->showMessage("New Trail Created", 2000);
	QMessageBox::information(this, "Trail Manager", "New Trail Created");
}


//calibration
void MainWindow::on_pushButton_calibration_clicked()
{
	pSender->creatFiles("cali", pSender->m_subjpath);
	pSender->setfilehead();
	qDebug() << "start calibaration" << endl;
	ui.statusBar->showMessage("start calibaration", 2000);
	QMessageBox::information(this, "start calibaration", "processing...");
	ui.statusBar->showMessage("processing...");
	startRec();
	//10s 后自动停止
	QTimer::singleShot(10000, this, SLOT(stopRec()));
	//522
	//计算平均角度
	QTimer::singleShot(13000, this, SLOT(caliSaved()));
	//按键不能按，直到更改username
	ui.pushButton_calibration ->setDisabled(true);
	ui.pushButton_calibration ->setStyleSheet("background-color: rgb(170, 0, 255);");
}


void MainWindow::startRec()
{
	rectimer->start();
	pSender->start();
	if (pSender->m_trailName == "0" )
	{
		qDebug() << "no_trailname_found" << endl;
		ui.statusBar->showMessage("Key in TrailName First", 2000);
		QMessageBox::information(this, "Error", "Key in TrailName First");
		return;
	}
	if (countDown == 0)
	{
		ui.label_recording->setVisible(true);
		qDebug() << "start Rec  at " << pSender->framerate << " fps" << endl;
		ui.statusBar->showMessage("Start Rec, at 25 fps", 2000);
		
	}
	else
	{
		ui.label_recording->setVisible(true);
		qDebug() << "start Rec  at " << pSender->framerate << " fps"<<"/CD: " <<countDown <<"sec"<< endl;
		ui.statusBar->showMessage("Start Rec, at 25 fps ,with CountDown", 2000);
		//倒计时结束 后自动停止
		QTimer::singleShot(countDown*1000, this, SLOT(stopRec()));
	}
	//除非按下stopRec不然不能再次按下StartRec
	ui.pushButton_StartRec->setDisabled(true);
	ui.pushButton_StartRec->setStyleSheet("background-color: rgb(170, 0, 255);");
	
}

void MainWindow::stopRec()
{
	//停止并重置录制时间
	rectimer->stop();
	recTime = 0;
	ui.lcdNumber_RecTime->display(recTime);

	//停止文件记录
	pSender->stop();
	qDebug() << "stop Rec succeed" << endl;
	ui.statusBar->showMessage("Stop Rec Succeed", 2000);

	//使StartREC按钮再次可用
	ui.pushButton_StartRec->setDisabled(false);
	ui.pushButton_StartRec->setStyleSheet("QPushButton{ border-radius: 35px; }"
                                           "QPushButton:hover{background-color: rgb(76, 120, 65) ;}"
                                          "QPushButton:!hover{background-color: rgb(105, 165, 90); }"
										);

	//隐藏recording图标
	ui.label_recording->setVisible(false);
}

void MainWindow::timeLapse()
{
	if (countDown == 0)
	{
		qDebug() << "set CD first" << endl;
		ui.statusBar->showMessage("Set CountDown first", 2000);
		QMessageBox::information(this, "Error", "Set CountDown first");
	}
	else
	{
		//2分钟 拍一次
		lapsetimer->setInterval(120 * 1000);
		ui.progressBar_tl->show();

		lapsed.start();

		//拍2分钟
		ui.progressBar_tl->setRange(0, tLapse * 60);

		lapsetimer->start();

	}
	

		
	
}

void MainWindow::oneLapse()
{
	if (lapsed.elapsed()/1000 > tLapse*60)
	{
		lapsetimer->stop();
		ui.progressBar_tl->setValue(tLapse * 60);
		ui.progressBar_tl->hide();
	}
	else
	{
		startRec();
		ui.progressBar_tl->setValue(lapsed.elapsed() / 1000);
	}
}



//522
void MainWindow::caliSaved()
{
//	pSender->CalSubcaliAngle();
	qDebug() << "calibration saved" << endl;
	ui.statusBar->showMessage("Calibration Saved", 2000);
	QMessageBox::information(this, "Calibration", "Finished");
}

void MainWindow::error_openfile()
{
	ui.statusBar->showMessage("error_openfile!!!", 2000);
	QMessageBox::information(this, "Error:", "Can't Open file!!!");
	ui.pushButton_StartRec->setDisabled(true);
	ui.pushButton_StopRec->click();
}

void MainWindow::readFileProgress(int f)
{
	ui.progressBar_tl->setValue(f);
}

void MainWindow::Click(QTreeWidgetItem * item)
{
	qDebug() << "click" << item->text(0) << endl;
	if (item->text(0).contains(".csv", Qt::CaseSensitive))
	{
		ui.lineEdit_rtn->setText(item->text(0));
		ui.lineEdit_rsubjn->setText(item->parent()->text(0));
		ui.lineEdit_rdate->setText(item->parent()->parent()->text(0));
	}
	
	
}

void MainWindow::DoubleClick(QTreeWidgetItem * item)
{
	qDebug() << "double click" <<item->text(0)<< endl;

	//QString path = QDir::currentPath();//获取程序当前目录
	//path.replace("/", "\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
	//
	if (item->text(0) == QString("Record"))
	{
		QProcess::startDetached("explorer " + item->text(1));//打开上面获取的目录
	}
	if (item->text(0).contains(".csv", Qt::CaseInsensitive))
	{
		//QProcess::execute("/E/Users/yj/Desktop/QTprogram/nWindows/nWindows/Record/2019-04-26/ivan/cali_Position.csv");
		//QProcess p(0);
		//QString filename = ".\\Record\\2019-04-26\\ivan\\cali_Position.csv";
		QString tn = item->text(0);
		QString sn = item->parent()->text(0);
		QString dn = item->parent()->parent()->text(0);
		QString filename = ".\\Record\\" + dn + "\\" + sn + "\\" + tn;

		QFile file(filename);
		if (file.exists())
		{
			QDesktopServices::openUrl(QUrl::fromLocalFile(filename));
		}
		
		//p.execute(command);//command是要执行的命令,args是参数
		//p.waitForFinished();
		//qDebug() << QString::fromLocal8Bit(p.readAllStandardError());
		//QProcess::startDetached("E:\\Users\\yj\\Desktop\\QTprogram\\nWindows\\nWindows\\Record\\2019-04-26\\ivan\\cali_Position.csv");
	}
	
	//QProcess::execute("notepad.exe");
}

void MainWindow::Expend(QTreeWidgetItem * item)
{
	qDebug() << "expended" << item->text(0) << endl;

}

void MainWindow::UpdateDir()
{
	while (root->childCount() > 0)
	{
		root->removeChild(root->child(0));
	}
	allFile(root, rootPath);
}

QFileInfoList MainWindow::allFile(QTreeWidgetItem * item,QString path)
{
	/*添加path路径文件*/
	QDir dir(path);          //遍历各级子目录

	QDir dir_file(path);    //遍历子目录中所有文件

	dir_file.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);        //获取当前所有文件
	dir_file.setSorting(QDir::Size | QDir::Reversed);

	QFileInfoList list_file = dir_file.entryInfoList();

	for (int i = 0; i < list_file.size(); ++i) {       //将当前目录中所有文件添加到treewidget中
		QFileInfo fileInfo = list_file.at(i);
		QString name2 = fileInfo.fileName();
		QTreeWidgetItem* child = new QTreeWidgetItem(QStringList() << name2);
		//child->setIcon(0, QIcon(":/file/image/link.ico"));
		child->setCheckState(1, Qt::Checked);
		item->addChild(child);
	}


	QFileInfoList file_list = dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
	QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);   //获取当前所有目录

	for (int i = 0; i != folder_list.size(); i++)         //自动递归添加各目录到上一级目录
	{
		QString namepath = folder_list.at(i).absoluteFilePath();    //获取路径
		QFileInfo folderinfo = folder_list.at(i);
		QString name = folderinfo.fileName();      //获取目录名
		QTreeWidgetItem* childroot = new QTreeWidgetItem(QStringList() << name);
		//childroot->setIcon(0, QIcon(":/file/image/link.ico"));
		childroot->setCheckState(1, Qt::Checked);
		item->addChild(childroot);              //将当前目录添加成path的子项

		QFileInfoList child_file_list = allFile(childroot, namepath);          //进行递归

		file_list.append(child_file_list);

		file_list.append(name);

	}

	return file_list;

}

void MainWindow::readRec()
{ 
	if (ui.lineEdit_rtn->text().contains("_Position.csv"))
	{
		//OBJ::Obj obj;
		QString filepath = ".\\Record\\" + ui.lineEdit_rdate->text() + "\\" + ui.lineEdit_rsubjn->text() + "\\";
		//obj.setFilePath(".\\Record\\2019-04-26\\ivan\\");
		p_obj->setFilePath(filepath);
		QString tfn = ui.lineEdit_rtn->text(); //取得trailname
		QString tn = tfn.left(tfn.length() - 13); //从后面查找"/"位置
		//QString tn = m_FilePath.right(m_FilePath.length() - first - 1); //从右边截取
		p_obj->addtrail(tn);

		QString RPM = tn.left(tn.length() - 2);
		RPM = RPM.right(2);
		p_obj->RPM = RPM.toInt();

		qDebug() <<"RPM: "<< p_obj->RPM << endl;
		//显示trail读取进度
		ui.progressBar_tl->setValue(0);
		ui.progressBar_tl->setRange(0, p_obj->getFrameNumber()); //还未读取到帧数，需要修正
		ui.progressBar_tl->show();

		pSender->readSubjInfo(*p_obj);
		pSender->readCali(*p_obj);
		//读取Position.csv
		pSender->readTrail(*p_obj);
		//设定滑动条范围用于预览
		ui.horizontalSlider->setRange(0, p_obj->getFrameNumber() - 1);
		ui.spinBox_Nframe->setRange(0, p_obj->getFrameNumber() - 1);

		//写出Angles.csv和moment
		//pSender->writeTrialAngle(*p_obj);
		//p_obj->calcSpinebaseFMwithBag();
		//pSender->writeMoment(*p_obj);
		
		
		

		//Filter
		p_obj->setJoints_filted(Filter::LP_Filter(p_obj->getJoints(),3));
		//p_obj->setJoints(Filter::LP_Filter(p_obj->getJoints(), 5));
		p_obj->setSegments_filted(p_obj->buildSegments(p_obj->getJoints_filted()));
		p_obj->calJointAngles_filted();


		//画图
		//脚踝的y坐标（上下）filt前后对比
		LineChart *chart = new LineChart();
		chart->plotJointPosition(*p_obj,JointType_AnkleLeft);
		chart->setTitle("Position_Ankle_left");
		chart->setAnimationOptions(QChart::NoAnimation);
		//chart->axisY()->setRange(-0.5, 0.5);
		QChartView *chartview_filtered = new QChartView();
		chartview_filtered->setChart(chart);
		chartview_filtered->setRenderHint(QPainter::Antialiasing);
		ui.scrollArea_2->setWidget(chartview_filtered);

		//关节角度kneeleft filt前后对比
		LineChart *chart_jA = new LineChart();
		chart_jA->plotJointAngle(*p_obj);
		chart_jA->setTitle("Knee_left Angle");
		chart_jA->setAnimationOptions(QChart::NoAnimation);
		//chart->axisY()->setRange(-0.5, 0.5);
		QChartView *chartview_jA = new QChartView();
		chartview_jA->setChart(chart_jA);
		chartview_jA->setRenderHint(QPainter::Antialiasing);
		ui.scrollArea_KneeAngle_clip->setWidget(chartview_jA);

		//建立Cycle
		Cycle data(*p_obj);
		//data.setPlotpart(JointType_KneeLeft, "y", 8);
		data.setPlotMat(9);
		LineChart *chart_c = new LineChart();
		chart_c->plotCycle(Cycle::extractMatdata(data.getCycles_Angle()),data.getNorFrameMark());
		chart_c->setTitle("Position_Ankle_left_y");
		chart_c->legend()->hide();
		chart_c->setAnimationOptions(QChart::NoAnimation);
		QChartView *chartview_ori = new QChartView();
		chartview_ori->setChart(chart_c);
		chartview_ori->setRenderHint(QPainter::Antialiasing);
		ui.scrollArea_graph->setWidget(chartview_ori);

		LineChart *poly = new LineChart();
		poly->plotPolyfitRes(data.getPlfPara()[6], data.getNorFrameMark()[6], data.getLeftAnkleY()[6]);
		poly->setTitle("Ankle_left_JointAngle[6]_polyFit");
		poly->legend()->hide();
		poly->setAnimationOptions(QChart::NoAnimation);
		QChartView *chartview_pl = new QChartView();
		chartview_pl->setChart(poly);
		chartview_pl->setRenderHint(QPainter::Antialiasing);
		ui.scrollArea_3->setWidget(chartview_pl);
		
		LineChart *chart_m = new LineChart();
		chart_m->plotMeanSqErr(data);
		chart_m->setTitle("Ankle_left_JointAngle_MeanSqErr");
		chart_m->legend()->hide();
		chart_m->setAnimationOptions(QChart::NoAnimation);
		QChartView *chartview_mse = new QChartView();
		chartview_mse->setChart(chart_m);
		chartview_mse->setRenderHint(QPainter::Antialiasing);
		ui.scrollArea_4->setWidget(chartview_mse);
		
		////opt
		//p_obj->setOptJoints(OPT::Optframes(*p_obj));
		
		
		////coord
		//OBJ::coordSys coordtrunk;
		//coordtrunk = p_obj->calCoordupTunkR(p_obj->getJoints()[0]);
		//coordtrunk.print();
		////打印trunk位置
		//std::cout << "trunk" << std::endl;
		//std::cout << p_obj->getJoints()[0][JointType_ShoulderLeft].jointPosition << std::endl;
		//std::cout << p_obj->getJoints()[0][JointType_ShoulderRight].jointPosition << std::endl;
		//std::cout << p_obj->getJoints()[0][JointType_SpineMid].jointPosition << std::endl;
		//std::cout << "trunk t" << std::endl;
		//std::cout << p_obj->Pg2l(p_obj->getJoints()[0][JointType_ShoulderLeft], coordtrunk) << std::endl;
		//std::cout << p_obj->Pg2l(p_obj->getJoints()[0][JointType_ShoulderRight], coordtrunk) << std::endl;
		//std::cout << p_obj->Pg2l(p_obj->getJoints()[0][JointType_SpineMid], coordtrunk) << std::endl;

		////打印bag位置
		//Eigen::Vector3f Pbag{0,0.2,0};
		//Eigen::Vector3f Pbaglocal = p_obj->getJoints()[0][JointType_SpineMid].Pg2l(coordtrunk) + Pbag;
		//Eigen::Vector3f PbagG = p_obj->Pl2g(Pbaglocal, coordtrunk);
		//std::cout << "bag position" << std::endl;
		//std::cout << PbagG << std::endl;
		//////打印pelvis
		//std::cout << "Pelvis" << std::endl;
		//std::cout << p_obj->getJoints()[0][JointType_HipLeft].jointPosition << std::endl;
		//std::cout << p_obj->getJoints()[0][JointType_HipRight].jointPosition << std::endl;
		//std::cout << p_obj->getJoints()[0][JointType_SpineMid].jointPosition << std::endl;

		//ui提示
		ui.statusBar->showMessage("Reconstruct Success", 2000);
		QMessageBox::information(this, "Reconstruct", "Reconstruct Success~");
		ui.progressBar_tl->hide();
	}
	else
	{
		ui.statusBar->showMessage("Reconstruct failed", 2000);
		QMessageBox::information(this, "Reconstruct", "Please select position file.");
	}
}


//关闭时清理内存使用
MainWindow::~MainWindow()
{
	///!!这里的内存释放still have problem（这是Openni使用Xtion2时的代码）!!(kinect2的内存管理比较好)

	//if(myCamera->isnotclosed()){ myCamera->closeCamera(); }
	//if (myCamera != NULL) {
	//	myCamera->closeCamera();
	//}
	delete[]subjName;
	thread->quit();
	thread->wait();
}