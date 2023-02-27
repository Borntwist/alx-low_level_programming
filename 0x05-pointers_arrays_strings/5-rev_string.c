#include "main.h"

/**
 *  rev_string - reverse a string
 *  @s: input
 *  Return: string in reverse
 */
void rev_string
{
	char rv = s[0];
	int c = 0;
	int j;

	while (s[c] != '\0')
		c++;
	for (j = 0; j < c; j++)
	{
		c--;
		rv = s[j];
		s[j] = s[c];
