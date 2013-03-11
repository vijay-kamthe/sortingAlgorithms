#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "bubblesort.h"
#include "quicksort.h"
#include "mergesort.h"
#include "heapsort.h"
#include "test.h"

#define LAST_MARKER INT_MAX

static int compr(const void *p1, const void *p2) {

    int a = *(int *) p1;
    int b = *(int *) p2;

    if(a<b) return -1;
    if(a>b) return 1;
    return 0;
}

static void testSort(sortFun sortfun, char *funName) {

    int *testArrays[] = {
                           (int[]){1, 12, 8, 4, -2, LAST_MARKER},
                           (int[]){1, 2, 3, LAST_MARKER},
                           (int[]){1, LAST_MARKER},
                           (int[]){LAST_MARKER},
                           (int[]){-3, -3, 34, LAST_MARKER},
                           (int[]){-3, -3, 34, LAST_MARKER},
                           (int[]){-1, 2, -5, 6, 8, LAST_MARKER},
                           (int[]){1, 12, -100, 4, 52, LAST_MARKER}
                        };

    unsigned int i;
    for(i=0; i<sizeof(testArrays)/sizeof(testArrays[0]); ++i){
        int *list = testArrays[i];

        int length;
        for(length=0; list[length]!=LAST_MARKER; ++length);

        struct vector a;
        int tempa[length];
        a.numbers = tempa;
        fillVector(&a, list, length);

        struct vector b;
        int tempb[length];
        b.numbers = tempb;
        fillVector(&b, list, length);

        qsort(a.numbers, a.length, sizeof(int), compr);

        sortfun(&b);

        printf("Testing %s array[%d]... ", funName, i);
        assert(compareVectors(&a, &b));
        printf("Test passed \n");

    }
}

int main() {

    struct {
        sortFun fun;
        char * name;
    } funs[] = {{bubbleSort, "bubblesort"}, {quickSort, "quicksort"}, {mergeSort, "mergesort"}, {heapSort, "heapsort"}};

    unsigned int i;
    for(i=0; i<sizeof(funs)/sizeof(funs[0]); ++i) {
        testSort(funs[i].fun, funs[i].name);
        printf("%s tests passed\n\n", funs[i].name);
    }
    return 0;
}

