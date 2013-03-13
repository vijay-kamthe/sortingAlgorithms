#include <stdlib.h>
#include "utils.h"
#include "mergesort.h"

static void * merge(void * a, size_t lengthA, void * b, size_t lengthB, \
        size_t size, int(*cmp)(const void * p1, const void *p2)) {

    // create a new array on the heap that merge
    // two sorted arrays while keeping the order

    size_t totalLength = lengthA + lengthB;
    void * result = malloc(totalLength*size);
    size_t i = 0;
    size_t j = 0;
    size_t counter = 0;

    while (i < lengthA && j < lengthB) {
        if (cmp(a + i*size, b + j*size)<=0) {
            copy(result + counter * size, a + i * size, size);
            ++i;
        } else {
            copy(result + counter * size, b + j * size, size);
            ++j;
        }
        ++counter;
    }

    while (i < lengthA) {
        copy(result + counter * size, a + i * size, size);
        ++i;
        ++counter;
    }

    while (j < lengthB) {
        copy(result + counter * size, b + j * size, size);
        ++j;
        ++counter;
    }

    return result;
}

static void * mergeSortRecur(void *base, size_t nmemb, size_t size, int(*cmp)(const void * p1, const void *p2)) {
    if (nmemb > 1) {
        int half = nmemb / 2;
        void *merged = merge(mergeSortRecur(base, half, size, cmp), half, \
                mergeSortRecur(base + half * size, nmemb - half, size, cmp), nmemb - half, size, cmp);
        copy(base, merged, nmemb*size);
        free(merged);
    }
    return base;
}

void mergeSort(void *base, size_t nmemb, size_t size, int(*cmp)(const void * p1, const void *p2)) {
    mergeSortRecur(base, nmemb, size, cmp);
}

