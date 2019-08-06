#include "linechart.h"

LineChart::LineChart(QGraphicsItem *parent, Qt::WindowFlags wFlags)
	: QChart(QChart::ChartTypeCartesian, parent, wFlags)
{
	
	
	
}

LineChart::~LineChart()
{
}

void LineChart::setColors(int A)
{
	QList<QColor> colors;
	QList<QColor> colorsA;
	colors.append(QColor(161, 47, 47)); //red
	colors.append(QColor(230, 159, 0)); //orange
	colors.append(QColor(86, 140, 255));//blue
	colors.append(QColor(0, 200, 115));//green
	colors.append(QColor(240, 228, 66)); //ylw
	colors.append(QColor(117, 112, 179)); //purple
	colors.append(QColor(251, 180, 174)); //pink

	colorsA.append(QColor(161, 47, 47, A));
	colorsA.append(QColor(230, 159, 0,A));
	colorsA.append(QColor(86, 140, 255,A));
	colorsA.append(QColor(0, 200, 115,A));
	colorsA.append(QColor(240, 228, 66, A)); //ylw
	colorsA.append(QColor(117, 112, 179,A)); //purple
	colorsA.append(QColor(251, 180, 174,A)); //pink

	m_colors = colors;
	m_colorsA = colorsA;
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

void LineChart::plotJointPosition(const OBJ::Obj & obj, JointType jt)
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

void LineChart::plotJointAngle(const OBJ::Obj & obj,OBJ::JAngleType jAt)
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
		p_Angle->append(i, obj.getJointAngles()[i][jAt].Angle_x);
		p_Angle_Filted->append(i, obj.getJointAngles_filted()[i][jAt].Angle_x);
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

	std::vector<double> plx(361, 0.0);
	for (int i = 0; i < 361; i++)
	{
		plx[i] = double(i);
	}
	
	std::vector<double> plRes = myMath::polyRes(p, plx);

	for (int i = 0; i < plRes.size(); i++)
	{
		p_lineS->append(i, plRes[i]);
	}
	/*for (int i = 0; i < 361; i++)
	{
		double y_value = 0;

		for (int n = 0; n < p.size(); n++)
		{
			y_value += pow(i, n)*p[n];
		}
		p_lineS->append(i, y_value);
	}*/
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

//void LineChart::plotOptdiff(const OBJ::Obj & obj)
//{
//	std::vector<Cycle> cycles;
//
//	for (int ncycle = 0; ncycle < cycles.size(); ncycle++)
//	{
//		//画fit曲线
//		QLineSeries *p_lineS = new QLineSeries();
//		//p_lineS->setColor(QColor(255, 0, 0));
//		std::vector<double> p = cycles[ncycle].getAvePara();
//		for (int i = 0; i < 361; i++)
//		{
//			double y_value = 0;
//
//			for (int n = 0; n < p.size(); n++)
//			{
//				y_value += pow(i, n)*p[n];
//			}
//			p_lineS->append(i, y_value);
//		}
//		QPen pen(m_colors[ncycle]);
//		pen.setWidth(3);
//		p_lineS->setPen(pen);
//		m_series.append(p_lineS);
//
//		//画均方根
//		QLineSeries *up = new QLineSeries();
//		QLineSeries *down = new QLineSeries();
//		for (int i = 0; i < 361; i++)
//		{
//			double y_value_u = 0;
//			double y_value_d = 0;
//			for (int n = 0; n < p.size(); n++)
//			{
//				y_value_u += pow(i, n)*p[n];
//				y_value_d += pow(i, n)*p[n];
//			}
//			y_value_u += cycles[ncycle].getMeanSqErr()[i];
//			y_value_d -= cycles[ncycle].getMeanSqErr()[i];
//			up->append(i, y_value_u);
//			down->append(i, y_value_d);
//		}
//		QAreaSeries *areaS = new QAreaSeries(up, down);
//		QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
//		/*gradient.setColorAt(0.0, 0x3cc63c);
//		gradient.setColorAt(1.0, 0x26f626);
//		gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
//		areaS->setBrush(gradient);*/
//		areaS->setColor(m_colorsA[ncycle]);
//		areaS->setBorderColor(m_colorsA[ncycle]);
//		m_areaSeries.append(areaS);
//	}
//
//	//for (int i = 0; i < m_areaSeries.size(); i++)
//	//{
//	//	//m_areaSeries[i]->setColor(QColor(m_series[0]->color()., m_series[0]->color().green(), m_series[0]->color().blue(), 100));
//	//	m_areaSeries[i]->setColor(m_series[i]->color);
//	//}
//
//
//	for (auto serie : m_areaSeries)
//	{
//		addSeries(serie);
//	}
//
//	for (auto serie : m_series)
//	{
//		addSeries(serie);
//	}
//
//	createDefaultAxes();
//	QBrush background(QColor(225, 225, 225));
//	setBackgroundBrush(background);
//	//setPlotAreaBackgroundBrush(background);
//	legend()->hide();
//	setAnimationOptions(QChart::NoAnimation);
//
//	// Customize axis label font
//	QFont labelsFont;
//	labelsFont.setPixelSize(14);
//	axisX()->setLabelsFont(labelsFont);
//	axisY()->setLabelsFont(labelsFont);
//	axisX()->setGridLineColor(QColor(245, 245, 245));
//	axisY()->setGridLineColor(QColor(245, 245, 245));
//	axisY()->setRange(0, 180);
//	//QValueAxis a;
//	//a.setLabelFormat("%i");
//
//	//// Customize axis label colors
//	//QBrush axisBrush(Qt::white);
//	//axisX()->setLabelsBrush(axisBrush);
//	//axisY()->setLabelsBrush(axisBrush);
//
//	// Customize chart title
//	QFont font;
//	font.setPixelSize(18);
//	setTitleFont(font);
//	setTitleBrush(QBrush(Qt::black));
//}

void LineChart::plotMeanSqErr(std::vector<Cycle>& cycles)
{
	
	for (int ncycle = 0; ncycle < cycles.size(); ncycle++)
	{
		//画fit曲线
		QLineSeries *p_lineS = new QLineSeries();
		//p_lineS->setColor(QColor(255, 0, 0));
		std::vector<double> p = cycles[ncycle].getAvePara();

		std::vector<double> polyX(360, 0.0);
		for (int i = 0; i < polyX.size(); i++)
		{
			polyX[i] = double(i);
		}
		std::vector<double> polyRes = myMath::polyRes(p, polyX);

		for (int i = 0; i < polyX.size(); i++)
		{
			p_lineS->append(i, polyRes[i]);
		}
		
		QPen pen(m_colors[ncycle]);
		pen.setWidth(3);
		p_lineS->setPen(pen);
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
			y_value_u += cycles[ncycle].getMeanSqErr()[i];
			y_value_d -= cycles[ncycle].getMeanSqErr()[i];
			up->append(i, y_value_u);
			down->append(i, y_value_d);
		}
		QAreaSeries *areaS = new QAreaSeries(up, down);
		QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
		/*gradient.setColorAt(0.0, 0x3cc63c);
		gradient.setColorAt(1.0, 0x26f626);
		gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
		areaS->setBrush(gradient);*/
		areaS->setColor(m_colorsA[ncycle]);
		areaS->setBorderColor(m_colorsA[ncycle]);
		m_areaSeries.append(areaS);
	}
	
	
	

	for (auto serie :m_areaSeries)
	{
		addSeries(serie);
	}
	
	for (auto serie:m_series)
	{
		addSeries(serie);
	}
	
	
	QBrush background(QColor(225, 225, 225));
	setBackgroundBrush(background);
	//setPlotAreaBackgroundBrush(background);
	legend()->hide();
	setAnimationOptions(QChart::NoAnimation);
	
	// Customize axis 
	QValueAxis * axisX = new QValueAxis();
	axisX->setRange(0, 360);
	axisX->setTickCount(5);
	axisX->setLabelFormat("%d");

	QValueAxis * axisY = new QValueAxis();
	axisY->setRange(0, 120);
	axisY->setTickCount(7);
	axisY->setLabelFormat("%d");

	QFont labelsFont;
	labelsFont.setPixelSize(10);
	axisX->setLabelsFont(labelsFont);
	axisY->setLabelsFont(labelsFont);
	axisX->setGridLineColor(QColor(245, 245, 245));
	axisY->setGridLineColor(QColor(245, 245, 245));

	axisX->setLinePenColor(QColor(245, 245, 245));
	axisY->setLinePenColor(QColor(245, 245, 245));
	addAxis(axisX, Qt::AlignBottom);
	addAxis(axisY, Qt::AlignLeft);

	for (auto serie : m_series)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}

	for (auto serie : m_areaSeries)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}

	// Customize chart title
	QFont font;
	font.setPixelSize(14);
	setTitleFont(font);
	setTitleBrush(QBrush(Qt::black));

}

