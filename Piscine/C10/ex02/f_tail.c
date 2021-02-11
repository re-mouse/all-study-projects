/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:52:51 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/28 15:52:52 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

int		readfile(long offset, char *filename, int ar, int g)
{
	ssize_t	text;
	int		fd;
	long	j;
	long	i;
	char	printc;

	i = 0;
	fd = 0;
	j = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (1);
	while ((text = read(fd, &printc, 1)) > 0)
		i++;
	if (text == -1 || close(fd) < 0 || (fd = open(filename, O_RDONLY)) < 0)
		return (1);
	checkar(ar, filename, g);
	while ((text = read(fd, &printc, 1)) > 0)
	{
		j++;
		if (j + offset > i)
			write(1, &printc, 1);
	}
	if (text == -1 || close(fd) == -1)
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

void	checkinput(long offset)
{
	char	inp[BUFFSIZE];
	long	i;

	i = 0;
	while ((i = read(0, inp + i, 1) > 0))
	{
	}
	if (offset > i)
		offset = i;
	write(1, inp + i - offset, offset);
}

void	checkar(int ar, char *namefile, int i)
{
	if (ar > 4)
	{
		if (i != 3)
			write(1, "\n", 1);
		write(1, "==> ", 4);
		write(1, basename(namefile), strlen(basename(namefile)));
		write(1, " <==\n", 5);
	}
}
