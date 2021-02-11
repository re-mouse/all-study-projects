/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:33:25 by welease           #+#    #+#             */
/*   Updated: 2020/12/19 17:34:29 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/builtin_funcs.h"
#include "../inc/minishell.h"

char	**add_new_el(int newsize, char *new_el)
{
	int		i;
	char	**new_env;

	i = 0;
	if ((new_env = (char **)malloc((newsize + 1) * sizeof(char *))) == NULL)
		return (NULL);
	while (i < newsize - 1)
	{
		if ((new_env[i] = ft_strdup(g_env[i])) == NULL)
			return (NULL);
		free(g_env[i++]);
	}
	if (new_el)
		new_env[i++] = ft_strdup(new_el);
	new_env[i] = NULL;
	free(g_env);
	return (new_env);
}

void	ft_sort(char **ar, int size)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (i < size - 1)
	{
		j = size - 1;
		while (j > i)
		{
			if (ft_strncmp(ar[j - 1], ar[j], ft_strlen(ar[j - 1])) > 0)
			{
				tmp = ar[j - 1];
				ar[j - 1] = ar[j];
				ar[j] = tmp;
			}
			j--;
		}
		i++;
	}
}

void	change_new_el(char **new_el, int exp_or_env, int *j)
{
	if (exp_or_env)
	{
		while ((*new_el)[*j] != '+' && (*new_el)[*j])
			(*j)++;
		if ((*new_el)[*j] == '+')
			ft_memmove(*new_el + *j, *new_el + *j + 1,
			ft_strlen(*new_el) - *j);
	}
	*j = 0;
	while ((*new_el)[*j] != '=' && (*new_el)[*j])
		(*j)++;
}

int		check_el_in_env(char **new_el, int exp_or_env)
{
	int i;
	int j;
	int k;

	j = 0;
	i = 0;
	change_new_el(new_el, exp_or_env, &j);
	while (g_env[i])
	{
		k = 0;
		while (g_env[i][k] != '=' && g_env[i][k])
			k++;
		if (ft_strncmp(g_env[i], *new_el, j < k ? k : j) == 0)
			return (i);
		i++;
	}
	return (-1);
}
