/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 13:29:29 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/23 13:29:30 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power);

int	ft_iterative_power(int nb, int power)
{
	int to_return;

	to_return = 1;
	if (power < 0)
		return (0);
	while (power-- > 0)
		to_return *= nb;
	return (to_return);
}
