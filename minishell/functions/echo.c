/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 15:53:17 by welease           #+#    #+#             */
/*   Updated: 2020/12/19 15:55:18 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/builtin_funcs.h"
#include "../inc/minishell.h"

int		is_nnn(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 'n')
		i++;
	if (str[i + 1] == '\0' && i > 0)
		return (1);
	return (0);
}

int		ft_echo(t_command *list, t_list *order)
{
	int	i;
	int	endl;

	endl = 1;
	i = 0;
	while (list)
	{
		if (list->command[0] == '-' && is_nnn(list->command + 1) && i == 0)
		{
			i++;
			endl = 0;
			list = list->next;
			continue;
		}
		ft_putstr_fd(list->command, order->fd[1]);
		if (list->next)
			write(order->fd[1], " ", 1);
		else if (endl)
			write(order->fd[1], "\n", 1);
		list = list->next;
		i++;
	}
	!i ? write(order->fd[1], "\n", 1) : 0;
	change_err("?=0");
	return (0);
}