void LineChart::plotVicon_Kinect(std::vector<Cycle> & cycles, std::vector<double> vicondata)
{
	for (int ncycle = 0; ncycle < cycles.size(); ncycle++)
	{
		//画fit曲线
		QLineSeries *p_lineS = new QLineSeries();
		//p_lineS->setColor(QColor(255, 0, 0));
		std::vector<double> p = cycles[ncycle].getAvePara();
		for (int i = 0; i < 361; i++)
		{
			double y_value = 0;

			for (int n = 0; n < p.size(); n++)
			{
				y_value += pow(i, n)*p[n];
			}
			p_lineS->append(i, y_value);
		}
		QPen pen(m_colors[ncycle+1]);
		pen.setWidth(3);
		p_lineS->setPen(pen);
		m_series.append(p_lineS);
		
		//画vicondata
		QLineSeries *p_lineVicon= new QLineSeries();
		for (int i = 0; i < vicondata.size(); i++)
		{
			p_lineVicon->append(double(i) / vicondata.size() * 361.0, vicondata[i]);
		}
		QPen pen_vicon(m_colors[0]);
		pen_vicon.setWidth(3);
		p_lineVicon->setPen(pen_vicon);
		m_series.append(p_lineVicon);
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
			y_value_u += cycles[ncycle].getMeanSqErr()[i];
			y_value_d -= cycles[ncycle].getMeanSqErr()[i];
			up->append(i, y_value_u);
			down->append(i, y_value_d);
		}
		QAreaSeries *areaS = new QAreaSeries(up, down);
		QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
		
		areaS->setColor(m_colorsA[ncycle]);
		areaS->setBorderColor(m_colorsA[ncycle]);
		m_areaSeries.append(areaS);
	}

	for (auto serie : m_areaSeries)
	{
		addSeries(serie);
	}

	for (auto serie : m_series)
	{
		addSeries(serie);
	}

	
	QBrush background(QColor(225, 225, 225));
	setBackgroundBrush(background);
	//setPlotAreaBackgroundBrush(background);
	legend()->hide();
	setAnimationOptions(QChart::NoAnimation);

	// Customize axis 
	QValueAxis * axisX = new QValueAxis();
	axisX->setRange(0, 360);
	axisX->setTickCount(5);
	axisX->setLabelFormat("%d");

	QValueAxis * axisY = new QValueAxis();
	axisY->setRange(0, 120);
	axisY->setTickCount(7);
	axisY->setLabelFormat("%d");

	QFont labelsFont;
	labelsFont.setPixelSize(10);
	axisX->setLabelsFont(labelsFont);
	axisY->setLabelsFont(labelsFont);
	axisX->setGridLineColor(QColor(245, 245, 245));
	axisY->setGridLineColor(QColor(245, 245, 245));

	axisX->setLinePenColor(QColor(245, 245, 245));
	axisY->setLinePenColor(QColor(245, 245, 245));
	addAxis(axisX, Qt::AlignBottom);
	addAxis(axisY, Qt::AlignLeft);

	for (auto serie : m_series)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}
	
	for (auto serie : m_areaSeries)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}

	// Customize chart title
	QFont font;
	font.setPixelSize(14);
	setTitleFont(font);
	setTitleBrush(QBrush(Qt::black));
}

void LineChart::plotNvicon(stdMatd vicondatas)
{
	int ndata = 0;
	for (auto vicondata: vicondatas)
	{
		//画vicondata
		QLineSeries *p_lineVicon = new QLineSeries();
		for (int i = 0; i < vicondata.size(); i++)
		{
			p_lineVicon->append(double(i) / (vicondata.size()-1) * 360.0, vicondata[i]);
		}
		QPen pen_vicon(m_colors[ndata]);
		pen_vicon.setWidth(3);
		p_lineVicon->setPen(pen_vicon);
		m_series.append(p_lineVicon);
		ndata++;
	}
	for (auto serie : m_series)
	{
		addSeries(serie);
	}
	
	QBrush background(QColor(225, 225, 225));
	setBackgroundBrush(background);
	//setPlotAreaBackgroundBrush(background);
	legend()->hide();
	setAnimationOptions(QChart::NoAnimation);

	// Customize axis 
	QValueAxis * axisX = new QValueAxis();
	axisX->setRange(0, 360);
	axisX->setTickCount(5);
	axisX->setLabelFormat("%d");

	QValueAxis * axisY = new QValueAxis();
	axisY->setRange(0, 120);
	axisY->setTickCount(7);
	axisY->setLabelFormat("%d");

	QFont labelsFont;
	labelsFont.setPixelSize(10);
	axisX->setLabelsFont(labelsFont);
	axisY->setLabelsFont(labelsFont);
	axisX->setGridLineColor(QColor(245, 245, 245));
	axisY->setGridLineColor(QColor(245, 245, 245));
	
	axisX->setLinePenColor(QColor(245, 245, 245));
	axisY->setLinePenColor(QColor(245, 245, 245));
	addAxis(axisX, Qt::AlignBottom);
	addAxis(axisY, Qt::AlignLeft);
	
	for (auto serie : m_series)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}
	

	

	// Customize chart title
	QFont font;
	font.setPixelSize(14);
	setTitleFont(font);
	setTitleBrush(QBrush(Qt::black));
}

