#include "myMath.h"



myMath::myMath()
{
}


myMath::~myMath()
{
}

std::vector<double> myMath::VectorXd_2_stdVector(Eigen::VectorXd v)
{
	std::vector<double> res;
	res.reserve(v.size());
	for (int i = 0; i < v.size(); i++)
	{
		res.push_back(v(i));
	}
	return res;
}

Eigen::VectorXd myMath::stdVector_2_VectorXd(std::vector<double> vec)
{
	Eigen::VectorXd res(vec.size());
	for (int i = 0; i < vec.size(); i++)
	{
		res(i) = vec[i];
	}
	return res;
}

std::vector<double> myMath::polyDer(std::vector<double> p, int dorder)
{
	std::vector<double> P = p;
	std::vector<double> dp;
	for (int j = 0; j < dorder; j++)
	{
		dp.clear();
		int n = P.size() - 1;
		std::reverse(P.begin(), P.end());
		for (int i = 0; i < n; i++)
		{
			dp.push_back(P[i + 1] * (i + 1));
		}
		std::reverse(dp.begin(), dp.end());
		P = dp;
	}

	return dp;

}

std::vector<double> myMath::polyfit(std::vector<double> x, std::vector<double> y, int n)
{
	Eigen::VectorXd vecX = stdVector_2_VectorXd(x);
	Eigen::VectorXd vecY = stdVector_2_VectorXd(y);
	int size = vecX.size();
	int x_num = n + 1;//所求未知数个数
					  //构造矩阵U和Y

	Eigen::MatrixXd U, Y;
	U.resize(size, x_num);
	Y.resize(size, 1);

	for (int i = 0; i < U.rows(); ++i) {
		for (int j = 0; j < U.cols(); ++j)
		{
			U(i, j) = pow(vecX[i], j);
		}
	}

	for (int i = 0; i < vecY.rows(); ++i) {
		{
			Y(i, 0) = vecY[i];
		}
	}

	//矩阵运算，获得系数矩阵K

	Eigen::VectorXd K;
	K.resize(x_num);
	K = (U.transpose()*U).inverse() *U.transpose()*Y;

	//std::cout << "poly fit parameter:" << std::endl;
	//std::cout << K << std::endl;

	return VectorXd_2_stdVector(K);
}

std::vector<double> myMath::polyRes(std::vector<double> p, std::vector<double> x)
{
	std::vector<double> res;
	res.reserve(x.size());
	for (int i = 0; i < x.size(); i++)
	{
		double y_value = 0;

		for (int n = 0; n < p.size(); n++)
		{
			y_value += pow(x[i], n)*p[n];
		}
		res.push_back(y_value);
	}
	return res;
}

std::vector<double> myMath::leastSquaresFit_sin(std::vector<double> x, std::vector<double> y)
{
	parameter_vector p;
	std::vector<std::pair<double, double> > data;
	for (int i = 0; i < x.size(); ++i)
	{
		const double input = x[i];
		const double output = y[i];

		// save the pair
		data.push_back(std::make_pair(input, output));
	}
	dlib::solve_least_squares(dlib::objective_delta_stop_strategy(1e-7).be_verbose(),
		residual_sin,
		dlib::derivative(residual_sin),
		data,
		p);

	std::vector<double> res{ p(0),p(1),p(2),p(3) };
	return res;
		
}

std::vector<double> myMath::leastSquaresFit_cubic(std::vector<double> x, std::vector<double> y)
{
	parameter_vector p;
	std::vector<std::pair<double, double> > data;
	for (int i = 0; i < x.size(); ++i)
	{
		const double input = x[i];
		const double output = y[i];

		// save the pair
		data.push_back(std::make_pair(input, output));
	}
	dlib::solve_least_squares(dlib::objective_delta_stop_strategy(1e-7).be_verbose(),
		residual_cubic,
		dlib::derivative(residual_cubic),
		data,
		p);

	std::vector<double> res{ p(0),p(1),p(2),p(3) };
	return res;
}

double myMath::residual_cubic(const std::pair<double, double>& data, const parameter_vector & params)
{
	return model_cubic(data.first, params) - data.second;
}

double myMath::model_cubic(const double input, const parameter_vector & params)
{

	double temp = 0;
	for (int n = 0; n < params.size(); n++)
	{
		temp += pow(input, n)*params(n);
	}
	

	return temp;
}

double myMath::residual_sin(const std::pair<double, double>& data, const parameter_vector & params)
{
	return model_sin(data.first, params) - data.second;
}

double myMath::model_sin(const double input, const parameter_vector & params)
{
	//Asin(ωx+φ)+k
	return params(0)*sin(params(1)*input+ params(2))+params(3);
}

bool myMath::circleLeastFit(std::vector<double> vecX, std::vector<double> vecY, double & center_x, double & center_y, double & radius)
{
	center_x = 0.0f;
	center_y = 0.0f;
	radius = 0.0f;
	if (vecX.size() < 3 || vecX.size()!=vecY.size())
	{
		return false;
	}

	double sum_x = 0.0f, sum_y = 0.0f;
	double sum_x2 = 0.0f, sum_y2 = 0.0f;
	double sum_x3 = 0.0f, sum_y3 = 0.0f;
	double sum_xy = 0.0f, sum_x1y2 = 0.0f, sum_x2y1 = 0.0f;

	int N = vecX.size();
	for (int i = 0; i < N; i++)
	{
		double x = vecX[i];
		double y = vecY[i];
		double x2 = x * x;
		double y2 = y * y;
		sum_x += x;
		sum_y += y;
		sum_x2 += x2;
		sum_y2 += y2;
		sum_x3 += x2 * x;
		sum_y3 += y2 * y;
		sum_xy += x * y;
		sum_x1y2 += x * y2;
		sum_x2y1 += x2 * y;
	}

	double C, D, E, G, H;
	double a, b, c;

	C = N * sum_x2 - sum_x * sum_x;
	D = N * sum_xy - sum_x * sum_y;
	E = N * sum_x3 + N * sum_x1y2 - (sum_x2 + sum_y2) * sum_x;
	G = N * sum_y2 - sum_y * sum_y;
	H = N * sum_x2y1 + N * sum_y3 - (sum_x2 + sum_y2) * sum_y;
	a = (H * D - E * G) / (C * G - D * D);
	b = (H * C - E * D) / (D * D - G * C);
	c = -(a * sum_x + b * sum_y + sum_x2 + sum_y2) / N;

	center_x = a / (-2);
	center_y = b / (-2);
	radius = sqrt(a * a + b * b - 4 * c) / 2;
	return true;
}

