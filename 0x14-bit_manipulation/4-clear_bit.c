#include "main.h"
/**
*clear_bit - sets a bit position to 0
*@p: num to be used
*@index: position to be cleared
*Return: on success 1, on fail -1
*/
int clear_bit(unsigned long int *p, unsigned int index)
{
	if (p == NULL || (index > (sizeof(unsigned long int) * 8) - 1))
		return (-1);
	*p &= ~(1 << index);
	return (1);
}
