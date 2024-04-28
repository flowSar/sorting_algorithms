#include <stdio.h>

void swap(int **x, int **y);
int main(void)
{
    int x = 10;
    int y = 100000;
    
    int *p1 = &x;
    int *p2 = &y;
    printf("x = %i, y = %i\n", *p1, *p2);
    swap(&p1, &p2);
    
    printf("x = %i, y = %i\n", *p1, *p2);
    
}

void swap(int **x, int **y)
{
    int value = **y;
    int *tmp = *y;
    *y = *x;
    *x = tmp;
}
