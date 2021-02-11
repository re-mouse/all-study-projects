#include <string.h>
#include <stdio.h>

int	ft_recursive_factorial(int nb);

int main()
{
    int factorial = 7;
    printf("factorial %d = %d", factorial, ft_recursive_factorial(factorial));
}
