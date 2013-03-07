#ifndef QUICKSORT
#define QUICKSORT

#include "vector.h"

int partition(Vector * vector, int left, int right, int pivotIndex);
void quickSortRecur(Vector * vector, int left, int right);
Vector * quickSort(Vector * vector);

#endif

