/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:53:22 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/21 12:53:23 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

void	ft_putnbr(int nb)
{
	int				index;
	unsigned int	numb;
	char			num[100];

	index = 0;
	numb = (unsigned)nb;
	if (nb < 0)
		write(1, "-", 1);
	while (numb > 0)
	{
		num[index] = '0' + numb % 10;
		numb /= 10;
		index++;
	}
	while (index-- > 0)
		write(1, &num[index], 1);
}
