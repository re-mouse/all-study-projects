/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:07:55 by welease           #+#    #+#             */
/*   Updated: 2020/12/19 22:23:41 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/builtin_funcs.h"
#include "../inc/minishell.h"

int		print_env_err(t_list *order, t_command *new)
{
	ft_putstr_fd("env: ", order->fd[2]);
	ft_putstr_fd(new->command, order->fd[2]);
	ft_putstr_fd(": No such file or directory\n", order->fd[2]);
	return (1);
}

void	put_to_env(int i, int *env_size, t_command **new)
{
	if ((i = check_el_in_env(&((*new)->command), 0)) > -1)
		change_el_in_env(((*new)->command), i);
	else
	{
		g_env = add_new_el(*env_size + 1, (*new)->command);
		(*env_size)++;
	}
	(*new) = (*new)->next;
}

int		ft_env(t_command *n, t_list *order)
{
	int	env_size;
	int	i;
	int	flag;

	flag = 0;
	env_size = find_count_of_strs(g_env);
	while (n)
	{
		i = 0;
		while (n->command[i] != '=' && n->command[i])
			i++;
		if (!ft_strncmp(n->command, ".", 2) ||
		!ft_strncmp(n->command, "..", 3) || i == (int)ft_strlen(n->command))
		{
			print_env_err(order, n) ? flag = 1 : 0;
			i == (int)ft_strlen(n->command) ? change_err("?=127") : 0;
			n = n->next;
			continue;
		}
		put_to_env(i, &env_size, &n);
	}
	!flag ? change_err("?=0") : 0;
	print_env(find_count_of_strs(g_env), 0, order->fd[1]);
	return (0);
}
