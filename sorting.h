#define SORTING_H
#ifndef SORTING_H

void bubbleSort(int *array, int size);
void mergeSort(int *array,int start,int end);
void quickSort(int *array, int start, int end);
void fillArray(int *array, int size);
void printArray(int *array, int size);
void merge(int *array,int start,int end);
int partition(int *array, int start, int end);
void insertionSortIterative(int *array, int size);

#endif // SORTING_H
