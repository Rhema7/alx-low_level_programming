#include "main.h"

/**
 * flip_bits - counts the number of bits to be
 *             changed from one number to another
 * @a: first number
 * @b: second number
 * Return: number of bits to be changed
 */
unsigned int flip_bits(unsigned long int a, unsigned long int b)
{
	int i, count = 0;
	unsigned long int current;
	unsigned long int exclusive = a ^ b;

	for (i = 63; i >= 0; i--)
	{
		current = exclusive >> i;
		if (current & 1)
			count++;
	}

	return (count);
}
