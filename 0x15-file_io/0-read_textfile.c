#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - reads and prints from a file
 * @filename: path to file
 * @letters: chars to read
 * Return: chars read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int su;
	char *buff;
	ssize_t bytes, g;

	if (!filename)
		return (0);
	su = open(filename, O_RDONLY);
	if (su == -1)
	{
		close(su);
		return (0);
	}

	buff = malloc(sizeof(char) * letters);
	if (!buff)
	{
		close(su);
		return (0);
	}

	bytes = read(su, buff, letters);

	if (bytes == -1)
	{
		close(su);
		free(buff);
		return (0);
	}

	g = write(STDOUT_FILENO, buff, bytes);

	if (g == -1)
	{
		close(su);
		free(buff);
		return (0);
	}
	close(su);
	return (bytes);
}
