#include "sort.h"

/**
 * cocktail_sort_list - this algorithm works like bubble sort
 * with additional rigth to left sort
 *
 * @list: linked_list head
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *prev, *current, *first_node, *last_node;

	if (list == NULL || (*list)->next == NULL)
		return;

	first_node = (*list);
	while (first_node)
	{
		prev = (*list);
		current = prev->next;
		last_node =  sort_left_r(list, prev, current);
		sort_right_l(list, last_node->prev, last_node);
		first_node = first_node->next;
	}
}

/**
 * sort_left_r - sort from left to right
 *
 * @list: linked_list head
 * @node1: node 1
 * @node2: node 2
 *
 * Return: last last node of a list
 */
listint_t *sort_left_r(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev, *current;

	if (node2 == NULL || node1 == NULL)
		return (node1);

	prev = node1;
	current = node2;
	Swap_nodes_cocktail(list, prev, current);
	return (sort_left_r(list, current, current->next));
}
/**
 * sort_right_l - sort from right to left
 *
 * @list: linked_list head
 * @node1: node 1
 * @node2: node 2
 */
void sort_right_l(listint_t **list, listint_t *node2, listint_t *node1)
{
	listint_t *prev, *current;

	if (node2 == NULL || node1 == NULL)
		return;

	prev = node1;
	current = node2;
	Swap_nodes_cocktail(list, current, prev);
	sort_right_l(list, current->prev, current);
}
/**
 * Swap_nodes_cocktail - sort from left to right
 *
 * @list: linked_list head
 * @node1: node 1
 * @node2: node 2
 *
 * Return: last last node of a list
 */
void Swap_nodes_cocktail(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1 != NULL && node2 != NULL)
	{
		if (node2->n < node1->n)
		{
			node1->next = node2->next;
			if (node2->next != NULL)
				node2->next->prev = node1;
			node2->prev = node1->prev;
			if (node1->prev != NULL)
				node1->prev->next = node2;
			else
				*list = node2;
			node2->next = node1;
			node1->prev = node2;
			print_list((*list));
		}
	}
}
