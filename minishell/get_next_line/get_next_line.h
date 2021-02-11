/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:19:31 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/19 23:51:59 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 256

# include <stdlib.h>
# include <unistd.h>

size_t	ftstrlen(const char *s);
char	*ftstrrjoin(char const *s1, char const *s2, char c);
int		get_next_line(int fd, char **line);
char	*ftstrchr(const char *s, int c);
int		ftbzero(void *s, size_t n);

#endif
