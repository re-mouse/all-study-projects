/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_programm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:52:51 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/28 15:52:52 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		readfile(int fd);

int		main(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0 || readfile(fd) != 0)
	{
		write(2, "Cannot read file.\n", 18);
		return (1);
	}
}

int		readfile(int fd)
{
	ssize_t text;
	int		n;
	char	printc;

	while ((text = read(fd, &printc, 1)) > 0)
	{
		write(1, &printc, 1);
	}
	n = close(fd);
	if (n == -1 || text == -1)
		return (1);
	return (0);
}
