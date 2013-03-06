#include "vector.h"
#include "utils.h"
#include "heapsort.h"

int parent(int i) {
    return (i+1)/2-1;
}

void fix(int * a, int length) {
    int i;
    for(i = length-1; i>0; --i) {
        if(a[i]>a[parent(i)]) {
            swap(&a[i], &a[parent(i)]);
            i = length;
        }
    }
}

Vector * heapSort(Vector * vec) {

    int length = vec->length;

    while(length>0) {
        fix(vec->numbers, length);
        swap(&vec->numbers[0], &vec->numbers[length-1]);
        --length;
    }

    return vec;
}

