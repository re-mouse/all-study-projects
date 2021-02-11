#include <string.h>
#include <stdio.h>

int	ft_find_next_prime(int nb);

int main()
{
    int check_int = 40;
    printf("%d and next prime = %d", check_int, ft_find_next_prime(check_int));
}