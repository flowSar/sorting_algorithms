#include "sort.h"

void comapre_and_swap(listint_t *head, listint_t *node);

void insertion_sort_list(listint_t **list)
{
	listint_t *start_node, *prev_node;

	
	start_node = (*list)->next;
    prev_node = start_node->prev;
    
    while(start_node)
    {
        comapre_and_swap((*list), start_node);
        start_node = start_node->next;
    }

}
 
void comapre_and_swap(listint_t *head, listint_t *node)
{
    int tmp;
    listint_t *prev_node, *current;
    
    current = node;
    prev_node = current->prev;

    while (current)
    {
        if (prev_node != NULL && current->n < prev_node->n)
        {
            tmp = current->n;
            current->n = prev_node->n;
            prev_node->n = tmp;
            print_list(head);
        }
        
        current = current->prev;
        if (current != NULL && current->prev != NULL)
            prev_node = current->prev;
    }
} 
