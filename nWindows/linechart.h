#ifndef CHART_H
#define CHART_H

#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QScatterseries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QCategoryAxis>
#include "obj.h"
#include "cycle.h"
#include "motiondetect.h"
QT_CHARTS_BEGIN_NAMESPACE
class QLineSeries;
class QScatterSeries;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class LineChart : public QChart
{
	//Q_OBJECT

public:
	LineChart(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);
	~LineChart();

public:
	void setColors(int A);
	void SetXY(std::vector<double> X, std::vector<double> Y);
	void plotJointPosition(const OBJ::Obj & obj,JointType jt);
	void plotJointAngle(const OBJ::Obj & obj, OBJ::JAngleType jAt);
	void plotCycle(Cycle & cycledata, JointType jt, QString xyz);		//Œª÷√
	void plotCycle(const stdMatd & dataMat,const stdMatd & frameMat);	//Ω«∂»
	void plotPolyfitRes(std::vector<double> p, std::vector<double> x,std::vector<double> y);
	void plotMeanSqErr(Cycle & cycledata);
	//void plotOptdiff(const OBJ::Obj & obj);
	void plotMeanSqErr(std::vector<Cycle> & cycles);
	void plotVicon_Kinect(std::vector<Cycle> & cycles,std::vector<double> vicondata);
	void plotNvicon(stdMatd vicondatas);
	void plotScatter(stdMatd dataMat);
	void plotScatter_fit(stdMatd dataMat, stdMatd nframeMark);
	void plotAnkleScatter_fit_traj(stdMatd dataMat, stdMatd nframeMark, const OBJ::Obj &obj);
	void plotKneeScatter_fit_traj(stdMatd dataMat, stdMatd nframeMark, const OBJ::Obj &obj);
	void plotJointYZScatter(const OBJ::Obj & obj, JointType jt);
	void plotAnkleYZScatter_circleFit(const OBJ::Obj & obj);
	void plotKneeYZScatter_polyFit(const OBJ::Obj & obj);
	void plotVicon_Kinect_Fit(std::vector<Cycle> & cycles, std::vector<double> vicondata, const OBJ::Obj & obj);
	void plotNviconMeanSqErr_Knee(stdMatd viconMat, std::vector<Cycle> & cycles);
	void plotNviconMeanSqErr_Hip(stdMatd viconMat, std::vector<Cycle> & cycles);
	void plotNviconMeanSqErr_Ankle(stdMatd viconMat, std::vector<Cycle> & cycles);
private:
	QList<QLineSeries *>	m_series;
	QList<QScatterSeries *>	m_scatterSeries;
	QList<QAreaSeries *>	m_areaSeries;
	QList<QColor> m_colors;
	QList<QColor> m_colorsA;
};

#endif
