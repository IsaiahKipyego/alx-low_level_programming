#include <stdlib.h>
#include "search_algos.h"

void free_list(listint_t *list);

/**
 * create_list - create single linked list
 *
 * @array: a pointer to array to use to fill list
 * @size: Size of array
 *
 * Return: a pointer to head of created list
 */
listint_t *create_list(int *array, size_t size)
{
	listint_t *list;
	listint_t *node;

	list = NULL;
	while (array && size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
		{
			free_list(list);
			return (NULL);
		}
		node->n = array[size];
		node->index = size;
		node->next = list;
		list = node;
	}
	return (list);
}
