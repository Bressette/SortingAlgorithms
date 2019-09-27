#include "stdlib.h"
#include "stdio.h"
#include "sorting.h"
#include "time.h"

/*Implementation of bubble sort the simplest sorting algorithm
 *that runs in O(n^2) time. Using nested for loops for every
 *n pass bubbles one element to the correct position and then
 *successive passes bubble up the remaining elements
*/
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

//fills an array with random elements between 0-99
void fillArray(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        array[i] = rand() % 100;
    }
}

//prints the array that is passed in with the specified size
void printArray(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}


//merges the subarrays from mergeSort()
void merge(int *a,int s,int e)
{
    //calculates the middle index in the array
    int mid = s + (e-s)/2;

    //iterators
    int i = s;
    int j = mid+1;
    int k = s;

    //temp array for storing sorted array
    int temp[100];

    //compares the values of the 2 subarrays and sorts them into a single array
    while(i<=mid && j<=e){
        if(a[i] < a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
        }
    }

    //fill remaining values if first subarray was not fully used
    while(i<=mid)
    {
        temp[k++] = a[i++];
    }

    //fill remaining values if second subarray was not fully used
    while(j<=e)
    {
        temp[k++]  = a[j++];
    }

    //transfers sorted array back into the result array
    for(int i=s;i<=e;i++){
        a[i] = temp[i];
    }


}

/*Implementation of merge sort, a divide and conquer sorting algorithm
 *that uses recursion to divide the array in half each time and
 *utilizes a merge function to merge all of the subarrays to sort
 *the array. The running time is O(n*logn)
*/
//s is the starting index and e is the final index
void mergeSort(int *a,int s,int e)
{
//base case when array size is 1 recursive calls exit
    if(s>=e)
    {
        return;
    }

//calculates the middle index of the array
    int mid = s + (e-s)/2;

//splits array in half until size is 1
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);

//merges every subarray into one array
    merge(a,s,e);

}
