/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 03:48:54 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/01 03:48:54 by hleilani         ###   ########.fr       */
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

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *temp;

	if (begin_list == 0)
		return ;
	temp = *begin_list;
	*begin_list = ft_create_elem(data);
	if (*begin_list != NULL)
		(*begin_list)->next = temp;
	else
		return ;
}
