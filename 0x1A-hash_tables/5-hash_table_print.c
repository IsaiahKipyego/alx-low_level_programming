#include "hash_tables.h"

/**
 * hash_table_print - prints items in a hash table
 * @ht: hash table to print
 *
 * Description: if hash table is NULL prints nothing 
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t **array, *temp;
	unsigned long int index = 0;
	int flag = 0;

	/* if hash table is NULL */
	if (!ht)
		return;
	putchar('{');
	array = ht->array;
	/* iterate through the array */
	while (index < ht->size)
	{
		temp = array[index];
		if (flag == 1 && temp)
			printf(", ");
		/* print all elements at a particular node */
		while (temp)
		{
			printf("'%s': '%s'", temp->key, temp->value);
			temp = temp->next;
			if (temp)
				printf(", ");
			flag = 1;
		}
		index++;
	}
	printf("}\n");
}
