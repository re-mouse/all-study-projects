/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 05:06:14 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/19 05:06:15 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b);

void	ft_swap(int *a, int *b)
{
	int temp_a;
	int temp_b;

	temp_a = *a;
	temp_b = *b;
	*a = temp_b;
	*b = temp_a;
}
