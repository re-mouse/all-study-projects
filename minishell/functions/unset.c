/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:30:59 by welease           #+#    #+#             */
/*   Updated: 2020/12/20 00:36:20 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/builtin_funcs.h"
#include "../inc/minishell.h"

int		delete_el(int newsize, char **del_el)
{
	int	i;

	i = check_el_in_env(del_el, 0);
	free(g_env[i]);
	g_env[i] = NULL;
	while (i + 1 < newsize)
	{
		g_env[i] = g_env[i + 1];
		i++;
	}
	return (0);
}

void	unset_with_err(int *flag, t_command **del, t_list *order)
{
	ft_putstr_fd("trashell0.1: unset: `", order->fd[2]);
	ft_putstr_fd((*del)->command, order->fd[2]);
	ft_putstr_fd("': not a valid identifier\n", order->fd[2]);
	change_err("?=1");
	(*del) = (*del)->next;
	*flag = 1;
}

int		unset(t_command *del, t_list *order)
{
	int	env_size;
	int	flag;
	int	i;

	flag = 0;
	if (!del || !del->command)
		return (0);
	env_size = find_count_of_strs(g_env);
	while (del)
	{
		if (check_str_for_export(del->command) == -1)
		{
			unset_with_err(&flag, &del, order);
			continue;
		}
		if ((i = check_el_in_env(&del->command, 0)) == -1)
			return (0);
		else if (delete_el(env_size-- + 1, &del->command) < 0)
			return (-1);
		del = del->next;
	}
	!flag ? change_err("?=0") : 0;
	return (0);
}
