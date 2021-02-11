/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:54:42 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/19 23:52:37 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ftcalloc(size_t count, size_t size)
{
	void			*temp;
	unsigned int	i;

	temp = malloc(count * size);
	if (temp == NULL)
		return (NULL);
	i = -1;
	while (++i < count * size)
		*((unsigned char*)temp + i) = 0;
	return (temp);
}

void	*ftmemmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
		while (--len + 1 > 0)
			*((char*)dst + len) = *((char*)src + len);
	else
		while (++i < len)
			*((char*)dst + i) = *((char*)src + i);
	return (dst);
}

int		move_buff(char *buff, char *findedchar)
{
	int a;
	int b;
	int c;

	if (findedchar == NULL)
	{
		free(buff);
		return (0);
	}
	a = findedchar - buff;
	b = ftstrlen(buff) - a;
	c = BUFFER_SIZE - a - b;
	ftmemmove(buff, buff + a + 1, b);
	ftbzero(buff + b, BUFFER_SIZE - b);
	return (1);
}

int		post_read_process(char **buff, char **l, int r)
{
	char	*temp;
	char	*chrf;

	(void)r;
	if (r <= 0)
	{
		free(*buff);
		*buff = NULL;
		return (r);
	}
	if ((chrf = ftstrchr(*buff, '\n')))
	{
		temp = *l;
		*l = ftstrrjoin(*buff, *l, '\n');
		free(temp);
		move_buff(*buff, chrf);
		return (*l ? 1 : -1 + move_buff(*buff, NULL));
	}
	free(*buff);
	*buff = NULL;
	return (0);
}

/*
** F пирам, пришлось, сори((0(
*/

int		get_next_line(int fd, char **l)
{
	char		*chrf;
	int			r;
	static char	*buff;
	char		*temp;

	if (fd < 0 || !l || (!buff && !(buff = ftcalloc(BUFFER_SIZE + 1, 1))))
		return (-1);
	*l = "\0";
	if ((chrf = ftstrchr(buff, 10)))
	{
		*l = ftstrrjoin(buff, *l, 10);
		move_buff(buff, chrf);
		return (*l ? 1 : -1 + move_buff(buff, NULL));
	}
	else if (!(*l = ftstrrjoin(buff, *l, 10)) & !ftbzero(buff, 128))
		return (-1 + move_buff(buff, NULL));
	while (((r = read(fd, buff, 128)) > 0 || **l) && !ftstrchr(buff, 10))
	{
		ftbzero(buff + r, BUFFER_SIZE - r + 1) ? temp = *l : 0;
		if (!(*l = ftstrrjoin(buff, *l, 10)) & !ftbzero(buff, BUFFER_SIZE))
			return (-1 + move_buff(buff, NULL));
		free(temp);
	}
	return (post_read_process(&buff, l, r));
}
