#include "main.h"

/**
 * append_text_to_file - Adds text to the end of a file
 * @filename: pointer to the name of a file
 * @text_content: string to add to the end of file
 *
 * Return: If function fails or filename is Empty --1
 *         the user lacks write permission when the file does not exist --1
 *         ELSE -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	w = write(o, text_content, len);

	if (o == -1 || w == -1)
		return (-1);

	close(o);

	return (1);
}
