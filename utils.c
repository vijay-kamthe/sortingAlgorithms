#include "utils.h"

void swap(void *a, void *b, size_t numBytes) {

    // Swaps numBytes bytes between memory
    // location a and b

    char *ptr1 = (char*)a;
    char *ptr2 = (char*)b;

    size_t i;
    for(i=0; i<numBytes; ++i){
        char temp = ptr1[i];
        ptr1[i] = ptr2[i];
        ptr2[i] = temp;
    }
}

void copy(void *a, void *b, size_t numBytes) {
    char *ptr1 = (char*)a;
    char *ptr2 = (char*)b;

    size_t i;
    for (i = 0; i < numBytes; ++i) {
        ptr1[i] = ptr2[i];
    }
}

