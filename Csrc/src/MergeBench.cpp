#include "MergeBench.hpp"
#include "mergeSort.hpp"
#include <cstdlib> //malloc, free
#include <cstring> //memcpy

MergeBench::MergeBench(int* tab, int size) :
  _sourceTab(tab), _sourceSize(size) {}

void MergeBench::setTableToSort(int* tab, int size){
  _sourceTab = tab;
  _sourceSize = size;
}


void MergeBench::setup(){
  _toSortTab = (int*) malloc (_sourceSize*sizeof(int));
  _tempTab = (int*) malloc (_sourceSize*sizeof(int));
}


void MergeBench::beforeEachBench(){
  memcpy(_toSortTab, _sourceTab, _sourceSize*sizeof(int));
}

void MergeBench::toBench(){
  mergeSort(_toSortTab, _tempTab, 0, _sourceSize-1);
}

void MergeBench::afterEachBench(){return;}


void MergeBench::clear(){
  free(_toSortTab);
  free(_tempTab);
}
