#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include <time.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}



int heapify(int *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;

    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;

    }
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}



int heapsort(int *arr, int n)
{
    int i;
    for (i = (n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


int main()
{
    int *arr;
    arr = newheader();
    int i;
    int n = 10000;
    printf("array before sort:");
    for (i = 0; i < n; i++)
    {
        printf("%d\t ", arr[i]);
    }
    clock_t beg = clock();
    heapsort(arr, n);
    clock_t end = clock();
    printf("\narray after sort:");
    for (i = 0; i < n; i++)
    {
        printf("%d\t ", arr[i]);
    }

    double d = (double)(end - beg) / CLOCKS_PER_SEC;
    printf("execution time is %lf", d);
    return 0;
}
