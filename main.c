#include "stdio.h"
#include "stdlib.h"
#include "sorting.h"
#include "time.h"

int main()
{
    srand(time(0));
    int array[10];
    int size = 10;

    fillArray(array, size);
    printArray(array, size);
    bubbleSort(array, size);
    printArray(array, size);

    return 0;
}