void LineChart::plotScatter(stdMatd dataMat)
{
	for (auto data : dataMat)
	{
		QScatterSeries *p_scatterS = new QScatterSeries();
		for (int i = 0; i < data.size(); i++)
		{
			p_scatterS->append(double(i) / (data.size() - 1) * 360.0, data[i]);
		}
		/*QPen pen_scatter(QColor(255,0,0));
		pen_scatter.setWidth(3);

		p_scatterS->setPen(pen_scatter);*/
		p_scatterS->setMarkerSize(7);
		m_scatterSeries.append(p_scatterS);
	}
	for (auto serie : m_scatterSeries)
	{
		addSeries(serie);
	}

	QBrush background(QColor(225, 225, 225));
	setBackgroundBrush(background);
	//setPlotAreaBackgroundBrush(background);
	legend()->hide();
	setAnimationOptions(QChart::NoAnimation);

	// Customize axis 
	QValueAxis * axisX = new QValueAxis();
	axisX->setRange(0, 360);
	axisX->setTickCount(5);
	axisX->setLabelFormat("%d");

	QValueAxis * axisY = new QValueAxis();
	axisY->setRange(-0.8, 0.2);
	axisY->setTickCount(7);
	//axisY->setLabelFormat("%d");

	QFont labelsFont;
	labelsFont.setPixelSize(10);
	axisX->setLabelsFont(labelsFont);
	axisY->setLabelsFont(labelsFont);
	axisX->setGridLineColor(QColor(245, 245, 245));
	axisY->setGridLineColor(QColor(245, 245, 245));

	axisX->setLinePenColor(QColor(245, 245, 245));
	axisY->setLinePenColor(QColor(245, 245, 245));
	addAxis(axisX, Qt::AlignBottom);
	addAxis(axisY, Qt::AlignLeft);

	for (auto serie : m_scatterSeries)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}

	// Customize chart title
	QFont font;
	font.setPixelSize(14);
	setTitleFont(font);
	setTitleBrush(QBrush(Qt::black));
}

void LineChart::plotScatter_fit(stdMatd dataMat, stdMatd nframeMark)
{
	//polyfit
	std::vector<double> x;
	std::vector<double> y;
	for (auto mark:nframeMark)
	{
		x.insert(x.end(), mark.begin(), mark.end());
	}
	for (auto data:dataMat)
	{
		y.insert(y.end(), data.begin(), data.end());
	}
	/*x = nframeMark[6];
	y = dataMat[6];*/
	std::vector<double> polyP = myMath::polyfit(x, y,10);

	std::vector<double> resX(361, 0.0);
	for (int i = 0; i < resX.size(); i++)
	{
		resX[i] = double(i);
	}
	
	std::vector<double> res = myMath::polyRes(polyP, resX);
	/*std::vector<double> res(361,0.0);
	for (int i = 0; i < 361; i++)
	{
		res[i] = polyP[0]*sin(polyP[1] *i + polyP[2]) + polyP[3];
	}*/
	
	QLineSeries *p_polyline = new QLineSeries();
	for (int i = 0; i < res.size(); i++)
	{
		p_polyline->append(i, res[i]);
	}
	QPen pen_polyline(QColor(255,0,0));
	pen_polyline.setWidth(3);

	p_polyline->setPen(pen_polyline);

	m_series.append(p_polyline);
	
	
	
	//plot scatter
	int ncycle = 0;


	QScatterSeries *p_scatterS = new QScatterSeries();
	for (int i = 0; i < x.size(); i++)
	{
		p_scatterS->append(x[i], y[i]);
	}
	p_scatterS->setMarkerSize(7);
	m_scatterSeries.append(p_scatterS);

	//for (auto data : dataMat)
	//{
	//	QScatterSeries *p_scatterS = new QScatterSeries();
	//	for (int i = 0; i < data.size(); i++)
	//	{
	//		p_scatterS->append(nframeMark[ncycle][i], data[i]);
	//	}
	//	/*QPen pen_scatter(QColor(255,0,0));
	//	pen_scatter.setWidth(3);

	//	p_scatterS->setPen(pen_scatter);*/
	//	p_scatterS->setMarkerSize(7);
	//	m_scatterSeries.append(p_scatterS);

	//	ncycle++;
	//}
	for (auto serie : m_scatterSeries)
	{
		addSeries(serie);
	}
	for (auto serie : m_series)
	{
		addSeries(serie);
	}
	QBrush background(QColor(225, 225, 225));
	setBackgroundBrush(background);
	//setPlotAreaBackgroundBrush(background);
	legend()->hide();
	setAnimationOptions(QChart::NoAnimation);

	// Customize axis 
	QValueAxis * axisX = new QValueAxis();
	axisX->setRange(0, 360);
	axisX->setTickCount(5);
	axisX->setLabelFormat("%d");

	QValueAxis * axisY = new QValueAxis();
	axisY->setRange(-0.8, 0.2);
	axisY->setTickCount(7);
	//axisY->setLabelFormat("%d");

	QFont labelsFont;
	labelsFont.setPixelSize(20);
	axisX->setLabelsFont(labelsFont);
	axisY->setLabelsFont(labelsFont);
	axisX->setGridLineColor(QColor(245, 245, 245));
	axisY->setGridLineColor(QColor(245, 245, 245));

	axisX->setLinePenColor(QColor(245, 245, 245));
	axisY->setLinePenColor(QColor(245, 245, 245));
	addAxis(axisX, Qt::AlignBottom);
	addAxis(axisY, Qt::AlignLeft);

	for (auto serie : m_scatterSeries)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}
	for (auto serie:m_series)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}

	// Customize chart title
	QFont font;
	font.setPixelSize(30);
	setTitleFont(font);
	setTitleBrush(QBrush(Qt::black));
}

