#include "sort.h"

/**
 * insertion_sort_list - sort linkedlist of integer
 *
 * @list: linked_list head
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *start_node;

	start_node = (*list)->next;
	while (start_node)
	{
		comapre_and_swap(list, start_node);
		start_node = start_node->next;
	}
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
	if (node1->prev != NULL)
	{
		node1->prev->next = node2;
		node2->prev = node1->prev;
		node1->next = node2->next;
		if (node2->next != NULL)
			node2->next->prev = node1;
		node2->next = node1;
		node1->prev = node2;
		return (node2);
	}
	else
	{
		listint_t **tmp = &node1;
		*head = node2;

		(*tmp)->next = node2->next;
		(*tmp)->prev = (*head);
		node2->next->prev = (*tmp);
		(*head)->next = (*tmp);
		(*head)->prev = NULL;
		return (*tmp);
	}
}
