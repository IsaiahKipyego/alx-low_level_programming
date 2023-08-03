#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stddef.h>
unsigned int binary_to_uint(const char *a);
int check_valid_string(const char *a);
int _putchar(char c);
void print_binary(unsigned long int p);
int get_bit(unsigned long int p, unsigned int index);
int set_bit(unsigned long int *p, unsigned int index);
int clear_bit(unsigned long int *p, unsigned int index);
unsigned int flip_bits(unsigned long int p, unsigned long int q);
int get_endianness(void);
#endif
