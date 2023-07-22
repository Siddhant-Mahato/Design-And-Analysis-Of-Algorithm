#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#include "random.h"

long int partition(long int *a, long int low, long int high)
{
	long int i, j, k, pivot, temp;
	pivot = a[low];
	i = low + 1;
	j = high;
	do
	{
		while (a[i] <= pivot)
		{
			i++;
		}
		while (a[j] > pivot)
		{
			j--;
		}
		if (i < j)
		{
			temp = a[i];
			a[low] = a[j];
			a[j] = temp;
		}

	} while (i < j);
	temp = a[low];
	a[low] = a[j];
	a[j] = temp;

	return j;
}

void quick_sort(long int *a, long int low, long int high)
{

	long int loc;
	if (low < high)
	{
		loc = partition(a, low, high);
		quick_sort(a, low, loc - 1);
		quick_sort(a, loc + 1, high);
	}
}

int main()
{

	long int *a;
	a=newheader();
	long int i, b, y = 45, n = 80000;
	printf("array before sort: ");
	for (i = 0; i < n; i++)
	{
		printf("%ld\t", a[i]);
	}
	clock_t beg = clock();
	quick_sort(a, 0, n - 1);
	clock_t end = clock();
	printf("array after sort: ");
	for (i = 0; i < n; i++)
	{
		printf("%ld\t", a[i]);
	}

	double d = (double)(end - beg) / CLOCKS_PER_SEC;

	printf("EXECUTION TIME = %lf", d);

	return 0;
}
