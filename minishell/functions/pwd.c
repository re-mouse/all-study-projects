/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:27:08 by welease           #+#    #+#             */
/*   Updated: 2020/12/19 17:27:16 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/builtin_funcs.h"
#include "../inc/minishell.h"

int		ft_pwd(t_list *order)
{
	char pwd_str[MAXSTRLEN];

	getcwd(pwd_str, MAXSTRLEN);
	ft_putstr_fd(pwd_str, order->fd[1]);
	write(order->fd[1], "\n", 1);
	change_err("?=0");
	return (0);
}
