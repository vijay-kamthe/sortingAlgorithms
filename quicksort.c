#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include "quicksort.h"

static size_t partition(void * base, size_t nmemb, size_t size, \
        int(*cmp)(const void *p1, const void *p2), size_t pivotIndex) {

    void *pivotPtr = base + pivotIndex * size;
    void *endPtr = base + (nmemb - 1) * size;
    swap(pivotPtr, endPtr, size);

    void *storePtr = base;
    void *i;
    for(i=base; i<endPtr; i+=size) {
        if(cmp(i, endPtr)<0){
            swap(i, storePtr, size);
            storePtr += size;
        }
    }

    swap(storePtr, endPtr, size);

    return (storePtr-base)/size;
}

void quickSort(void * base, size_t nmemb, size_t size, int(*cmp)(const void *p1, const void *p2)) {

    if(nmemb>1) {

        size_t pivotIndex = rand() % nmemb;

        pivotIndex = partition(base, nmemb, size, cmp, pivotIndex);

        quickSort(base, pivotIndex, size, cmp);
        quickSort(base + (pivotIndex + 1) * size , nmemb - pivotIndex - 1, size, cmp);

    }
}

