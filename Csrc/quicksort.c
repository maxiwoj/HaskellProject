#include <stdio.h>
#include <stdlib.h>

void quicksort(int* tab, int start, int lastIndex);

int main(int argc, char const *argv[]) {
  const int size = 13;
  int tab[] = {2,4,1,5,65,23,5,5,31,4,6,5,3};
  //int tab[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
  //int tab[] = {5,5,5,5,5,5,5,5,5,5,5,5,5};
  //int tab[] = {1,2,3,4,5,6,7,13,9,10,11,12,8};
  quicksort(tab, 0, size-1);
  for(int i = 0; i < size; i++){
    printf("%d, ", tab[i]);
  }
  printf("\b\b  \n");
  return 0;
}

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
