#include "sort.h"

/**
 * insertion_sort_list - sort linkedlist of integer
 *
 * @list: linked_list head
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *start_node;

	if ((list) != NULL && is_dubby_linked_list(list) != 0)
	{
		start_node = (*list)->next;
		while (start_node)
		{
			comapre_and_swap(list, start_node);
			start_node = start_node->next;
		}
	}
}
/**
 * is_dubby_linked_list - check if linked_list is
 * a doublylinked_list
 *
 * @head: linked_list head
 *
 * Return: 0 if not and 1 if it's a doublt linked_list.
 */
int is_dubby_linked_list(listint_t **head)
{
	listint_t *next;

	next = (*head)->next;
	if (next)
	{
		if (next->prev == NULL)
			return (0);
	}
	return (1);
}
/**
 * comapre_and_swap - function for cmpare two nodes and swap
 * if one smaller than another depend on direction of sorting.
 *
 * @head: linked_list head
 * @start: starting node for sorting
 */
void comapre_and_swap(listint_t **head, listint_t *start)
{
	listint_t *prev_node, *current;

	current = start;
	prev_node = current->prev;
	while (current)
	{
		if (prev_node != NULL && current->n < prev_node->n)
		{
			print_list(*head);
			current = swap_nodes(head, prev_node, current);
		}
		else
			current = current->prev;

		if (current != NULL && current->prev != NULL)
			prev_node = current->prev;
	}
}
/**
 * swap_nodes - function for swaping two nodes
 * inclue swaping of head of linked_list
 *
 * @head: linked_list head
 * @node1: first node
 * @node2 : first node
 *
 * Return: starting node : the node that we are comparing
 * with previous node.
 */
listint_t *swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
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
				*head = node2;
			node2->next = node1;
			node1->prev = node2;
		}
	}
}
