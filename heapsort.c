#include "vector.h"
#include "utils.h"

// the heap structure is solely conceptual,
// the work is actually done in place in the
// array

// returns the index of the parent
// node in the array
#define PARENT(i) ((i+1)/2-1)

static void fix(void *base, size_t nmemb, size_t size, int(*cmp)(const void *, const void *)) {
    // take a broken heap (i.e. one
    // which has parent node(s) holding
    // value(s) smaller than their children,
    // and fix it by swapping those values
    size_t i;
    for(i = nmemb-1; i>0; --i) {
        if(cmp(base + i * size, base + PARENT(i) * size)>0) {
            swap(base + i * size, base + PARENT(i) * size, size);
            i = nmemb;
        }
    }
}

void heapSort(void *base, size_t nmemb, size_t size, int(*cmp)(const void *, const void *)) {
    while(nmemb>0) {
        fix(base, nmemb, size, cmp);
        swap(base, base + (nmemb - 1) * size, size);
        --nmemb;
    }
}

