#include "main.h"

/**
 * clear_bit - sets the value of the bit given to it to 0
 * @n: pointer to the number to be changed
 * @index: index of the bit to be cleared
 * Return: Return 1 for positive and -1 for negative
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
