#pragma once

#define COUNT  10000

typedef struct ArrayInfo{
  int *array;
  int low;
  int high;
} ArrayInfo;

void swap(int *a, int *b);
int partition(int array[], int low, int high);
int partitionForThreads(ArrayInfo* arrayInfo);
void* quickSortForThreads(void *arg);
void quickSort(int array[], int low, int high);
