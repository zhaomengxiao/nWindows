#include "linechart.h"
#include <QtCharts/QLineSeries>
LineChart::LineChart(QGraphicsItem *parent, Qt::WindowFlags wFlags)
	: QChart(QChart::ChartTypeCartesian, parent, wFlags),
	mp_series(0),
	m_Xvector(0),
	m_Yvector(0)
{
	mp_series = new QLineSeries(this);
	QPen lineColor(Qt::red);
	mp_series->setPen(lineColor);
	
	
}

LineChart::~LineChart()
{
}

void LineChart::SetXY(std::vector<double> X, std::vector<double> Y)
{
	m_Xvector = X;
	m_Yvector = Y;
	for (int i = 0; i < m_Xvector.size(); ++i)
	{
		mp_series->append(m_Xvector[i], m_Yvector[i]);
	}
	addSeries(mp_series);
	createDefaultAxes();
}
