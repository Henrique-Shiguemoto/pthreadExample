#pragma once

#define COUNT  10000

typedef struct ArrayInfo{
  int *array;
  int low;
  int high;
} ArrayInfo;

void mergeSort(int arr[], int l, int r);
void* mergeSortForThreads(void* arg);
void merge(int arr[], int p, int q, int r);
void mergeForThreads(ArrayInfo* arrayInfo);