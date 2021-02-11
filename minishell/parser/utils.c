/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 12:23:01 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/19 23:42:43 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/minishell.h"

int		is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 11));
}

void	freecommand(t_command *command)
{
	free(command->command);
	free(command);
}

void	freeorders(t_list *ord)
{
	t_command	*tmp;
	t_list		*list;
	t_command	*cmd;

	while (ord)
	{
		cmd = ord->content;
		while (cmd)
		{
			tmp = cmd;
			cmd = cmd->next;
			freecommand(tmp);
		}
		list = ord;
		ord = ord->next;
		free(list);
	}
}

t_list	*getlastorder(t_cmd *cmd)
{
	t_list *updatingorder;

	updatingorder = cmd->cmdorder;
	while (updatingorder->next)
		updatingorder = updatingorder->next;
	return (updatingorder);
}

void	updatefd(t_cmd *cmd, int index, int newfd)
{
	t_list *updatingorder;

	updatingorder = cmd->cmdorder;
	while (updatingorder->next)
		updatingorder = updatingorder->next;
	if (updatingorder->fd[index] > 2)
		close(updatingorder->fd[index]);
	updatingorder->fd[index] = newfd;
}
