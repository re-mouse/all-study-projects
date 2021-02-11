#include <stdio.h>

char	**ft_split(char *str, char *charset);

int	main()
{
	char *a = "12131231asd gdgf hg ja zxc gfas12asdasas4dsdsd3l76a";
	char *sep = "2";
	char **b = ft_split(a, sep);
	while (**b)
	{
		printf("stroka = %s\n", *b);
		b++;
	}
}