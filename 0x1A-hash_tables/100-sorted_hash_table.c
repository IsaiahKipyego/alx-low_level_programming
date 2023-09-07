#include "hash_tables.h"

/**
 * shash_table_create - creates a hash table of given size
 * @size: size of hash table to be created
 *
 * Return: the created hash table, returns NULL on error
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new;
	shash_node_t **array;

	if (size < 1)
		return (NULL);

	new = malloc(sizeof(shash_table_t));
	if (!new)
		return (NULL);

	new->shead = NULL;
	new->stail = NULL;

	array = calloc(sizeof(new->array),  size);
	if (!array)
	{
		free(new);
		return (NULL);
	}

	new->size = size;
	new->array = array;

	return (new);
}

/**
 * create_node - creates a node with key value to be added to hash table
 * @key: key identifier
 * @value: value of item to create
 *
 * Return: returns node created, if error occured NULL
 */
shash_node_t *create_node_sorted(const char *key, const char *value)
{
	shash_node_t *new;

	new = malloc(sizeof(shash_node_t));
	if (!new)
		return (NULL);

	new->key = strdup(key);
	if (!new->key)
	{
		free(new);
		return (NULL);
	}
	new->value = strdup(value);
	if (!new->value)
	{
		free(new->key);
		free(new);
		return (NULL);
	}
	new->next = new->snext = new->sprev = NULL;

	return (new);
}

/**
 * insert_node_sorted - inserts a node in a sorted way
 * @ht: hash table to insert to
 * @item: item to add
 */
void insert_node_sorted(shash_table_t *ht, shash_node_t *item)
{
	shash_node_t *temp;

	if (!ht->shead && !ht->stail)
	{
		ht->shead = ht->stail = item;
		return;
	}
	temp = ht->shead;
	while (temp)
	{
		if (strcmp(item->key, temp->key) < 0)
		{
			item->snext = temp;
			item->sprev = temp->sprev;
			temp->sprev = item;
			if (item->sprev)
				item->sprev->snext = item;
			else
				ht->shead = item;
			return;
		}
		temp = temp->snext;
	}
	item->sprev = ht->stail;
	ht->stail->snext = item;
	ht->stail = item;
}

/**
 * shash_table_set - sets items in a table
 * @ht: table to set
 * @key: key item
 * value of the item
 *
 * Return: on error 0, on success 1
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t **array, *temp, *node;
	unsigned long int index;

	if (!ht || !ht->array || ht->size == 0) /* if no table provided */
		return (0);
	if (!key || strlen(key) == 0)
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
	node = create_node_sorted(key, value);
	if (!node)
		return (0);
	/* add new node to hash table */
	node->next = array[index];
	array[index] = node;
	insert_node_sorted(ht, node);

	return (1);
}

/**
 * shash_table_get - gets an item in a hash table
 * @ht: hash table
 * @key: key value  to get
 *
 * Return: returns element found, if not found NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t **array, *temp;

	if (!ht || !ht->array || ht->size == 0)
		return (NULL);

	if (!key || strlen(key) == 0)
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

/**
 * shash_table_print - prints a hash table in sorted way
 * @ht: table to print
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *temp;
	int flag = 0;

	/* if hash table is NULL */
	if (!ht || !ht->array)
		return;

	putchar('{');
	/* iterate through the array */
	temp = ht->shead;
	while (temp)
	{
		if (flag == 1)
			printf(", ");
		/* print all elements at a particular node */
		printf("'%s': '%s'", temp->key, temp->value);
		temp = temp->snext;
		flag = 1;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints in reverse order
 * @ht: hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *temp;
	char flag = 0;

	if (!ht || !ht->array)
		return;

	putchar('{');
	temp = ht->stail;
	while (temp)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		temp = temp->sprev;
		flag = 1;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a table
 * @ht: table to delete
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *temp;
	unsigned long int index = 0;

	if (!ht || !ht->array || !ht->size)
		return;

	while (index < ht->size)
	{
		while (ht->array[index])
		{
			temp = ht->array[index]->next;
			free(ht->array[index]->key);
			free(ht->array[index]->value);
			free(ht->array[index]);
			ht->array[index] = temp;
		}
		index++;
	}
	free(ht->array);
	ht->array = NULL;
	ht->shead = ht->stail = NULL;
	free(ht);
}
