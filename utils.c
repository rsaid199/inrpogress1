/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaid <rsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 01:14:52 by rsaid             #+#    #+#             */
/*   Updated: 2023/04/21 20:15:32 by rsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int epc01_checker(char *str)
{
	int i;
	int flags;
	int w_flag;
	int sp_flag;
	int p_flag;
	int c_flag;
	int e_flag;
	int inv_flag;

	c_flag, w_flag, sp_flag, p_flag, e_flag, inv_flag, i = 0;
	if(!str)
		return (0);
	while(str[i])
	{
		if(str[i] == '1')
			w_flag = 1;
		i++;
	}
	i = 0;
	while(str[i])
	{
		if(str[i] == '0')
			sp_flag = 1;
		i++;
	}
	i = 0;
	while(str[i])
	{
		if(str[i] == 'C')
			c_flag = 1;
		i++;
	}
	i = 0;
	while(str[i])
	{
		if(str[i] == 'P')
			p_flag++;
		i++;
	}
	i = 0;
	while(str[i])
	{
		if(str[i] == 'E')
			e_flag++;
		i++;
	}
	i = 0;
	while(str[i])
	{
		if(str[i] != 'E' && str[i] != 'C' 
		&& str[i] != 'P' && str[i] != '1' 
		&& str[i] != '0' && str[i] != '\n')
		{
			inv_flag = 1;
		}
		i++;
	}
	flags = inv_flag + w_flag + sp_flag + e_flag + p_flag + c_flag;
	return(flags) ;
}

int map_strlen(char *str)
{
	int i;
	int flag;

	i = 0;
	if(!str)
		return 0;
	while(str[i])
	{
		if(str[i] == '\n')
			flag = 1;
		i++;
	}
	if(flag == 1)
		i -= 1;
	if(str[0] != '1' || str[i - 1] != '1')
	{
		exit(0);
	}
	return (i);
}


void map_size_checker(char *str, int flag)
{
	static int tmp;
	int len;

	len = map_strlen(str);
	if(!str)
		return ;
	if(flag == 1)
		tmp = len;
	else
		if(tmp != len)
		{
			exit(0);
		}
}

char **map_organizer(int fd)
{
	char *line;
	char *sec_map;
	char **map_dp;
	sec_map = NULL;
	
	line = get_next_line(fd);
	map_size_checker(line, 1);
	while(line)
	{
		sec_map = ft_strjoin(sec_map, line);
		line = get_next_line(fd);
		map_size_checker(line, 0);
	}
	if(epc01_checker(sec_map) != 5)
	{
		exit(0);
	}
	close(fd);
	map_dp = ft_split(sec_map, '\n');
	return(map_dp);
}