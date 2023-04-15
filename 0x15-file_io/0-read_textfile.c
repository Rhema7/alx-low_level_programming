#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads text file and prints to STDOUT
 * @filename: the text file that is being read
 * @letters: shows the number of letters to be read
 * Return: w - the actual number of bytes that are read
 * and printed 0 when the function fails
 *          or thr filename id empty
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);


	free(buf);
	close(fd);
	return (w);
}
