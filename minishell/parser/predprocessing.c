/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predprocessing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 22:55:09 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/20 00:11:26 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/builtin_funcs.h"
#include "../inc/minishell.h"

void	change_err(char *err)
{
	char	*tmp_str;
	int		i;

	tmp_str = ft_strdup(err);
	i = check_el_in_env(&tmp_str, 1);
	change_el_in_env(tmp_str, i);
	free(tmp_str);
}

void	put_er(t_cmd *cmd)
{
	ft_putstr_fd("trashell0.1: ", cmd->cmdorder->fd[2]);
	ft_putstr_fd(cmd->cmd->command, cmd->cmdorder->fd[2]);
	ft_putendl_fd(":command not found", cmd->cmdorder->fd[2]);
}

void	postprocess(t_cmd *cmd, int temp, int temp1, int temp0)
{
	temp > 2 ? close(temp) : 0;
	dup2(temp1, 1);
	dup2(temp0, 0);
	cmd->cmdorder = cmd->cmdorder->next;
}

void	puterrorf(t_cmd *cmd)
{
	put_er(cmd);
	change_err("?=127");
	cmd->cmdorder = cmd->cmdorder->next;
}

void	predprocess(t_cmd *cmd)
{
	int temparray[2];
	int fd[2];

	temparray[1] = dup(1);
	temparray[0] = dup(0);
	while (cmd->cmdorder)
	{
		pprocess(cmd, fd, &g_pipetemp1, &g_pipetemp0);
		if (!parsebuiltinfunc(cmd))
		{
			if (!*cmd->cmd->command)
			{
				cmd->cmdorder = cmd->cmdorder->next;
				continue ;
			}
			preparetoprocess(cmd);
			if (g_argv == NULL)
			{
				puterrorf(cmd);
				break ;
			}
			startforks(cmd, g_pipetemp1, g_pipetemp0);
		}
		postprocess(cmd, g_pipetemp1, temparray[1], temparray[0]);
	}
}
