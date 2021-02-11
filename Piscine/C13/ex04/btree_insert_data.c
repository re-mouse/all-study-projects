/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 23:40:20 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/02 23:40:21 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **r, void *i, int (*cmp)(void *, void *))
{
	if (*r == NULL)
	{
		*r = btree_create_node(i);
		return ;
	}
	if (cmp((*r)->item, i) < 0)
		btree_insert_data(&(*r)->left, i, cmp);
	else
		btree_insert_data(&(*r)->right, i, cmp);
}
