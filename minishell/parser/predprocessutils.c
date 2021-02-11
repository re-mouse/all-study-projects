/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predprocessutils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:01:10 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/20 00:12:12 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include "../inc/builtin_funcs.h"

void	preparetoprocess(t_cmd *cmd)
{
	g_argv ? free_mass1(&g_argv) : 0;
	g_argv = argv_mass(cmd->cmd);
}
