/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 19:44:10 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/01 19:44:11 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	if (begin_list1 == 0 || begin_list2 == 0)
		return ;
	if (*begin_list1 == 0)
		*begin_list1 = begin_list2;
	while (*begin_list1 != 0)
		*begin_list1 = (*begin_list1)->next;
	(*begin_list1)->next = begin_list2;
}
