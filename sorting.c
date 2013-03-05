#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int length;
  int *numbers;
} Vector;

void printVector(Vector *vec) {
  int i;
  printf("[");
  for (i = 0; i < vec->length; ++i) {
    printf("%d, ",  vec->numbers[i]);
  }
  printf("]");
}

void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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

typedef Vector* (*sortVector)(Vector *);

void testSort(sortVector sort) {
  Vector bar;
  bar.length = 0;

  Vector baz;
  baz.length = 5;
  int temp[5] = {1, 2, 3, 4, 5};
  baz.numbers = temp;

  Vector negatives;
  negatives.length = 5;
  int temp1[5] = {-1, 2, -5, 6, 8};
  negatives.numbers = temp1;

  Vector negativesSorted;
  negatives.length = 5;
  int temp2[5] = {-5, -1, 2, 6, 8};
  negatives.numbers = temp2;

  Vector bam;
  bam.length = 5;
  int temp3[5] = {1, 12, 8, 4, 52 };
  bam.numbers = temp3;

  Vector bamSorted;
  bamSorted.length = 5;
  int temp4[5] = {1, 4, 8, 12, 52 };
  bamSorted.numbers = temp4;

  //printVector(sort(&bam));
  //printVector(sort(&negatives));
  //printVector(sort(&baz));
  //printVector(sort(&bar));

  assert(compareVectors(sort(&bam), &bamSorted));
  assert(compareVectors(sort(&negatives), &negativesSorted));
  assert(compareVectors(sort(&baz), &baz));
  assert(compareVectors(sort(&bar), &bar));
  printf("\nTests passed\n");
}



Vector* bubbleSort(Vector *vector) {
  int sorted;
  int i;
  do {
    sorted = 1;
    for (i = 0; i < vector->length-1; ++i) {
      if (vector->numbers[i] > vector->numbers[i+1]) {
        swap(&vector->numbers[i], &vector->numbers[i+1]);
        sorted = 0;
      }
    }
  } while (!sorted);
  return vector;
}

int partition(Vector * vector, int left, int right, int pivotIndex) {

    int pivotValue = vector->numbers[pivotIndex];

    swap(&vector->numbers[pivotIndex], &vector->numbers[right]);
    
    int storeIndex = left;
    int i;

    for(i=left; i<right; ++i) {
        if(vector->numbers[i] < pivotValue){
            swap(&vector->numbers[i], &vector->numbers[storeIndex]);
            ++storeIndex;
        }
    }

    swap(&vector->numbers[storeIndex], &vector->numbers[right]);
    
    return storeIndex;
}
    
void quickSortRecur(Vector * vector, int left, int right) {

    if(left<right) {

        int pivotIndex =  left + rand() % (right-left+1);
   
        pivotIndex = partition(vector, left, right, pivotIndex);

        quickSortRecur(vector, left, pivotIndex-1); 

        quickSortRecur(vector, pivotIndex+1, right); 
    }
}

Vector * quickSort(Vector * vector) {

    quickSortRecur(vector, 0, vector->length-1);

    return vector;
}

void runTests() {

    int a = 0;
    int b = 3;

    swap(&a, &b);
    assert(b==0);
    assert(a==3);

    testSort(bubbleSort);
    testSort(quickSort);
}

int main(int argc, char *argv[]) {

  /* initialize random seed: */
  srand (time(NULL));

//  Vector temp;
//  temp.length = 5;
//  int a[5] = {1, 3, 4, 5, 1};
//  temp.numbers = a;
//  quickSort(&temp);
//  printVector(&temp);

  runTests();

  return 0;
}

