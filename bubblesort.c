#include "utils.h"
#include "bubblesort.h"

void bubbleSort(void *base, size_t nmemb, size_t size, int(*cmp)(const void *, const void *)) {

    size_t i;
    char * ptr; // chars are exactly one byte
    int sorted; 
    do {
        ptr = (char*) base;
        sorted = 1;
        for (i = 0; i < nmemb-1; ++i) {
            if (cmp(ptr + i * size,  ptr + (i + 1) * size)>0) {
                swap(ptr + i * size, ptr + (i+1) * size, size);
                sorted = 0;
            }
        }
    } while (!sorted);
}

