/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 19:41:48 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/01 19:41:49 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	if (nbr < 0)
		return (0);
	while (nbr > 0)
	{
		if (begin_list == 0 || begin_list->next == 0)
			return (0);
		begin_list = begin_list->next;
		nbr--;
	}
	return (begin_list);
}
