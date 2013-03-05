#include <stdio.h>
#include "vector.h"

void printVector(Vector *vec) {
  int i;
  printf("[");
  for (i = 0; i < vec->length; ++i) {
    printf("%d, ",  vec->numbers[i]);
  }
  printf("]");
}

int compareVectors(Vector *a, Vector *b) {
  if (a->length != b->length) return 1;
  int largest = a->length > b->length ? a->length : b->length;

  int i;
  for (i = 0; i < largest; ++i) {
    if (a->numbers[i] != b->numbers[i]) {
      return 0;
    }
  }
  return 1;
}

