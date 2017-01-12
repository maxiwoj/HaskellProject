#include "bench.hpp"

#include <time.h>
#include <iostream>

using namespace std;

typedef struct timespec timeStamp;

double mean(double values[], int size);


inline double timeDiff(timeStamp after, timeStamp before){
  return (after.tv_sec - before.tv_sec) + (double)(after.tv_nsec - before.tv_nsec)/1000000000;
}

double bench(Benchable* testObject, double testTime, int maxTests){
  testObject->setup();

  double duration[maxTests];
  timeStamp ts_start;
  timeStamp ts_end;

  struct timespec ts_startOfTest;
  clock_gettime(CLOCK_MONOTONIC, &ts_startOfTest);
  clock_gettime(CLOCK_MONOTONIC, &ts_end);
  int i;
  for (i = 0; i < maxTests && timeDiff(ts_end, ts_startOfTest) < testTime; i++){
    testObject->beforeEachBench();
    clock_gettime(CLOCK_MONOTONIC, &ts_start);
    testObject->toBench();
    clock_gettime(CLOCK_MONOTONIC, &ts_end);
    testObject->afterEachBench();
    duration[i] = timeDiff(ts_end, ts_start);
  }

  testObject->clear();
  return mean(duration, i);
}


double mean(double values[], int size){
  if(size == 0) return 0;
  double sum = 0;
  for (int i = 0; i < size; i++) {
    sum += values[i];
  }
  return sum/size;
}

/*
ts_end.tv_sec = ts_end.tv_sec - ts_start.tv_sec;
ts_end.tv_nsec = ts_end.tv_nsec - ts_start.tv_nsec;
if (ts_end.tv_nsec < 0) {
  ts_end.tv_sec--;
  ts_end.tv_nsec += 1000000000;
}
*/
