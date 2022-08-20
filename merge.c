#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "merge.h"

void merge(int arr[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

void mergeForThreads(ArrayInfo* arrayInfo){
  int m = arrayInfo->low + (arrayInfo->high - arrayInfo->low) / 2;
  merge(arrayInfo->array, arrayInfo->low, m, arrayInfo->high);
}

void* mergeSortForThreads(void* arg){
  ArrayInfo* arrayInfo = (ArrayInfo*)arg;

  static bool twoThreadsWereAlreadyCreated = false;
  int l = arrayInfo->low;
  int r = arrayInfo->high;
  if (l < r) {
    int m = l + (r - l) / 2;
    if(twoThreadsWereAlreadyCreated == false){
      twoThreadsWereAlreadyCreated = true;
      pthread_t t1, t2;
      pthread_create(&t1, NULL, &mergeSortForThreads, &(ArrayInfo){arrayInfo->array, l, m});
      pthread_create(&t2, NULL, &mergeSortForThreads, &(ArrayInfo){arrayInfo->array, m, r});
      pthread_join(t1, NULL);
      pthread_join(t2, NULL);
      mergeSortForThreads(&(ArrayInfo){arrayInfo->array, l, r});
    }else{
      mergeSort(arrayInfo->array, l, m);
      mergeSort(arrayInfo->array, m + 1, r);
      merge(arrayInfo->array, l, m, r);  
    }
  }

  return arrayInfo;
}