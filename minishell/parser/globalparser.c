/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globalparser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:28:05 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/19 23:42:43 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		*parsesinglequote(t_command *cmdtemp, char *cmdline, t_cmd *cmd)
{
	(void)cmd;
	cmdline++;
	while (*cmdline != '\'' && *cmdline)
		cmdtemp->command = ft_charjoin(*cmdline++, cmdtemp->command);
	*cmdline ? cmdline++ : 0;
	return (cmdline);
}

char		*parsewithoutquote(t_command *c, char *cmdline, t_cmd *cmd, int m)
{
	if (*cmdline == '\\')
	{
		cmdline++;
		cmd->cmdtemp->command = ft_charjoin(*cmdline, cmd->cmdtemp->command);
		cmdline++;
	}
	else if (*cmdline == '$')
		cmdline = findenvvar(c, cmd->env, cmdline);
	else if (*cmdline == ';' && m)
		cmdline = processdot(cmdline, cmd);
	else if (*cmdline == '|' && m)
		cmdline = processpipe(cmdline, cmd);
	else
		cmdline = simpleprocess(cmdline, cmd, m);
	return (cmdline);
}

char		*parsedoublequote(t_command *cmdtemp, char *cmdline, t_cmd *cmd)
{
	cmdline++;
	while (*cmdline != '\"' && *cmdline)
	{
		if (*cmdline == '\\' && !ft_isalnum(cmdline[1]) &&
		!is_space(cmdline[1]) && cmdline[1] != '\'')
		{
			cmdline++;
			cmd->cmdtemp->command =
			ft_charjoin(*cmdline, cmd->cmdtemp->command);
			cmdline++;
		}
		else if (*cmdline != '$')
			cmdtemp->command = ft_charjoin(*cmdline++, cmdtemp->command);
		else
			cmdline = findenvvar(cmdtemp, cmd->env, cmdline);
	}
	*cmdline ? cmdline++ : 0;
	return (cmdline);
}

void		parseline(t_cmd *cmd, char *cmdline)
{
	while (*cmdline)
	{
		if (*skipspace(cmdline) == '\0')
			cmdline = skipspace(cmdline);
		else if (*cmdline == '\'')
			cmdline = parsesinglequote(cmd->cmdtemp, cmdline, cmd);
		else if (*cmdline == '\"')
			cmdline = parsedoublequote(cmd->cmdtemp, cmdline, cmd);
		else
			cmdline = parsewithoutquote(cmd->cmdtemp, cmdline, cmd, 1);
		if (is_space(*cmdline) && !isbannedsymbol(*(cmdline + 1)))
		{
			if (!isredirect((cmdline + 1)))
				cmd->cmdtemp = allocatenewcommand(cmd->cmdtemp);
			cmdline != skipspace(cmdline) ? cmdline = skipspace(cmdline) :
			cmdline++;
		}
		else if (*cmdline && *(cmdline + 1) && is_space(*cmdline) &&
				isbannedsymbol(*(cmdline + 1)))
			cmdline++;
		else if (*cmdline && *(cmdline + 1) && is_space(*cmdline))
			cmdline = skipspace(cmdline) - 1;
	}
}

void		parsecommand(t_cmd *cmd)
{
	char	*cmdline;
	t_list	*tmp;

	g_parseerr = 0;
	cmdline = cmd->line;
	cmd->env = g_env;
	cmd->cmdtemp = cmd->cmd;
	cmdline = skipspace(cmdline);
	parseline(cmd, cmdline);
	cmd->cmdtemp = cmd->cmd;
	free(cmd->line);
	tmp = cmd->cmdorder;
	if (!g_parseerr)
		predprocess(cmd);
	freeorders(tmp);
}
