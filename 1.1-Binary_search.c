#include <stdio.h>
#include <stdlib.h>
#include "Random.h"

void bubblesort(int *arr, int n)
{
	int i, j;
	for (i = 0; i <= n - 1; i++)
	{
		for (j = 0; j <= n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int search(int *arr, int n, int x)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == x)
		{
			return mid;
		}
		else if (arr[mid] < x)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	if (left > right)
		return 0;
}

int main()
{
	int *a, n = 10000, i, w, s;
	a = newheader();
	printf("array elements before sorting: \n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
	bubblesort(a, n);
	printf("\nArray after sorting :\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
	w = 56;
	clock_t beg = clock();
	s = search(a, n, w);
	if (s == 0)
		printf("\nNot found");
	else
		printf("\nElement found at position %d\t", s + 1);
	clock_t end = clock();

	double d = (double)(end - beg) / CLOCKS_PER_SEC;
	printf("Execution time = %lf", d);
}
