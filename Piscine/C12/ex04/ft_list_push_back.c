/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 03:49:10 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/01 03:49:11 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *ret;

	if ((ret = malloc(sizeof(t_list))) == 0)
		return (NULL);
	ret->data = data;
	ret->next = 0;
	return (ret);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *a;

	if (begin_list == 0)
		return ;
	if (*begin_list != 0)
		a = *begin_list;
	else
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	while (a->next != 0)
		a = a->next;
	a->next = ft_create_elem(data);
}
