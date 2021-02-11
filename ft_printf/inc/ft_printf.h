/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:06:52 by hleilani          #+#    #+#             */
/*   Updated: 2020/11/07 13:55:41 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct	s_param
{
	char		flags;
	size_t		width;
	size_t		precision;
	char		type;
	int			sign;
	int			min;
	void		*variable;
}				t_param;

int				ft_print_final_str(t_param param, char *str);
int				ft_precision_pr(t_param param, char *str);
char			*ft_get_hex(unsigned nb, char base);
int				ft_print_i(t_param param, va_list list);
int				ft_print_s(t_param param, va_list list);
int				ft_print_c(t_param param, va_list list);
int				ft_print_u(t_param param, va_list list);
int				ft_print_xx(t_param param, va_list list);
int				ft_print_x(t_param param, va_list list);
int				ft_print_p(t_param param, va_list list);
char			*ft_pars(char *f, va_list list, int *l);
int				ft_printf(const char *f, ...);
char			*ft_itoa_p(int n, t_param *param);

#endif
