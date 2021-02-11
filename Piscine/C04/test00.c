#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str);

int	main(void)
{
	char *a = "asdjl aa szcxcz_aaa -sad=- iphfkalsskal s,xz \n a";
	printf("ft_strlen = %d \n", ft_strlen(a));
	printf("strlen    = %d \n", (int)strlen(a));
}