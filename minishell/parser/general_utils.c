/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:39:04 by welease           #+#    #+#             */
/*   Updated: 2020/12/19 23:39:05 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		**free_mass1(char ***tab)
{
	unsigned int	i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
	return (NULL);
}

int			find_count_of_strs(char **env)
{
	int		i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char		**copy_of_env(char **env, int flag)
{
	char	**env_copy;
	int		count_of_strs;
	int		i;

	i = 0;
	count_of_strs = find_count_of_strs(env);
	if ((env_copy = (char **)malloc((count_of_strs + 2) * sizeof(char *))) ==
		NULL)
		return (NULL);
	while (env[i])
	{
		if ((env_copy[i] = (char *)malloc(ft_strlen(env[i]) + 1)) == NULL)
			return (free_mass1(&env_copy));
		ft_strlcpy(env_copy[i], env[i], ft_strlen(env[i]) + 1);
		i++;
	}
	if (flag)
		env_copy[i++] = ft_strdup("?=0");
	env_copy[i] = NULL;
	return (env_copy);
}

int			is_abs_path(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == '/')
			return (1);
	}
	return (0);
}

void		free_path_math(char **paths_mass)
{
	int		j;

	j = 0;
	if (paths_mass)
	{
		while ((paths_mass)[j])
		{
			if (paths_mass[j])
				free(paths_mass[j++]);
			else
				j++;
		}
		free(paths_mass);
	}
}
