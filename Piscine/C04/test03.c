#include <stdio.h>
#include <string.h>

int	ft_atoi(char *str);

int	main(void)
{
	char *a =  "  \n \v \r \f \t  -+---+123456 as 7";
	printf(" \nft_atoi    = %d", ft_atoi(a));
	//printf(" \nft_atoi    = %d", atoi(a));
}
