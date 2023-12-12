#ifndef SEARCH_H
#define SEARCH_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * struct listint_s - singly linked list
 *
 * @n: Integer
 * @index: of the node in the list
 * @next: Pointer to next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
	int n;
	size_t index;
	struct listint_s *next;
} listint_t;


/*
 * Function searches for a value in an
 * array of integers using Linear search algorithm
 */
int linear_search(int *array, size_t size, int value);

/*
 * function to searches for a value in a sorted array
 * of integers using Binary search algorithm
 */
int binary_search(int *array, size_t size, int value);

/*
 * Function to searche for a value in a
 * sorted array of integers using Jump search algorithm
 */
int jump_search(int *array, size_t size, int value);

/*
 * function searches for a value in a sorted array of
 * integers using the Interpolation search algorithm
 */
int interpolation_search(int *array, size_t size, int value);

/*
 * function searches for a value in a sorted array
 * of integers using Exponential search algorithm
 */
int exponential_search(int *array, size_t size, int value);

/*
 * function that searches for a value in a sorted list
 * of integers using the Jump search algorithm in a singly linked list
 */
listint_t *jump_list(listint_t *list, size_t size, int value);

 /* print_list - Prints content of a listint_t */
void print_list(const listint_t *list);

/* create_list - Creates single linked list */
listint_t *create_list(int *array, size_t size);

/* free_list - deallocates a singly linked list */
void free_list(listint_t *list);

#endif /* SEARCH_H */
