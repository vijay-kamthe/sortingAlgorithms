#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include "quicksort.h"

static int partition(struct vector * vector, int left, int right, int pivotIndex) {

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

static void quickSortRecur(struct vector * vector, int left, int right) {

    if(left<right) {

        int pivotIndex =  left + rand() % (right-left+1);

        pivotIndex = partition(vector, left, right, pivotIndex);

        quickSortRecur(vector, left, pivotIndex-1);

        quickSortRecur(vector, pivotIndex+1, right);
    }
}

struct vector * quickSort(struct vector * vector) {

    quickSortRecur(vector, 0, vector->length-1);

    return vector;
}

