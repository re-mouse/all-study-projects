/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:39:50 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/04 23:35:35 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*g_temp;
int		g_t_c;
int		g_i;
int		g_zero_c;
int		g_z;
int		g_g;

char	*convert(char *st, int g_zero_c)
{
	int		size;
	int		c;
	char	*num;

	c = 0;
	while (*(st + c))
		c++;
	num = malloc(sizeof(char) * c + 1);
	size = c;
	*(num + c + 1) = 0;
	while (*(st + --c))
		*(num + c) = *(st + c);
	while (g_zero_c > 0)
	{
		*(num + --size) = '0';
		g_zero_c--;
	}
	return (num);
}

/*
**префикс 2 триады = 1000, 4 триады 1000000000
*/

char	*pfix(int triad)
{
	char	*prefix;
	int		c;
	int		j;

	c = (triad - 1) * 3 - 1;
	j = c;
	prefix = malloc(sizeof(char) * c + 1);
	while (j > 0)
	{
		prefix[j] = 0;
		j--;
	}
	while (c - 1 > 0)
	{
		prefix[c - 2] = '0';
		c--;
	}
	prefix[c - 1] = '1';
	return (prefix);
}

void	cycle(char *st, char *fl)
{
	g_i = (ft_get_triad_count(st) - 1) * 3;
	g_zero_c = g_i;
	while (g_i-- > 0 && g_z != 1)
	{
		g_temp = convert(st, g_zero_c - g_i);
		if (cm(g_temp, pfix(g_t_c + 1)) != 0)
			g_z = get_value(fl, g_temp);
	}
}

int		pechat_triad(char *st, char *fl)
{
	write(1, " ", 1);
	g_temp = pfix(g_t_c + 1);
	if (get_value(fl, g_temp) != 1)
		return (-1);
	g_temp = get_triad_by_num(st, 2);
	free(g_temp);
	check_space(st);
	return (1);
}

int		ft_split_by_key(char *st, char *fl)
{
	g_g = 0;
	g_t_c = ft_get_triad_count(st);
	while (*st && g_t_c > 0)
	{
		g_z = 0;
		if (cm(st, "100") && cm(st, pfix(g_t_c + 1)) && get_value(fl, st) == 1)
			break ;
		cycle(st, fl);
		if (g_z == 1)
			st += ft_strlen(st) - g_i;
		else
		{
			g_temp = get_triad_by_num(st, 1);
			if (triad_checker(g_temp, fl) != 1)
				return (-1);
			free(g_temp);
			if (cm(g_temp, "000") && g_t_c - 1 > 0)
				if (pechat_triad(st, fl) != 1)
					return (-1);
			st = get_next_triad(st);
		}
		g_t_c--;
	}
	return (1);
}
