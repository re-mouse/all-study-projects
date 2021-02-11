#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int *ft_range(int min, int max);

int main()
{
    int min = -5;
    int max = 20;
    int *a;
    a = ft_range(min, max);
    for(int i = 0; i < max - min; i++)
        printf("%d ", a[i]);
}