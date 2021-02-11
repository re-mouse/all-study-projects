/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_mass_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:23:07 by welease           #+#    #+#             */
/*   Updated: 2020/12/19 23:48:10 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"
#include "inc/builtin_funcs.h"

void		free_in_get_path_mass(char ***mass, char **tmp, char ***ret)
{
	int		i;

	i = 0;
	if (*mass)
	{
		while ((*mass)[i])
		{
			(*ret)[i] = ft_strjoin((*mass)[i], *tmp);
			free((*mass)[i]);
			i++;
		}
		free(*mass);
	}
	free(*tmp);
	(*ret)[i] = NULL;
}

char		**get_path_mass(char *com)
{
	int		i;
	char	**mass;
	char	*tmp;
	char	*t;
	char	**ret;

	i = 0;
	tmp = ft_strjoin("/", com);
	while (g_env[i])
		if ((t = ft_strnstr(g_env[i++], "PATH=", 5)) != NULL)
			break ;
	if (i == find_count_of_strs(g_env) || !t)
	{
		free(tmp);
		return (NULL);
	}
	while (*t != '=')
		t++;
	mass = ft_split(++t, ':');
	i = 0;
	while (mass[i])
		i++;
	ret = (char **)malloc((i + 1) * sizeof(char *));
	free_in_get_path_mass(&mass, &tmp, &ret);
	return (ret);
}

char		*get_path_to_exec(char *str, char **path_mass)
{
	int			i;
	struct stat buf;

	if (is_abs_path(str))
		return (ft_strdup(str));
	i = 0;
	if (path_mass)
		while (path_mass[i])
		{
			if (lstat(path_mass[i], &buf) < 0)
				i++;
			else if (buf.st_mode & X_OK)
				return (ft_strdup(path_mass[i]));
		}
	return (NULL);
}

char		**free_all_in_argv_mass(char ***paths_mass, char **copy,
														char ***ret)
{
	int i;

	i = 1;
	free_path_math(*paths_mass);
	free(*copy);
	if (*ret)
	{
		while ((*ret)[i])
		{
			if ((*ret)[i])
				free((*ret)[i++]);
		}
	}
	free(*ret);
	return (NULL);
}

char		**pm_getting(t_command *el, t_command **tmp, char **copy, int *i)
{
	*tmp = el;
	*copy = ft_strdup(el->command);
	while (*tmp)
	{
		*tmp = (*tmp)->next;
		(*i)++;
	}
	return (get_path_mass(*copy));
}
