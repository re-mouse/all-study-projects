/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_user_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:55:40 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/07 20:07:19 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

int		ft_start_input(void)
{
	char	temp_char;
	int		fd;

	if ((fd = open("temp", O_WRONLY, O_CREAT | O_TRUNC)) < 0)
		return (-1);
	while (read(0, &temp_char, 1) > 0)
	{
		write(fd, &temp_char, 1);
	}
	if (close(fd) < 0)
		return (-1);
	return (1);
}

int		ft_corrupt_file(void)
{
	int fd;

	if ((fd = open("temp", O_WRONLY, O_TRUNC)) < 0)
		return (-1);
	write(fd, "abc", 3);
	if (close(fd) < 0)
		return (-1);
	return (1);
}
