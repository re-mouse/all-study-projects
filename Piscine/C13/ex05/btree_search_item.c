/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 23:40:01 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/02 23:40:02 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *r, void *d, int (*c)(void *, void *))
{
	if (r == NULL)
		return (NULL);
	if (btree_search_item(r->left, d, c) != NULL)
		return (d);
	if (c(r->item, d) == 0)
		return (d);
	if (btree_search_item(r->right, d, c) != NULL)
		return (d);
	return (NULL);
}
