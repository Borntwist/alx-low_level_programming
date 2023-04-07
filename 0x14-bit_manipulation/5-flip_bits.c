#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @k: first number
 * @h: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int k, unsigned long int h)
{
int j, count = 0;
unsigned long int current;
unsigned long int exclusive = k ^ h;

for (j = 63; j >= 0; j--)
{
current = exclusive >> j;
if (current & 1)
count++;
}

return (count);
}
