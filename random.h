#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int n = 10000;
int *newheader()
{
	int *a, limit = 100000, i;
	a = (int *)malloc(n * 4);
	srand(time(NULL));
	for (i = 0; i < n; i++)
		a[i] = rand() % limit;
	return a;
}
