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
	void SetXY(std::vector<double> X, std::vector<double> Y);
	void plotJointPosition(const OBJ::Obj obj,JointType jt);
	void plotJointAngle(const OBJ::Obj obj);
	void plotCycle(Cycle & cycledata, JointType jt, QString xyz);
	void plotCycle(const stdMatd & dataMat,const stdMatd & frameMat);
	void plotPolyfitRes(std::vector<double> p, std::vector<double> x,std::vector<double> y);
	void plotMeanSqErr(Cycle & cycledata);
private:
	QList<QLineSeries *> m_series;
	QList<QScatterSeries *>m_scatterSeries;
};

#endif