void LineChart::plotAnkleScatter_fit_traj(stdMatd dataMat, stdMatd nframeMark, const OBJ::Obj & obj)
{
	//ankle trajectory
	QLineSeries *p_trajline = new QLineSeries();
	for (int i = 0; i < obj.Trajectory_Ankle.size(); i++)
	{
		p_trajline->append(i, obj.Trajectory_Ankle[i].y());
	}
	QPen pen_trajline(QColor(99, 200, 142));
	pen_trajline.setWidth(3);

	p_trajline->setPen(pen_trajline);

	m_series.append(p_trajline);
	//polyfit
	std::vector<double> x;
	std::vector<double> y;
	for (auto mark : nframeMark)
	{
		x.insert(x.end(), mark.begin(), mark.end());
	}
	for (auto data : dataMat)
	{
		y.insert(y.end(), data.begin(), data.end());
	}
	/*x = nframeMark[6];
	y = dataMat[6];*/
	std::vector<double> polyP = myMath::polyfit(x, y, 10);

	std::vector<double> resX(361, 0.0);
	for (int i = 0; i < resX.size(); i++)
	{
		resX[i] = double(i);
	}

	std::vector<double> res = myMath::polyRes(polyP, resX);
	/*std::vector<double> res(361,0.0);
	for (int i = 0; i < 361; i++)
	{
		res[i] = polyP[0]*sin(polyP[1] *i + polyP[2]) + polyP[3];
	}*/

	QLineSeries *p_polyline = new QLineSeries();
	for (int i = 0; i < res.size(); i++)
	{
		p_polyline->append(i, res[i]);
	}
	QPen pen_polyline(QColor(255, 0, 0));
	pen_polyline.setWidth(3);

	p_polyline->setPen(pen_polyline);

	m_series.append(p_polyline);



	//plot scatter
	int ncycle = 0;


	QScatterSeries *p_scatterS = new QScatterSeries();
	for (int i = 0; i < x.size(); i++)
	{
		p_scatterS->append(x[i], y[i]);
	}
	p_scatterS->setMarkerSize(7);
	m_scatterSeries.append(p_scatterS);

	//for (auto data : dataMat)
	//{
	//	QScatterSeries *p_scatterS = new QScatterSeries();
	//	for (int i = 0; i < data.size(); i++)
	//	{
	//		p_scatterS->append(nframeMark[ncycle][i], data[i]);
	//	}
	//	/*QPen pen_scatter(QColor(255,0,0));
	//	pen_scatter.setWidth(3);

	//	p_scatterS->setPen(pen_scatter);*/
	//	p_scatterS->setMarkerSize(7);
	//	m_scatterSeries.append(p_scatterS);

	//	ncycle++;
	//}
	for (auto serie : m_scatterSeries)
	{
		addSeries(serie);
	}
	for (auto serie : m_series)
	{
		addSeries(serie);
	}
	QBrush background(QColor(225, 225, 225));
	setBackgroundBrush(background);
	//setPlotAreaBackgroundBrush(background);
	legend()->hide();
	setAnimationOptions(QChart::NoAnimation);

	// Customize axis 
	QValueAxis * axisX = new QValueAxis();
	axisX->setRange(0, 360);
	axisX->setTickCount(5);
	axisX->setLabelFormat("%d");

	QValueAxis * axisY = new QValueAxis();
	axisY->setRange(-0.8, 0.2);
	axisY->setTickCount(7);
	//axisY->setLabelFormat("%d");

	QFont labelsFont;
	labelsFont.setPixelSize(20);
	axisX->setLabelsFont(labelsFont);
	axisY->setLabelsFont(labelsFont);
	axisX->setGridLineColor(QColor(245, 245, 245));
	axisY->setGridLineColor(QColor(245, 245, 245));

	axisX->setLinePenColor(QColor(245, 245, 245));
	axisY->setLinePenColor(QColor(245, 245, 245));
	addAxis(axisX, Qt::AlignBottom);
	addAxis(axisY, Qt::AlignLeft);

	for (auto serie : m_scatterSeries)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}
	for (auto serie : m_series)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}

	// Customize chart title
	QFont font;
	font.setPixelSize(30);
	setTitleFont(font);
	setTitleBrush(QBrush(Qt::black));
}

void LineChart::plotKneeScatter_fit_traj(stdMatd dataMat, stdMatd nframeMark, const OBJ::Obj & obj)
{
	//ankle trajectory
	QLineSeries *p_trajline = new QLineSeries();
	for (int i = 0; i < obj.Trajectory_Knee.size(); i++)
	{
		p_trajline->append(i, obj.Trajectory_Knee[i].y());
	}
	QPen pen_trajline(QColor(99, 200, 142));
	pen_trajline.setWidth(3);

	p_trajline->setPen(pen_trajline);

	m_series.append(p_trajline);
	//polyfit
	std::vector<double> x;
	std::vector<double> y;
	for (auto mark : nframeMark)
	{
		x.insert(x.end(), mark.begin(), mark.end());
	}
	for (auto data : dataMat)
	{
		y.insert(y.end(), data.begin(), data.end());
	}
	/*x = nframeMark[6];
	y = dataMat[6];*/
	std::vector<double> polyP = myMath::polyfit(x, y, 10);

	std::vector<double> resX(361, 0.0);
	for (int i = 0; i < resX.size(); i++)
	{
		resX[i] = double(i);
	}

	std::vector<double> res = myMath::polyRes(polyP, resX);
	/*std::vector<double> res(361,0.0);
	for (int i = 0; i < 361; i++)
	{
		res[i] = polyP[0]*sin(polyP[1] *i + polyP[2]) + polyP[3];
	}*/

	QLineSeries *p_polyline = new QLineSeries();
	for (int i = 0; i < res.size(); i++)
	{
		p_polyline->append(i, res[i]);
	}
	QPen pen_polyline(QColor(255, 0, 0));
	pen_polyline.setWidth(3);

	p_polyline->setPen(pen_polyline);

	m_series.append(p_polyline);



	//plot scatter
	int ncycle = 0;


	QScatterSeries *p_scatterS = new QScatterSeries();
	for (int i = 0; i < x.size(); i++)
	{
		p_scatterS->append(x[i], y[i]);
	}
	p_scatterS->setMarkerSize(7);
	m_scatterSeries.append(p_scatterS);

	//for (auto data : dataMat)
	//{
	//	QScatterSeries *p_scatterS = new QScatterSeries();
	//	for (int i = 0; i < data.size(); i++)
	//	{
	//		p_scatterS->append(nframeMark[ncycle][i], data[i]);
	//	}
	//	/*QPen pen_scatter(QColor(255,0,0));
	//	pen_scatter.setWidth(3);

	//	p_scatterS->setPen(pen_scatter);*/
	//	p_scatterS->setMarkerSize(7);
	//	m_scatterSeries.append(p_scatterS);

	//	ncycle++;
	//}
	for (auto serie : m_scatterSeries)
	{
		addSeries(serie);
	}
	for (auto serie : m_series)
	{
		addSeries(serie);
	}
	QBrush background(QColor(225, 225, 225));
	setBackgroundBrush(background);
	//setPlotAreaBackgroundBrush(background);
	legend()->hide();
	setAnimationOptions(QChart::NoAnimation);

	// Customize axis 
	QValueAxis * axisX = new QValueAxis();
	axisX->setRange(0, 360);
	axisX->setTickCount(5);
	axisX->setLabelFormat("%d");

	QValueAxis * axisY = new QValueAxis();
	axisY->setRange(-0.8, 0.2);
	axisY->setTickCount(7);
	//axisY->setLabelFormat("%d");

	QFont labelsFont;
	labelsFont.setPixelSize(20);
	axisX->setLabelsFont(labelsFont);
	axisY->setLabelsFont(labelsFont);
	axisX->setGridLineColor(QColor(245, 245, 245));
	axisY->setGridLineColor(QColor(245, 245, 245));

	axisX->setLinePenColor(QColor(245, 245, 245));
	axisY->setLinePenColor(QColor(245, 245, 245));
	addAxis(axisX, Qt::AlignBottom);
	addAxis(axisY, Qt::AlignLeft);

	for (auto serie : m_scatterSeries)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}
	for (auto serie : m_series)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}

	// Customize chart title
	QFont font;
	font.setPixelSize(30);
	setTitleFont(font);
	setTitleBrush(QBrush(Qt::black));
}

