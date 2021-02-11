#include <string.h>
#include <stdio.h>
#include <math.h>

int	ft_sqrt(int index);

int main()
{
    int ind = 625;
    printf("\nsqrt(%d) = %d", ind, ft_sqrt(ind));
    printf("sqrt orig = %f", sqrt(ind));
}