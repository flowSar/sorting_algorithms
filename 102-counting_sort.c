#include "sort.h"

int count_array_size(int *array, size_t size);
void count_array(int *array, int *count, int count_size, size_t array_size);
void update_array(int *array, size_t size, int *count);

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

	if (size == 0 || array == NULL)
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
