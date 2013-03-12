#include <stdio.h>
#include <assert.h>
#include "bubblesort.h"
#include "quicksort.h"
//#include "mergesort.h"
//#include "heapsort.h"
#include "test.h"

static int cmpInt(const void *p1, const void *p2) {

    int a = *(int *) p1;
    int b = *(int *) p2;
//    printf("a = %d, b = %d\n", a, b);

    if(a<b) return -1;
    if(a>b) return 1;
    return 0;
}

static int cmpDouble(const void *p1, const void *p2) {

    double a = *(double *) p1;
    double b = *(double *) p2;

    if(a<b) return -1;
    if(a>b) return 1;
    return 0;
}

static int cmpChar(const void *p1, const void *p2) {

    char a = *(char *) p1;
    char b = *(char *) p2;

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
    size_t length1 = 5;
    qsort(array1a, length1, sizeof(int), cmpInt);
    sortfun(array1b, length1, sizeof(int), cmpInt);
    assert(cmpArrays(array1a, array1b, length1, cmpInt));
    printf("test passed \n");

    // test #2
    printf("Testing %s algorithm, integers array #2... ", funName);
    int array2a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t length2 = 10;
    qsort(array2a, length2, sizeof(int), cmpInt);
    sortfun(array2b, length2, sizeof(int), cmpInt);
    assert(cmpArrays(array2a, array2b, length2, cmpInt));
    printf("test passed \n");

    // test #3
    printf("Testing %s algorithm, integers array #3... ", funName);
    int array3a[] = {-1, -10, -13, 2, 0, 0, -5, 0};
    int array3b[] = {-1, -10, -13, 2, 0, 0, -5, 0};
    size_t length3 = 8;
    qsort(array3a, length3, sizeof(int), cmpInt);
    sortfun(array3b, length3, sizeof(int), cmpInt);
    assert(cmpArrays(array3a, array3b, length3, cmpInt));
    printf("test passed \n");

    // test #4
    printf("Testing %s algorithm, integers array #4... ", funName);
    int array4a[] = {1};
    int array4b[] = {1};
    size_t length4 = 1;
    qsort(array4a, length4, sizeof(int), cmpInt);
    sortfun(array4b, length4, sizeof(int), cmpInt);
    assert(cmpArrays(array4a, array4b, length4, cmpInt));
    printf("test passed \n");

    // test #5
    printf("Testing %s algorithm, integers array #5... ", funName);
    int array5a[] = {};
    int array5b[] = {};
    size_t length5 = 0;
    qsort(array5a, length5, sizeof(int), cmpInt);
    sortfun(array5b, length5, sizeof(int), cmpInt);
    assert(cmpArrays(array5a, array5b, length5, cmpInt));
    printf("test passed \n");

    // test #6
    printf("Testing %s algorithm, double array #1... ", funName);
    double array6a[] = {-19.8474, 273.3433, -0.00, 2.3333, -12.3233, -0.00, 2.3333};
    double array6b[] = {-19.8474, 273.3433, -0.00, 2.3333, -12.3233, -0.00, 2.3333};
    size_t length6 = 7;
    qsort(array6a, length6, sizeof(double), cmpDouble);
    sortfun(array6b, length6, sizeof(double), cmpDouble);
    assert(cmpArrays(array6a, array6b, length6, cmpDouble));
    printf("test passed \n");

    // test #7
    printf("Testing %s algorithm, char array #1... ", funName);
    double array7a[] = {'v', 't', 'a', 'b', 'c', 'T', 'W', 'E', 'g', 'G'};
    double array7b[] = {'v', 't', 'a', 'b', 'c', 'T', 'W', 'E', 'g', 'G'};
    size_t length7 = 10;
    qsort(array7a, length7, sizeof(char), cmpChar);
    sortfun(array7b, length7, sizeof(char), cmpChar);
    assert(cmpArrays(array7a, array7b, length7, cmpChar));
    printf("test passed \n");

}

int main() {

    struct {
        sortFun fun;
        char * name;
    } funs[] = {{bubbleSort, "bubblesort"}, {quickSort, "quicksort"}};//, {mergeSort, "mergesort"}, {heapSort, "heapsort"}};

    size_t i;
    for(i=0; i<sizeof(funs)/sizeof(funs[0]); ++i) {
        testSort(funs[i].fun, funs[i].name);
    }
    return 0;
}

