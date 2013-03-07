#ifndef VECTOR
#define VECTOR

struct vector{
  int length;
  int *numbers;
};

void fillVector(struct vector *, int *, int);
void printVector(struct vector *);
int compareVectors(struct vector *, struct vector *);

#endif

