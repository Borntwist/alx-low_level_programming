#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

#define READ_ERR "Error: Can't read from file %s\n"
#define WRITE_ERR "Error: Can't write to %s\n"

/**
 * main - check the code for Alx  School students.
 * @argc: num of args
 * @argv: args
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	int src_fd, dest_fd, close_status, read_bytes, write_bytes;
	char buffer[1024];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (dest_fd == -1)
		dprintf(STDERR_FILENO, WRITE_ERR, argv[2]), exit(99);
	src_fd = open(argv[1], O_RDONLY);
	if (src_fd == -1)
		dprintf(STDERR_FILENO, READ_ERR, argv[1]), exit(98);
	while (1)
	{
		read_bytes = read(src_fd, buffer, 1024);
		if (read_bytes == -1)
			dprintf(STDERR_FILENO, READ_ERR, argv[1]), exit(98);
		if (read_bytes > 0)
		{
			write_bytes = write(dest_fd, buffer, read_bytes);
			if (write_bytes == -1)
				dprintf(STDERR_FILENO, WRITE_ERR, argv[2]), exit(99);
		} else
			break;
	}
	close_status = close(src_fd);
	if (close_status == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", src_fd), exit(100);
	close_status = close(dest_fd);
	if (close_status == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_fd), exit(100);
	return (0);
}
