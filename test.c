#include "sort.h"

/**
 * insertion_sort_list - Sorts a dll using insertion sort.
 * @list: The list to be sorted.
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = (*list)->next;

	if (*list == NULL || list == NULL || (*list)->next == NULL)
		return;

	while (curr != NULL)
	{
		listint_t *point = curr;
		listint_t *prev = point->prev;
		/*int value = curr->n;*/

		while (prev != NULL && prev->n > point->n)
		{
			if (point->next != NULL)
				point->next->prev = prev;
			prev->next = point->next;
			point->next = prev;
			point->prev = prev->prev;
			prev->prev = point;

			if (point->prev != NULL)
				point->prev->next = point;
			else
				*list = point;

			prev = point->prev;

		}

            print_list(*list);
		curr = curr->next;
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
    int array[] = {19, 4};
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
