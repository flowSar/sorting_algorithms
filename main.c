#include <stdio.h>
#include <string.h>

void Quick_Sort(int *my_list, int f, int l);
void left_Quick_sort(int *list, int l, int h);
void right_Quick_Sort(int *list, int l, int h);
void print_array(const int *array, size_t size);
void swap(int *array, int i, int j);
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
// 	int array[] = {4, 9, 6, 2, 0, 7, 3};
    size_t size = sizeof(array) / sizeof(array[0]);
    print_array(array, size);
    printf("\n");
    Quick_Sort(array, 0, size - 1);
    printf("\n");
    print_array(array, size);
    return (0);
}
// 19, 48, 99, 71, 13, 52, 96, 73, 86, 7
// 
// 
// 
// 

void Quick_Sort(int *my_list, int f, int l)
{
	int i, j, pivot;
	
	pivot = my_list[l];
	i = f;
	j = l;
	if (l <= f)
		return;
	while (i <= j)
	{
		for (; my_list[j] >= pivot && j > 0; j--);

		for (; my_list[i] <= pivot && i < l; i++);
		
		if (j <= i)
			break;
		if (my_list[i] > my_list[j])
			swap(my_list, i, j);
	}
	if (j <= i)
		swap(my_list, i, l);

	Quick_Sort(my_list, f, j);
	Quick_Sort(my_list, j+1, l);
}

void swap(int *array, int i, int j)
{
    int tmp;
	if (i != j)
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, 10);
	}

}

void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}

/*
void Quick_Sort(int *my_list, int f, int l)
{
    int pivot = my_list[l];
    int j = l;
    int i = f;
    if (l <= f)
        return;
    
    while (i <= j)
    {
        if (my_list[j] >= pivot)
            j--;
        if(my_list[i] < pivot)
            i++;
        if (my_list[i] > my_list[j] && my_list[j] < pivot)
        {
            swap(my_list, i, j);
        }
        if (j <= i)
        {
            if (my_list[i] > my_list[l])
                swap(my_list, i, l);
            break;
        }
    }

    Quick_Sort(my_list, f, i);
    Quick_Sort(my_list, j+1, l);
}
*/


