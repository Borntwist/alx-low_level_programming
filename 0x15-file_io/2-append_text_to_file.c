#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

/**
 * append_text_to_file - apends text to file
 * @filename: path to file
 * @text_content: content
 * Return: 1 or -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int se;
	ssize_t t;
	int size;

	if (!filename)
		return (-1);

	se = open(filename, O_WRONLY | O_APPEND);

	if (se == -1)
		return (-1);

	if (!text_content)
	{
		close(se);
		return (1);
	}

	size = _strlen(text_content);
	t = write(se, text_content, size);

	if (t == -1)
	{
		close(se);
		return (-1);
	}
	close(se);
	return (1);
}

/**
 * _strlen - len
 *
 * @a: is a pointer to a char
 *
 * Return: Always 0.
 */

int _strlen(const char *a)
{
	int c = 0;

	while (*(a + c) != '\0')
	{
		c++;
	}

	return (c);
}
