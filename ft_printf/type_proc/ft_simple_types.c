/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:02:46 by hleilani          #+#    #+#             */
/*   Updated: 2020/11/07 16:33:41 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_i(t_param param, va_list list)
{
	int		nb;
	char	*nb_str;

	nb = va_arg(list, int);
	if (param.precision != 0 || nb != 0)
		nb_str = ft_itoa_p(nb, &param);
	else
		nb_str = ft_calloc(1, 1);
	return (ft_precision_pr(param, nb_str));
}

int	ft_print_s(t_param param, va_list list)
{
	char *str;

	str = va_arg(list, char*);
	if (str == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	return (ft_precision_pr(param, str));
}

int	ft_print_u(t_param param, va_list list)
{
	unsigned int	nb;
	char			*nb_str;

	nb = va_arg(list, unsigned int);
	if (param.precision != 0 || nb != 0)
		nb_str = ft_itoa_u(nb);
	else
		nb_str = ft_calloc(1, 1);
	return (ft_precision_pr(param, nb_str));
}

int	ft_print_x(t_param param, va_list list)
{
	unsigned int	nb;
	char			*nb_str;

	nb = va_arg(list, unsigned int);
	if (param.precision != 0 || nb != 0)
		nb_str = ft_get_hex(nb, 'A');
	else
		nb_str = ft_calloc(1, 1);
	return (ft_precision_pr(param, nb_str));
}

int	ft_print_xx(t_param param, va_list list)
{
	unsigned int	nb;
	char			*nb_str;

	nb = va_arg(list, unsigned int);
	if (param.precision != 0 || nb != 0)
		nb_str = ft_get_hex(nb, 'a');
	else
		nb_str = ft_calloc(1, 1);
	return (ft_precision_pr(param, nb_str));
}