void LineChart::plotJointYZScatter(const OBJ::Obj & obj, JointType jt)
{
	QScatterSeries *p_scatterS = new QScatterSeries();
	for (auto joints: obj.getJoints())
	{
		p_scatterS->append(joints[jt].jointPosition.z() , joints[jt].jointPosition.y());
	}
	/*QPen pen_scatter(QColor(255,0,0));
	pen_scatter.setWidth(3);

	p_scatterS->setPen(pen_scatter);*/
	p_scatterS->setMarkerSize(8);
	m_scatterSeries.append(p_scatterS);

	for (auto serie : m_scatterSeries)
	{
		addSeries(serie);
	}

	QBrush background(QColor(225, 225, 225));
	setBackgroundBrush(background);
	//setPlotAreaBackgroundBrush(background);
	legend()->hide();
	setAnimationOptions(QChart::NoAnimation);

	// Customize axis 
	QValueAxis * axisX = new QValueAxis();
	axisX->setRange(1.9, 2.9);
	//axisX->setTickCount(5);
	//axisX->setLabelFormat("%d");

	QValueAxis * axisY = new QValueAxis();
	axisY->setRange(-0.8, 0.2);
	//axisY->setTickCount(7);
	//axisY->setLabelFormat("%d");

	QFont labelsFont;
	labelsFont.setPixelSize(20);
	axisX->setLabelsFont(labelsFont);
	axisY->setLabelsFont(labelsFont);
	axisX->setGridLineColor(QColor(245, 245, 245));
	axisY->setGridLineColor(QColor(245, 245, 245));

	axisX->setLinePenColor(QColor(245, 245, 245));
	axisY->setLinePenColor(QColor(245, 245, 245));
	addAxis(axisX, Qt::AlignBottom);
	addAxis(axisY, Qt::AlignLeft);

	for (auto serie : m_scatterSeries)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}

	// Customize chart title
	QFont font;
	font.setPixelSize(24);
	setTitleFont(font);
	setTitleBrush(QBrush(Qt::black));
}

void LineChart::plotAnkleYZScatter_circleFit(const OBJ::Obj & obj)
{
	//fit circle
	std::vector<double> vecX;
	std::vector<double> vecY;
	vecX.reserve(obj.getJoints().size());
	vecY.reserve(obj.getJoints().size());
	for (auto joints : obj.getJoints())
	{
		vecX.push_back(joints[JointType_AnkleLeft].jointPosition.z());
		vecY.push_back(joints[JointType_AnkleLeft].jointPosition.y());
	}
	double centerX = 0;
	double centerY = 0;
	double radius = 0;
	myMath::circleLeastFit(vecX, vecY, centerX, centerY, radius);
	std::cout << "centerX:" << centerX << " , " << "centerY:" << centerY << " , " << "radius:" << radius << std::endl;
	//plot circle
	QLineSeries *p_circleUp = new QLineSeries();
	double xl = centerX - radius;
	double xr = centerX + radius;
	while (xl < xr + 0.01)
	{
		double yvelue = sqrt(pow(radius,2) - pow(xl - centerX, 2)) + centerY;
		p_circleUp->append(xl, yvelue);
		xl += 0.005;
	}
	QLineSeries *p_circleDown = new QLineSeries();
	xl = centerX - radius;
	xr = centerX + radius;
	while (xl < xr + 0.01)
	{
		double yvelue = - sqrt(pow(radius, 2) - pow(xl - centerX, 2)) + centerY;
		p_circleDown->append(xl, yvelue);
		xl += 0.005;
	}
	QPen pen_circle(QColor(255, 0, 0));
	pen_circle.setWidth(5);
	p_circleDown->setPen(pen_circle);
	p_circleUp->setPen(pen_circle);
	m_series.append(p_circleDown);
	m_series.append(p_circleUp);

	QScatterSeries *p_scatterS = new QScatterSeries();
	for (auto joints : obj.getJoints())
	{
		p_scatterS->append(joints[JointType_AnkleLeft].jointPosition.z(), joints[JointType_AnkleLeft].jointPosition.y());
	}
	/*QPen pen_scatter(QColor(255,0,0));
	pen_scatter.setWidth(3);

	p_scatterS->setPen(pen_scatter);*/
	p_scatterS->setMarkerSize(8);
	m_scatterSeries.append(p_scatterS);

	for (auto serie : m_scatterSeries)
	{
		addSeries(serie);
	}
	for (auto serie : m_series) {
		addSeries(serie);
	}

	QBrush background(QColor(225, 225, 225));
	setBackgroundBrush(background);
	//setPlotAreaBackgroundBrush(background);
	legend()->hide();
	setAnimationOptions(QChart::NoAnimation);

	// Customize axis 
	QValueAxis * axisX = new QValueAxis();
	axisX->setRange(1.9, 2.9);
	//axisX->setTickCount(5);
	//axisX->setLabelFormat("%d");

	QValueAxis * axisY = new QValueAxis();
	axisY->setRange(-0.8, 0.2);
	//axisY->setTickCount(7);
	//axisY->setLabelFormat("%d");

	QFont labelsFont;
	labelsFont.setPixelSize(20);
	axisX->setLabelsFont(labelsFont);
	axisY->setLabelsFont(labelsFont);
	axisX->setGridLineColor(QColor(245, 245, 245));
	axisY->setGridLineColor(QColor(245, 245, 245));

	axisX->setLinePenColor(QColor(245, 245, 245));
	axisY->setLinePenColor(QColor(245, 245, 245));
	addAxis(axisX, Qt::AlignBottom);
	addAxis(axisY, Qt::AlignLeft);

	for (auto serie : m_scatterSeries)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}
	for (auto serie : m_series)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}

	// Customize chart title
	QFont font;
	font.setPixelSize(24);
	setTitleFont(font);
	setTitleBrush(QBrush(Qt::black));
}

void LineChart::plotKneeYZScatter_polyFit(const OBJ::Obj & obj)
{
	//plot polyfit
	QLineSeries *p_polyfit = new QLineSeries();

	for (int i = 0; i < obj.Trajectory_Knee.size(); i++)
	{
		p_polyfit->append(obj.Trajectory_Knee[i].z(), obj.Trajectory_Knee[i].y());
	}
	QPen pen_polyfit(QColor(255,0,0));
	pen_polyfit.setWidth(5);
	p_polyfit->setPen(pen_polyfit);
	m_series.append(p_polyfit);



	QScatterSeries *p_scatterS = new QScatterSeries();
	for (auto joints : obj.getJoints())
	{
		p_scatterS->append(joints[JointType_KneeLeft].jointPosition.z(), joints[JointType_KneeLeft].jointPosition.y());
	}
	/*QPen pen_scatter(QColor(255,0,0));
	pen_scatter.setWidth(3);

	p_scatterS->setPen(pen_scatter);*/
	p_scatterS->setMarkerSize(8);
	m_scatterSeries.append(p_scatterS);

	for (auto serie : m_scatterSeries)
	{
		addSeries(serie);
	}
	for (auto serie : m_series) {
		addSeries(serie);
	}

	QBrush background(QColor(225, 225, 225));
	setBackgroundBrush(background);
	//setPlotAreaBackgroundBrush(background);
	legend()->hide();
	setAnimationOptions(QChart::NoAnimation);

	// Customize axis 
	QValueAxis * axisX = new QValueAxis();
	axisX->setRange(1.9, 2.9);
	//axisX->setTickCount(5);
	//axisX->setLabelFormat("%d");

	QValueAxis * axisY = new QValueAxis();
	axisY->setRange(-0.8, 0.2);
	//axisY->setTickCount(7);
	//axisY->setLabelFormat("%d");

	QFont labelsFont;
	labelsFont.setPixelSize(20);
	axisX->setLabelsFont(labelsFont);
	axisY->setLabelsFont(labelsFont);
	axisX->setGridLineColor(QColor(245, 245, 245));
	axisY->setGridLineColor(QColor(245, 245, 245));

	axisX->setLinePenColor(QColor(245, 245, 245));
	axisY->setLinePenColor(QColor(245, 245, 245));
	addAxis(axisX, Qt::AlignBottom);
	addAxis(axisY, Qt::AlignLeft);

	for (auto serie : m_scatterSeries)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}
	for (auto serie : m_series)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}

	// Customize chart title
	QFont font;
	font.setPixelSize(24);
	setTitleFont(font);
	setTitleBrush(QBrush(Qt::black));
}

