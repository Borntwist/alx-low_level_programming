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
	ssize_t p;
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
	p = write(su, text_content, size);
	if (p == -1)
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
 * @q: is a pointer to a char
 *
 * Return: Always 0.
 */

int _strlen(const char *q)
{
	int e = 0;

	while (*(q + e) != '\0')
	{
		e++;
	}

	return (e);
}
