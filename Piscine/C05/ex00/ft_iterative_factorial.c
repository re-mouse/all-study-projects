/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 13:28:50 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/23 13:28:51 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb);

int	ft_iterative_factorial(int nb)
{
	int return_nb;

	return_nb = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		return_nb *= nb;
		nb--;
	}
	return (return_nb);
}
