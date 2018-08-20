#include "mainwindow.h"
#include "imagewindow.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312")); //…Ë÷√±‡¬Î
	
	MainWindow w;
	ImageWindow iw;
	if (iw.exec() == QDialog::Accepted) {
		w.show();
		return a.exec();
	}
	
	else return 0;
}
