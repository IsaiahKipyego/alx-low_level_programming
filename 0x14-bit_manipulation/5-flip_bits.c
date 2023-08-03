#include "main.h"
/**
*flip_bits - get a number of bits to flip to get from p to q
*@p: the initial num
*@q: the final num
*Return: number of flipped bits
*/
unsigned int flip_bits(unsigned long int p, unsigned long int q)
{
	unsigned long int flipped = p ^ q;
	int count = 0;
	while (flipped)
	{
		if (flipped & 1)
			count++;
		flipped >>= 1;
	}
	return (count);
}
