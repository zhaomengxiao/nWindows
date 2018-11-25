#ifndef CHART_H
#define CHART_H

#include <QtCharts/QChart>

#include <vector>
QT_CHARTS_BEGIN_NAMESPACE
class QLineSeries;

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

private:
	QLineSeries *mp_series;
	std::vector<double> m_Xvector;
	std::vector<double> m_Yvector;
};

#endif
