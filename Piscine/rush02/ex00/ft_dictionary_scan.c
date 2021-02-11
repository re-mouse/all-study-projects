/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary_scan.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:39:55 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/04 20:41:43 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

/*
**Здесь храним код ошибки, если он больше 0, то ни одной ошибки, -1 = ошибка
*/

int		g_err;
/*
**Считаный символ, именно его читает везде
*/

char	g_r_ch;

/*
**Пропускает пробелы, двоеточие и опять пробелы, без двоеточия возращает -1
*/

int		skip_space(int fd)
{
	while (g_r_ch == ' ')
		g_err = read(fd, &g_r_ch, 1);
	if (g_r_ch != ':')
		return (-1);
	g_err = read(fd, &g_r_ch, 1);
	while (g_r_ch == ' ')
		g_err = read(fd, &g_r_ch, 1);
	return (g_err);
}

/*
**Пропускает 1 линию, если есть их пропускает skip_space
*/

int		skipline(int fd)
{
	if (g_r_ch == '\n')
	{
		g_err = read(fd, &g_r_ch, 1);
		return (g_err);
	}
	if ((g_err = skip_space(fd)) == 1)
		while (g_r_ch != '\n')
			g_err = read(fd, &g_r_ch, 1);
	if (g_r_ch == '\n')
		g_err = read(fd, &g_r_ch, 1);
	return (g_err);
}

/*
**Если текущее число совпало с ключом (число) то возвращает 1, иначе 0
*/

int		check_key(int fd, char *key)
{
	int cmp;

	cmp = 1;
	while (g_r_ch >= '0' && g_r_ch <= '9' && g_err > 0)
	{
		if (g_r_ch != *key)
			cmp = 0;
		key++;
		g_err = read(fd, &g_r_ch, 1);
	}
	if (*key != 0)
		cmp = 0;
	return (cmp);
}

/*
**Пропустить пробелы и двоеточие, напечатать все до новой линии
*/

int		print_line(int fd)
{
	int status;
	int space;

	space = 0;
	if ((status = skip_space(fd)) == 1)
		while (g_r_ch != '\n' && g_r_ch != 0 && g_err > 0)
		{
			if (g_r_ch != ' ' || space == 0)
			{
				write(1, &g_r_ch, 1);
				if (g_r_ch != ' ')
					space = 0;
				else
					space++;
			}
			else
				space++;
			g_err = read(fd, &g_r_ch, 1);
		}
	return (status);
}

int		get_value(char *namefile, char *key)
{
	int fd;

	fd = open(namefile, O_RDONLY);
	g_err = read(fd, &g_r_ch, 1);
	while ((g_err > 0 && g_err != 2) || (g_err = read(fd, &g_r_ch, 1)) > 0)
	{
		g_err = 2;
		if (check_key(fd, key) == 1)
		{
			g_err = print_line(fd);
			close(fd);
			return (g_err);
		}
		else if (skipline(fd) == -1)
			break ;
	}
	close(fd);
	return (g_err);
}
