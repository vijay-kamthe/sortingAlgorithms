#include <stdio.h>
#include "vector.h"
#include "utils.h"

void fillVector(struct vector * vec, int * array, int length) {
    vec->length = length;
    copy(array, vec->numbers, length);
}

void printVector(struct vector *vec) {
    int i;
    printf("[");
    for (i = 0; i < vec->length; ++i) {
        printf("%d, ",  vec->numbers[i]);
    }
    printf("]");
}

int compareVectors(struct vector *a, struct vector *b) {

    if (a->length != b->length) return 1;

    int i;
    for (i = 0; i < a->length; ++i) {
        if (a->numbers[i] != b->numbers[i]) {
            return 0;
        }
    }
    return 1;
}

