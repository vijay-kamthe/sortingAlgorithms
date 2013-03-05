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

        if(a->numbers[i] < b->numbers[j]) {

            result[counter] = a->numbers[i];
            ++i;

        } else {

            result[counter] = b->numbers[j];
            ++j;
        }
    }

    return result;
}

int main() {

    Vector * temp = NULL;
    temp->length = 5;
    int a[5] = {1, 3, 4, 5, 1};
    temp->numbers = a;

    Vector *  temp2 = NULL;
    temp2->length = 3;
    int b[3] = {10, 11, 12};
    temp2->numbers = b;

    int * result = merge(temp, temp2);

    printf("\n[");
    int i;
    for(i=0;i<8;++i){
        printf("%d, ", result[i]);
    }

    printf("[\n");
    free(result);
    return 0;
}

