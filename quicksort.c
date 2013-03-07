#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include "quicksort.h"

int partition(Vector * vector, int left, int right, int pivotIndex) {

    int pivotValue = vector->numbers[pivotIndex];

    swap(&vector->numbers[pivotIndex], &vector->numbers[right]);

    int storeIndex = left;
    int i;

    for(i=left; i<right; ++i) {
        if(vector->numbers[i] < pivotValue){
            swap(&vector->numbers[i], &vector->numbers[storeIndex]);
            ++storeIndex;
        }
    }

    swap(&vector->numbers[storeIndex], &vector->numbers[right]);

    return storeIndex;
}

void quickSortRecur(Vector * vector, int left, int right) {

    if(left<right) {

        int pivotIndex =  left + rand() % (right-left+1);

        pivotIndex = partition(vector, left, right, pivotIndex);

        quickSortRecur(vector, left, pivotIndex-1);

        quickSortRecur(vector, pivotIndex+1, right);
    }
}

Vector * quickSort(Vector * vector) {

    /* initialize random seed: */
    srand (time(NULL));

    quickSortRecur(vector, 0, vector->length-1);

    return vector;
}

