#include "QuicksortBench.hpp"
#include "quicksort.h"
#include <cstdlib> //malloc, free
#include <cstring> //memcpy

QuicksortBench::QuicksortBench(int* tab, int size) :
  _sourceTab(tab), _sourceSize(size) {}

void QuicksortBench::setTableToSort(int* tab, int size){
  _sourceTab = tab;
  _sourceSize = size;
}


void QuicksortBench::setup(){
  _toSortTab = (int*) malloc (_sourceSize*sizeof(int));
}


void QuicksortBench::beforeEachBench(){
  memcpy(_toSortTab, _sourceTab, _sourceSize*sizeof(int));
}

void QuicksortBench::toBench(){
  quicksort(_toSortTab, 0, _sourceSize-1);
}

void QuicksortBench::afterEachBench(){return;}


void QuicksortBench::clear(){
  free(_toSortTab);
}
