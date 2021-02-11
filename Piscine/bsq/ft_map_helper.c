/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 18:56:38 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/07 19:11:16 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

int		ft_check_square(char **map, int xcheck, int ycheck, int size)
{
	int		x;
	int		i;

	i = 0;
	if (ycheck + size > g_lines)
		return (-1);
	while (i < size)
	{
		x = i;
		while (x < size)
		{
			if (map[ycheck + i][xcheck + x] == g_obstacle)
				return (0);
			if (map[ycheck + x][xcheck + i] == g_obstacle)
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}

void	ft_update_max_square(int x, int y, int size)
{
	g_biggestsquare_x = x;
	g_biggestsquare_y = y;
	g_min_square = size;
}

int		ft_size_intalize(int size, int x, int y, char **map)
{
	int		sizetemp;
	int		x0;
	int		i;

	if (map[y][x] == g_obstacle || x == g_width)
	{
		if (size != 0 && size > g_min_square)
		{
			i = 0;
			x0 = x - size;
			while (size > g_min_square)
			{
				sizetemp = size + 1;
				while (--sizetemp > g_min_square)
					if (ft_check_square(map, x0 + i, y, sizetemp) > 0)
						ft_update_max_square(x0 + i, y, sizetemp);
				i++;
				size--;
			}
		}
		size = 0;
	}
	else
		size++;
	return (size);
}

void	ft_map_printer(char **map, int size, int x, int y)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = 0;
		while (j < size)
		{
			map[y + i][x + j] = g_full;
			j++;
		}
	}
	i = -1;
	while (map[++i] && i < g_lines)
	{
		j = 0;
		while (map[i][j])
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
	}
}
