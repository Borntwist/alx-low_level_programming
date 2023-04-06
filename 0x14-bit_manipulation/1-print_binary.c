#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @m: number to print in binary
 */
void print_binary(unsigned long int m)
{
	int j, count = 0;
	unsigned long int current;

	for (j = 63; j >= 0; j--)
	{
		current = m >> j;

		if (current & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}
