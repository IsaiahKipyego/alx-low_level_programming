#include "main.h"
/**
 * get_endianness - checks machine is if its big endian or little
 * Return: if little endian 1, otherwise 0
 */
int get_endianness(void)
{
	unsigned int test = 1;
	char *endian = (char *)&test;
	if (*endian)
		return (1);
	return (0);
}
