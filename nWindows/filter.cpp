#include "filter.h"


void Filter::FRILP_Filter(std::vector<OBJ::Joints>& jframes)
{
	
}

std::vector<OBJ::Joints> Filter::LP_Filter(std::vector<OBJ::Joints>& jframes,int factor)
{
	std::vector<OBJ::Joints> res = jframes;
	int frameNumber = jframes.size();
	Eigen::MatrixXd X(frameNumber,25), Y(frameNumber, 25), Z(frameNumber, 25);
	
	for (int i = 0; i < jframes.size(); ++i)
	{
		for (int j = 0; j < 25; j++)
		{
			X(i, j) = jframes[i][j].jointPosition.x();
			Y(i, j) = jframes[i][j].jointPosition.y();
			Z(i, j) = jframes[i][j].jointPosition.z();
		}	
	}
	X = smoothMatrix(X, factor);
	Y = smoothMatrix(Y, factor);
	Z = smoothMatrix(Z, factor);

	for (int i = 0; i < jframes.size(); ++i)
	{
		for (int j = 0; j < 25; ++j)
		{
			res[i][j].jointPosition = Eigen::Vector3f(X(i,j), Y(i, j), Z(i, j));
		}
	}
	return res;	
}



Eigen::VectorXd Filter::smoothArray(Eigen::VectorXd data,int factor)
{
	Eigen::VectorXd res(data.size());
	float value = data(0);
	for (int i = 1; i < data.size(); i++)
	{
		float currentValue = data(i);
		value += (currentValue - value) / float(factor);
		data(i) = value;
	}
	res = data;
	return res;
}

Eigen::MatrixXd Filter::smoothMatrix(Eigen::MatrixXd data, int factor)
{
	Eigen::MatrixXd res(data.rows(), data.cols());//rows是帧数，cols是jointtype
	for (int i = 0; i < data.cols(); i++)
	{
		res.col(i) = smoothArray(data.col(i), factor);
	}
	return res;
}

Eigen::VectorXd Filter::polyfit(Eigen::VectorXd data, int n)
{
	
	int size = data.size();
	int x_num = n + 1;//所求未知数个数
	//构造矩阵U和Y

	Eigen::MatrixXd U, Y;
	U.resize(size, x_num);
	Y.resize(size, 1);

	for (int i = 0; i < U.rows(); ++i) {
		for (int j = 0; j < U.cols(); ++j)
		{
			U(i, j) = pow(i, j);
		}
	}

	for (int i = 0; i < data.rows(); ++i) {
		{
			Y(i, 0) = data[i];
		}
	}

	//矩阵运算，获得系数矩阵K

	Eigen::VectorXd K;
	K.resize(x_num);
	K = (U.transpose()*U).inverse() *U.transpose()*Y;

	//std::cout << "poly fit parameter:" << std::endl;
	//std::cout << K << std::endl;
	
	Eigen::VectorXd res(data.size());
	
	for (int i = 0; i < res.size(); i++)
	{
		double y_value = 0;

		for (int n = 0; n < K.size(); n++)
		{
			y_value += pow(i, n)*K[n];
		}
		res(i)= y_value;
	}
	return res;
}




