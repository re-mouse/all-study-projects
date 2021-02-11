#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int ft_ultimate_range(int **range, int min, int max);

int main()
{
    int min = 10;
    int max = 20;
    int **b;
    int *a;
    b = (int **)malloc(sizeof(int *));
    printf("razmer = %d \n", ft_ultimate_range(b, min, max));
    a = *b;
    for(int i = 0; i < max - min; i++)
        printf("%d ",a[i]);
}