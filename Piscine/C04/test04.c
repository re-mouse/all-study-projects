#include <stdio.h>
#include <string.h>

int	ft_putnbr_base(int nb, char *base);

int	main(void)
{
	int a =   -2147483648;
	printf("%d = base number \n = ft_putnbr_base", a);
    ft_putnbr_base(a, "01");
}
