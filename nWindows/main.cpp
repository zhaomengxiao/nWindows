#include "mainwindow.h"
#include "imagewindow.h"



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
