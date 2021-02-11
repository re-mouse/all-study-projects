/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirectparse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:29:20 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/19 23:42:43 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			isredirect(char *line)
{
	return (*line == '>' || *line == '<');
}

char		*preredirect(char *cmdline, t_cmd *cmd, int *appendflag)
{
	if (*cmdline == '>' && *(cmdline + 1) == '>')
	{
		cmdline += 2;
		*appendflag = 1;
	}
	else
		cmdline++;
	while (is_space(*cmdline) && *cmdline)
		cmdline++;
	cmd->cmdtemp = ft_calloc(sizeof(t_command), 1);
	cmd->cmdtemp->next = NULL;
	while (!is_space(*cmdline) && *cmdline && !isbannedsymbol(*cmdline)
	&& !isredirect(cmdline))
	{
		if (*cmdline == '\'')
			cmdline = parsesinglequote(cmd->cmdtemp, cmdline, cmd);
		else if (*cmdline == '\"')
			cmdline = parsedoublequote(cmd->cmdtemp, cmdline, cmd);
		else
			cmdline = parsewithoutquote(cmd->cmdtemp, cmdline, cmd, 0);
	}
	return (cmdline);
}

char		*getredirect(char *cmdline, t_cmd *cmd, int fd)
{
	int			newfd;
	int			appendflag;
	t_list		*tmp;
	t_command	*tmpcmd;

	appendflag = 0;
	if (!isredirect(cmdline))
		return (cmdline);
	*cmdline == '<' ? fd = 0 : 0;
	tmpcmd = cmd->cmdtemp;
	tmp = getlastorder(cmd);
	cmdline = preredirect(cmdline, cmd, &appendflag);
	if (!appendflag)
		newfd = open(cmd->cmdtemp->command, O_RDWR | O_CREAT, 0777);
	else
		newfd = open(cmd->cmdtemp->command, O_RDWR | O_APPEND | O_CREAT, 0777);
	tmp->fd[fd] != fd ? close(tmp->fd[fd]) : 0;
	tmp->fd[fd] = newfd;
	free(cmd->cmdtemp);
	free(cmd->cmdtemp->command);
	cmd->cmdtemp = tmpcmd;
	cmd->cmdtemp->next = NULL;
	if (cmd->cmdorder->content == cmd->cmdtemp && !*(cmd->cmdtemp->command))
		cmdline = skipspace(cmdline);
	return (cmdline);
}

char		*checkredirect(char *cmdline, t_cmd *cmd)
{
	if ((*cmdline == '0' || *cmdline == '2' || *cmdline == '1') &&
	isredirect(cmdline + 1))
		cmdline = getredirect(cmdline + 1, cmd, *cmdline - '0');
	else
		cmdline = getredirect(cmdline, cmd, 1);
	return (cmdline);
}
