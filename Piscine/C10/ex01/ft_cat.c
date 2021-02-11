/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:52:51 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/28 15:52:52 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

int		readfile(int fd);

int		ft_strlen(char *str);

void	outputerror(char **argv, int i);

void	checkinput(void);

int		main(int ar, char **argv)
{
	int	fd;
	int i;

	i = 1;
	if (ar == 1)
		checkinput();
	if (ar > 1 && argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == 0)
	{
		if (ar == 2)
			checkinput();
		i++;
	}
	while (i < ar)
	{
		while (i < ar && (argv[i][0] == '-' && argv[i][1] == 0))
		{
			checkinput();
			i++;
		}
		if (i < ar && ((fd = open(argv[i], O_RDONLY)) < 0 || readfile(fd) < 0))
		{
			outputerror(argv, i);
		}
		i++;
	}
}

int		readfile(int fd)
{
	ssize_t text;
	int		n;
	char	printc;

	while ((text = read(fd, &printc, 1)) > 0)
	{
		write(1, &printc, 1);
	}
	if (text == -1)
		return (1);
	if ((n = close(fd)) == -1)
		return (1);
	return (0);
}

int		ft_strlen(char *str)
{
	int n;

	n = 0;
	while (*(str + n))
		n++;
	return (n);
}

void	checkinput(void)
{
	char	inp[BUFFSIZE];
	int		i;
	int		res;

	res = 0;
	i = 0;
	while ((res = read(0, inp, BUFFSIZE)) > 0)
	{
		i = 0;
		write(1, inp, res);
		while (i < res)
		{
			inp[i] = 0;
			i++;
		}
	}
}

void	outputerror(char **argv, int i)
{
	write(2, basename(argv[0]), strlen(basename(argv[0])));
	write(2, ": ", 2);
	write(2, basename(argv[i]), strlen(argv[i]));
	write(2, ": ", 2);
	write(2, strerror(errno), strlen(strerror(errno)));
	write(2, "\n", 1);
}
