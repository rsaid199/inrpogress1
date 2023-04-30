/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaid <rsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 01:14:52 by rsaid             #+#    #+#             */
/*   Updated: 2023/04/24 20:40:01 by rsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	init_epc01(t_epc01 *vars)
{
	vars->i = 0;
	vars->flags = 0;
	vars->w_flag = 0;
	vars->sp_flag = 0;
	vars->p_flag = 0;
	vars->c_flag = 0;
	vars->e_flag = 0;
	vars->inv_flag = 0;
}

int	epc01_checker(char *str)
{
	t_epc01	vars;

	init_epc01(&vars);
	if (!str)
		return (0);
	while (str[vars.i])
	{
		if (str[vars.i] == '1')
			vars.w_flag = 1;
		else if (str[vars.i] == '0')
				vars.sp_flag = 1;
		else if (str[vars.i] == 'C')
				vars.c_flag = 1;
		else if (str[vars.i] == 'P')
				vars.p_flag++;
		else if (str[vars.i] == 'E')
				vars.e_flag++;
		else if (str[vars.i] != 'E' && str[vars.i] != 'C' && str[vars.i] != 'P'
			&& str[vars.i] != '1' && str[vars.i] != '0' && str[vars.i] != '\n')
			vars.inv_flag = 1;
		vars.i++;
	}
	vars.flags = vars.inv_flag + vars.w_flag + vars.sp_flag
		+ vars.e_flag + vars.p_flag + vars.c_flag;
	return (vars.flags);
}

int	map_strlen(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			flag = 1;
		i++;
	}
	if (flag == 1)
		i -= 1;
	if (str[0] != '1' || str[i - 1] != '1')
		return (0);
	return (i);
}

int	map_size_checker(char *str, int flag)
{
	static int	tmp;
	int			len;

	if (!str)
		return (0);
	len = map_strlen(str);
	if (flag == 1)
		tmp = len;
	else
		if (tmp != len || map_strlen(str) == 0)
			return (0);
	return (1);
}

char	**map_organizer(int fd)
{
	t_organizer	vars;

	vars.sec_map = NULL;
	vars.line = get_next_line(fd);
	map_size_checker(vars.line, 1);
	while (vars.line)
	{
		vars.sec_map = ft_strjoin_with_free(vars.sec_map, vars.line);
		vars.line = get_next_line(fd);
		if (vars.line && map_size_checker(vars.line, 0) == 0)
		{
			free(vars.sec_map);
			free(vars.line);
			exit(0);
		}
	}
	if (epc01_checker(vars.sec_map) != 5)
	{
		free(vars.sec_map);
		exit(0);
	}
	close(fd);
	vars.tmp_dp = ft_split(vars.sec_map, '\n');
	// printf("%s\n", vars.tmp_dp[1]);
	if(valid_helper(vars.tmp_dp) == 0)
	{
		free(vars.sec_map);
		exit(2);
	}
	vars.map_dp = ft_split(vars.sec_map, '\n');
	return (free(vars.sec_map), vars.map_dp);
}
