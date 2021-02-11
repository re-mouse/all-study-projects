/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:32:51 by welease           #+#    #+#             */
/*   Updated: 2020/12/19 17:32:53 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/builtin_funcs.h"
#include "../inc/minishell.h"

void	free_two_par(char **buf, t_list **order)
{
	free(*order);
	free(*buf);
}

void	put_path(char **tmp, int i)
{
	(*tmp) = g_env[i];
	while (*(*tmp) != '=')
		(*tmp)++;
	(*tmp)++;
}
