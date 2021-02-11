/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:30:37 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/19 23:42:43 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_command	*newcommandorder(t_cmd *cmd, int pipe)
{
	t_list		*lastcommand;
	t_command	*newcommand;
	t_list		*neworder;

	lastcommand = cmd->cmdorder;
	while (lastcommand->next)
		lastcommand = lastcommand->next;
	lastcommand->pipe = pipe;
	neworder = ft_lstnew(ft_calloc(sizeof(t_command), 1));
	newcommand = neworder->content;
	neworder->fd[0] = 0;
	neworder->fd[1] = 1;
	neworder->fd[2] = 2;
	neworder->pipe = 0;
	newcommand->command = ft_calloc(1, 1);
	newcommand->next = NULL;
	lastcommand->next = neworder;
	return (newcommand);
}

char		*skipspace(char *line)
{
	while (is_space(*line))
		line++;
	return (line);
}

t_command	*allocatenewcommand(t_command *old)
{
	old->next = ft_calloc(sizeof(t_command), 1);
	old->next->next = NULL;
	old = old->next;
	old->command = ft_calloc(1, 1);
	return (old);
}

int			isbannedsymbol(char c)
{
	return (c == '|' || c == ';' || c == 0 || is_space(c));
}
