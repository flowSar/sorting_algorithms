#include "sort.h"

/**
 * radix_sort - radix sort array of integer
 *
 * @array: array of integer
 * @size: array size
 */
void radix_sort(int *array, size_t size)
{
	int i, j, v;
	bins_t **bins_array;

	if (size <= 1 || array == NULL)
		return;
	v = find_div(array, size);
	for (i = 1; i <= v; i = i * 10)
	{
		bins_array = malloc(10 * sizeof(bins_t *));
		for (j = 0; j < 10; j++)
			bins_array[j] = NULL;

		fill_bin_array(bins_array, array, size, i);
		Override_array(bins_array, array);
		print_array(array, size);
		free_memory(bins_array);
	}
}
/**
 * fill_bin_array - fill array in bins array in it's right index
 * that we found based of last number of element or first depend
 * of elment for example : 234 we store this element at index '4';
 * for the first time and then in '3' and '2' untile array was
 * sorted.
 *
 * @bins_array: bins array.
 * @array: array of integer
 * @size: array size.
 * @div: divided
 */
void fill_bin_array(bins_t **bins_array, int *array, size_t size, int div)
{
	size_t i;
	int index;
	bins_t *bins, *current;

	for (i = 0; i < size; i++)
	{
		index = (array[i] / div) % 10;
		if (bins_array[index] == NULL)
		{
			bins = malloc(sizeof(bins_t));
			bins->n = array[i];
			bins->next = NULL;
			bins_array[index] = bins;
		}
		else
		{
			current = bins_array[index];
			while (current->next)
				current = current->next;
			bins = malloc(sizeof(bins_t));
			bins->n = array[i];
			bins->next = NULL;
			current->next = bins;
		}
	}
}
/**
 * Override_array - thid function for override array with new partially or
 * stored numbers.
 * we take element from array_bins and we write them in original array
 *
 * @bins_array: bins array.
 * @array: array of integer
 */
void Override_array(bins_t **bins_array, int *array)
{
	int i;
	bins_t *current;
	size_t j = 0;

	for (i = 0; i < 10; i++)
	{
		if (bins_array[i] != NULL)
		{
			array[j] = bins_array[i]->n;
			j++;
			current = bins_array[i]->next;
			while (current)
			{
				array[j] = current->n;
				current = current->next;
				j++;
			}
		}
	}
}
/**
 * free_memory - this for free alocated memory for bins_array
 *
 * @array: bins array.
 */
void free_memory(bins_t **array)
{
	bins_t *current, *prev;
	int i = 0;

	while (i < 10)
	{
		if (array[i] != NULL)
		{
			current = array[i];
			while (current->next)
			{
				prev = current->next;
				free(current);
				current = prev;
			}
			if (current)
				free(current);
		}
		i++;
	}
	free(array);
}

/**
 * find_div - thif function for find divided number by finding
 * max number in a list
 * I still need to work on this function.
 *
 * @array: bins array.
 * @size: array size.
 *
 * Return: divided number.
 */
int find_div(int *array, size_t size)
{
	int max;
	size_t i = 0;
	int div = 1;

	max = array[0];
	for (; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	if (max < 9)
		div = 1;
	else if (max >= 10 && max <= 99)
		div = 10;
	else if (max >= 100 && max <= 999)
		div = 100;
	else if (max > 999)
		div = 1000;
	return (div);
}
int main(void)
{
	int array[] = {79, 47, 68, 87, 84, 91, 21, 32, 34, 2, 95, 31, 20, 22, 98, 39, 92, 41, 62, 1};
	size_t n = sizeof(array) / sizeof(array[0]);/* 20 */

	print_array(array, n);
	printf("\n");
	radix_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
