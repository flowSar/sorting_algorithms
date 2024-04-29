#include "sort.h"
int knuth_sequence(int array_size);
void swap(int *array, int i, int j);
void compare_with_interval(int *array, size_t size, int interval);
void compare_and_shift(int *array, int j, int i);
void insertion_sort(int *array, size_t size);

/**
 * shell_sort - shell sort algorithms works like a insertion_sort
 * sort , but with additional improvment with using interval
 *
 * @array: array of integer
 * @size: array size
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, initial_interval, i, k;

	initial_interval = knuth_sequence(size);
	interval = initial_interval;
	i = 0, k = 0;
	while (k < size && interval >= 1)
	{
		compare_with_interval(array, size, interval);
		interval = (interval / 3);
		print_array(array, size);
		if (interval == i)
		{
			insertion_sort(array, size);
			break;
		}
		k++;
	}
}
/**
 * compare_with_interval - this function for comparing two element
 * of an array that has a distance between them which is "interval".
 *
 * @array: array of integer
 * @size: array size.
 * @interval: distance between two element of an array that we compare.
 */
void compare_with_interval(int *array, size_t size, int interval)
{
	size_t j = interval;
	int i = 0;

	while (j < size)
	{
		if (array[i] > array[j])
			compare_and_shift(array, j, i);

		j++;
		i++;
	}
}
/**
 * insertion_sort - insertion sort we use it when interval equal 1.
 *
 * @array: array of integer
 * @size: array size.
 */
void insertion_sort(int *array, size_t size)
{
	size_t i, j;

	i = 0;
	j = 1;
	while (j < size)
	{
		if (array[j] < array[i])
		{
			compare_and_shift(array, j, i);
		}
		j++;
		i++;
	}
}
/**
 * compare_and_shift - in this function we compare two element of array at
 * index i and j and shif the small one to its right place,
 *
 * @array: array of integer
 * @j: index j.
 * @i: index i.
 */
void compare_and_shift(int *array, int j, int i)
{
	while (i >= 0 && j >= 0)
	{
		if (array[j] < array[i])
			swap(array, j, i);
		j--;
		i--;
	}
}
/**
 * swap - this function for waping two elemnt of an array with inde i and j.
 *
 * @array: array of integer
 * @j: index j.
 * @i: index i.
 */
void swap(int *array, int i, int j)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}
/**
 * knuth_sequence - this function falculate interval using the Knuth sequence.
 *
 * @array_size: array size
 * Return: interval.
 */
int knuth_sequence(int array_size)
{
	int interval = 1;

	while (interval <= array_size / 3)
		interval = interval * 3 + 1;
	return (interval);
}
