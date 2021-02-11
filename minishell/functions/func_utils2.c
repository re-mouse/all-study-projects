/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:34:51 by welease           #+#    #+#             */
/*   Updated: 2020/12/19 22:38:52 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/builtin_funcs.h"
#include "../inc/minishell.h"

int		change_env_inprint(char ***copy)
{
	g_env = free_mass1(&g_env);
	g_env = (*copy);
	*copy = NULL;
	return (0);
}

int		print_just_env(int output)
{
	int	i;

	i = 0;
	while (g_env[i])
	{
		if (ft_strncmp("?=", g_env[i], 2) == 0)
		{
			i++;
			continue;
		}
		ft_putstr_fd(g_env[i++], output);
		ft_putchar_fd('\n', output);
	}
	return (0);
}

void	print_just_exp(int output, int *i, int *j, int *flag)
{
	ft_putstr_fd("declare -x ", output);
	while (g_env[*i][*j])
	{
		ft_putchar_fd(g_env[*i][(*j)++], output);
		if (g_env[*i][(*j) - 1] == '=')
		{
			(*flag)++;
			if ((*flag) == 1)
				ft_putchar_fd('\"', output);
		}
	}
	if ((*flag))
	{
		ft_putchar_fd('\"', output);
		*flag = 0;
	}
	ft_putstr_fd("\n", output);
	(*i)++;
}

int		print_env(int env_size, int sort_or_not, int output)
{
	int		i;
	char	**copy;
	int		j;
	int		flag;

	i = 0;
	flag = 0;
	if (sort_or_not)
	{
		copy = copy_of_env(g_env, 0);
		ft_sort(g_env, env_size + 1);
		while (g_env[i])
		{
			j = 0;
			if (ft_strncmp("?=", g_env[i], 2) == 0)
			{
				i++;
				continue;
			}
			print_just_exp(output, &i, &j, &flag);
		}
		change_env_inprint(&copy);
		return (0);
	}
	return (print_just_env(output));
}
