#include "main.h"
/**
*print_binary - prints binary representation of a number
*@p: the number to be printed
*Return: null
*/
void print_binary(unsigned long int p)
{
if (p > 1)
	print_binary(p >> 1);
_putchar((p & 1) + '0');
}
