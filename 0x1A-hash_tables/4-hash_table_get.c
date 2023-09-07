#include "hash_tables.h"

/**
 * hash_table_get - retrieves the value associated with the key
 * @ht: hash table to be checked
 * @key: key being searched
 *
 * Return: returns value of the element with the key
 * returns if no element is found NULL
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t **array, *temp;

	if (!ht)
		return (NULL);

	if (!key || key[0] == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	array = ht->array;

	temp = array[index];
	while (temp)
	{
		if (strcmp(key, temp->key) == 0)
			return (temp->value);
		temp = temp->next;
	}

	return (NULL);
}
