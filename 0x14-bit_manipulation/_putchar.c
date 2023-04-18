#include "main.h"
#include <unistd.h>
/**
 * _putchar - this writes the char c to stdout
 * @c: this is the character to print
 * Return: when the result is positive(1)
 * Returns -1 when there is an error, then errno is set
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
