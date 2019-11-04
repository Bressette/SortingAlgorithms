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

    //fills the array and prints the initial values
    fillArray(array, size);
    printArray(array, size);

    //sorts the array and prints the sorted array
    bubbleSort(array, size);
    printArray(array, size);

    //fills the array with new elements and prints the result
    fillArray(array, size);
    printArray(array, size);

    //sorts the array and prints the result
    mergeSort(array, 0, size-1);
    printArray(array, size);

    //fills the array with new elements and prints the result
    fillArray(array, size);
    printArray(array, size);

    //sorts the array and prints the sorted array
    quickSort(array, 0, size-1);
    printArray(array, size);

    //fills the array with new elements and prints the result
    fillArray(array, size);
    printArray(array, size);

    //sorts the array and prints the sorted array
    insertionSortIterative(array, size);
    printArray(array, size);

    int newArray[10];
    fillArray(newArray, size);

    heapSort(newArray, size);

    return 0;
}
