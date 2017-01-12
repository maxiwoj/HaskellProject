#ifndef QUICKSORTBENCH_HPP
#define QUICKSORTBENCH_HPP

#include "benchable.hpp"

class QuicksortBench: public Benchable {
  int* _sourceTab;
  int _sourceSize;
  int* _toSortTab;
public:
  QuicksortBench(int* tab, int size);
  void setTableToSort(int* tab, int size);
  void beforeEachBench();
  void afterEachBench();
  void toBench();
  void setup();
  void clear();
};

#endif // QUICKSORTBENCH_HPP
