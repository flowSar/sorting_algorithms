#ifndef LISTINT
#define LISTINT

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* struct listint_s - Doubly linked list node
*
* @n: Integer stored in the node
* @prev: Pointer to the previous element of the list
* @next: Pointer to the next element of the list
*/
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
int is_dubby_linked_list(listint_t **head);
void comapre_and_swap(listint_t **head, listint_t *start);
listint_t *swap_nodes(listint_t **head, listint_t *node1, listint_t *node2);
void Swap(int *array, size_t size, int i, int j);
void quik_sort_handler(int *array, size_t size, int f, int l);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);

/* quick sort hoare partition */
void quick_sort_hoare_handler(int *array, size_t size, int f, int l);
void quick_sort_hoare(int *array, size_t size);
/* functions for shell-sort   */


/* function for cocktail sort */
listint_t *sort_left_r(listint_t **list, listint_t *node1,
					 listint_t *node2, listint_t *st);
listint_t *sort_right_l(listint_t **list, listint_t *node2,
						listint_t *node1, listint_t *st);
void Swap_nodes_cocktail(listint_t **list, listint_t *node1, listint_t *node2);

/* counting sort algorith function */
int count_array_size(int *array, size_t size);
void count_array(int *array, int *count, int count_size, size_t array_size);
void update_array(int *array, size_t size, int *count);

/* Merge sort functions */
void merge_sort(int *array, size_t size);
void merge_sort_handler(int *array, int f, int l);
void merge(int *array, int f, int l);
void print_array_from_to(const int *array, int i, int j);

/* radix sort */
/**
* struct bins_s - array bins node
*
* @n: Integer stored in the node
* @next: Pointer to the next element of the list
*/
typedef struct bins_s
{
	int n;
	struct bins_s *next;
} bins_t;

void fill_bin_array(bins_t **bins_array, int *array, size_t size, int div);
void Override_array(bins_t **bins_array, int *array);
void free_memory(bins_t **array);
int find_div(int *array, size_t size);
void radix_sort(int *array, size_t size);

#endif
