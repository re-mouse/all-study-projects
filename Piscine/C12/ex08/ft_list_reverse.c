/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 19:42:01 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/01 19:42:01 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	int		i;
	t_list	*temp;
	t_list	*next;
	t_list	*prev;

	if (begin_list == 0)
		return ;
	i = 0;
	next = 0;
	prev = 0;
	temp = *begin_list;
	while (temp != 0)
	{
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	*begin_list = prev;
}
