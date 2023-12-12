#ifndef _SEARCH_ALGOS_H_
#define _SEARCH_ALGOS_H_

#include <stdio.h>

typedef struct listint_s
{
    int n;               /* Integer stored at node. */
    size_t index;        /* Index of the node in list. */
    struct listint_s *next; /* Pointer to next node. */
} listint_t;

typedef struct skiplist_s
{
    int n;               /* Integer stored at node. */
    size_t index;        /* Index of the node in list. */
    struct skiplist_s *next;    /* Pointer to  next node. */
    struct skiplist_s *express; /* Pointer to next node in express lane. */
} skiplist_t;


int linear_search(int *array, size_t size, int value);


void print_array(int *array, size_t l, size_t r);


int binary_search_index(int *array, size_t l, size_t r, int value);


int binary_search(int *array, size_t size, int value);


int jump_search(int *array, size_t size, int value);

int interpolation_search(int *array, size_t size, int value);


int exponential_search(int *array, size_t size, int value);


int advanced_binary(int *array, size_t size, int value);


listint_t *jump_list(listint_t *list, size_t size, int value);


skiplist_t *linear_skip(skiplist_t *list, int value);


listint_t *create_list(int *array, size_t size);


void print_list(const listint_t *list);


void free_list(listint_t *list);


skiplist_t *create_skiplist(int *array, size_t size);


void print_skiplist(const skiplist_t *list);


void free_skiplist(skiplist_t *list);

#endif /* _SEARCH_ALGOS_H_ */
