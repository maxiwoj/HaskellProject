#ifndef KMPBENCH_HPP
#define KMPBENCH_HPP

#include "benchable.hpp"

class KMPBench: public Benchable {
  char* _pattern;
  char* _data;
  int* _returnTab;
public:
  KMPBench(char* pattern, char* data);
  void setPattern(char* pattern);
  void setData(char* data);
  void beforeEachBench();
  void afterEachBench();
  void toBench();
  void setup();
  void clear();
};

#endif // KMPBENCH_HPP
