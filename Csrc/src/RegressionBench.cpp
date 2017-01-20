#include "RegressionBench.hpp"
#include "regression.hpp"

RegressionBench::RegressionBench(double* x, double* y, int size) :
  _xTab(x), _yTab(y), _size(size) {}

void RegressionBench::setData(double* x, double* y, int size){
  _xTab = x;
  _yTab = y;
  _size = size;
}


void RegressionBench::setup(){return;}


void RegressionBench::beforeEachBench(){return;}

void RegressionBench::toBench(){
  regress(_xTab, _yTab, _size);
}

void RegressionBench::afterEachBench(){return;}


void RegressionBench::clear(){return;}
