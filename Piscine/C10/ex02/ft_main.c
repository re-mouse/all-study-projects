/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:52:51 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/28 15:52:52 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

int		main(int ar, char **argv)
{
	long	offset;
	int		i;
	int		error;

	i = 3;
	error = 0;
	offset = 0;
	if (ar > 1 && argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] == 0)
	{
		if (ar == 2)
			return (returnerror(argv));
		offset = getnum(argv[2], &error);
		if (error < 0)
			outputerror(argv[0], argv[2], "illegal offset", 2);
	}
	if (error <= 0)
		return (1);
	if (ar == 3)
		checkinput(offset);
	while (i < ar)
	{
		if (i < ar && readfile(offset, argv[i], ar, i) == 1)
			outputerror(argv[0], argv[i], strerror(errno), 1);
		i++;
	}
}

void	outputerror(char *programname, char *task, char *error, int mode)
{
	write(2, basename(programname), strlen(basename(programname)));
	write(2, ": ", 2);
	if (mode == 1)
	{
		write(2, basename(task), strlen(task));
		write(2, ": ", 2);
	}
	write(2, error, strlen(error));
	if (mode == 2)
	{
		write(2, " -- ", 4);
		write(2, basename(task), strlen(task));
	}
	write(2, "\n", 1);
}

long	getnum(char *str, int *errorlog)
{
	long	ret;

	ret = 0;
	while (*str)
	{
		if (*str > '9' || *str < '0')
		{
			*errorlog = -1;
			return (0);
		}
		ret = ret * 10 + ((*str - '0') % 10);
		str++;
	}
	*errorlog = 1;
	return (ret);
}

int		checkinputarg(long *offset, char **argv, int *error)
{
	if (argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] == 0)
	{
		*offset = getnum(argv[2], error);
		if (error < 0)
		{
			outputerror(argv[0], argv[2], "illegal offset", 2);
			return (1);
		}
	}
	return (0);
}

int		returnerror(char **argv)
{
	write(2, basename(argv[0]), strlen(basename(argv[0])));
	write(2, ": option requires an argument -- c\n", 35);
	return (1);
}
