/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaid <rsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:05:31 by rsaid             #+#    #+#             */
/*   Updated: 2023/01/28 15:55:12 by rsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	new_line_checker(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (1);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*linemaker(char *buffer, int c)
{
	int		i;
	int		x;
	char	*line;

	i = 0;
	x = 0;
	c = 0 + 1;
	if (!buffer || (buffer[i] == '\0'))
		return (NULL);
	while (buffer[i] != '\n')
	{
		if (buffer[i] == '\0')
			break ;
		i++;
	}
	i++;
	line = malloc(i + 1);
	while (x < i)
	{
		line[x] = buffer[x];
		x++;
	}
	line[x] = '\0';
	return (line);
}
