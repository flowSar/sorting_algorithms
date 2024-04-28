#include <stdio.h>
#include "sort.h"
void compare_and_sort(int *array, int start_index);
void insertion_sort(int *array, size_t size)
{
    size_t i = 1;
    while (i < size)
    {
        compare_and_sort(array, i);
        i++;
    }
}

void compare_and_sort(int *array, int start_index)
{
    int sp = start_index;
    int tmp;
    while (sp > 0)
    {
        if (array[sp] < array[sp - 1])
        {
            tmp = array[sp];
            array[sp] = array[sp-1];
            array[sp-1] = tmp;
        }
        sp--;
    }
}

int main(void)
{

    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);


    print_array(array, n);
    printf("\n");
    insertion_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
