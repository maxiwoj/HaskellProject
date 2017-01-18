#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

#include "bench.hpp"
#include "KMPBench.hpp"
#include "QuicksortBench.hpp"
#include "MergeBench.hpp"

using namespace std;

int main(int argc, char **argv){

  const int KMPdataSize = 1000001;
  const int KMPpatternSize = 6;
  char *kmpDataTab = (char*) malloc(KMPdataSize*sizeof(char));
  char *kmpPatternTab = (char*) malloc(KMPpatternSize*sizeof(char));
  ifstream kmpData ("data/KMP.txt");
  if (kmpData.is_open())
  {
    int i;
    for(i=0;i<KMPpatternSize;i++){
      kmpData >> kmpPatternTab[i];
    }
    kmpPatternTab[i] = '\0';

    for(i=0;i<KMPdataSize;i++){
      kmpData >> kmpDataTab[i];
    }
    kmpDataTab[i] = '\0';
    kmpData.close();
  }
  else{
    cout << "data/KMP.txt could not be open. Exit" << endl;
    return 0;
  }

  cout.precision(17);
  KMPBench kmptest(kmpPatternTab,kmpDataTab);
  cout << fixed << "kmp 1000000: \t" << bench(&kmptest) << endl;

  free(kmpDataTab);
  free(kmpPatternTab);

  const int size = 10000;
  int *tab = (int*) malloc(size*sizeof(int));
  ifstream sortData ("data/NumbersToSort10k.txt");
  if (sortData.is_open())
  {
    int i;
    for(i=0;i<size;i++){
      sortData >> tab[i];
    }
    sortData.close();
  }
  else{
    cout << "data/NumbersToSort10k.txt could not be open. Exit" << endl;
    return 0;
  }

  QuicksortBench qstest(tab, size);
  cout <<"quicksort 10000: \t" << bench(&qstest) << endl;

  MergeBench mstest(tab, size);
  cout << "merge sort 10000: \t"<< bench(&mstest) << endl;

  free(tab);

  return 0;
}
