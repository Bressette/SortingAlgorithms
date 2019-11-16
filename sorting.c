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
    printf("\n");
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

/*Implementation of insert sort an in-place sorting algorithm with an average time complexity of O(n^2)
  Starting from the left of the array elements are compared to elements to the left of them and the element
  is inserted into the correct position in the array
*/
void insertionSortIterative(int *array, int size)
{
    int i, key, j;

    //for loop that iterates i that signifies which index of the
    for(i = 1; i < size; i++)
    {
        //holds the value of the element that will be inserted that is compared to everything else
        key = array[i];
        //sets the index of elements to be compared to be less than the element that will be compared
        j= i -1;

        //move elements greater than the key one position ahead of their current position
        while(j >= 0 && array[j] > key)
        {
            array[j+1] = array[j];
            j = j-1;
        }
        //inserts the key into the correct position of the array
        array[j+1] = key;
    }
}

void heapify(int *array, int size, int rootIndex)
{
    int largest = rootIndex;
    int left = rootIndex*2 + 1;
    int right = rootIndex*2 + 2;
    if(left < size && array[left] > array[largest])
    {
        largest = left;
    }

    if(right < size && array[right] > array[largest])
    {
        largest = right;
    }

    if(largest != rootIndex)
    {
        int temp = array[largest];
        array[largest] = array[rootIndex];
        array[rootIndex] = temp;
        heapify(array, size, largest);
    }


}


//Build a max heap from current array
//Replace the root with the last item in the array
//Decrease the size of the heap by one
//Repeat while size of heap is greater than one
void heapSort(int *array, int size)
{
    for(int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);

    for(int i = size - 1; i >= 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        heapify(array, i, 0);
    }
}

void selectionSort(int *arr, int sizeOfArray)
{
    int minIndex, temp;

    for(int i = 0; i < sizeOfArray-1; i++)
    {
        minIndex = i;
        for(int j = i + 1; j < sizeOfArray; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if(minIndex != i)
        {
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}
