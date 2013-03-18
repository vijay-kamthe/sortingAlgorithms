#include <stdio.h>       // for printf
#include <assert.h>      // for assert()
#include <time.h>        // for clock_gettime() and struct timespec
#include <stdlib.h>      // for size_t
#include <unistd.h>      // for getopt()
#include <limits.h>      // for INT_MAX
#include "bubblesort.h"  // for bubbleSort()
#include "quicksort.h"   // for quickSort()
#include "mergesort.h"   // for mergeSort()
#include "heapsort.h"    // for heapSort()
#include "utils.h"       // for copy()

typedef void (*sortFun)(void *, size_t, size_t, int(*cmp)(const void *, const void *));

static int cmpInt(const void *p1, const void *p2) {

    int a = *(int *) p1;
    int b = *(int *) p2;

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
//    printf("[");
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

int main(int argc, char * argv[]) {

    char *USAGE = "\n  Incorrect usage. Use must be one of:\n\n"
        "  $ ./run -t                  # to run test suite\n\n"
        "  $ ./run -b                  # to run benchmarks\n\n"
        "  or\n\n"
        "  $ ./run -t -b               # to run both\n\n";

    if(argc<2 || argc>3) {
        printf("%s", USAGE);
        return 0;
    }

    int testBool = 0;
    int benchmarkBool = 0;

    int c;
    extern char *optarg;
    extern int optind, optopt;
    while ((c = getopt(argc, argv, "tb")) != -1) {
        switch(c) {
            case 't':
                ++testBool;
                break;
            case 'b':
                ++benchmarkBool;
                break;
        }
    }

    struct {
        sortFun fun;
        char * name;
    } funs[] = { \
//        {bubbleSort, "bubblesort"}, \ // Simply too slow to benchmark...
        {quickSort, "quicksort   "}, \
        {qsort, "stdlib qsort"}, \
        {mergeSort, "mergesort   "}, \
        {heapSort, "heapsort    "}};

    if(testBool) {
        // UNIT TESTING
        printf("\n");
        size_t i;
        for(i=0; i<sizeof(funs)/sizeof(funs[0]); ++i) {
            testSort(funs[i].fun, funs[i].name);
        }
        printf("\n");
    }
    
    if(benchmarkBool) {
        // BENCHMARKING
        unsigned int  NUMTRIALS = 10;
        unsigned int ARRAYSIZE = 200000;
    
        // Build shuffled array
        char *shuffled = malloc(ARRAYSIZE * sizeof(char));
        size_t i;
        for(i=0; i<ARRAYSIZE; ++i) {
            shuffled[i] = (char) rand() % 254 - 127;
        }
    
    
        size_t j;
        for(i=0; i<sizeof(funs)/sizeof(funs[0]); ++i) {
    
            printf("Benchmarking %s algorithm on shuffled array of %u chars (%u trials), best time: ", \
                    funs[i].name, ARRAYSIZE, NUMTRIALS);
            
            struct timespec startTime;
            struct timespec endTime;
            unsigned long thisTime;
            unsigned long bestTime = INT_MAX;
            for(j=0; j<NUMTRIALS; ++j) {

                char *_shuffled = malloc(ARRAYSIZE * sizeof(char));
                copy(_shuffled, shuffled, ARRAYSIZE * sizeof(char));
    
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &startTime);
                funs[i].fun(_shuffled, ARRAYSIZE, sizeof(char), cmpChar);
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &endTime);
    
                free(_shuffled);

                thisTime = 1000000000*(endTime.tv_sec - startTime.tv_sec) + (endTime.tv_nsec - startTime.tv_nsec);
                bestTime = thisTime<bestTime ? thisTime : bestTime;
            }
            printf ("%lu nanoseconds\n", bestTime);
        }

        printf("\n");

        // Build sorted array
        char *sorted = malloc(ARRAYSIZE * sizeof(char));
        copy(sorted, shuffled, ARRAYSIZE * sizeof(char));
        qsort(sorted, ARRAYSIZE, sizeof(char), cmpChar);

        for(i=0; i<sizeof(funs)/sizeof(funs[0]); ++i) {
    
            printf("Benchmarking %s algorithm on sorted array of %u chars (%u trials), best time: ", \
                    funs[i].name, ARRAYSIZE, NUMTRIALS);
            
            struct timespec startTime;
            struct timespec endTime;
            unsigned long thisTime;
            unsigned long bestTime = INT_MAX;
            for(j=0; j<NUMTRIALS; ++j) {

                char *_sorted = malloc(ARRAYSIZE * sizeof(char));
                copy(_sorted, sorted, ARRAYSIZE * sizeof(char));
                
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &startTime);
                funs[i].fun(_sorted, ARRAYSIZE, sizeof(char), cmpChar);
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &endTime);
   
                free(_sorted);

                thisTime = 1000000000*(endTime.tv_sec - startTime.tv_sec) + (endTime.tv_nsec - startTime.tv_nsec);
                bestTime = thisTime<bestTime ? thisTime : bestTime;
            }
            printf ("%lu milliseconds\n", bestTime);
        }
   
        printf ("\n");

        free(shuffled);
        free(sorted);
    }
    return 0;
}

