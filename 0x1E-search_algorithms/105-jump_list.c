#include "search_algos.h"

/**
 * jump_list - searches a value in a sorted linked list of integers
 * using Jump search algorithm.
 *
 * @list: a pointer to head of linked list
 * @size: a number of nodes in linked list
 * @value: a value to search for
 *
 * Return: a Pointer to  first node where value is located or
 * if value is not present in head or if head is NULL, return NULL
 */
{
	listint_t *low =  NULL, *high = NULL;
	size_t limit = 0;

	if (list != NULL)
	{
		low = list;
		high = list;
		while (high->next != NULL && high->index < size && high->n < value)
		{
			low = high;
			limit += sqrt(size);
			while (high->index < limit && high->next != NULL)
				high = high->next;
			printf("Value checked at index [%lu] = [%d]\n", high->index, high->n);
		}
		printf("Value found between indexes [%lu] and [%lu]\n",
		       low->index, high->index);
		while (low != NULL && low->index < size && low->index <= high->index)
		{
			printf("Value checked at index [%lu] = [%d]\n", low->index, low->n);
			if (low->n == value)
				return (low);
			low = low->next;
		}
	}
	return (NULL);

}
