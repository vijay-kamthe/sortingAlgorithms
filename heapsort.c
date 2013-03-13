#include "utils.h"

// the heap structure is solely conceptual,
// the work is actually done in place in the
// array

#define LEFT(i) (2*i+1)
#define RIGHT(i) (2*i+2)

static void heapify(void *base, size_t nmemb, size_t size, int(*cmp)(const void *, const void *), size_t index) {
    
    size_t le = LEFT(index);
    size_t ri = RIGHT(index);
    size_t largest;

    if(le<nmemb && cmp(base + le * size, base + index * size)>0) {
        largest = le;
    } else {
        largest = index;
    }

    if(ri<nmemb && cmp(base + ri * size, base + largest * size)>0) {
        largest = ri;
    }

    if(largest != index) {
        swap(base + index * size, base + largest * size, size);
        heapify(base, nmemb, size, cmp, largest);
    }
}

static void buildHeap(void *base, size_t nmemb, size_t size, int(*cmp)(const void *, const void *)) {
    // take a broken heap (i.e. one
    // which has parent node(s) holding
    // value(s) smaller than their children,
    // and fix it by swapping those values
    int i;
    for(i = nmemb/2; i>=0; --i) {
        heapify(base, nmemb, size, cmp, i);
    }
}

void heapSort(void *base, size_t nmemb, size_t size, int(*cmp)(const void *, const void *)) {
    if(nmemb>0) {
        buildHeap(base, nmemb, size, cmp);
        size_t i;
        for(i=nmemb-1; i>0; --i) {
            swap(base, base + i * size, size);
            --nmemb;
            heapify(base, nmemb, size, cmp, 0);
        }
    }
}

