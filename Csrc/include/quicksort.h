#ifndef QUICKSORT_H
#define QUICKSORT_H

#ifdef __cplusplus
extern "C" {
#endif

/*
1 argument: array of interager that should be sorted
2 argument: index of first element that would be sorted
3 argument: index of last element that would be sorted
resault: array will be sorted from index start to lastIndex incuding both elements that are pointed by start and lastIndex
*/
void quicksort(int* tab, int start, int lastIndex);

#ifdef __cplusplus
}  //extern "C"
#endif

#endif // QUICKSORT_H
