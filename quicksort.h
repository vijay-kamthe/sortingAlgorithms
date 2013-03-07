#ifndef QUICKSORT
#define QUICKSORT

#include "vector.h"

int partition(struct vector * vector, int left, int right, int pivotIndex);
void quickSortRecur(struct vector * vector, int left, int right);
struct vector * quickSort(struct vector * vector);

#endif

