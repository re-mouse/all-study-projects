#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	ft_putnbr(int nb);

int	main(void)
{
	write(1, "ft_putnbr = ", 12);
	int a = 2147483647;
    ft_putnbr(a);
	printf(" \nputnbr    = %d", a);
}
