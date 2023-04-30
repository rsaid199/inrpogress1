/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaid <rsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 10:55:03 by rsaid             #+#    #+#             */
/*   Updated: 2023/04/30 11:23:58 by rsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	move_right(t_main *vars, int x, int i)
{
	while (vars->sec_map[x][i])
	{
		if (vars->sec_map[x][i] == 'P' && vars->sec_map[x][i + 1] != '1')
		{
			if (vars->sec_map[x][i + 1] == 'E' && checker_e(vars->sec_map) == 0)
				break ;
			vars->sec_map[x][i] = '0';
			vars->sec_map[x][i + 1] = 'P';
			mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
			map_drawer(vars->sec_map, vars->mlx_ptr, vars->win_ptr);
			if (checker_c(vars->sec_map) == 1)
			{
				write(1, "GG", 2);
				exit(0);
			}
			break ;
		}
		i++;
		if (i == (ft_strlen(vars->sec_map[x]) - 1)
			&& vars->sec_map[x + 1] != NULL)
		{
			x++;
			i = 0;
		}
	}
}

void	move_left(t_main *vars, int x, int i)
{
	while (vars->sec_map[x][i])
	{
		if (vars->sec_map[x][i] == 'P' && vars->sec_map[x][i - 1] != '1')
		{
			if (vars->sec_map[x][i - 1] == 'E' && checker_e(vars->sec_map) == 0)
				break ;
			vars->sec_map[x][i] = '0';
			vars->sec_map[x][i - 1] = 'P';
			mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
			map_drawer(vars->sec_map, vars->mlx_ptr, vars->win_ptr);
			if (checker_c(vars->sec_map) == 1)
			{
				write(1, "GG", 2);
				exit(0);
			}
			break ;
		}
		i++;
		if (i == (ft_strlen(vars->sec_map[x]) - 1)
			&& vars->sec_map[x + 1] != NULL)
		{
			x++;
			i = 0;
		}
	}
}

void	move_up(t_main *vars, int x, int i)
{
	while (vars->sec_map[x][i])
	{
		if (vars->sec_map[x][i] == 'P' && vars->sec_map[x - 1][i] != '1')
		{
			if (vars->sec_map[x - 1][i] == 'E' && checker_e(vars->sec_map) == 0)
				break ;
			vars->sec_map[x][i] = '0';
			vars->sec_map[x - 1][i] = 'P';
			mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
			map_drawer(vars->sec_map, vars->mlx_ptr, vars->win_ptr);
			if (checker_c(vars->sec_map) == 1)
			{
				write(1, "GG", 2);
				exit(0);
			}
			break ;
		}
		i++;
		if (i == (ft_strlen(vars->sec_map[x]) - 1)
			&& vars->sec_map[x + 1] != NULL)
		{
			x++;
			i = 0;
		}
	}
}

void	move_down(t_main *vars, int x, int i)
{
	while (vars->sec_map[x][i])
	{
		if (vars->sec_map[x][i] == 'P' && vars->sec_map[x + 1][i] != '1')
		{
			if (vars->sec_map[x + 1][i] == 'E' && checker_e(vars->sec_map) == 0)
				break ;
			vars->sec_map[x][i] = '0';
			vars->sec_map[x + 1][i] = 'P';
			mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
			map_drawer(vars->sec_map, vars->mlx_ptr, vars->win_ptr);
			if (checker_c(vars->sec_map) == 1)
			{
				write(1, "GG", 2);
				exit(0);
			}
			break ;
		}
		i++;
		if (i == (ft_strlen(vars->sec_map[x]) - 1)
			&& vars->sec_map[x + 1] != NULL)
		{
			x++;
			i = 0;
		}
	}
}
