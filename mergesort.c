#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "mergesort.h"

int * merge(const Vector * a, const Vector * b) {

    // create a new array on the heap that merge
    // two sorted arrays while keeping the order

    int totalLength = a->length+b->length;
    int * result = malloc(totalLength*sizeof(int));
    int i = 0;
    int j = 0;
    int counter = 0;

    while (i < a->length || j < b->length) {
      if (i < a->length && j < b->length) {
        if (a->numbers[i] <= b->numbers[j]) {
          result[counter] = a->numbers[i];
          i++;
          counter++;
        } else {
          result[counter] = b->numbers[j];
          j++;
          counter++;
        }
      } else if (i < a->length) {
        result[counter] = a->numbers[i];
        i++;
        counter++;
      } else if (j < b->length) {
        result[counter] = b->numbers[j];
        j++;
        counter++;
      }
    }
    return result;
}


Vector * mergeSort(Vector *vec) {
  if (vec->length <= 1) {
    return vec;
  }

  int middle = vec->length / 2;

  Vector a;
  a.length = middle;
  a.numbers = vec->numbers;

  Vector b;
  b.length = vec->length - middle;
  b.numbers = vec->numbers + middle;

  int *merged = merge(mergeSort(&a), mergeSort(&b));
  copy(merged, vec->numbers, vec->length);
  free(merged);

  return vec;
}

