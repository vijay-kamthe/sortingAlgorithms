#include <stdio.h>
#include <assert.h>
#include "bubblesort.h"
#include "quicksort.h"
#include "mergesort.h"
#include "heapsort.h"
#include "test.h"

void testSort(sortVector sort) {
    // sortVector is a pointer to a function
    // that takes a Vector and sorts it

    Vector bar;
    bar.length = 0;

    Vector baz;
    baz.length = 5;
    int temp[5] = {1, 12, 8, 4, 52 };
    baz.numbers = temp;

    Vector bazSorted;
    bazSorted.length = 5;
    int temp10[5] = {1, 4, 8, 12, 52 };
    bazSorted.numbers = temp10;

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

    assert(compareVectors(sort(&bam), &bamSorted));
    assert(compareVectors(sort(&negatives), &negativesSorted));
    assert(compareVectors(sort(&baz), &bazSorted));
    assert(compareVectors(sort(&bar), &bar));
}

int main(int argc, char *argv[]) {

    testSort(bubbleSort);
    printf("\nBubble Sort tests passed\n");
    testSort(quickSort);
    printf("\nQuick Sort tests passed\n");
    testSort(mergeSort);
    printf("\nMerge sort tests passed\n");
    testSort(heapSort);
    printf("\nHeap sort tests passed\n\n");

    return 0;
}