void LineChart::plotVicon_Kinect_Fit(std::vector<Cycle>& cycles, std::vector<double> vicondata, const OBJ::Obj & obj)
{
	////畫Fit trajectory 的結果
	//QLineSeries *p_lineTraj = new QLineSeries();
	//for (int i = 0; i < obj.cycleAngleframes.size(); i++)
	//{
	//	p_lineTraj->append(i, obj.cycleAngleframes[i][1]);
	//}
	//QPen pen_traj(QColor(0,255,0));
	//pen_traj.setWidth(3);
	//p_lineTraj->setPen(pen_traj);
	//m_series.append(p_lineTraj);
	for (int ncycle = 0; ncycle < cycles.size(); ncycle++)
	{
		//画polyfit曲线
		QLineSeries *p_lineS = new QLineSeries();
		QLineSeries *p_lineFit = new QLineSeries();
		//p_lineS->setColor(QColor(255, 0, 0));
		std::vector<double> p = cycles[ncycle].getAvePara();
		for (int i = 0; i < 361; i++)
		{
			double y_value = 0;

			for (int n = 0; n < p.size(); n++)
			{
				y_value += pow(i, n)*p[n];
			}
			p_lineS->append(i, y_value);
			if (i<181)
			{
				p_lineFit->append(i, y_value + (i*0.11));
			}
			else
			{
				p_lineFit->append(i, y_value + ((361-i)*0.11));
			}
			
		}
		QPen pen(m_colors[ncycle + 1]);
		pen.setWidth(3);
		p_lineS->setPen(pen);
		m_series.append(p_lineS);
		QPen pen_fit(QColor(0,255,0));
		pen_fit.setWidth(3);
		p_lineFit->setPen(pen_fit);
		m_series.append(p_lineFit);
		//hua fit
		


		//画vicondata
		QLineSeries *p_lineVicon = new QLineSeries();
		for (int i = 0; i < vicondata.size(); i++)
		{
			p_lineVicon->append(double(i) / vicondata.size() * 361.0, vicondata[i]);
		}
		QPen pen_vicon(m_colors[0]);
		pen_vicon.setWidth(3);
		p_lineVicon->setPen(pen_vicon);
		m_series.append(p_lineVicon);
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
			y_value_u += cycles[ncycle].getMeanSqErr()[i];
			y_value_d -= cycles[ncycle].getMeanSqErr()[i];
			up->append(i, y_value_u);
			down->append(i, y_value_d);
		}
		QAreaSeries *areaS = new QAreaSeries(up, down);
		QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));

		areaS->setColor(m_colorsA[ncycle]);
		areaS->setBorderColor(m_colorsA[ncycle]);
		m_areaSeries.append(areaS);
	}

	for (auto serie : m_areaSeries)
	{
		addSeries(serie);
	}

	for (auto serie : m_series)
	{
		addSeries(serie);
	}


	QBrush background(QColor(225, 225, 225));
	setBackgroundBrush(background);
	//setPlotAreaBackgroundBrush(background);
	legend()->hide();
	setAnimationOptions(QChart::NoAnimation);

	// Customize axis 
	QValueAxis * axisX = new QValueAxis();
	axisX->setRange(0, 360);
	axisX->setTickCount(5);
	axisX->setLabelFormat("%d");

	QValueAxis * axisY = new QValueAxis();
	axisY->setRange(0, 120);
	axisY->setTickCount(7);
	axisY->setLabelFormat("%d");

	QFont labelsFont;
	labelsFont.setPixelSize(10);
	axisX->setLabelsFont(labelsFont);
	axisY->setLabelsFont(labelsFont);
	axisX->setGridLineColor(QColor(245, 245, 245));
	axisY->setGridLineColor(QColor(245, 245, 245));

	axisX->setLinePenColor(QColor(245, 245, 245));
	axisY->setLinePenColor(QColor(245, 245, 245));
	addAxis(axisX, Qt::AlignBottom);
	addAxis(axisY, Qt::AlignLeft);

	for (auto serie : m_series)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}

	for (auto serie : m_areaSeries)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}

	// Customize chart title
	QFont font;
	font.setPixelSize(14);
	setTitleFont(font);
	setTitleBrush(QBrush(Qt::black));
}

