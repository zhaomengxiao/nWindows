#include "mainwindow.h"
#include "imagewindow.h"



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
