/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 03:08:09 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/01 03:08:09 by hleilani         ###   ########.fr       */
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
