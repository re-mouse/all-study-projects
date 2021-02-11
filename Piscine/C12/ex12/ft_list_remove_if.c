/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 19:42:34 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/01 19:42:47 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_relink(t_list *n, t_list *p, t_list **b)
{
	if (p == 0)
		*b = n;
	else
		p->next = n;
}

void	ft_list_remove_if(t_list **b, void *d, int (*c)(), void (*f)(void *))
{
	t_list *temp;
	t_list *prev;
	t_list *next;

	if (b == 0)
		return ;
	temp = *b;
	next = 0;
	prev = 0;
	while (temp != 0)
	{
		next = temp->next;
		if ((*c)(temp->data, d) == 0)
		{
			ft_relink(next, prev, b);
			(*f)(temp->data);
			free(temp);
		}
		prev = temp;
		temp = next;
	}
}
