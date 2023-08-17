#include "lists.h"

/**
 * get_dnodeint_at_index - gets nth node of a doubly linked list
 * @head: list pointer
 * @index: index of node to return
 *
 * Return: address of the node or NULL if it does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (!head)
		return (NULL);

	while (head && i < index)
	{
		head = head->next;
		i++;
	}

	return (head ? head : NULL);
}
