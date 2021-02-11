/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 14:31:53 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/23 14:31:54 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb);

int	ft_sqrt(int nb)
{
	int temp;

	if (nb <= 0)
		return (0);
	temp = 0;
	while (temp * temp < nb)
	{
		temp++;
	}
	if ((temp * temp) % nb != 0)
		return (0);
	return (temp);
}
