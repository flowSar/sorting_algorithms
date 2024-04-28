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
		if (node2->next != NULL)
			node2->next->prev = (*tmp);
		(*head)->next = (*tmp);
		(*head)->prev = NULL;
		return (*tmp);
	}
}
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;
    int array[] = {19};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
