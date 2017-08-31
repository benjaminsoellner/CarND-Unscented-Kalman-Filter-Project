#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
	VectorXd result(4);
	result.fill(0);
	// sanity check
	if (estimations.size()==0 || (estimations.size() != ground_truth.size())) {
		std::cout << "Error: estimations and ground_truth must be the same size";
		return result;
	}
	// calculate the residuals ...
	for (int i = 0; i < estimations.size(); i++) {
		VectorXd residual = estimations[i] - ground_truth[i];
		residual = residual.array() * residual.array();
		result += residual;
	}
	// ... mean ...
	result /= estimations.size();
	// ... square root
	result = result.array().sqrt();
	return result;
}