#include "get_next_line.h"

void map_maker(char *line, void *mlx_ptr, void *win_ptr,int ra2si)
{
    int i = 0;
    int ofoki;
    void *img;
    int img_height;
    int img_weidth;
    char *wall_path = "pictures/wall.xpm";
    char *sea_path = "pictures/sea.xpm";
    char *shark_path = "pictures/shark.xpm";
    char *fish_path = "pictures/fish.xpm";
    char *exit_path = "pictures/exit.xpm";
    ofoki = 0;

    while(line[i] != '\0')
    {
        if(line[i] == '1')
        {
            img = mlx_xpm_file_to_image(mlx_ptr, wall_path, &img_height, &img_weidth);
            mlx_put_image_to_window(mlx_ptr, win_ptr, img, ofoki, ra2si);
            ofoki += 64;
        }
        else if(line[i] == '0')
        {
            img = mlx_xpm_file_to_image(mlx_ptr, sea_path, &img_height, &img_weidth);
            mlx_put_image_to_window(mlx_ptr, win_ptr, img, ofoki, ra2si);
            ofoki += 64;
        }
        else if(line[i] == 'C')
        {
            img = mlx_xpm_file_to_image(mlx_ptr, fish_path, &img_height, &img_weidth);
            mlx_put_image_to_window(mlx_ptr, win_ptr, img, ofoki, ra2si);
            ofoki += 64;
        }
        else if(line[i] == 'P')
        {
            img = mlx_xpm_file_to_image(mlx_ptr, shark_path, &img_height, &img_weidth);
            mlx_put_image_to_window(mlx_ptr, win_ptr, img, ofoki, ra2si);
            ofoki += 64;
        }
        else if(line[i] == 'E')
        {
            img = mlx_xpm_file_to_image(mlx_ptr, exit_path, &img_height, &img_weidth);
            mlx_put_image_to_window(mlx_ptr, win_ptr, img, ofoki, ra2si);
            ofoki += 64;
        }
        i++;
    }
}