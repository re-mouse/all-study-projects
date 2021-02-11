/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 23:42:59 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/02 23:43:00 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	if (root == 0)
		return (0);
	if (btree_level_count(root->left) > btree_level_count(root->right))
		return (btree_level_count(root->left) + 1);
	else
		return (btree_level_count(root->right) + 1);
}
