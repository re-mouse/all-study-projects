/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 19:41:41 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/01 19:41:42 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *temp;

	while (begin_list != 0)
	{
		temp = begin_list;
		begin_list = begin_list->next;
		free_fct(temp->data);
		temp->next = 0;
		free(temp);
	}
}
