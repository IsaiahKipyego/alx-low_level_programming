#include "main.h"
/**
*set_bit - sets a bit position to 1
*@p: number 
*@index: index to set
*Return: on success 1, on failure -1
*/
int set_bit(unsigned long int *p, unsigned int index)
{
	if (p == NULL || (index > (sizeof(unsigned long int) * 8) - 1))
		return (-1);
	*p |= (1 << index);
	return (1);
}
