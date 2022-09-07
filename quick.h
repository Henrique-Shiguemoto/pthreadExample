#pragma once

#include "utils.h"

#define COUNT  10000

void swap(int *a, int *b);
int partition(int array[], int low, int high);
int partitionForThreads(ArrayInfo* arrayInfo);
void* quickSortForThreads(void *arg);
void quickSort(int array[], int low, int high);
