#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "quick.h"

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;      
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

int partitionForThreads(ArrayInfo* arrayInfo){
  return partition(arrayInfo->array, arrayInfo->low, arrayInfo->high);
}

void* quickSortForThreads(void *arg){
  ArrayInfo* arrayInfo = (ArrayInfo*)arg;

  static bool twoThreadsWereAlreadyCreated = false;

  int low = arrayInfo->low;
  int high = arrayInfo->high;

  if(low < high){
    int pi = partitionForThreads(arrayInfo);

    if(twoThreadsWereAlreadyCreated == false){
      twoThreadsWereAlreadyCreated = true;
      pthread_t t1, t2;
      pthread_create(&t1, NULL, &quickSortForThreads, &(ArrayInfo){arrayInfo->array, arrayInfo->low, pi - 1});
      pthread_create(&t2, NULL, &quickSortForThreads, &(ArrayInfo){arrayInfo->array, pi + 1, arrayInfo->high});
      pthread_join(t1, NULL);
      pthread_join(t2, NULL);      
    }else{
      quickSortForThreads(&(ArrayInfo){arrayInfo->array, arrayInfo->low, pi - 1});
      quickSortForThreads(&(ArrayInfo){arrayInfo->array, pi + 1, arrayInfo->high});
    }
    
  }

  return arrayInfo;
}