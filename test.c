#include <stdio.h>
#include <assert.h>
#include "bubblesort.h"
//#include "quicksort.h"
//#include "mergesort.h"
//#include "heapsort.h"
#include "test.h"

static int cmpInt(const void *p1, const void *p2) {

    int a = *(int *) p1;
    int b = *(int *) p2;

    if(a<b) return -1;
    if(a>b) return 1;
    return 0;
}

static int cmpArrays(const void *p1, const void *p2, size_t nmemb, int(*cmp)(const void *p1, const void *p2)) {
    size_t i;
    for(i=0; i<nmemb; ++i) {
        if(cmp(p1, p2) != 0) return 0;
    }
    return 1;
}

//static void print(int array[], size_t length){
//    printf("\n[");
//    size_t i;
//    for(i=0; i<length; ++i) {
//        printf("%d, ", array[i]);
//    }
//    printf("]\n");
//}

static void testSort(sortFun sortfun, char *funName) {

    // test #1
    printf("Testing %s algorithm, integers array #1... ", funName);
    int array1a[] = {1, 12, 8, 4, -2};
    int array1b[] = {1, 12, 8, 4, -2};
    int length1 = 5;
    qsort(array1a, length1, sizeof(int), cmpInt);
    sortfun(array1b, length1, sizeof(int), cmpInt);
    assert(cmpArrays(array1a, array1b, length1, cmpInt));
    printf("test passed \n");

}

int main() {

    struct {
        sortFun fun;
        char * name;
    } funs[] = {{bubbleSort, "bubblesort"}};//, {quickSort, "quicksort"}, {mergeSort, "mergesort"}, {heapSort, "heapsort"}};

    size_t i;
    for(i=0; i<sizeof(funs)/sizeof(funs[0]); ++i) {
        testSort(funs[i].fun, funs[i].name);
    }
    return 0;
}

