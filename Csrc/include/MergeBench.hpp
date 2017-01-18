#ifndef MERGEBENCH_HPP
#define MERGEBENCH_HPP

#include "benchable.hpp"

class MergeBench: public Benchable {
  int* _sourceTab;
  int _sourceSize;
  int* _toSortTab;
  int* _tempTab;
public:
  MergeBench(int* tab, int size);
  void setTableToSort(int* tab, int size);
  void beforeEachBench();
  void afterEachBench();
  void toBench();
  void setup();
  void clear();
};

#endif // MERGEBENCH_HPP
