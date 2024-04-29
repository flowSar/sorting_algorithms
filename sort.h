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

int is_dubby_linked_list(listint_t **head);
void comapre_and_swap(listint_t **head, listint_t *start);
listint_t *swap_nodes(listint_t **head, listint_t *node1, listint_t *node2);
void Swap(int *array, size_t size, int i, int j);
void quik_sort_handler(int *array, size_t size, int f, int l);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
/* functions for shell-sort   */


/* function for cocktal sort */
listint_t *sort_left_r(listint_t **list, listint_t *node1, listint_t *node2);
void sort_right_l(listint_t **list, listint_t *node2, listint_t *node1);
void Swap_nodes_cocktail(listint_t **list, listint_t *node1, listint_t *node2);


#endif
