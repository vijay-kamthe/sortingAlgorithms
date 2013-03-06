#include "utils.h"

void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void copy(int *a, int *b, int length) {
  int i;
  for (i = 0; i < length; i++) {
    b[i] = a[i];
  }
}
