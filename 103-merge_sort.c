#include "sort.h"
/**
 * merge_sort - start merge sort
 *
 * @array: array
 * @size: array size
 */
void merge_sort(int *array, size_t size)
{
	merge_sort_handler(array, 0, size - 1);
}
/**
 * merge_sort_handler - this recuersive fuction works on divide our array
 * into array od size 2 to we can sort it easily
 *
 * @array: array
 * @f: from index f begining of divided array or portion of the array
 * @l: to inde l, enf of the divided array
 */
void merge_sort_handler(int *array, int f, int l)
{
	int m, ml, mr;

	mr = 0;
	ml = 0;
	if (f == l)
		return;

	m = (l + f) / 2;
	if ((l + f) % 2 == 0)
	{
		ml = m - 1;
		mr = m;

	}
	else
	{
		ml = m;
		mr = m + 1;
	}

	merge_sort_handler(array, f, ml);
	merge_sort_handler(array, mr, l);
	merge(array, f, l);
}
/**
 * merge - this function for sorting and mergening the piece of the array
 * that was divided by merge_sort_handler, we don't relly divide
 * the array we just get the inde of piece of array
 *
 * @array: array
 * @f: from index f begining of the portion
 * @l: to inde l, enf of the portion
 */
void merge(int *array, int f, int l)
{
	int *left, *right;
	int i, j, middle, left_size, right_size, left_index, right_index, idex;
	int l1, l2;

	printf("Merging...\n");
	middle = (l - f + 1) / 2;
	left_size = middle;
	if ((f + l + 1) % 2 != 0)
		right_size = middle + 1;
	else
		right_size = middle;
	left_index = f;
	right_index = (f + l + 1) / 2;
	idex = f;
	left = malloc(left_size * sizeof(int));
	for (i = 0; i < left_size; i++)
		left[i] = array[left_index++];
	right = malloc(right_size * sizeof(int));
	for (j = 0; j < right_size; j++)
		right[j] = array[right_index++];
	i = 0, j = 0;
	while (i < left_size && j < right_size)
	{
		if (right[j] < left[i])
			array[idex++] = right[j++];
		else
			array[idex++] = left[i++];
	}
	for (l1 = i; l1 < left_size && idex <= l; l1++)
		array[idex++] = left[i++];
	for (l2 = j; l2 < right_size && idex <= l; l2++)
		array[idex++] = right[j++];
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);
	printf("[Done]: ");
	print_array_from_to(array, f, l + 1);
	free(right);
	free(left);
}
/**
 * print_array_from_to - this function for printing thet portion
 * that we sort and merged
 *
 * @array: array
 * @i: from index i begining of the portion
 * @j: to inde j, enf of the portion
 */
void print_array_from_to(const int *array, int i, int j)
{
	int k = i;

	while (array && k < j)
	{
		printf("%d", array[k]);
		if (k  < j - 1)
			printf(", ");
		++k;
	}
	printf("\n");
}
