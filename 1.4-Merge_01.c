
#include <stdio.h>
#include "random.h"
void mergesort(long int *, int left, int right);
void merge(long int *, int left, int mid, int right);
int main()
{
  long int i, n = 10000, *arr;
  fflush(stdin);
  arr = newheader();
  printf("\nelements before sorting:\n");
  for (i = 0; i < n; i++)
    printf("%ld\t", arr[i]);
  clock_t beg = clock();
  mergesort(arr, 0, n - 1);
  printf("\nthe sorted array is:\n");
  clock_t end = clock();
  for (i = 0; i < n; i++)
    printf("%ld\t", arr[i]);
  double tt = (double)(end - beg) / CLOCKS_PER_SEC;
  printf("execution time=%lf", tt);
  return 0;
}

void mergesort(long int *arr, int left, int right)

{
  if (left < right)
  {
    int mid = (right + left) / 2;
    mergesort(arr, left, mid);
    mergesort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

void merge(long int *arr, int left, int mid, int right)
{
  int i, j, k;
  int size1 = mid - left + 1;
  int size2 = right - mid;
  int Left[size1], Right[size2];
  for (i = 0; i < size1; i++)
    Left[i] = arr[left + i];
  for (j = 0; j < size2; j++)
    Right[j] = arr[mid + 1 + j];
  i = 0;
  j = 0;
  k = left;

  while (i < size1 && j < size2)
  {
    if (Left[i] <= Right[j])
    {
      arr[k] = Left[i];
      i++;
    }
    else
    {
      arr[k] = Right[j];
      j++;
    }
    k++;
  }
  while (i < size1)

  {
    arr[k] = Left[i];
    i++;
    k++;
  }
  while (j < size2)
  {
    arr[k] = Right[j];
    j++;
    k++;
  }
}
