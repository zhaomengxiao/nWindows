#include "linechart.h"

LineChart::LineChart(QGraphicsItem *parent, Qt::WindowFlags wFlags)
	: QChart(QChart::ChartTypeCartesian, parent, wFlags)
{
	
	
	
}

LineChart::~LineChart()
{
}

void LineChart::SetXY(std::vector<double> X, std::vector<double> Y)
{
	std::vector<double> Xvector{ X };
	std::vector<double> Yvector{ Y };

	QLineSeries *data = new	QLineSeries();
	for (int i = 0; i < Xvector.size(); ++i)
	{
		data->append(Xvector[i], Yvector[i]);
	}
	m_series.append(data);
	for (auto i:m_series)
	{
		addSeries(i);
	}
	createDefaultAxes();
}

void LineChart::plotJointPosition(const OBJ::Obj obj, JointType jt)
{
	QLineSeries *p_X = new	QLineSeries();
	QLineSeries *p_Y = new	QLineSeries();
	QLineSeries *p_Z = new	QLineSeries();
	QLineSeries *p_Y_Filted = new QLineSeries();
	p_X->setColor(QColor(255, 0, 0));
	p_Y->setColor(QColor(0, 255, 0));
	p_Z->setColor(QColor(0, 0, 255));
	p_Y_Filted->setColor(QColor(150, 150, 0));
	p_X->setName("x");
	p_Y->setName("y");
	p_Z->setName("z");
	p_Y_Filted->setName("y_filted");
	m_series.append(p_X);
	m_series.append(p_Y);
	m_series.append(p_Z);
	m_series.append(p_Y_Filted);
	for (int i = 0; i < obj.getJoints().size(); i++)
	{
		p_X->append(i, obj.getJoints()[i][jt].jointPosition.x()- obj.getJoints()[0][jt].jointPosition.x());
		p_Y->append(i, obj.getJoints()[i][jt].jointPosition.y()- obj.getJoints()[0][jt].jointPosition.y());
		p_Z->append(i, obj.getJoints()[i][jt].jointPosition.z()- obj.getJoints()[0][jt].jointPosition.z());
		p_Y_Filted->append(i, obj.getJoints_filted()[i][jt].jointPosition.y() - obj.getJoints_filted()[0][jt].jointPosition.y());
	}
	
	for (auto i : m_series)
	{
		addSeries(i);
	}
	createDefaultAxes();
	//画每转分割线
	std::vector<int> cycle = Cycle::getExtremeFrame(obj.getJoints_filted(),obj.RPM);
	QCategoryAxis *axisX = new QCategoryAxis();
	for (int i = 0; i < cycle.size(); i++)
	{
		axisX->append(QString(i), cycle[i]);
	}
	
	axisX->setLinePenColor(QColor(255, 0, 0));
	axisX->setGridLineColor(QColor(255, 0, 0));

	addAxis(axisX, Qt::AlignBottom);
	
	p_X->attachAxis(axisX);
	p_Y->attachAxis(axisX);
	p_Z->attachAxis(axisX);
	p_Y_Filted->attachAxis(axisX);
}

void LineChart::plotJointAngle(const OBJ::Obj obj)
{
	QLineSeries *p_Angle = new	QLineSeries();
	QLineSeries *p_Angle_Filted = new QLineSeries();
	
	p_Angle->setColor(QColor(255, 0, 0));
	p_Angle_Filted->setColor(QColor(150, 150, 0));
	
	p_Angle->setName("Joint Angle");
	p_Angle_Filted->setName("Joint Angle_filted");
	
	m_series.append(p_Angle);
	m_series.append(p_Angle_Filted);
	for (int i = 0; i < obj.getJointAngles().size(); i++)
	{
		p_Angle->append(i, obj.getJointAngles()[i].KneeL);
		p_Angle_Filted->append(i, obj.getJointAngles_filted()[i].KneeL);
	}

	for (auto i : m_series)
	{
		addSeries(i);
	}
	createDefaultAxes();
	//画每转分割线
	std::vector<int> cycle = Cycle::getExtremeFrame(obj.getJoints_filted(), obj.RPM);
	QCategoryAxis *axisX = new QCategoryAxis();
	for (int i = 0; i < cycle.size(); i++)
	{
		axisX->append(QString(i), cycle[i]);
	}

	axisX->setLinePenColor(QColor(255, 0, 0));
	axisX->setGridLineColor(QColor(255, 0, 0));

	addAxis(axisX, Qt::AlignBottom);

	p_Angle->attachAxis(axisX);
	
	p_Angle_Filted->attachAxis(axisX);
}

