/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 19:00:22 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/07 20:07:25 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int		g_biggestsquare_x;
int		g_biggestsquare_y;
int		g_min_square;
int		g_width;
int		g_lines;
char	g_empty;
char	g_obstacle;
char	g_full;
char	g_ch;

/*
**Возвращает карту формата [y,x], принимает название карты
**Автоматически обновляет глобальные переменные с параметрами карты
*/

char	**ft_get_map(char *filename);

/*
**intialize gap, if current symb is not obstacle
*/

int		ft_size_intalize(int size, int oper, int l, char **map);

void	ft_start_analyze(char **map);

int		ft_is_valid(void);

int		ft_count_fl_length(char *filename);

/*
**print map with square x,y, size options
*/

void	ft_map_printer(char **map, int x, int y, int size);

int		ft_start_input(void);

int		ft_corrupt_file(void);

#endif