void LineChart::plotNviconMeanSqErr_Hip(stdMatd viconMat, std::vector<Cycle>& cycles)
{
	//畫kinect
	//画polyfit曲线

	QLineSeries *p_lineFit = new QLineSeries();
	//p_lineS->setColor(QColor(255, 0, 0));
	std::vector<double> p = cycles[0].getAvePara();
	for (int i = 0; i < 361; i++)
	{
		double y_value = 0;

		for (int n = 0; n < p.size(); n++)
		{
			y_value += pow(i, n)*p[n];
		}
		if (i < 181)
		{
			p_lineFit->append(i, y_value + (i*0.11)+11);
		}
		else
		{
			p_lineFit->append(i, y_value + ((361 - i)*0.11)+11);
		}

	}
	QPen pen_fit(m_colors[2]);
	pen_fit.setWidth(3);
	p_lineFit->setPen(pen_fit);
	m_series.append(p_lineFit);




	//畫vicon
	stdMatd polyxMat;
	for (auto vicondata : viconMat)
	{
		std::vector<double> polyx;
		for (int i = 0; i < vicondata.size(); i++)
		{
			polyx.push_back(double(i) / (vicondata.size() - 1) * 360);
		}
		polyxMat.push_back(polyx);
	}

	//画fit曲线
	QLineSeries *p_lineS = new QLineSeries();
	p_lineS->setColor(QColor(255, 0, 0));
	stdMatd polypMat = Cycle::polyfit(polyxMat, viconMat, 8);
	std::vector<double> AveP = Cycle::calAvePara(polypMat);
	std::vector<double> meanSqErr = Cycle::calMeanSqErr(polypMat, AveP);

	std::vector<double> polyX(360, 0.0);
	for (int i = 0; i < polyX.size(); i++)
	{
		polyX[i] = double(i);
	}
	std::vector<double> polyRes = myMath::polyRes(AveP, polyX);

	for (int i = 0; i < polyX.size(); i++)
	{
		p_lineS->append(i, polyRes[i]);
	}

	QPen pen(m_colors[0]);
	pen.setWidth(3);
	p_lineS->setPen(pen);
	m_series.append(p_lineS);

	//画均方根
	QLineSeries *up = new QLineSeries();
	QLineSeries *down = new QLineSeries();
	for (int i = 0; i < 361; i++)
	{
		double y_value_u = 0;
		double y_value_d = 0;
		for (int n = 0; n < AveP.size(); n++)
		{
			y_value_u += pow(i, n)*AveP[n];
			y_value_d += pow(i, n)*AveP[n];
		}
		y_value_u += meanSqErr[i];
		y_value_d -= meanSqErr[i];
		up->append(i, y_value_u);
		down->append(i, y_value_d);
	}
	QAreaSeries *areaS = new QAreaSeries(up, down);
	//QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
	/*gradient.setColorAt(0.0, 0x3cc63c);
	gradient.setColorAt(1.0, 0x26f626);
	gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
	areaS->setBrush(gradient);*/
	areaS->setColor(m_colorsA[0]);
	areaS->setBorderColor(m_colorsA[0]);
	m_areaSeries.append(areaS);

	//kinect画均方根
	QLineSeries *up_kinect = new QLineSeries();
	QLineSeries *down_kinect = new QLineSeries();
	for (int i = 0; i < 361; i++)
	{
		double y_value_u = 0;
		double y_value_d = 0;
		for (int n = 0; n < p.size(); n++)
		{
			y_value_u += pow(i, n)*p[n];
			y_value_d += pow(i, n)*p[n];
		}
		y_value_u += cycles[0].getMeanSqErr()[i];
		y_value_d -= cycles[0].getMeanSqErr()[i];
		if (i < 181)
		{
			up_kinect->append(i, y_value_u + (i*0.11)+11);
			down_kinect->append(i, y_value_d + (i*0.11)+11);
		}
		else
		{
			up_kinect->append(i, y_value_u + ((361 - i)*0.11)+11);
			down_kinect->append(i, y_value_d + ((361 - i)*0.11)+11);
		}
	}
	QAreaSeries *areaS_kinect = new QAreaSeries(up_kinect, down_kinect);
	//QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));

	areaS_kinect->setColor(m_colorsA[2]);
	areaS_kinect->setBorderColor(m_colorsA[2]);
	m_areaSeries.append(areaS_kinect);

	for (auto serie : m_areaSeries)
	{
		addSeries(serie);
	}

	for (auto serie : m_series)
	{
		addSeries(serie);
	}


	QBrush background(QColor(225, 225, 225));
	setBackgroundBrush(background);
	//setPlotAreaBackgroundBrush(background);
	legend()->hide();
	setAnimationOptions(QChart::NoAnimation);

	// Customize axis 
	QValueAxis * axisX = new QValueAxis();
	axisX->setRange(0, 360);
	axisX->setTickCount(5);
	axisX->setLabelFormat("%d");

	QValueAxis * axisY = new QValueAxis();
	axisY->setRange(0, 120);
	axisY->setTickCount(7);
	axisY->setLabelFormat("%d");

	QFont labelsFont;
	labelsFont.setPixelSize(10);
	axisX->setLabelsFont(labelsFont);
	axisY->setLabelsFont(labelsFont);
	axisX->setGridLineColor(QColor(245, 245, 245));
	axisY->setGridLineColor(QColor(245, 245, 245));

	axisX->setLinePenColor(QColor(245, 245, 245));
	axisY->setLinePenColor(QColor(245, 245, 245));
	addAxis(axisX, Qt::AlignBottom);
	addAxis(axisY, Qt::AlignLeft);

	for (auto serie : m_series)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}

	for (auto serie : m_areaSeries)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}

	// Customize chart title
	QFont font;
	font.setPixelSize(14);
	setTitleFont(font);
	setTitleBrush(QBrush(Qt::black));
}

void LineChart::plotNviconMeanSqErr_Ankle(stdMatd viconMat, std::vector<Cycle>& cycles)
{
	//畫kinect
	//画polyfit曲线

	QLineSeries *p_lineFit = new QLineSeries();
	//p_lineS->setColor(QColor(255, 0, 0));
	std::vector<double> p = cycles[0].getAvePara();
	for (int i = 0; i < 361; i++)
	{
		double y_value = 0;

		for (int n = 0; n < p.size(); n++)
		{
			y_value += pow(i, n)*p[n];
		}
		if (i < 181)
		{
			p_lineFit->append(i, y_value + (i*0.0));
		}
		else
		{
			p_lineFit->append(i, y_value + ((361 - i)*0.0));
		}

	}
	QPen pen_fit(m_colors[2]);
	pen_fit.setWidth(3);
	p_lineFit->setPen(pen_fit);
	m_series.append(p_lineFit);




	//畫vicon
	stdMatd polyxMat;
	for (auto vicondata : viconMat)
	{
		std::vector<double> polyx;
		for (int i = 0; i < vicondata.size(); i++)
		{
			polyx.push_back(double(i) / (vicondata.size() - 1) * 360);
		}
		polyxMat.push_back(polyx);
	}

	//画fit曲线
	QLineSeries *p_lineS = new QLineSeries();
	p_lineS->setColor(QColor(255, 0, 0));
	stdMatd polypMat = Cycle::polyfit(polyxMat, viconMat, 8);
	std::vector<double> AveP = Cycle::calAvePara(polypMat);
	std::vector<double> meanSqErr = Cycle::calMeanSqErr(polypMat, AveP);

	std::vector<double> polyX(360, 0.0);
	for (int i = 0; i < polyX.size(); i++)
	{
		polyX[i] = double(i);
	}
	std::vector<double> polyRes = myMath::polyRes(AveP, polyX);

	for (int i = 0; i < polyX.size(); i++)
	{
		p_lineS->append(i, polyRes[i]);
	}

	QPen pen(m_colors[0]);
	pen.setWidth(3);
	p_lineS->setPen(pen);
	m_series.append(p_lineS);

	//画均方根
	QLineSeries *up = new QLineSeries();
	QLineSeries *down = new QLineSeries();
	for (int i = 0; i < 361; i++)
	{
		double y_value_u = 0;
		double y_value_d = 0;
		for (int n = 0; n < AveP.size(); n++)
		{
			y_value_u += pow(i, n)*AveP[n];
			y_value_d += pow(i, n)*AveP[n];
		}
		y_value_u += meanSqErr[i];
		y_value_d -= meanSqErr[i];
		up->append(i, y_value_u);
		down->append(i, y_value_d);
	}
	QAreaSeries *areaS = new QAreaSeries(up, down);
	//QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
	/*gradient.setColorAt(0.0, 0x3cc63c);
	gradient.setColorAt(1.0, 0x26f626);
	gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
	areaS->setBrush(gradient);*/
	areaS->setColor(m_colorsA[0]);
	areaS->setBorderColor(m_colorsA[0]);
	m_areaSeries.append(areaS);

	//kinect画均方根
	QLineSeries *up_kinect = new QLineSeries();
	QLineSeries *down_kinect = new QLineSeries();
	for (int i = 0; i < 361; i++)
	{
		double y_value_u = 0;
		double y_value_d = 0;
		for (int n = 0; n < p.size(); n++)
		{
			y_value_u += pow(i, n)*p[n];
			y_value_d += pow(i, n)*p[n];
		}
		y_value_u += cycles[0].getMeanSqErr()[i];
		y_value_d -= cycles[0].getMeanSqErr()[i];
		if (i < 181)
		{
			up_kinect->append(i, y_value_u + (i*0.0));
			down_kinect->append(i, y_value_d + (i*0.0));
		}
		else
		{
			up_kinect->append(i, y_value_u + ((361 - i)*0.0));
			down_kinect->append(i, y_value_d + ((361 - i)*0.0));
		}
	}
	QAreaSeries *areaS_kinect = new QAreaSeries(up_kinect, down_kinect);
	//QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));

	areaS_kinect->setColor(m_colorsA[2]);
	areaS_kinect->setBorderColor(m_colorsA[2]);
	m_areaSeries.append(areaS_kinect);

	for (auto serie : m_areaSeries)
	{
		addSeries(serie);
	}

	for (auto serie : m_series)
	{
		addSeries(serie);
	}


	QBrush background(QColor(225, 225, 225));
	setBackgroundBrush(background);
	//setPlotAreaBackgroundBrush(background);
	legend()->hide();
	setAnimationOptions(QChart::NoAnimation);

	// Customize axis 
	QValueAxis * axisX = new QValueAxis();
	axisX->setRange(0, 360);
	axisX->setTickCount(5);
	axisX->setLabelFormat("%d");

	QValueAxis * axisY = new QValueAxis();
	axisY->setRange(0, 120);
	axisY->setTickCount(7);
	axisY->setLabelFormat("%d");

	QFont labelsFont;
	labelsFont.setPixelSize(10);
	axisX->setLabelsFont(labelsFont);
	axisY->setLabelsFont(labelsFont);
	axisX->setGridLineColor(QColor(245, 245, 245));
	axisY->setGridLineColor(QColor(245, 245, 245));

	axisX->setLinePenColor(QColor(245, 245, 245));
	axisY->setLinePenColor(QColor(245, 245, 245));
	addAxis(axisX, Qt::AlignBottom);
	addAxis(axisY, Qt::AlignLeft);

	for (auto serie : m_series)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}

	for (auto serie : m_areaSeries)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}

	// Customize chart title
	QFont font;
	font.setPixelSize(14);
	setTitleFont(font);
	setTitleBrush(QBrush(Qt::black));
}

