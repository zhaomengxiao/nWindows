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
	////3d��Ⱦ
	//std::thread rendtheBall(ballrenderer);
	//rendtheBall.detach();
	
	
	//���ڽ���
	QApplication a(argc, argv);
	//QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312")); //���ñ���
	
	MainWindow w;
	ImageWindow iw;
	if (iw.exec() == QDialog::Accepted) {
		w.show();
		return a.exec();
	}
	
	else return 0;
}
