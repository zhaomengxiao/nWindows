#include "chart.h"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDebug>
Chart::Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags)
	: QChart(QChart::ChartTypeCartesian, parent, wFlags),
	m_series(0),
	m_axis(new QValueAxis),
	m_step(0),
	m_x(0),
	m_y(0)
{
	QObject::connect(&m_timer, &QTimer::timeout, this, &Chart::handleTimeout);
	m_timer.setInterval(100);

	m_series = new QSplineSeries(this);
	QPen green(Qt::red);
	green.setWidth(3);
	m_series->setPen(green);
	m_series->append(m_x,m_y);

	addSeries(m_series);
	createDefaultAxes();
	setAxisX(m_axis, m_series);
	m_axis->setTickCount(5);
	//axisX()->setRange(0, 10);
	axisY()->setRange(0, 360);

	m_timer.start();
}

Chart::~Chart()
{
	m_timer.stop();
}

void Chart::getX(double time)
{
	m_x = time;
	//qDebug() << time << endl;
}

void Chart::getY( double val)
{
	m_y = val;
	//qDebug() << val << endl;
}

void Chart::handleTimeout()
{
	qreal x = plotArea().width() / m_axis->tickCount();
	qreal y = (m_axis->max() - m_axis->min()) / m_axis->tickCount();
	
	m_series->append(m_x, m_y);
	if(x>10)
	scroll(0.1, 0);
}