#include <string.h>
#include <stdio.h>

int ft_recursive_power(int nb, int power);

int main()
{
    int nb = -2;
    int power = 31;
    printf("%d^%d = %d", nb, power, ft_recursive_power(nb, power));
}
