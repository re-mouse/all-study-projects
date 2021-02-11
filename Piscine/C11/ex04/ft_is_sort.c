/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:38:37 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/30 20:38:38 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int order_f;
	int order_s;

	order_f = 0;
	order_s = 0;
	if (length == 2 || length == 1)
		return (1);
	if (length < 1)
		return (0);
	while (length - 1 > 0)
	{
		if (f(*tab, *(tab + 1)) > 0)
			order_f = 1;
		if (f(*tab, *(tab + 1)) < 0)
			order_s = 1;
		tab++;
		length--;
	}
	if (order_s == 0 || order_f == 0)
		return (1);
	return (0);
}
