#include "sort.h"
void swap(int *array, size_t size, size_t idex1, size_t idex2);
/**
 * selection_sort - sort array of integer
 *
 * @array: array of integer
 * @size: array size
 */
void selection_sort(int *array, size_t size)
{
	size_t i, idex1, idex2;
	int tmp, swap_tracking;

	if (size < 2 || array == NULL)
		return;

	idex1 = 0, idex1 = 0;
	for (i = 0; i < size; i++)
	{
		tmp = array[i];
		idex2 = i;
		swap_tracking = 0;
		while (idex1 < size && idex2 < size)
		{
			if (array[idex2] < tmp)
			{
				tmp = array[idex2];
				idex1 = idex2;
				swap_tracking = 1;
			}
			idex2++;
		}
		if (swap_tracking == 1)
			swap(array, size, i, idex1);
	}
}
/**
 * swap - swaping two element of array.
 *
 * @array: array of integer
 * @size: array size
 * @idex1: index 1
 * @idex2: index 2
 */
void swap(int *array, size_t size, size_t idex1, size_t idex2)
{
	int tmp;

	tmp = array[idex1];
	array[idex1] = array[idex2];
	array[idex2] = tmp;
	print_array(array, size);
}
