#include "hash_tables.h"

/**
 * create_node - creates a node item
 * @key: key associated with value
 * @value: value to be added
 *
 * Return: returns the new element created, if failed NULL
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new;

	new = malloc(sizeof(hash_node_t));
	if (!new)
		return (NULL);

	new->key = strdup(key);
	new->value = strdup(value);
	new->next = NULL;

	return (new);
}

/**
 * hash_table_set - adds an element to hash table
 * @ht: hash table
 * @key: key of the item
 * @value: the value to be added to the hash table
 *
 * Return: returns on success 1, if function failed 0
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t **array, *temp;
	unsigned long int index;
	hash_node_t *node;

	if (!ht) /* if no table provided */
		return (0);
	if (!key || key[0] == '\0')
		return (0);
	if (!value)
		return (0);
	/* get the index of the key */
	index = key_index((const unsigned char *)key, ht->size);
	array = ht->array;
	/* check if key exists */
	temp = array[index];
	while (temp)
	{
		if (strcmp(key, temp->key) == 0)
		{
			free(temp->value);
			temp->value = strdup(value);
			return (1);
		}
		temp = temp->next;
	}
	/* create a new node */
	node = create_node(key, value);
	if (!node)
		return (0);
	/* add new node to hash table */
	if (array[index]) /* if item already present at index */
	{
		node->next = array[index];
		array[index] = node;
	}
	else /* first item at the current index */
		array[index] = node;
	return (1);
}
