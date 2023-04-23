#include "get_next_line.h"

void map_maker(char *line, void *mlx_ptr, void *win_ptr,int ra2si)
{
    int i = 0;
    int ofoki = 0;
	t_readmap vars;
    int img_height;
    int img_weidth;

    while(line[i] != '\0')
    {
        if(line[i] == '1')
        {
            vars.img_wall = mlx_xpm_file_to_image(mlx_ptr, "pictures/wall.xpm", &img_height, &img_weidth);
			if(!vars.img_wall)
				exit(2);
            mlx_put_image_to_window(mlx_ptr, win_ptr, vars.img_wall, ofoki, ra2si);
			mlx_destroy_image(mlx_ptr, vars.img_wall);
            ofoki += 64;
        }
        else if(line[i] == '0')
        {
            vars.img_space = mlx_xpm_file_to_image(mlx_ptr, "pictures/sea.xpm", &img_height, &img_weidth);
			if(!vars.img_space)
				exit(2);
            mlx_put_image_to_window(mlx_ptr, win_ptr, vars.img_space, ofoki, ra2si);
			mlx_destroy_image(mlx_ptr, vars.img_space);
            ofoki += 64;
        }
        else if(line[i] == 'C')
        {
            vars.img_fish = mlx_xpm_file_to_image(mlx_ptr, "pictures/fish.xpm", &img_height, &img_weidth);
			if(!vars.img_fish)
				exit(2);
            mlx_put_image_to_window(mlx_ptr, win_ptr, vars.img_fish, ofoki, ra2si);
			mlx_destroy_image(mlx_ptr, vars.img_fish);
            ofoki += 64;
        }
        else if(line[i] == 'P')
        {
            vars.img_shark = mlx_xpm_file_to_image(mlx_ptr, "pictures/shark.xpm", &img_height, &img_weidth);
			if(!vars.img_shark)
				exit(2);
            mlx_put_image_to_window(mlx_ptr, win_ptr, vars.img_shark, ofoki, ra2si);
			mlx_destroy_image(mlx_ptr, vars.img_shark);
            ofoki += 64;
        }
        else if(line[i] == 'E')
        {
            vars.img_exit = mlx_xpm_file_to_image(mlx_ptr, "pictures/exit.xpm", &img_height, &img_weidth);
			if(!vars.img_exit)
				exit(2);
            mlx_put_image_to_window(mlx_ptr, win_ptr, vars.img_exit, ofoki, ra2si);
			mlx_destroy_image(mlx_ptr, vars.img_exit);
            ofoki += 64;
        }
        i++;
    }
}