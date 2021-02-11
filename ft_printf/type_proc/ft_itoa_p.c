/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:58:23 by hleilani          #+#    #+#             */
/*   Updated: 2020/11/07 13:55:29 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_p(int n, t_param *param)
{
	char		*ret;
	int			d;
	unsigned	temp;

	d = 0;
	param->sign = n < 0 ? 1 : 0;
	temp = n < 0 ? -n : n;
	while (temp > 0 && d++ >= 0)
		temp /= 10;
	d = d > 0 ? d : 1;
	if ((ret = malloc(d + 1)) == NULL)
		return (NULL);
	ret[d--] = 0;
	d = d < 0 ? 0 : d;
	temp = n < 0 ? -n : n;
	while (d >= 0)
	{
		ret[d--] = temp % 10 + '0';
		temp /= 10;
	}
	return (ret);
}

char	*ft_get_hex(unsigned nb, char base)
{
	int				mod;
	char			*ret;
	int				digits;
	unsigned int	temp;

	digits = 0;
	temp = nb;
	while (temp > 0 && digits++ >= 0)
		temp /= 16;
	digits = digits > 0 ? digits : 1;
	if ((ret = malloc(digits + 1)) == NULL)
		return (NULL);
	ret[digits--] = 0;
	temp = nb;
	digits = digits < 0 ? 0 : digits;
	while (digits >= 0)
	{
		mod = temp % 16;
		if (mod >= 10)
			ret[digits--] = mod + base - 10;
		else
			ret[digits--] = mod + '0';
		temp /= 16;
	}
	return (ret);
}
