#include "sort.h"
void merge_sort_handler(int *array, size_t size, int l, int r);
void swap_and_merge(int *array, size_t size, int f, int m, int l);

void merge_sort(int *array, size_t size)
{
	
// 	for (int i = 0; i < size; i++)
	merge_sort_handler(array, size, 0, size - 1);
}

void merge_sort_handler(int *array, size_t size, int f, int l)
{
	int middle;
	
	if (l == f)
		return;
	middle = (f + l) / 2;
	merge_sort_handler(array, size, f, middle);
	merge_sort_handler(array, size, middle + 1, l);
	
	swap_and_merge(array, size, f, middle, l);
}

void swap_and_merge(int *array, size_t size, int f, int m, int l)
{
	int *new_array;
	int i, j, k;
	
	size = f + l;
	i = f;
	j = m;
	k = 0;
	
	new_array = malloc(size * sizeof(int));
	
	while (k < l && i <= m && j <= l)
	{
		if (array[j] < array[i])
		{
			new_array[k] = array[j];
			j++;
			k++;
			printf("k= %i\n", k);
		}
		i++;
	}
	if (i > l)
		new_array[k] = array[i];
	else
		new_array[k] = array[j];

// 	print_array(new_array, size);
}

int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	int array2[] = {19, 48, 99, 13, 71, 52, 96, 73, 7, 86};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    merge_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
