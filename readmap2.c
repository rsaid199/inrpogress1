/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaid <rsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:05:48 by rsaid             #+#    #+#             */
/*   Updated: 2023/05/01 12:12:38 by rsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	map_maker(char *line, void *mlx_ptr, void *win_ptr, int ra2si)
{
	t_readmap	vars;

	vars.x = 0;
	vars.i = 0;
	while (line[vars.i] != '\0')
	{
		if (line[vars.i] == '1')
			wall_draw(mlx_ptr, win_ptr, ra2si, &vars);
		else if (line[vars.i] == '0')
			space_draw(mlx_ptr, win_ptr, ra2si, &vars);
		else if (line[vars.i] == 'C')
			collect_draw(mlx_ptr, win_ptr, ra2si, &vars);
		else if (line[vars.i] == 'P')
			player_draw(mlx_ptr, win_ptr, ra2si, &vars);
		else if (line[vars.i] == 'E')
			exit_draw(mlx_ptr, win_ptr, ra2si, &vars);
		vars.i++;
	}
}
