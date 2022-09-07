#pragma once

#include <stdbool.h>

typedef struct ArrayInfo{
  int *array;
  int low;
  int high;
} ArrayInfo;

void printArray(int array[], int size);
bool isArraySorted(int array[], int size);
void fillArrayWithRandomIntegers(int array[], int size);