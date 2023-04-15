#include "main.h"

/**
 * create_file - creates a file
 * @filename: a pointer to the names of the files we are  creating
 * @text_content: a pointer to the string that will write to the file
 *
 * Return: If the function fails, print --1.
 *           Else -1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(fd, text_content, len);

	if (fd == -1 || w == -1)
		return (-1);

	close(fd);

	return (1);
}
