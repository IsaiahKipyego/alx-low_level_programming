#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: hash table to delete
 *
 * Description: frees occupied memory space hence deletes hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *temp, *temp_next;
	unsigned long int index = 0;

	if (!ht)
		return;

	while (index < ht->size)
	{
		temp = ht->array[index];
		while (temp)
		{
			temp_next = temp->next;
			free(temp->value);
			free(temp->key);
			free(temp);
			temp = temp_next;
		}
		index++;
	}
	free(ht->array);
	free(ht);
}
