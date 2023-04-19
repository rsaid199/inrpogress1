/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaid <rsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:49:25 by rsaid             #+#    #+#             */
/*   Updated: 2023/01/29 20:50:06 by rsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strchr(char *buffer, int c)
{
	int		i;
	int		x;
	int		z;
	char	*storage;

	i = 0;
	z = 0;
	if (!buffer)
		return (NULL);
	x = ft_strlen(buffer);
	while (buffer[i])
	{
		if (buffer[i] == c)
			break ;
		i++;
	}
	if ((x - i) >= 1)
		storage = malloc((x - i) + 1);
	if ((i == x) || ((x - i) < 1))
		return (NULL);
	while (++i < x)
		storage[z++] = buffer[i];
	storage[z] = '\0';
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	t_vars		vars;

	if (BUFFER_SIZE < 1 || fd < 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	vars.buffer = malloc(BUFFER_SIZE + 1);
	vars.read_size = read(fd, vars.buffer, BUFFER_SIZE);
	if (vars.read_size < 0)
		return (free(vars.buffer), NULL);
	vars.buffer[vars.read_size] = '\0';
	while (new_line_checker(vars.buffer) == 0 && vars.read_size > 0)
	{
		storage = ft_strjoin(storage, vars.buffer);
		vars.read_size = read(fd, vars.buffer, BUFFER_SIZE);
		vars.buffer[vars.read_size] = '\0';
	}
	if (vars.read_size == 0)
		vars.line = linemaker(storage, '\0');
	if (storage != NULL)
		vars.buffer = ft_strjoin_with_free(storage, vars.buffer);
	storage = ft_strchr(vars.buffer, '\n');
	if (vars.read_size > 0)
		vars.line = linemaker(vars.buffer, '\n');
	return (free(vars.buffer), vars.line);
}
