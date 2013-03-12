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

void mergeSort(void *base, size_t nmemb, size_t size, int(*cmp)(const void * p1, const void *p2)) {
  if (nmemb > 1) {
      int half = nmemb / 2;
      void *merged = merge(mergeSort(base, half, size, cmp), mergeSort(base + half * size, nmemb-half, size, cmp));
      copy(merged, base, nmemb*size);
      free(merged);
  }
}

