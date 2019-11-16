#include "stdio.h"
#include "stdlib.h"
#include "sorting.h"
#include "time.h"

int main()
{
    //seeds the random number generator based on time
    srand(time(0));

    int array[10];
    int size = 10;

    printf("Starting array");
    //fills the array and prints the initial values
    fillArray(array, size);
    printArray(array, size);


    printf("\nBubbble sort");
    //sorts the array and prints the sorted array
    bubbleSort(array, size);
    printArray(array, size);

    printf("\nStarting array");
    //fills the array with new elements and prints the result
    fillArray(array, size);
    printArray(array, size);


    printf("\nMerge sort");
    //sorts the array and prints the result
    mergeSort(array, 0, size-1);
    printArray(array, size);

    printf("\nStarting array");
    //fills the array with new elements and prints the result
    fillArray(array, size);
    printArray(array, size);

    printf("\nQuick sort");
    //sorts the array and prints the sorted array
    quickSort(array, 0, size-1);
    printArray(array, size);

    printf("\nStarting array");
    //fills the array with new elements and prints the result
    fillArray(array, size);
    printArray(array, size);

    printf("\nInsertion sort");
    //sorts the array and prints the sorted array
    insertionSortIterative(array, size);
    printArray(array, size);

    printf("\nStarting array");
    fillArray(array, size);
    printArray(array, size);

    printf("\nHeap sort");
    heapSort(array, size);
    printArray(array, size);

    printf("\nStarting array");
    fillArray(array, size);
    printArray(array, size);

    printf("\nSelection sort");
    selectionSort(array, size);
    printArray(array, size);


    return 0;
}
