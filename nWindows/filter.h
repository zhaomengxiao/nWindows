#pragma once

#include "obj.h"


class Filter 
{

public:

	//Frame Rate-Independent Low-Pass Filter
	static void FRILP_Filter(std::vector<OBJ::Joints> & jframes);
	static std::vector<OBJ::Joints> LP_Filter(std::vector<OBJ::Joints> & jframes,int factor);
	static Eigen::VectorXd smoothArray(Eigen::VectorXd data, int factor);
	static Eigen::MatrixXd smoothMatrix(Eigen::MatrixXd data, int factor);

	static Eigen::VectorXd polyfit(Eigen::VectorXd data, int n);
	
private:
	
};
