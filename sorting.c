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

void merge(int *a,int s,int e){
    int mid = s + (e-s)/2;

    int i = s;
    int j = mid+1;
    int k = s;

    int temp[100];

    while(i<=mid && j<=e){
        if(a[i] < a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
        }
    }
    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=e){
        temp[k++]  = a[j++];
    }


    for(int i=s;i<=e;i++){
        a[i] = temp[i];
    }


}



void mergeSort(int *a,int s,int e)
{

    if(s>=e)
    {
        return;
    }


    int mid = s + (e-s)/2;


    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);


    merge(a,s,e);

}
