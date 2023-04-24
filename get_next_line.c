/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaid <rsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:49:25 by rsaid             #+#    #+#             */
/*   Updated: 2023/04/24 19:54:03 by rsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	int		rd;
	char	character;
	char	*buffer;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	rd = 0;
	buffer = malloc(MAX);
	rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1);
	while (rd > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
		rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1);
	}
	buffer[i] = '\0';
	if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
		return (free(buffer), NULL);
	return (buffer);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		s2i;
	char	*z;

	i = 0;
	s2i = 0;
	z = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!z)
		return (NULL);
	if (s1)
	{
		while (s1[i] != '\0')
		{
			z[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (s2[s2i] != '\0')
			z[i++] = s2[s2i++];
		free(s2);
	}
	z[i] = '\0';
	return (z);
}

char	*ft_strjoin_with_free(char *s1, char *s2)
{
	int		i;
	int		s2i;
	char	*z;

	i = 0;
	s2i = 0;
	z = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!z)
		return (NULL);
	if (s1)
	{
		while (s1[i] != '\0')
		{
			z[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (s2[s2i] != '\0')
			z[i++] = s2[s2i++];
	}
	z[i] = '\0';
	return (free(s1), free(s2), z);
}
