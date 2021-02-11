/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 12:22:56 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/20 00:48:35 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		*processdot(char *cmdline, t_cmd *cmd)
{
	if (((isbannedsymbol(*skipspace(cmdline + 1)) || !*cmd->cmd->command)
	&& !*cmd->cmdtemp->command) || *(cmdline + 1) == ';')
	{
		if (*(cmdline + 1) != ';')
			ft_putendl_fd("syntax error near unexpected token ';'", 1);
		else
			ft_putendl_fd("syntax error near unexpected token ';;'", 1);
		change_err("?=258");
		g_parseerr = 1;
		cmdline += ft_strlen(cmdline);
		return (cmdline);
	}
	else
	{
		cmd->cmdtemp = newcommandorder(cmd, 0);
		cmdline = skipspace(++cmdline);
	}
	return (cmdline);
}

char		*processpipe(char *cmdline, t_cmd *cmd)
{
	if (isbannedsymbol(*skipspace(cmdline + 1)) || !*cmd->cmd->command ||
		*(cmdline + 1) == '|')
	{
		g_parseerr = 1;
		if (*(cmdline + 1) != '|')
			ft_putendl_fd("syntax error near unexpected token '|'", 1);
		else
			ft_putendl_fd("syntax error near unexpected token '||'", 1);
		cmdline += ft_strlen(cmdline);
		return (cmdline);
	}
	else
	{
		cmd->cmdtemp = newcommandorder(cmd, 1);
		cmdline = skipspace(++cmdline);
	}
	return (cmdline);
}

char		*simpleprocess(char *cmdline, t_cmd *cmd, int m)
{
	char *temp;

	temp = cmdline;
	if (m)
		cmdline = checkredirect(cmdline, cmd);
	if (!isbannedsymbol(*cmdline) && !isredirect(cmdline) &&
		temp == cmdline)
	{
		cmd->cmdtemp->command =
				ft_charjoin(*cmdline, cmd->cmdtemp->command);
		cmdline++;
	}
	return (cmdline);
}
