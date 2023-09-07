#include "hash_tables.h"

/**
 * key_index - gives index of a key
 * @key: key that is being hashed
 * @size: size of array of hash table
 *
 * Return: returns the index of the key provided
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index;

	index = hash_djb2(key) % size;
	return (index);
}
