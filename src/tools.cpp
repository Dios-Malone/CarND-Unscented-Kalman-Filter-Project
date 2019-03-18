#include "tools.h"

using Eigen::VectorXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
   * TODO: Calculate the RMSE here.
   */
  VectorXd rmse(4);
  rmse << 0,0,0,0;

  // TODO: YOUR CODE HERE
  // check the validity of the following inputs:
  //  * the estimation vector size should not be zero
  if(estimations.size()==0)return rmse;
  //  * the estimation vector size should equal ground truth vector size
  if(estimations.size()!=ground_truth.size())return rmse;

  // TODO: accumulate squared residuals
  for (int i=0; i < estimations.size(); ++i) {
  // ... your code here
  rmse += (estimations[i] - ground_truth[i]).cwiseAbs2();
  }

  // TODO: calculate the mean
  rmse = rmse / estimations.size();
  // TODO: calculate the squared root
  rmse = rmse.cwiseSqrt();
  // return the result
  return rmse;   
}