void LineChart::plotCycle( Cycle & cycledata, JointType jt, QString xyz)
{
	cycles_joints cycle = cycledata.getCycles_Joints();
	stdMatd frameMarks = cycledata.getNorFrameMark();
	stdMatd jointData = Cycle::extractMatdata(cycle, jt, xyz);
	for (int i = 0; i < cycle.size(); i++)
	{
		QLineSeries *p_series = new	QLineSeries();
		p_series->setColor(QColor(255, 0, 0));
		m_series.append(p_series);
		for (int j =0;j<cycle[i].size();j++)
		{
			p_series->append(frameMarks[i][j], jointData[i][j]);
		}
	}
	
	for (auto i : m_series)
	{
		addSeries(i);
	}
	
	createDefaultAxes();
}

void LineChart::plotCycle(const stdMatd & dataMat, const stdMatd & frameMat)
{
	for (int i = 0; i < dataMat.size(); i++)
	{
		QLineSeries *p_series = new	QLineSeries();
		p_series->setColor(QColor(255, 0, 0));
		m_series.append(p_series);
		for (int j = 0; j < dataMat[i].size(); j++)
		{
			p_series->append(frameMat[i][j], dataMat[i][j]);
		}
	}

	for (auto i : m_series)
	{
		addSeries(i);
	}

	createDefaultAxes();
}

void LineChart::plotPolyfitRes(std::vector<double> p, std::vector<double> x, std::vector<double> y)
{
	//画散点图
	QScatterSeries *p_series = new QScatterSeries();
	
	p_series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
	p_series->setMarkerSize(5.0);
	p_series->setColor(QColor(255, 0, 0));
	for (int i = 0; i < x.size(); i++)
	{
		p_series->append(x[i], y[i]);
	}
	addSeries(p_series);
	

	//画fit曲线
	QLineSeries *p_lineS = new QLineSeries();
	for (int i = 0; i < 361; i++)
	{
		double y_value = 0;

		for (int n = 0; n < p.size(); n++)
		{
			y_value += pow(i, n)*p[n];
		}
		p_lineS->append(i, y_value);
	}
	addSeries(p_lineS);
	createDefaultAxes();
}

void LineChart::plotMeanSqErr(Cycle & cycledata)
{
	//画fit曲线
	QLineSeries *p_lineS = new QLineSeries();
	p_lineS->setColor(QColor(255, 0, 0));
	std::vector<double> p = cycledata.getAvePara();
	for (int i = 0; i < 361; i++)
	{
		double y_value = 0;

		for (int n = 0; n < p.size(); n++)
		{
			y_value += pow(i, n)*p[n];
		}
		p_lineS->append(i, y_value);
	}
	m_series.append(p_lineS);
	//画均方根
	QLineSeries *up = new QLineSeries();
	QLineSeries *down = new QLineSeries();
	for (int i = 0; i < 361; i++)
	{
		double y_value_u = 0;
		double y_value_d = 0;
		for (int n = 0; n < p.size(); n++)
		{
			y_value_u += pow(i, n)*p[n];
			y_value_d += pow(i, n)*p[n];
		}
		y_value_u += cycledata.getMeanSqErr()[i];
		y_value_d -= cycledata.getMeanSqErr()[i];
		up->append(i, y_value_u);
		down->append(i, y_value_d);
	}
	QAreaSeries *areaS = new QAreaSeries(up, down);
	QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
	gradient.setColorAt(0.0, 0x3cc63c);
	gradient.setColorAt(1.0, 0x26f626);
	gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
	areaS->setBrush(gradient);


	addSeries(areaS);
	addSeries(p_lineS);
	createDefaultAxes();
}




	

