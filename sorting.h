#define SORTING_H
#ifndef SORTING_H

void bubbleSort(int *array, int size);
void merge_sort(int i, int j, int a[], int aux[]);
void quickSort(int *array, int s, int e);
void fillArray(int *array, int size);
void printArray(int *array, int size);
void merge(int *a,int s,int e);
int partition(int *a, int s, int e);

#endif // SORTING_H
