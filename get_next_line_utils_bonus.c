/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:50:57 by gade-alm          #+#    #+#             */
/*   Updated: 2022/04/05 12:00:37 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

int	is_newline(char *str)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	ret = 0;
	j = 0;
	while (str[i])
	{
		if (ret)
			str[j++] = str[i];
		if (str[i] == '\n')
			ret = 1;
		str[i] = 0;
		i++;
	}
	return (ret);
}

char	*ft_get_line(char *buff, char *line)
{
	int		i;
	int		j;
	int		buff_size;
	char	*temp;

	buff_size = ft_strlen(buff);
	temp = malloc(sizeof(char) * (buff_size + ft_strlen(line) + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (line && line[i])
	{
		temp[i] = line[i];
		i++;
	}
	j = 0;
	while (j < buff_size)
		temp[i++] = buff[j++];
	temp[i] = '\0';
	if (line)
		free (line);
	return (temp);
}
