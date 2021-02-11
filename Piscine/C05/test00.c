#include <string.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb);

int main()
{
    int factorial = 5;
    printf("factorial %d = %d", factorial, ft_iterative_factorial(factorial));
}