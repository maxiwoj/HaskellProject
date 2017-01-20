#include "KMPBench.hpp"
#include "KMP.h"
#include <cstdlib> //free

KMPBench::KMPBench(char* pattern, char* data) :
  _pattern(pattern), _data(data) {}

void KMPBench::setPattern(char* pattern){
  _pattern = pattern;
}

void KMPBench::setData(char* data){
  _data = data;
}


void KMPBench::setup(){return;}


void KMPBench::beforeEachBench(){return;}

void KMPBench::toBench(){
  _returnTab = KMP(_pattern, _data);
}

void KMPBench::afterEachBench(){
  free(_returnTab);
}


void KMPBench::clear(){return;}
