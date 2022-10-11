/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:50:40 by gade-alm          #+#    #+#             */
/*   Updated: 2022/04/05 12:10:11 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char		buffer[FOPEN_MAX][BUFFER_SIZE];
	int				re;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	line = NULL;
	re = 1;
	while (1)
	{		
		if (!buffer[fd][0])
			re = read(fd, buffer[fd], BUFFER_SIZE);
		if (re > 0)
			line = ft_get_line(buffer[fd], line);
		if (re < 1 || is_newline(buffer[fd]))
			break ;
	}
	return (line);
}
