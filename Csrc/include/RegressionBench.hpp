#ifndef REGRESSIONBENCH_HPP
#define REGRESSIONBENCH_HPP

#include "benchable.hpp"

class RegressionBench: public Benchable {
  double* _xTab;
  double* _yTab;
  int  _size;
public:
  RegressionBench(double* x, double* y, int size);
  void setData(double* x, double* y, int size);
  void beforeEachBench();
  void afterEachBench();
  void toBench();
  void setup();
  void clear();
};

#endif // REGRESSIONBENCH_HPP
