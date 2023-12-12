#include "search_algos.h"

/**
 * linear_skip - function that searches a linked list with an express list
 * @list: to search through
 * @value: to find in the list
 *
 * Return: address of the value in the list, otherwise NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	size_t i;
	skiplist_t *temp = list, *prev;

	while (temp)
	{
		if (temp->express)
		{
			prev = temp;
			temp = temp->express;
		}
		else
		{
			prev = temp;
			while (temp->next)
				temp = temp->next;
		}
		if (prev == temp)
			return (NULL);

		printf("Value checked at index [%lu] = [%d]\n",
		       temp->index, temp->n);
		if (temp->n >= value || temp->next == NULL)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
			       prev->index, temp->index);
			for (i = prev->index; i <= temp->index; i++)
			{
				printf("Value checked at index [%lu] = [%d]\n",
				       prev->index, prev->n);
				if (prev->n == value)
					return (prev);
				prev = prev->next;
			}
			return (NULL);
		}
	}
	return (NULL);
}
