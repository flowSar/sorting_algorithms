#include "sort.h"

void Swap(int *array, size_t size, int f, int l);
void Quick_sort_hadler(int *array, size_t size, int f, int l);

void Quick_sort(int *array, size_t size)
{
	Quick_sort_hadler(array, size, 0, size - 1);
}

void Quick_sort_hadler(int *array, size_t size, int f, int l)
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
	Quick_sort_hadler(array, size, f, j);
	Quick_sort_hadler(array, size, j + 1, l);
}

void Swap(int *array, size_t size, int f, int l)
{
	int tmp;
	if (f != l)
	{
		tmp = array[f];
		array[f] = array[l];
		array[l] = tmp;
		print_array(array, size);
	}
}

int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    Quick_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
