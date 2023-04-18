#include "main.h"

/**
 * set_bit - sets a bit to 1 when it gets to its required index
 * @n: pointer to the number to be changed
 * @index: index of the number that is meant to be set to 1
 * Return - Return 1 for positive and -1 for negative
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
