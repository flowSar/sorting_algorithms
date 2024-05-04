#include "sort.h"

/**
 * cocktail_sort_list - this algorithm works like bubble sort
 * but instead sorting from one direction with this algorithm
 * we sort from two direction  right to left, left to right.
 * this @stpf for storing the last node we sort from left
 * this @stpl for storing the last node we sort from right
 * so we can track the node that we store and prevent algorithm
 * from reach sorted nodes.
 * it like we start from left to right and from right to left
 * like >>>> stop when we reach the middle <<<<<
 *
 * @list: linked_list head
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *prev, *current, *first_node, *last_node, *first, *stpf, *stpl;

	if (list == NULL || (*list)->next == NULL)
		return;

	first_node = (*list);
	first = (*list);
	stpf = NULL;
	stpl = NULL;

	while (first)
	{
		while (first_node)
		{
			prev = first_node;
			current = prev->next;
			last_node =  sort_left_r(list, prev, current, stpl);
			first = sort_right_l(list, last_node->prev, last_node, stpf);
			first_node = first_node->next;
			if (first_node == stpl)
				break;
		}
		stpf = first;
		stpl = last_node;
		if (stpf->next == stpl)
			break;
		first = first->next;
		first_node = first;
	}
}

/**
 * sort_left_r - sort from left to right
 * and @st variable for stoping recurcive function
 * from reeach to last sroted node.
 *
 * @list: linked_list head
 * @node1: node 1
 * @node2: node 2
 * @st: last node sorted on the left.
 *
 * Return: return last node we sort direction left->right
 */
listint_t *sort_left_r(listint_t **list, listint_t *node1,
					   listint_t *node2, listint_t *st)
{
	listint_t *prev, *current;

	if (node2 == st)
		return (node1);

	prev = node1;
	current = node2;
	Swap_nodes_cocktail(list, prev, current);
	return (sort_left_r(list, current, current->next, st));
}
/**
 * sort_right_l - sort from right to left
 * and @st variable for stoping recurcive function
 * from reeach to last sroted node.
 *
 * @list: linked_list head
 * @node1: node 1
 * @node2: node 2
 * @st: last node sorted on the right
 *
 * Return: return first node we sort, direct right to left
 */
listint_t *sort_right_l(listint_t **list, listint_t *node2,
						listint_t *node1, listint_t *st)
{
	listint_t *prev, *current;

	if (node2 == st)
		return (node1);

	prev = node1;
	current = node2;
	Swap_nodes_cocktail(list, current, prev);
	return (sort_right_l(list, current->prev, current, st));
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
