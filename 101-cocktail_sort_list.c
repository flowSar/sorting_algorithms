#include "sort.h"

listint_t *cocktail_sort_list_handler(listint_t **head, listint_t *node1, listint_t *node2);
void Swap_nodes_cocktail(listint_t **head, listint_t *node1, listint_t *node2);

void cocktail_sort_list(listint_t **list)
{
    listint_t *start, *prev;
    
    start = (*list)->next;
    prev = start->prev;
    
	Swap_nodes_cocktail(list, prev, start);
	
//     cocktail_sort_list_handler(list, prev, start);
//     while (start)
//     {
//         
//         if (prev != NULL &&start->n < prev->n)
//         prev = start;
//         start = start->next;
//         
//     }
}

listint_t *cocktail_sort_list_handler(listint_t **head, listint_t *node1, listint_t *node2)
{
// 	if (node2 == NULL)
// 		return;
	
// 	Swap_nodes();
// 	cocktail_sort_list_handler();
// 	Swap_nodes();
	
}

void Swap_nodes_cocktail(listint_t **head, listint_t *node1, listint_t *node2)
{
	if (node1 != NULL && node2 != NULL)
	{
		printf("swap");
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
    int array[] = {19, 6, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    cocktail_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
