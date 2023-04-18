#include "main.h"

/**
 * get_endianness - checks if a computer is big or small endian
 * Return: Returns 1 for small and 0 for big
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}
