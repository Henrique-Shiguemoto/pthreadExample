#include <stdio.h>
#include <time.h>
#include "quick.h"
#include "merge.h"
#include "utils.h"

#define LINEAR_SORTING

int main(void) {
  printf("\n");

  int data[COUNT];
  printf("Filling the array with random integers...\n");
  fillArrayWithRandomIntegers(data, COUNT);
  
#ifdef LINEAR_SORTING
  printf("Sorting the array sequentially...\n");
  long before = clock();
  mergeSort(data, 0, COUNT - 1);
  long after = clock();
  double elapsed = (double)(after - before)/CLOCKS_PER_SEC;
  printf("%lf seconds elapsed...\n", elapsed);
  printf("Array is sorted? => %s\n", isArraySorted(data, COUNT) ? "true" : "false");
#else
  printf("Sorting the array with threads...\n");
  long before = clock();
  mergeSortForThreads(&(ArrayInfo) {data, 0, COUNT - 1});
  long after = clock();
  double elapsed = (double)(after - before)/CLOCKS_PER_SEC;
  printf("%lf seconds elapsed...\n", elapsed);
  printf("Array is sorted? => %s\n", isArraySorted(data, COUNT) ? "true" : "false");
#endif  

  return 0;
}