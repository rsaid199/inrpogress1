/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaid <rsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:46:44 by rsaid             #+#    #+#             */
/*   Updated: 2023/04/24 20:46:45 by rsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void map_maker(char *line, void *mlx_ptr, void *win_ptr,int ra2si)
{
	t_readmap vars;
    vars.x = 0;
	vars.i = 0;

    while(line[vars.i] != '\0')
    {
        if(line[vars.i] == '1')
        {
            vars.img_wall = mlx_xpm_file_to_image(mlx_ptr, "pictures/wall.xpm", &vars.img_height, &vars.img_weidth);
			if(!vars.img_wall)
				exit(2);
            mlx_put_image_to_window(mlx_ptr, win_ptr, vars.img_wall, vars.x, ra2si);
			mlx_destroy_image(mlx_ptr, vars.img_wall);
            vars.x += 64;
        }
        else if(line[vars.i] == '0')
        {
            vars.img_space = mlx_xpm_file_to_image(mlx_ptr, "pictures/sea.xpm", &vars.img_height, &vars.img_weidth);
			if(!vars.img_space)
				exit(2);
            mlx_put_image_to_window(mlx_ptr, win_ptr, vars.img_space, vars.x, ra2si);
			mlx_destroy_image(mlx_ptr, vars.img_space);
            vars.x += 64;
        }
        else if(line[vars.i] == 'C')
        {
            vars.img_fish = mlx_xpm_file_to_image(mlx_ptr, "pictures/fish.xpm", &vars.img_height, &vars.img_weidth);
			if(!vars.img_fish)
				exit(2);
            mlx_put_image_to_window(mlx_ptr, win_ptr, vars.img_fish, vars.x, ra2si);
			mlx_destroy_image(mlx_ptr, vars.img_fish);
            vars.x += 64;
        }
        else if(line[vars.i] == 'P')
        {
            vars.img_shark = mlx_xpm_file_to_image(mlx_ptr, "pictures/shark.xpm", &vars.img_height, &vars.img_weidth);
			if(!vars.img_shark)
				exit(2);
            mlx_put_image_to_window(mlx_ptr, win_ptr, vars.img_shark, vars.x, ra2si);
			mlx_destroy_image(mlx_ptr, vars.img_shark);
            vars.x += 64;
        }
        else if(line[vars.i] == 'E')
        {
            vars.img_exit = mlx_xpm_file_to_image(mlx_ptr, "pictures/exit.xpm", &vars.img_height, &vars.img_weidth);
			if(!vars.img_exit)
				exit(2);
            mlx_put_image_to_window(mlx_ptr, win_ptr, vars.img_exit, vars.x, ra2si);
			mlx_destroy_image(mlx_ptr, vars.img_exit);
            vars.x += 64;
        }
        vars.i++;
    }
}