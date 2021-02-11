/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:36:36 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/07 19:56:40 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

void	ft_start_analyze(char **map)
{
	int y;
	int	size;
	int	x;

	y = 0;
	while (y < g_lines)
	{
		size = 0;
		x = 0;
		while (x <= g_width)
		{
			size = ft_size_intalize(size, x, y, map);
			x++;
		}
		y++;
	}
}

int		ft_is_valid(void)
{
	if (g_obstacle < 32 || g_obstacle > 126)
		return (0);
	if (g_empty < 32 || g_empty > 126)
		return (0);
	if (g_full < 32 || g_full > 126)
		return (0);
	if (g_obstacle == g_empty || g_obstacle == g_full || g_full == g_empty)
		return (0);
	return (1);
}

int		ft_count_fl_length(char *filename)
{
	char	symb;
	int		size;
	int		fd;
	int		err;

	size = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (-1);
	while ((err = read(fd, &symb, 1)) > 0 && symb != '\n')
		size++;
	if (err < 0 || close(fd) < 0)
		return (-1);
	if (size < 4)
		return (-1);
	return (size);
}
