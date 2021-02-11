/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triad_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:17:00 by mlorette          #+#    #+#             */
/*   Updated: 2020/10/04 21:44:56 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		g_error_out;
int		g_i;
int		g_p;
int		g_s;
char	*g_c;
char	*g_n;
char	*g_sym;
char	*g_t;

/*
**печатает полностью триаду, ищет до совпадений
*/

void	second_cycle(char *file)
{
	while (*(g_c + g_i))
	{
		*(g_n + g_i) = *(g_c + g_i);
		g_i++;
	}
	*(g_n + g_i) = 0;
	while (g_i - 1 > 0)
	{
		g_n[g_i - 1] = '0';
		if (((g_i - 2 > 0 || g_n[0] != '1') && cm(g_n, "100") && cm(g_n, "0")))
			g_s = get_value(file, g_n);
		if (g_s == 1)
			write(1, " ", 1);
		g_i--;
	}
}

int		cycle_first(char *str, char *file)
{
	while (g_p >= 0)
	{
		g_i = 0;
		if (cm(g_c, "100") && cm(g_c, "0") && get_value(file, g_c) == 1)
			break ;
		second_cycle(file);
		if (g_s != 1 && g_p != 0 && g_n[0] != '0')
		{
			g_sym[0] = g_n[0];
			if (get_value(file, g_sym) != 1)
				return (-1);
			write(1, " ", 1);
			g_n[g_i - 1] = '1';
			if (get_value(file, g_n) != 1)
				return (-1);
			if (cm(str, "100"))
				write(1, " ", 1);
		}
		g_c++;
		g_p--;
	}
	return (1);
}

int		triad_checker(char *str, char *file)
{
	g_error_out = 1;
	g_i = 0;
	while (*(str + g_i))
		g_i++;
	g_sym = malloc(sizeof(char) * 2);
	g_sym[1] = 0;
	g_n = malloc(sizeof(char) * g_i);
	g_c = malloc(sizeof(char) * g_i);
	g_t = g_c;
	g_p = g_i - 1;
	g_i = 0;
	g_s = 0;
	while (*(str + g_i))
	{
		*(g_c + g_i) = *(str + g_i);
		g_i++;
	}
	g_error_out = cycle_first(str, file);
	free(g_n);
	free(g_t);
	free(g_sym);
	return (g_error_out);
}
