#include "stdlib.h"
#include "stdio.h"
#include "sorting.h"
#include "time.h"

void bubbleSort(int *array, int size)
{
    int temp = 0;
    for(int i = 0; i < size;i++)
    {
        for(int j = 0; j < size-1;j++)
        {
            if(array[j] > array[j+1])
            {
               temp = array[j+1];
               array[j+1] = array[j];
               array[j] = temp;
            }
        }
    }
}

void fillArray(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        array[i] = rand() % 100;
    }
}


void printArray(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
