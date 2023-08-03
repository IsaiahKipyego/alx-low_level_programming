#include "main.h"
/**
*get_bit - gets value of a bit at a given index
*@p: number
*@index: index starting from 0 of the bit required
*Return: converted value
*/
int get_bit(unsigned long int p, unsigned int index)
{
	if (index > 63)
		return (-1);
	return ((p >> index) & 1);
}
