#include "get_next_line.h"

int checker_c(char **sec_map)
{
    int i;
    int x;
    x = 0;
    i = 0;
    int c_flag = 0;
    int e_flag = 0;
    while(sec_map[x][i])
    {
        if(sec_map[x][i] == 'C')
            c_flag = 1;
        if(sec_map[x][i] == 'E')
            e_flag = 1;
        i++;
        if(i == (ft_strlen(sec_map[x]) - 1) && sec_map[x + 1] != NULL)
        {
            x++;
            i = 0;
        }
    }
    if(c_flag + e_flag == 0)
        return (1);
    else
        return 0;
}


void map_drawer(char **sec_map, void *mlx_ptr, void *win_ptr)
{
    int x = 0;
    int ra2si = 0;

    while(sec_map[x])
    {
        map_maker(sec_map[x], mlx_ptr, win_ptr, ra2si);
        x++;
        ra2si += 64;
    }
}


char **handle_keypress(int keycode, char **param)
{
    int i = 0;
    int x = 1;

    if(keycode == 6)
    {
        while(param[x][i])
        {
            if(param[x][i] == 'P' && param[x][i + 1] != '1')
            {
                param[x][i] = '0';
                param[x][i + 1] = 'P';
                if(checker_c(param) == 1)
                {
                    write(1, "GG", 2);
                    exit(0);
                }
                break ;
            }
            i++;
            if(i == (ft_strlen(param[x]) - 1) && param[x + 1] != NULL)
            {
                x++;
                i = 0;
            }
        }
    }
    else if(keycode == 4)
    {
        while(param[x][i])
        {
            if(param[x][i] == 'P' && param[x][i - 1] != '1')
            {
                param[x][i] = '0';
                param[x][i - 1] = 'P';
                if(checker_c(param) == 1)
                {
                    write(1, "GG", 2);
                    exit(0);
                }
                break;
            }
            i++;
            if(i == (ft_strlen(param[x]) - 1) && param[x + 1] != NULL)
            {
                x++;
                i = 0;
            }
        }
    }
    else if(keycode == 8)
    {
        while(param[x][i])
        {
            if(param[x][i] == 'P' && param[x - 1][i] != '1')
            {
                param[x][i] = '0';
                param[x - 1][i] = 'P';
                if(checker_c(param) == 1)
                {
                    write(1, "GG", 2);
                    exit(0);
                }
                break;
            }
            i++;
            if(i == (ft_strlen(param[x]) - 1) && param[x + 1] != NULL)
            {
                x++;
                i = 0;
            }
        }
    }
    else if(keycode == 5)
    {
        while(param[x][i])
        {
            if(param[x][i] == 'P' && param[x + 1][i] != '1')
            {
                param[x][i] = '0';
                param[x + 1][i] = 'P';
                if(checker_c(param) == 1)
                {
                    write(1, "GG", 2);
                    exit(0);
                }
                break;
            }
            i++;
            if(i == (ft_strlen(param[x]) - 1) && param[x + 1] != NULL)
            {
                x++;
                i = 0;
            }
        }
    }
    return (param);
}

int main()
{

    void *img;
    int img_height;
    int img_weidth;
	char **sec_map;
    char *line;
    int i = 0;
    int x = 0;
    int ra2si = 0;
    int fd;

    fd = open("maps/map.ber", O_RDONLY);
    sec_map = map_organizer(fd);
    i = ft_strlen(sec_map[x]);
    while(sec_map[x])
        x++;
    void *mlx_ptr = mlx_init();
    void *win_ptr = mlx_new_window(mlx_ptr, i*64, x*64, "Test Window");
    map_drawer(sec_map, mlx_ptr, win_ptr);
    sec_map = handle_keypress(6,sec_map);
    map_drawer(sec_map, mlx_ptr, win_ptr);
    sec_map = handle_keypress(6,sec_map);
    map_drawer(sec_map, mlx_ptr, win_ptr);
    sec_map = handle_keypress(8,sec_map);
    map_drawer(sec_map, mlx_ptr, win_ptr);
    sec_map = handle_keypress(6,sec_map);
    map_drawer(sec_map, mlx_ptr, win_ptr);
     sec_map = handle_keypress(8,sec_map);
    map_drawer(sec_map, mlx_ptr, win_ptr);
    sec_map = handle_keypress(6,sec_map);
    map_drawer(sec_map, mlx_ptr, win_ptr);
    sec_map = handle_keypress(6,sec_map);
    map_drawer(sec_map, mlx_ptr, win_ptr);
    sec_map = handle_keypress(6,sec_map);
    map_drawer(sec_map, mlx_ptr, win_ptr);
    sec_map = handle_keypress(6,sec_map);
    map_drawer(sec_map, mlx_ptr, win_ptr);
    sec_map = handle_keypress(6,sec_map);
    map_drawer(sec_map, mlx_ptr, win_ptr);
     sec_map = handle_keypress(6,sec_map);
    map_drawer(sec_map, mlx_ptr, win_ptr);
    sec_map = handle_keypress(6,sec_map);
    map_drawer(sec_map, mlx_ptr, win_ptr);
    sec_map = handle_keypress(5,sec_map);
    map_drawer(sec_map, mlx_ptr, win_ptr);
    sec_map = handle_keypress(5,sec_map);
    map_drawer(sec_map, mlx_ptr, win_ptr);
    sec_map = handle_keypress(5,sec_map);
    map_drawer(sec_map, mlx_ptr, win_ptr);
    sec_map = handle_keypress(4,sec_map);
    map_drawer(sec_map, mlx_ptr, win_ptr);
    sec_map = handle_keypress(4,sec_map);
    map_drawer(sec_map, mlx_ptr, win_ptr);
    sec_map = handle_keypress(4,sec_map);
    map_drawer(sec_map, mlx_ptr, win_ptr);
    sec_map = handle_keypress(4,sec_map);
    map_drawer(sec_map, mlx_ptr, win_ptr);
    sec_map = handle_keypress(4,sec_map);
    map_drawer(sec_map, mlx_ptr, win_ptr);

    mlx_loop(mlx_ptr);

    return 0;
}