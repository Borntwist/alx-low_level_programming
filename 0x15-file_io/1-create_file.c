#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

/**
 * create_file - append to file
 * @filename: path to file
 * @text_content: content
 * Return: chars read
 */

int create_file(const char *filename, char *text_content)
{
	int su;
	size_t u;
	int size;
	char *mem;

	if (!filename)
	{
		return (-1);
	}
	su = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (su == -1)
		return (-1);
	if (!text_content)
	{
		close(su);
		return (1);
	}
	size = _strlen(text_content);
	mem = malloc(sizeof(char) * size);
	if (!mem)
	{
		close(su);
		return (-1);
	}
	u = write(su, text_content, size);
	if (u = -1)
	{
		close(su);
		free(mem);
		return (-1);
	}
	close(su);
	free(mem);
	return (1);
}

/**
 * _strlen - len
 *
 * @w: is a pointer to a char
 *
 * Return: Always 0.
 */

int _strlen(const char *w)
{
	int k = 0;

	while (*(w + k) != '\0')
	{
		k++;
	}

	return (1);
}
