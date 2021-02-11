/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:30:10 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/19 23:42:43 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void		findinenv(char *var, t_command *cmd, char **env)
{
	char *line;

	while (*env != NULL)
	{
		if (ft_strlen(*env) >= ft_strlen(var) && !ft_strncmp(*env, var,
		ft_strlen(var)) && (*(*env + ft_strlen(var)) == '=' ||
		*(*env + ft_strlen(var)) == 0))
			break ;
		env++;
	}
	if (ft_strlen(var) > 0 && *env != NULL &&
	!ft_strncmp(*env, var, ft_strlen(var)))
	{
		line = *env;
		while (*line != '=' && *line)
			line++;
		*line ? line++ : 0;
		while (*line)
		{
			cmd->command = ft_charjoin(*line, cmd->command);
			line++;
		}
	}
}

char		*findenvvar(t_command *cmd, char **env, char *cmdline)
{
	char	*var;

	var = ft_calloc(1, 1);
	cmdline++;
	if (ft_isdigit(*cmdline))
	{
		cmdline++;
		return (cmdline);
	}
	while (*cmdline != '\"' && *cmdline != '\'' && *cmdline &&
	!is_space(*cmdline) && *cmdline != '$' && *cmdline != '>' &&
	*cmdline != ';' && *cmdline != '|' && *cmdline != '\\')
	{
		var = ft_charjoin(*cmdline, var);
		cmdline++;
	}
	findinenv(var, cmd, env);
	free(var);
	return (cmdline);
}
