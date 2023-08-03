#include "main.h"
/**
 * binary_to_uint - converts binary to  unsigned integer
 * @a: the binary num as a stri
 *
 * Return: converted value
 */
unsigned int binary_to_uint(const char *a)
{
unsigned int decimal = 0;
int str_len = 0, base = 1;

if (!check_valid_string(a))
return (0);
while (a[str_len] != '\0')
str_len++;
while (str_len)
{
decimal += ((a[str_len - 1] - '0') * base);
base *= 2;
str_len--;
}
return (decimal);
}
/**
 * check_valid_string - checks if str has 0's and 1's only
 * @a: string to be checked
 * Return: 1 if string is valid, 0 otherwise
 */
int check_valid_string(const char *a)
{
if (a == NULL)
return (0);

while (*a)
{
if (*a != '1' && *a != '0')
return (0);
a++;
}
return (1);
}
