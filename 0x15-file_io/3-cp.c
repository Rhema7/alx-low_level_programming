#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - reserves 1024 bytes for a buffer
 * @file: the name the file buffer is stroring characters for
 * Return: Pointer to the newly allocated buffer
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - closes file descriptors
 * @fd: shows the file descriptor to be closed
 */
void close_file(int fd)
{
	int c;
c = close(fd);
if (c == -1)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
}
}

/**
 * main - copies the content of a file to another file
 * @argc: the number of arguments given to the program
 * @argv: an array of pointers to the arguments
 * Return: 0 when its all accurate.
 * Description - if count of argument is incorrect -exit code 7
 * If file_from cannot be read or does not exist - exit code 8
 * If file_to cannot be created or written to - exit code 9
 * If file_to or file_from cannot be closed - exit code 10
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(7);
	}

buffer = create_buffer(argv[2]);
from = open(argv[1], O_RDONLY);
r = read(from, buffer, 1024);
to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

do {
	if (from == -1 || r == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(8);
	}

	w = write(to, buffer, r);
	if (to == -1 || w == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
		free(buffer);
		exit(9);
	}

	r = read(from, buffer, 1024);
	to = open(argv[2], O_WRONLY | O_APPEND);
} while (r > 0);
free(buffer);
close_file(from);
close_file(to);

return (0);
}
