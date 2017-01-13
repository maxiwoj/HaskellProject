#include "quicksort.h"

#include <stdlib.h>

void swap(int *a, int *b){
  int t = *a;
  *a = *b;
  *b = t;
}

typedef struct {
  int top;
  int *data;
} stack;

int pop(stack *s){
  s->top--;
  return s->data[s->top];
}

void push(stack *s, int v){
  s->data[s->top] = v;
  s->top++;
}

void quicksort(int* tab,int start, int lastIndex){
  int t;
  stack s;
  s.top = 0;
  int size = lastIndex - start + 1;
  int stackSize = 1;
  do{
    stackSize++;
    size >>= 1;
  }while(size != 0);
  stackSize <<= 1;
  s.data = (int*) malloc(stackSize*sizeof(int));
  push(&s, start);
  push(&s, lastIndex);

  while(s.top != 0){

    int right = pop(&s);
    int left = pop(&s);
    start = left;
    lastIndex = right;
    int pivot = tab[right];
    if(start < lastIndex){
      while(right>left){
        swap(&(tab[left]), &(tab[right]));
        while(tab[left] <= pivot && left <= right){
          left++;
        }
        while(tab[right] > pivot){
          right--;
        }
      }
      swap(&(tab[start]), &(tab[right]));
      if(right - start < lastIndex - right){
        push(&s,right+1);
        push(&s,lastIndex);

        push(&s, start);
        push(&s, right-1);
      }
      else{
        push(&s, start);
        push(&s, right-1);

        push(&s,right+1);
        push(&s,lastIndex);
      }
    }
  }
  free(s.data);
}