void LineChart::plotNviconMeanSqErr_Knee(stdMatd viconMat, std::vector<Cycle> & cycles)
{
	//畫kinect
	//画polyfit曲线

	QLineSeries *p_lineFit = new QLineSeries();
	//p_lineS->setColor(QColor(255, 0, 0));
	std::vector<double> p = cycles[0].getAvePara();
	for (int i = 0; i < 361; i++)
	{
		double y_value = 0;

		for (int n = 0; n < p.size(); n++)
		{
			y_value += pow(i, n)*p[n];
		}
		if (i < 181)
		{
			p_lineFit->append(i, y_value + (i*0.11));
		}
		else
		{
			p_lineFit->append(i, y_value + ((361 - i)*0.11));
		}

	}
	QPen pen_fit(m_colors[2]);
	pen_fit.setWidth(3);
	p_lineFit->setPen(pen_fit);
	m_series.append(p_lineFit);
	



	//畫vicon
	stdMatd polyxMat;
	for (auto vicondata:viconMat)
	{
		std::vector<double> polyx;
		for (int i = 0; i < vicondata.size(); i++)
		{
			polyx.push_back(double(i) / (vicondata.size() - 1) * 360);
		}
		polyxMat.push_back(polyx);
	}
	
	//画fit曲线
	QLineSeries *p_lineS = new QLineSeries();
	p_lineS->setColor(QColor(255, 0, 0));
	stdMatd polypMat = Cycle::polyfit(polyxMat, viconMat, 8);
	std::vector<double> AveP = Cycle::calAvePara(polypMat);
	std::vector<double> meanSqErr = Cycle::calMeanSqErr(polypMat, AveP);

	std::vector<double> polyX(360, 0.0);
	for (int i = 0; i < polyX.size(); i++)
	{
		polyX[i] = double(i);
	}
	std::vector<double> polyRes = myMath::polyRes(AveP, polyX);

	for (int i = 0; i < polyX.size(); i++)
	{
		p_lineS->append(i, polyRes[i]);
	}

	QPen pen(m_colors[0]);
	pen.setWidth(3);
	p_lineS->setPen(pen);
	m_series.append(p_lineS);

	//画均方根
	QLineSeries *up = new QLineSeries();
	QLineSeries *down = new QLineSeries();
	for (int i = 0; i < 361; i++)
	{
		double y_value_u = 0;
		double y_value_d = 0;
		for (int n = 0; n < AveP.size(); n++)
		{
			y_value_u += pow(i, n)*AveP[n];
			y_value_d += pow(i, n)*AveP[n];
		}
		y_value_u += meanSqErr[i];
		y_value_d -= meanSqErr[i];
		up->append(i, y_value_u);
		down->append(i, y_value_d);
	}
	QAreaSeries *areaS = new QAreaSeries(up, down);
	//QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
	/*gradient.setColorAt(0.0, 0x3cc63c);
	gradient.setColorAt(1.0, 0x26f626);
	gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
	areaS->setBrush(gradient);*/
	areaS->setColor(m_colorsA[0]);
	areaS->setBorderColor(m_colorsA[0]);
	m_areaSeries.append(areaS);

	//kinect画均方根
	QLineSeries *up_kinect = new QLineSeries();
	QLineSeries *down_kinect = new QLineSeries();
	for (int i = 0; i < 361; i++)
	{
		double y_value_u = 0;
		double y_value_d = 0;
		for (int n = 0; n < p.size(); n++)
		{
			y_value_u += pow(i, n)*p[n];
			y_value_d += pow(i, n)*p[n];
		}
		y_value_u += cycles[0].getMeanSqErr()[i];
		y_value_d -= cycles[0].getMeanSqErr()[i];
		if (i < 181)
		{
			up_kinect->append(i, y_value_u + (i*0.11));
			down_kinect->append(i, y_value_d + (i*0.11));
		}
		else
		{
			up_kinect->append(i, y_value_u + ((361 - i)*0.11));
			down_kinect->append(i, y_value_d + ((361 - i)*0.11));
		}
	}
	QAreaSeries *areaS_kinect = new QAreaSeries(up_kinect, down_kinect);
	//QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));

	areaS_kinect->setColor(m_colorsA[2]);
	areaS_kinect->setBorderColor(m_colorsA[2]);
	m_areaSeries.append(areaS_kinect);

	for (auto serie : m_areaSeries)
	{
		addSeries(serie);
	}

	for (auto serie : m_series)
	{
		addSeries(serie);
	}


	QBrush background(QColor(225, 225, 225));
	setBackgroundBrush(background);
	//setPlotAreaBackgroundBrush(background);
	legend()->hide();
	setAnimationOptions(QChart::NoAnimation);

	// Customize axis 
	QValueAxis * axisX = new QValueAxis();
	axisX->setRange(0, 360);
	axisX->setTickCount(5);
	axisX->setLabelFormat("%d");

	QValueAxis * axisY = new QValueAxis();
	axisY->setRange(0, 120);
	axisY->setTickCount(7);
	axisY->setLabelFormat("%d");

	QFont labelsFont;
	labelsFont.setPixelSize(10);
	axisX->setLabelsFont(labelsFont);
	axisY->setLabelsFont(labelsFont);
	axisX->setGridLineColor(QColor(245, 245, 245));
	axisY->setGridLineColor(QColor(245, 245, 245));

	axisX->setLinePenColor(QColor(245, 245, 245));
	axisY->setLinePenColor(QColor(245, 245, 245));
	addAxis(axisX, Qt::AlignBottom);
	addAxis(axisY, Qt::AlignLeft);

	for (auto serie : m_series)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}

	for (auto serie : m_areaSeries)
	{
		serie->attachAxis(axisX);
		serie->attachAxis(axisY);
	}

	// Customize chart title
	QFont font;
	font.setPixelSize(14);
	setTitleFont(font);
	setTitleBrush(QBrush(Qt::black));



}






	

