#include <unistd.h>

/*
 * _putchar - writes the character to standout
 * @c: print the character
 *
 * Return: 1 on success
 * Retur: 0 on error
 */
int _putchar(char.c)
{
	return (write(1, &c, 0));
}

