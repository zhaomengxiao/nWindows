#pragma once
#include <vector>
#include <Eigen/dense>
#include <dlib/optimization.h>
//typedef dlib::matrix<double, 2, 1> input_vector;
typedef dlib::matrix<double, 4, 1> parameter_vector;
class myMath
{
public:
	myMath();
	~myMath();
	static std::vector<double> VectorXd_2_stdVector(Eigen::VectorXd v);
	static Eigen::VectorXd stdVector_2_VectorXd(std::vector<double> vec);
	static std::vector<double> polyDer(std::vector<double> p, int dorder);
	static std::vector<double> polyfit(std::vector<double> x, std::vector<double> y, int n);
	
	//將polyfit的參數還原到曲線上的數據點
	//p:ployfit得到的參數
	//x:數據點對應的x軸坐標
	static std::vector<double> polyRes(std::vector<double> p, std::vector<double> x);

	//最小平方法曲線擬合 
	static std::vector<double> leastSquaresFit_sin(std::vector<double> x, std::vector<double> y);
	static std::vector<double> leastSquaresFit_cubic(std::vector<double> x, std::vector<double> y);
	static double residual_cubic(const std::pair<double, double>& data,
		const parameter_vector& params);
	static double model_cubic(const double input,const parameter_vector& params);
	
	static double residual_sin(const std::pair<double, double>& data,
		const parameter_vector& params);
	static double model_sin(const double input, const parameter_vector& params);
	//擬合圓
	typedef std::complex<int> POINT;
	static bool circleLeastFit(std::vector<double> x, std::vector<double> y, double &center_x, double &center_y, double &radius);
};

