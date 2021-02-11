/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_c_pr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:06:21 by hleilani          #+#    #+#             */
/*   Updated: 2020/11/07 11:25:15 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_hex_pointer(void *p)
{
	int				mod;
	char			*ret;
	int				digits;
	uintmax_t		temp;

	digits = 0;
	temp = (uintmax_t)p;
	while (temp > 0 && digits++ >= 0)
		temp /= 16;
	digits = digits > 0 ? digits : 1;
	if ((ret = malloc(digits + 1)) == NULL)
		return (NULL);
	ret[digits--] = 0;
	temp = (uintmax_t)p;
	digits = digits < 0 ? 0 : digits;
	while (digits >= 0)
	{
		mod = temp % 16;
		if (mod >= 10)
			ret[digits--] = mod + 'a' - 10;
		else
			ret[digits--] = mod + '0';
		temp /= 16;
	}
	return (ret);
}

int		ft_print_p(t_param param, va_list list)
{
	void	*p;
	char	*p_str;

	p = va_arg(list, void*);
	if (param.precision != 0)
		p_str = ft_get_hex_pointer(p);
	else
		p_str = ft_calloc(1, 1);
	return (ft_precision_pr(param, p_str));
}

int		ft_print_c(t_param param, va_list list)
{
	unsigned char	print_c;
	char			*str;

	if (param.type == 'c')
		print_c = (unsigned char)va_arg(list, int);
	else
		print_c = param.type;
	str = ft_calloc(2, 1);
	str[0] = print_c;
	return (ft_precision_pr(param, str));
}
