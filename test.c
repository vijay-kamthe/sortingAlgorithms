#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bubblesort.h"
//#include "quicksort.h"
//#include "mergesort.h"
//#include "heapsort.h"
#include "test.h"

#define LAST_MARKER 666

int compr(const void *p1, const void *p2) {

    int a = *(int *) p1;
    int b = *(int *) p2;

    if(a<b) return -1;
    if(a>b) return 1;
    return 0;
}

void testSort(sortFun sortfun) {

    int testArrays[][99] = {
                            {1, 12, 8, 4, -2, LAST_MARKER},
                            {1, 2, 3, LAST_MARKER},
                            {1, LAST_MARKER},
                            {-3, -3, 34, LAST_MARKER},
                            {-3, -3, 34, LAST_MARKER},
                            {-1, 2, -5, 6, 8, LAST_MARKER},
                            {1, 12, -100, 4, 52, LAST_MARKER}
                        };

    unsigned int i;
    for(i=0; i<sizeof(testArrays)/sizeof(testArrays[0]); ++i){
        int *list = testArrays[i];

        int length;
        for(length=0; list[length]!=LAST_MARKER; ++length);

        struct vector a;
        int tempa[99];
        a.numbers = tempa;
        fillVector(&a, list, length);

        struct vector b;
        int tempb[99];
        b.numbers = tempb;
        fillVector(&b, list, length);

        qsort(a.numbers, a.length, sizeof(int), compr);

        sortfun(&b);

        printf("\n Test #%d:\nVector a: ",i);
        printVector(&a);
        printf("\nVector b: ");
        printVector(&b);
        printf("\n");
    }
//    struct vector bar;
//    bar.length = 0;
//
//    struct vector baz;
//    baz.length = 5;
//    int temp[5] = {1, 12, 8, 4, 52 };
//    baz.numbers = temp;
//
//    struct vector bazSorted;
//    bazSorted.length = 5;
//    int temp10[5] = {1, 4, 8, 12, 52 };
//    bazSorted.numbers = temp10;
//
//    struct vector negatives;
//    negatives.length = 5;
//    int temp1[5] = {-1, 2, -5, 6, 8};
//    negatives.numbers = temp1;
//
//    struct vector negativesSorted;
//    negatives.length = 5;
//    int temp2[5] = {-5, -1, 2, 6, 8};
//    negatives.numbers = temp2;
//
//    struct vector bam;
//    bam.length = 5;
//    int temp3[5] = {1, 12, 8, 4, 52 };
//    bam.numbers = temp3;
//
//    struct vector bamSorted;
//    bamSorted.length = 5;
//    int temp4[5] = {1, 4, 8, 12, 52 };
//    bamSorted.numbers = temp4;

//    assert(compareVectors(sortfun(&bam), &bamSorted));
//    assert(compareVectors(sortfun(&negatives), &negativesSorted));
//    assert(compareVectors(sortfun(&baz), &bazSorted));
//    assert(compareVectors(sortfun(&bar), &bar));
}

int main() {

    testSort(bubbleSort);
    printf("\nBubble Sort tests passed\n");
//    testSort(quickSort);
//    printf("\nQuick Sort tests passed\n");
//    testSort(mergeSort);
//    printf("\nMerge sort tests passed\n");
//    testSort(heapSort);
//    printf("\nHeap sort tests passed\n\n");

    return 0;
}

