#include "main.h"
#include <stdio.h>

/**
 *  print_array - print n elemenst of an array
 *  @a: array
 *  @n: number of values to be printed
 */
void print_array(int *a, int n)
{
	int y;

	for (y = 0; y < n; t++)
	{
		printf("%d", a[y]);
		if (y != n - 1)
			printf(",");
	}
	printf("\n");
}
