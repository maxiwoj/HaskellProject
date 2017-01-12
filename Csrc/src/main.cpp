#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "bench.hpp"
#include "KMPBench.hpp"
#include "QuicksortBench.hpp"

using namespace std;

int main(int argc, char **argv){
  KMPBench kmptest("test","atsesatestestsetstsstadsasttdsadsajdhasjkdhaskdtststsftststtststtstststtstsetsesttsetsetstetstetstetstesttestetstsstetstetstesteststetst");
  cout.precision(17);

  cout << fixed << bench(&kmptest) << endl;

  const int size = 1000000;
  int i;
  int *tab = (int*) malloc(size*sizeof(int));
  for(i=0;i<size;i++){
    tab[i]=rand();
  }
  QuicksortBench qstest(tab, size);
  cout << bench(&qstest) << endl;

  free(tab);

  return 0;
}
