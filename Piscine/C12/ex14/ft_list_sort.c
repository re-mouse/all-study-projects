/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 21:15:50 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/01 21:15:50 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	swap_elem(t_list *p, t_list *n, t_list *c, t_list **b);

int		ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list != 0)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*cur;
	t_list	*prev;
	t_list	*cur_s;
	int		i;

	if (begin_list == 0)
		return ;
	i = ft_list_size(*begin_list);
	while (i - 1 > 0)
	{
		cur = *begin_list;
		cur_s = cur->next;
		prev = 0;
		while (cur && cur_s)
		{
			if ((*cmp)(cur->data, cur_s->data) > 0)
				swap_elem(prev, cur_s->next, cur, begin_list);
			prev = cur;
			cur = cur_s;
			cur_s = cur->next;
		}
		i--;
	}
}

void	swap_elem(t_list *p, t_list *n, t_list *c, t_list **b)
{
	t_list *c1;

	c1 = c->next;
	if (p == 0)
	{
		*b = c1;
		c1->next = c;
		c->next = n;
	}
	else
	{
		p->next = c1;
		c1->next = c;
		c->next = n;
	}
}
