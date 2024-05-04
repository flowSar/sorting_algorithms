#include "sort.h"

/**
 * counting_sort - is the main function of sorting our aray
 * it used for calling the funcion that works from creating
 * counting array and fill sorted array in out original array.
 *
 * @array: array of integer.
 * @size: size of array.
 */
void counting_sort(int *array, size_t size)
{
	int count_size;
	int *count;

	if (size < 2 || array == NULL)
		return;

	count_size = count_array_size(array, size);
	count = malloc(count_size * sizeof(int));

	count_array(array, count, count_size, size);
	print_array(count, count_size);
	update_array(array, size, count);

	free(count);
}
/**
 * count_array_size - this function retur max element of array
 * so we can use it to build our counting array
 *
 * @array: array of integer.
 * @size: size of array.
 *
 * Return: max number + 1;
 */
int count_array_size(int *array, size_t size)
{
	size_t i;
	int count_size;

	count_size = array[0];
	for (i = 0; i < size; i++)
	{
		if (count_size < array[i])
			count_size = array[i];
	}
	return (count_size + 1);
}
/**
 * count_array - this function for creating our counting array
 * first we fill our array with zeros to avoid garbage data
 * and then we count number of our array element and we store
 * them in count array,
 * and calculate out index by count[k] = count[k-1] + count[k]
 *
 * @array: array of integer.
 * @count: counting array.
 * @count_size: size of counting array
 * @array_size: size of array.
 */
void count_array(int *array, int *count, int count_size, size_t array_size)
{
	int i, k;
	size_t j;

	for (i = 0; i < count_size; i++)
		count[i] = 0;

	for (j = 0; j < array_size; j++)
		count[array[j]] += 1;

	for (k = 1; k < count_size; k++)
		count[k] = count[k - 1] + count[k];
}
/**
 * update_array - this function for sorting our array in a new array
 * based on counting array.
 * and them override our original array data with this new sorted array
 *
 * @array: array of integer.
 * @size: size of array.
 * @count: counting array.
 */
void update_array(int *array, size_t size, int *count)
{
	int *new_array;
	int i, index;
	size_t j;

	new_array = malloc((size) * sizeof(int));

	for (i = size - 1; i >= 0; i--)
	{
		index = count[array[i]] - 1;
		count[array[i]] -= 1;
		new_array[index] = array[i];
	}

	for (j = 0; j < size; j++)
		array[j] = new_array[j];

	free(new_array);
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
 * is_doubly_linked - Check if a doubly linked list is corectly linked
 *
 * @list: Pointer to the first node of the list to check
 *
 * Return: 1 if the list is correctly formated, 0 otherwise
 */
int is_doubly_linked(const listint_t *list)
{
	const listint_t *prev;

	prev = list ? list->prev : NULL;
	while (list)
	{
		if (list->prev != prev)
			return (0);
		prev = list;
		list = list->next;
	}
	return (1);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *list;
	int array[] = {98, 95, 92, 91, 87, 84, 79, 68, 62, 47, 41, 39, 34, 32, 31, 22, 21, 20, 2, 1};
	size_t n = sizeof(array) / sizeof(array[0]);

	list = create_listint(array, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	cocktail_sort_list(&list);
	printf("\n");
	print_list(list);
	if (!is_doubly_linked(list))
	{
		printf("The list is not correctly doubly linked !\n");
		return (1);
	}
	return (0);
}
