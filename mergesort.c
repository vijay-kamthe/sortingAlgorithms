#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "mergesort.h"

static int * merge(const struct vector * a, const struct vector * b) {

    // create a new array on the heap that merge
    // two sorted arrays while keeping the order

    int totalLength = a->length+b->length;
    int * result = malloc(totalLength*sizeof(int));
    int i = 0;
    int j = 0;
    int counter = 0;

    while (i < a->length && j < b->length) {
      if (a->numbers[i] <= b->numbers[j]) {
        result[counter] = a->numbers[i];
        i++;
      } else {
        result[counter] = b->numbers[j];
        j++;
      }
      counter++;
    }

    while (i < a->length) {
      result[counter] = a->numbers[i];
      i++;
      counter++;
    }

    while (j < b->length) {
      result[counter] = b->numbers[j];
      j++;
      counter++;
    }
    return result;
}

struct vector * mergeSort(struct vector *vec) {
  if (vec->length <= 1) {
    return vec;
  }

  int middle = vec->length / 2;

  struct vector a;
  a.length = middle;
  a.numbers = vec->numbers;

  struct vector b;
  b.length = vec->length - middle;
  b.numbers = vec->numbers + middle;

  int *merged = merge(mergeSort(&a), mergeSort(&b));
  copy(merged, vec->numbers, vec->length);
  free(merged);

  return vec;
}

