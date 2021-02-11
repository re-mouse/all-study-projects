/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:30:27 by welease           #+#    #+#             */
/*   Updated: 2020/12/19 16:31:35 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include "../inc/builtin_funcs.h"

int		numeric_exit(char *str, int sign, int output)
{
	ft_putendl_fd("exit", output);
	ft_putstr_fd("exit: ", output);
	ft_putstr_fd(str, output);
	if (sign == -1)
		ft_putchar_fd('-', output);
	ft_putstr_fd(": numeric argument required\n", output);
	exit(255);
}

void	exit2(t_command *tmp, t_list *order, int i, int sign)
{
	unsigned long long	code;

	if ((int)ft_strlen(tmp->command) == i)
	{
		if (i <= 20)
			code = ft_atol(tmp->command);
		if (i > 19 || (code > 9223372036854775807 && sign == 1) ||
		(code + 1 > 9223372036854775807 && sign == -1))
			numeric_exit(tmp->command, sign, order->fd[2]);
		else
		{
			errno = (unsigned char)(ft_atol(tmp->command) * sign);
			ft_putendl_fd("exit", order->fd[2]);
			exit(errno);
		}
	}
	else
		numeric_exit(tmp->command, sign, order->fd[2]);
}

void	exit1(t_command *tmp, t_list *order, int i, int count_of_num_str)
{
	int	sign;

	sign = 1;
	if (i == count_of_num_str && i > 1)
	{
		errno = 1;
		ft_putendl_fd("exit", order->fd[2]);
		ft_putendl_fd("exit: too many arguments", order->fd[2]);
		return ;
	}
	else if (i > count_of_num_str && i > 1)
		numeric_exit(tmp->command, sign, order->fd[2]);
	if (tmp->command[0] == '+' || tmp->command[0] == '-')
	{
		sign = -1;
		ft_memmove(tmp->command, tmp->command + 1, ft_strlen(tmp->command));
	}
	while (ft_isdigit(tmp->command[i]))
		i++;
	exit2(tmp, order, i, sign);
}

int		ft_exit(t_command *tmp, t_list *order)
{
	int			count_of_num_str;
	t_command	*copy;
	int			i;

	i = 0;
	count_of_num_str = 0;
	copy = tmp;
	if (!tmp)
	{
		errno = 0;
		ft_putendl_fd("exit", order->fd[2]);
		exit(0);
	}
	while (copy)
	{
		if (is_str_num(copy->command))
			count_of_num_str++;
		copy = copy->next;
		i++;
	}
	exit1(tmp, order, i, count_of_num_str);
	return (0);
}
