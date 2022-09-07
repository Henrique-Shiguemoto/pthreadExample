#pragma once

#include "utils.h"

#define COUNT  10000

void mergeSort(int arr[], int l, int r);
void* mergeSortForThreads(void* arg);
void merge(int arr[], int p, int q, int r);
void mergeForThreads(ArrayInfo* arrayInfo);