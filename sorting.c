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
void merge(int *array,int start,int end)
{
    //calculates the middle index in the array
    int mid = (start+end)/2;

    //iterators
    int i = start;
    int j = mid+1;
    int k = start;

    //temp array for storing sorted array
    int temp[100];

    //compares the values of the 2 subarrays and sorts them into a single array
    while(i<=mid && j<=end){
        if(array[i] < array[j]){
            temp[k++] = array[i++];
        }
        else{
            temp[k++] = array[j++];
        }
    }

    //fill remaining values if first subarray was not fully used
    while(i<=mid)
    {
        temp[k++] = array[i++];
    }

    //fill remaining values if second subarray was not fully used
    while(j<=end)
    {
        temp[k++]  = array[j++];
    }

    //transfers sorted array back into the result array
    for(int i=start;i<=end;i++)
    {
        array[i] = temp[i];
    }


}

/*Implementation of merge sort, a divide and conquer sorting algorithm
 *that uses recursion to divide the array in half each time and
 *utilizes a merge function to merge all of the subarrays to sort
 *the array. The running time is O(n*logn)
*/
//start is the starting index and end is the final index for input end should be size-1
void mergeSort(int *array,int start,int end)
{
//base case when array size is 1 recursive calls exit
    if(start>=end)
    {
        return;
    }

//calculates the middle index of the array
    int mid = (start+end)/2;

//splits array in half until size is 1
    mergeSort(array,start,mid);
    mergeSort(array,mid+1,end);

//merges every subarray into one array
    merge(array,start,end);

}

/*Function that rearranges elements in an integer array around
 *a pivot point that is selected as the last element in the array
*/
int partition(int *array, int start, int end)
{
    //holds the value of the pivot element
    int pivot = array[end];
    //index of smaller element
    int i = start-1;
    //temp variable used for swaps
    int temp;

    //loop that rearranges elements around a pivot point
    for(int j = start; j < end; j++)
    {
        //if the current element of the array is less than the pivot swap with element that is greater than pivot
        if(array[j] < pivot)
        {
            //increments i so that it is the proper position of an element that can be swapped
            i++;

            //swaps the smaller element in j with the larger element in i
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }

    //holds the index of the pivot which is i+1 as the smaller elements end at index i
    int pivotIndex = (i+1);

    //swaps the pivot element with the larger element in i+1
    temp = array[end];
    array[end] = array[i+1];
    array[i+1] = temp;

    //returns the pivotIndex to be used with recursive calls in quicksort
    return pivotIndex;


}

/*Implementation of quick sort if the starting index is smaller than the ending index
 *the array is partitioned so that the elements are arranged around a pivot point and
 *returns the index of the pivot point. Then quickSort is called first for the array from
 *element s(the starting index) to pivotIndex-1. This call sorts the elements that are lower
 *than the first pivot point. A second call is made to quickSort from element pivotIndex+1 to
 *e and this sorts the elements in the array that are after the first pivot point.
 *The recursive calls continue and pivot points are selected until the array is sorted
*/
void quickSort(int *array, int start, int end)
{
    //variable that holds the index of the last pivot element
    int pivotIndex;

    //base case if the starting index becomes equal to or greater than the ending index stops recursive calls
    if(start < end)
    {
        //partitions the array around a pivot and returns the pivot index into pivotIndex
        pivotIndex = partition(array, start, end);

        //sorts the array recursively from the start of the array to the element before the pivot
        quickSort(array, start, pivotIndex-1);
        //sorts the array recursively from the element after the pivot to the end of the array
        quickSort(array,pivotIndex+1, end);
    }
}


