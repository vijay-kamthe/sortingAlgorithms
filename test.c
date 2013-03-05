#include <stdio.h>
#include <assert.h>
#include "vector.h"
#include "bubblesort.h"
#include "quicksort.h"
#include "test.h"

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
}

int main(int argc, char *argv[]) {
//  Vector temp;
//  temp.length = 5;
//  int a[5] = {1, 3, 4, 5, 1};
//  temp.numbers = a;
//  quickSort(&temp);
//  printVector(&temp);

    testSort(bubbleSort);
    printf("\nBubble Sort tests passed\n");
    testSort(quickSort);
    printf("\nQuick Sort tests passed\n");

  return 0;
}

