
#ifndef HEAPSORT
#define HEAPSORT

#include "vector.h"

int parent(int);
void fix(int *, int);
void heapify(Vector *);
Vector * heapSort(Vector *);

#endif
