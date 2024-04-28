#include "sort.h"
/**
 * quick_sort - sort array of integer
 *
 * @array: array of integer
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (size <= 1 || array == NULL)
		return;
	quik_sort_handler(array, size, 0, size - 1);
}
/**
 * quik_sort_handler - sort array of integer
 *
 * @array: array of integer
 * @size: size of array
 * @f: first index of partition
 * @l: last index of partition
 */
void quik_sort_handler(int *array, size_t size, int f, int l)
{
	int i = f;
	int j = l;
	int pivot = array[l];

	if (l <= f)
		return;
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
	quik_sort_handler(array, size, f, j);
	quik_sort_handler(array, size, j + 1, l);
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
		print_array(array, size);
	}
}
