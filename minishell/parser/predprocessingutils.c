/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predprocessingutils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 21:19:21 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/19 23:57:38 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include "../inc/builtin_funcs.h"

void	pprocess(t_cmd *cmd, int *fd, int *temp, int *my_tmp)
{
	*temp = 0;
	*my_tmp = 0;
	if (cmd->cmdorder->pipe)
	{
		pipe(fd);
		cmd->cmdorder->fd[1] > 2 ? close(cmd->cmdorder->fd[1]) : 0;
		cmd->cmdorder->fd[1] = fd[1];
		cmd->cmdorder->next->fd[0] > 2 ? close(cmd->cmdorder->next->fd[0]) : 0;
		cmd->cmdorder->next->fd[0] = fd[0];
		*temp = fd[1];
		*my_tmp = fd[0];
	}
	cmd->cmd = cmd->cmdorder->content;
}

int		parsebuiltinfunc(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->cmd->command, "echo", 5))
		ft_echo(cmd->cmd->next, cmd->cmdorder);
	else if (!ft_strncmp(cmd->cmd->command, "cd", 3))
		ft_cd(cmd->cmd->next, cmd->cmdorder);
	else if (!ft_strncmp(cmd->cmd->command, "pwd", 4))
		ft_pwd(cmd->cmdorder);
	else if (!ft_strncmp(cmd->cmd->command, "env", 4))
		ft_env(cmd->cmd->next, cmd->cmdorder);
	else if (!ft_strncmp(cmd->cmd->command, "export", 7))
		export(cmd->cmd->next, cmd->cmdorder);
	else if (!ft_strncmp(cmd->cmd->command, "unset", 6))
		unset(cmd->cmd->next, cmd->cmdorder);
	else if (!ft_strncmp(cmd->cmd->command, "exit", 5))
		ft_exit(cmd->cmd->next, cmd->cmdorder);
	else
		return (0);
	return (1);
}

void	startforks(t_cmd *cmd, int temp, int my_tmp)
{
	pid_t ret;

	dup2(cmd->cmdorder->fd[1], 1);
	dup2(cmd->cmdorder->fd[0], 0);
	g_flag = 1;
	if ((ret = fork()) == -1)
		ft_putstr_fd("fork error\n", cmd->cmdorder->fd[2]);
	else if (ret == 0)
		daughterpostprocess(ret, temp, my_tmp, cmd);
	else
		parentpostprocess(ret, temp);
	g_flag = 0;
}

void	parentpostprocess(int ret, int temp)
{
	char *tmp_str;
	char *tmp_str2;

	temp > 2 ? close(temp) : 0;
	waitpid(ret, &g_status, 0);
	tmp_str = ft_itoa(g_status);
	tmp_str2 = ft_strjoin("?=", tmp_str);
	change_err(tmp_str2);
	free(tmp_str);
	free(tmp_str2);
}

void	daughterpostprocess(int ret, int temp, int my_tmp, t_cmd *cmd)
{
	(void)ret;
	temp > 2 ? close(temp) : 0;
	execve(g_argv[0], g_argv, g_env);
	put_er(cmd);
	my_tmp > 2 ? close(my_tmp) : 0;
	exit(0);
}
