#include "sort.h"
int partition_hoare(int *array, size_t size, int f, int l);
/**
 * quick_sort_hoare - sort array of integer
 *
 * @array: array of integer
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size <= 1 || array == NULL)
		return;
	quick_sort_hoare_handler(array, size, 0, size - 1);
}
/**
 * quick_sort_hoare_handler - sort array of integer
 *
 * @array: array of integer
 * @size: size of array
 * @f: first index of array or partition
 * @l: last index of array or partition
 */
void quick_sort_hoare_handler(int *array, size_t size, int f, int l)
{
	int j;

	if (l <= f)
		return;
	j = partition_hoare(array, size, f, l);
	quick_sort_hoare_handler(array, size, f, j);
	quick_sort_hoare_handler(array, size, j + 1, l);
}

/**
 * partition_hoare - partition method for quick sort.
 * this function works on sorting or puting the
 * pivot in his right position .
 *
 * @array: array of integer
 * @size: size of array
 * @f: first index of partition
 * @l: last index of partition
 *
 * Return: return the index
 */
int partition_hoare(int *array, size_t size, int f, int l)
{
	int i = f;
	int j = l;
	int pivot = array[l];

	while (i <= j)
	{
		if (array[j] >= pivot)
			j--;

		if (array[i] <= pivot)
			i++;
		if (j < i)
			break;

		if (array[i] > pivot && array[j] < pivot)
			Swap(array, size, i, j);
	}
	Swap(array, size, i, l);
	return (j);
}

/**
 * Swap - swap two elment of an array
 *
 * @array: array of integer
 * @size: size of array
 * @i: first index
 * @j: second index
 */
void Swap(int *array, size_t size, int i, int j)
{
	int tmp;

	if (i != j)
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		if (array[i] != array[j])
			print_array(array, size);
	}
}
