#include "mainwindow.h"
//#include "ui_MainWindow.h"
#include "imagewindow.h"
//#include <QtWidgets/QApplication>
//#include <QTextCodec>
//#include <thread>
//#include <array>

//#include "vtkshape.h"

//from extern 
//FileREC *pSender = new FileREC();
//int jointSelected;
//float force ;
//float bodyWeight;
//float bagX ;
//float bagY ;
//float bagZ ;
//bool bag ;

//extern
extern float F_spinebase;
extern Eigen::Vector3f M_spinebase;








int main(int argc, char *argv[])
{
	////3d渲染
	//std::thread rendtheBall(ballrenderer);
	//rendtheBall.detach();
	
	
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
