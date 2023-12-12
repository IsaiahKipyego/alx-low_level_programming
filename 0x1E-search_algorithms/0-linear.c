#include "search_algos.h"

/**
 * linear_search - function searches for a value in
 * array of integers using Linear search algorithm
 *
 * @array: pointer to first element of the array to search in
 * @size: number of elements in array
 * @value: to search for in the array
 *
 * Return: first index where value is located
 * or -1 if value is not found or if array is NULL
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i = 0;

	if (array != NULL)
	{
		for (i = 0; i < size; i++)
		{
			printf("Value checked array[%lu] = [%d]\n", i, array[i]);
			if (array[i] == value)
			{
				return (i);
			}
		}
	}
	return (-1);
}
