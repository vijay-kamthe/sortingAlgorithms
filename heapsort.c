#include "vector.h"
#include "utils.h"

// the heap structure is solely conceptual,
// the work is actually done in place in the
// array

// returns the index of the parent
// node in the array
#define PARENT(i) ((i+1)/2-1)

static void fix(int * a, int length) {
    // take a broken heap (i.e. one
    // which has parent node(s) holding
    // value(s) smaller than their children,
    // and fix it by swapping those values
    int i;
    for(i = length-1; i>0; --i) {
        if(a[i]>a[PARENT(i)]) {
            swap(&a[i], &a[PARENT(i)]);
            i = length;
        }
    }
}

struct vector * heapSort(struct vector * vec) {

    int length = vec->length;

    while(length>0) {
        fix(vec->numbers, length);
        swap(&vec->numbers[0], &vec->numbers[length-1]);
        --length;
    }

    return vec;
}

