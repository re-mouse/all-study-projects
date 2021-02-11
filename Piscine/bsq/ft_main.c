/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 19:00:18 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/07 20:07:46 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

void	ft_free_map(char **map)
{
	int y;

	y = 0;
	while (y < g_lines)
	{
		free(map[y]);
		y++;
	}
	free(map);
}

void	ft_process_map(char *filename)
{
	char	**map;
	int		size;
	int		x;
	int		y;

	map = ft_get_map(filename);
	if (map == NULL)
		write(2, "map error\n", 10);
	else
	{
		ft_start_analyze(map);
		size = g_min_square;
		x = g_biggestsquare_x;
		y = g_biggestsquare_y;
		ft_map_printer(map, size, x, y);
		ft_free_map(map);
	}
}

int		main(int argc, char **argv)
{
	int		map_count;

	map_count = 1;
	if (argc == 1)
	{
		ft_start_input();
		ft_process_map("temp");
		ft_corrupt_file();
	}
	while (map_count < argc)
	{
		ft_process_map(argv[map_count]);
		if (map_count + 1 < argc)
			write(1, "\n", 1);
		map_count++;
	}
}
