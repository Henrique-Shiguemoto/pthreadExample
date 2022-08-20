#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

bool isArraySorted(int array[], int size){
  for(int i = 1; i < size; i++){
    if(array[i - 1] > array[i]){
      return false;
    }
  }
  return true;
}

void fillArrayWithRandomIntegers(int array[], int size){
  srand(time(NULL));
  for (int i = 0; i < size; ++i)
  {
    array[i] = rand() % 10000;
  }
}