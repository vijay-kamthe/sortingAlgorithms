#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "mergesort.h"

int * merge(Vector * a, Vector * b) {

    int total = a->length+b->length;
    int * result = malloc(total*sizeof(int));
    int i = 0;
    int j = 0;
    int counter;

    for(counter = 0; counter<total; ++counter) {
        if(i>=a->length || a->numbers[i] > b->numbers[j]) {
            result[counter] = b->numbers[j];
            ++j;
        } else if(j>=b->length || a->numbers[i] <= b->numbers[j]) {
            result[counter] = a->numbers[i];
            ++i;
        } else {
            printf("\nerrrroorr\n");
        }
    }

    return result;
}

int main() {

    Vector temp;
    temp.length = 5;
    int a[5] = {1, 3, 4, 7, 9};
    temp.numbers = a;

    Vector temp2;
    temp2.length = 3;
    int b[3] = {2, 6, 12};
    temp2.numbers = b;

    int * result = merge(&temp, &temp2);

    printf("\n[");
    int i;
    for(i=0;i<8;++i){
        printf("%d, ", result[i]);
    }

    printf("]\n");
    free(result);
    return 0;
}

