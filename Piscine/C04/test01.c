#include <stdio.h>
#include <string.h>
#include <unistd.h>

void    ft_putstr(char *str);

int	main(void)
{
	write(1, "ft_putstr = ", 12);
	char *a = "asdjl aa szcxcz_ -sad=- iphfkalsskal s,xz \n a";
    ft_putstr(a);
	printf("\nputstr    = %s", a);
}