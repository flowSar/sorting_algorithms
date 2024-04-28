#include "sort.h"

void compare_and_sort(listint_t **head, listint_t *start_node);
listint_t *swap_nodes(listint_t **head, listint_t *node1, listint_t *node2);

void insertion_sort_list(listint_t **list)
{
    listint_t *start_node;
    
    start_node = (*list)->next;
    
    while(start_node)
    {
        compare_and_sort(list, start_node);
        start_node = start_node->next;
    }
}

void compare_and_sort(listint_t **head, listint_t *start_node)
{
    listint_t *prev_node;
    
    prev_node = start_node->prev;
    
    while(start_node)
    {
        if (start_node->n < prev_node->n)
        {
            start_node = swap_nodes(head, prev_node, start_node);
        }
        else
            start_node = start_node->next;
    }
}

listint_t *swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t **tmp;
	
	if (node1->prev != NULL)
	{
		
	}
	else if (node1->prev == NULL)
	{
		tmp = &node1;
	}
}


void swap(int **p1, int **p2);
int main(void)
{
	
	int x = 10;
	int y = 10000;
	
	int *p1 = &x;
	int *p2 = &y;
	
	printf("p1 = %i, p2 = %i\n", *p1, *p2);
	swap(&p1, &p2);
	printf("p1 = %i, p2 = %i\n", *p1, *p2);
	return (0);
}

void swap(int **x, int **y)
{
}


