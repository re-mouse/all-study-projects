/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:15:42 by welease           #+#    #+#             */
/*   Updated: 2020/12/19 22:23:40 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/builtin_funcs.h"
#include "../inc/minishell.h"

int		change_el_in_env(char *change_el, int ind)
{
	free(g_env[ind]);
	g_env[ind] = ft_strdup(change_el);
	return (0);
}

int		is_full_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			i++;
		else
			break ;
	}
	if (i == (int)ft_strlen(str))
		return (1);
	return (0);
}

int		check_str_for_export(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i++]) || is_full_equal(str))
		return (-1);
	while (str[i] != '=' && str[i])
	{
		if (ft_isalnum(str[i]) || str[i] == '_' || str[i] == '=')
			i++;
		else
			break ;
	}
	if (str[i - 1] == '+')
		return (1);
	if (str[i] == '=' || i == (int)ft_strlen(str))
		return (1);
	return (-1);
}

int		exp_new(int *i, t_command **new, int *env_size)
{
	if ((*i = check_el_in_env(&((*new)->command), 1)) > -1)
	{
		if (find_char_in_str((*new)->command, '=') == -1)
		{
			(*new) = (*new)->next;
			return (1);
		}
		change_el_in_env((*new)->command, *i);
	}
	else
	{
		g_env = add_new_el(*env_size + 1, (*new)->command);
		(*env_size)++;
	}
	(*new) = (*new)->next;
	return (0);
}

int		export(t_command *new, t_list *order)
{
	int	env_size;
	int	i;
	int	flag;

	flag = 0;
	env_size = find_count_of_strs(g_env);
	if (!new || !(new->command))
		return (print_env(env_size, 1, order->fd[1]));
	while (new)
	{
		if (check_str_for_export(new->command) == -1)
		{
			ft_putstr_fd("trashell0.1: export: `", order->fd[2]);
			ft_putstr_fd(new->command, order->fd[2]);
			ft_putstr_fd("': not a valid identifier\n", order->fd[2]);
			change_err("?=1");
			flag = 1;
			new = new->next;
			continue;
		}
		exp_new(&i, &new, &env_size);
	}
	!flag ? change_err("?=0") : 0;
	return (0);
}
