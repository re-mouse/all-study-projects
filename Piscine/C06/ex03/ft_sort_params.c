/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 14:39:49 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/24 14:40:18 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_main(int argc, char *argv[]);

int		ft_strcmp(char *s1, char *s2);

int		main(int argc, char *argv[])
{
	int		a;
	int		size;
	char	*temp;
	int		i;

	i = 1;
	argc--;
	size = argc;
	while (i <= size)
	{
		a = i + 1;
		while (a <= size)
		{
			if (ft_strcmp(argv[i], argv[a]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[a];
				argv[a] = temp;
			}
			a++;
		}
		i++;
	}
	write_main(argc, argv);
}

int		ft_strcmp(char *s1, char *s2)
{
	int				raznica;
	unsigned char	a;
	unsigned char	b;

	raznica = 0;
	a = (unsigned char)*s1;
	b = (unsigned char)*s2;
	while ((s1 != '\0' || s2 != '\0') && raznica == 0)
	{
		a = (unsigned char)*s1;
		b = (unsigned char)*s2;
		raznica = a - b;
		s1++;
		s2++;
	}
	return (raznica);
}

void	write_main(int argc, char *argv[])
{
	int i;

	i = 1;
	while (i <= argc)
	{
		while (*argv[i] != 0)
		{
			write(1, argv[i], 1);
			argv[i]++;
		}
		write(1, "\n", 1);
		i++;
	}
}
