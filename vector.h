#ifndef VECTOR
#define VECTOR

typedef struct {
  int length;
  int *numbers;
} Vector;

void printVector(Vector *);
int compareVectors(Vector *, Vector *);

#endif

