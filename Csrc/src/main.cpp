#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

#include "bench.hpp"
#include "KMPBench.hpp"
#include "QuicksortBench.hpp"

using namespace std;

int main(int argc, char **argv){
  KMPBench kmptest("test","atsesatestestsetstsstadsasttdsadsajdhasjkdhaskdtststsftststtststtstststtstsetsesttsetsetstetstetstetstesttestetstsstetstetstesteststetst");
  cout.precision(17);

  cout << fixed << bench(&kmptest) << endl;

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
  cout << bench(&qstest) << endl;

  free(tab);

  return 0;
}
