/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 03:49:24 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/01 03:49:25 by hleilani         ###   ########.fr       */
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

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*ret;
	t_list	*temp;
	int		i;

	i = 0;
	if (size < 1)
		return (NULL);
	if ((ret = ft_create_elem(strs[i])) == 0)
		return (NULL);
	i++;
	while (i < size)
	{
		temp = ret;
		if ((ret = ft_create_elem(strs[i])) == 0)
			return (NULL);
		ret->next = temp;
		i++;
	}
	return (ret);
}
