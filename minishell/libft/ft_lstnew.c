/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:26:05 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/18 16:57:43 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *ret;

	if ((ret = ft_calloc(sizeof(t_list), 1)) == 0)
		return (NULL);
	ret->content = content;
	ret->next = 0;
	return (ret);
}
