/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_intializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 19:00:25 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/07 19:56:58 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

int		ft_is_part_of_map(char c)
{
	int out;

	out = -1;
	if (c == g_obstacle || c == g_empty)
		out = 1;
	return (out);
}

int		ft_check_parameters(int fd, int linc)
{
	int		ft_skip_b;

	g_width = 0;
	g_lines = 0;
	ft_skip_b = 0;
	g_min_square = 0;
	while (read(fd, &g_ch, 1) > 0 && g_ch >= '0' && g_ch <= '9' && linc-- > 0)
		g_lines = g_lines * 10 + g_ch - '0';
	g_empty = g_ch;
	if (g_empty == '\n')
		return (-1);
	if (read(fd, &g_obstacle, 1) != 1 || g_obstacle == '\n')
		return (-1);
	if (read(fd, &g_full, 1) != 1 || g_full == '\n')
		return (-1);
	if (read(fd, &g_ch, 1) > 0 && g_ch == '\n' && read(fd, &g_ch, 1) > 0)
	{
		while (g_ch != '\n' && read(fd, &g_ch, 1) > 0)
			g_width++;
		return (ft_skip_b + 4);
	}
	else
		return (-1);
}

int		ft_copy_line(int fd, int line, char **map)
{
	int		size;
	int		operations;
	char	*map_line;

	map_line = malloc(sizeof(char) * g_width + 1);
	map_line[g_width] = 0;
	operations = -1;
	size = 0;
	while (++operations < g_width && read(fd, &g_ch, 1) > 0 && g_ch != '\n')
	{
		if (ft_is_part_of_map(g_ch) != 1)
			return (-1);
		map_line[operations] = g_ch;
	}
	map[line] = map_line;
	if (operations != g_width)
		return (-1);
	read(fd, &g_ch, 1);
	if (g_ch != '\n')
		return (-1);
	return (operations);
}

void	ft_skip_bytes(int fd, int bytes_to_scip)
{
	char *temp;

	temp = malloc(sizeof(char) * bytes_to_scip);
	read(fd, temp, bytes_to_scip);
	free(temp);
}

char	**ft_get_map(char *filename)
{
	int		i;
	int		ft_skip_b;
	int		fd;
	char	**map;

	if ((ft_skip_b = ft_count_fl_length(filename)) < 0)
		return (NULL);
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	if (ft_check_parameters(fd, ft_skip_b - 3) <= 0 || close(fd) < 0)
		return (NULL);
	if (!ft_is_valid() || (fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	if (!(map = malloc(sizeof(char*) * g_lines)))
		return (NULL);
	i = -1;
	ft_skip_bytes(fd, ft_skip_b + 1);
	while (++i < g_lines)
		if (ft_copy_line(fd, i, map) <= 0)
			return (NULL);
	if (close(fd) < 0)
		return (NULL);
	return (map);
}
