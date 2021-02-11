/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:06:50 by hleilani          #+#    #+#             */
/*   Updated: 2020/11/07 11:58:01 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *f, ...)
{
	va_list list;
	int		len;

	len = 0;
	va_start(list, f);
	while (*f)
	{
		if (*f == '%')
			f = ft_pars((char*)f, list, &len);
		else
		{
			write(1, f, 1);
			len++;
			f++;
		}
	}
	return (len);
}
