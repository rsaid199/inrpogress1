/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaid <rsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:54:56 by rsaid             #+#    #+#             */
/*   Updated: 2023/04/30 13:48:43 by rsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	checker_c(char **sec_map)
{
	int	i;
	int	x;
	int	c_flag;
	int	e_flag;

	x = 0;
	i = 0;
	c_flag = 0;
	e_flag = 0;
	while (sec_map[x][i])
	{
		if (sec_map[x][i] == 'C')
			c_flag = 1;
		if (sec_map[x][i] == 'E')
			e_flag = 1;
		i++;
		if (i == (ft_strlen(sec_map[x]) - 1) && sec_map[x + 1] != NULL)
		{
			x++;
			i = 0;
		}
	}
	if (c_flag + e_flag == 0)
		return (1);
	return (0);
}

int	checker_e(char **sec_map)
{
	int	i;
	int	x;
	int	c_flag;

	x = 0;
	i = 0;
	c_flag = 0;
	while (sec_map[x][i])
	{
		if (sec_map[x][i] == 'C')
			c_flag = 1;
		i++;
		if (i == (ft_strlen(sec_map[x]) - 1) && sec_map[x + 1] != NULL)
		{
			x++;
			i = 0;
		}
	}
	if (c_flag == 0)
		return (1);
	else
		return (0);
}

void	map_drawer(char **sec_map, void *mlx_ptr, void *win_ptr)
{
	int			x;
	int			ra2si;
	t_readmap	vars;

	x = 0;
	ra2si = 0;
	while (sec_map[x])
	{
		map_maker(sec_map[x], mlx_ptr, win_ptr, ra2si);
		x++;
		ra2si += 64;
	}
}

int	handle_keypress(int keycode, t_main *vars)
{
	int	i;
	int	x;

	i = 0;
	x = 1;
	if (keycode == 124 || keycode == 2)
		move_right(vars, x, i);
	else if (keycode == 123 || keycode == 0)
		move_left(vars, x, i);
	else if (keycode == 126 || keycode == 13)
		move_up(vars, x, i);
	else if (keycode == 125 || keycode == 1)
		move_down(vars, x, i);
	else if (keycode == 53)
		exit(0);
	return (0);
}

int	main(void)
{
	t_main	vars;

	vars.i = 0;
	vars.x = 0;
	vars.fd = open("maps/map.ber", O_RDONLY);
	vars.sec_map = map_organizer(vars.fd);
	vars.i = ft_strlen(vars.sec_map[vars.x]);
	while (vars.sec_map[vars.x])
		vars.x++;
	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, vars.i * 64,
			vars.x * 64, "so_long");
	map_drawer(vars.sec_map, vars.mlx_ptr, vars.win_ptr);
	mlx_hook(vars.win_ptr, 2, 0, handle_keypress, &vars);
	mlx_hook(vars.win_ptr, 17, 0, (void *)exit, 0);
	mlx_loop(vars.mlx_ptr);
	free_dp(vars.sec_map);
	return (0);
}
