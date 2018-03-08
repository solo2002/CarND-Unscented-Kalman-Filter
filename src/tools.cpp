#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
  VectorXd rmse(4);
 	rmse << 0,0,0,0;
  
  if (estimations.size() == 0) {
    std::cout << "the estimation vector size should not be zero";
    return rmse;
  }
  
  if (estimations.size() != ground_truth.size())
    return rmse;
  //accumulate squared residuals
  VectorXd residul(4);
  for(int i=0; i < estimations.size(); ++i){
    // ... your code here
    residul = estimations[i] - ground_truth[i];
    residul = residul.array() * residul.array();
    rmse += residul;
  }
  rmse = rmse / estimations.size();
  rmse = rmse.array().sqrt();
  return rmse;
}