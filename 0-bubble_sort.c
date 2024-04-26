#include "sort.h"
/**
 * bubble_sort - sort array of integer
 *
 * @array: array of integer
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, i, tmp, swap_tracking;

	for (j = 0; j < size; j++)
	{
		swap_tracking = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swap_tracking += 1;
				print_array(array, size);
			}

		}
		if (swap_tracking == 0)
			break;
	}
}
