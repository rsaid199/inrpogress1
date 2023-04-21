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
int checker_e(char **sec_map)
{
	int i;
    int x;
    x = 0;
    i = 0;
    int c_flag = 0;
    while(sec_map[x][i])
    {
        if(sec_map[x][i] == 'C')
            c_flag = 1;
        i++;
        if(i == (ft_strlen(sec_map[x]) - 1) && sec_map[x + 1] != NULL)
        {
            x++;
            i = 0;
        }
    }
    if(c_flag  == 0)
        return (1);
    else
        return 0;
}

void map_drawer(char **sec_map, void *mlx_ptr, void *win_ptr)
{
    int x = 0;
    int ra2si = 0;
	t_readmap vars;
	
    while(sec_map[x])
    {
        map_maker(sec_map[x], mlx_ptr, win_ptr, ra2si);
        x++;
        ra2si += 64;
    }
}


int handle_keypress(int keycode, t_main *vars)
{
    int i = 0;
    int x = 1;

    if(keycode == 124)
    {
        while(vars->sec_map[x][i])
        {
            if(vars->sec_map[x][i] == 'P' && vars->sec_map[x][i + 1] != '1')
            {
				if(vars->sec_map[x][i + 1] == 'E' && checker_e(vars->sec_map) == 0)
					break;
                vars->sec_map[x][i] = '0';
                vars->sec_map[x][i + 1] = 'P';
				mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
				map_drawer(vars->sec_map, vars->mlx_ptr, vars->win_ptr);
                if(checker_c(vars->sec_map) == 1)
                {
                    write(1, "GG", 2);
                    exit(0);
                }
                break ;
            }
            i++;
            if(i == (ft_strlen(vars->sec_map[x]) - 1) && vars->sec_map[x + 1] != NULL)
            {
                x++;
                i = 0;
            }
        }
    }
    else if(keycode == 123)
    {
        while(vars->sec_map[x][i])
        {
            if(vars->sec_map[x][i] == 'P' && vars->sec_map[x][i - 1] != '1')
            {
				if(vars->sec_map[x][i - 1] == 'E' && checker_e(vars->sec_map) == 0)
					break;
                vars->sec_map[x][i] = '0';
                vars->sec_map[x][i - 1] = 'P';
				mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
				map_drawer(vars->sec_map, vars->mlx_ptr, vars->win_ptr);
                if(checker_c(vars->sec_map) == 1)
                {
                    write(1, "GG", 2);
                    exit(0);
                }
                break;
            }
            i++;
            if(i == (ft_strlen(vars->sec_map[x]) - 1) && vars->sec_map[x + 1] != NULL)
            {
                x++;
                i = 0;
            }
        }
    }
    else if(keycode == 126)
    {
        while(vars->sec_map[x][i])
        {
            if(vars->sec_map[x][i] == 'P' && vars->sec_map[x - 1][i] != '1')
            {
				if(vars->sec_map[x - 1][i] == 'E' && checker_e(vars->sec_map) == 0)
					break;
                vars->sec_map[x][i] = '0';
                vars->sec_map[x - 1][i] = 'P';
				mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
				map_drawer(vars->sec_map, vars->mlx_ptr, vars->win_ptr);
                if(checker_c(vars->sec_map) == 1)
                {
                    write(1, "GG", 2);
                    exit(0);
                }
                break;
            }
            i++;
            if(i == (ft_strlen(vars->sec_map[x]) - 1) && vars->sec_map[x + 1] != NULL)
            {
                x++;
                i = 0;
            }
        }
    }
    else if(keycode == 125)
    {
        while(vars->sec_map[x][i])
        {
            if(vars->sec_map[x][i] == 'P' && vars->sec_map[x + 1][i] != '1')
            {
				if(vars->sec_map[x + 1][i] == 'E' && checker_e(vars->sec_map) == 0)
					break;
                vars->sec_map[x][i] = '0';
                vars->sec_map[x + 1][i] = 'P';
				mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
				map_drawer(vars->sec_map, vars->mlx_ptr, vars->win_ptr);
                if(checker_c(vars->sec_map) == 1)
                {
                    write(1, "GG", 2);
                    exit(0);
                }
                break;
            }
            i++;
            if(i == (ft_strlen(vars->sec_map[x]) - 1) && vars->sec_map[x + 1] != NULL)
            {
                x++;
                i = 0;
            }
        }
    }
	if(keycode == 53)
	{
		exit(0);
	}
	return (0);
}

int main()
{
	t_main vars;
    vars.i = 0;
	vars.x = 0;

    vars.fd = open("maps/map2.ber", O_RDONLY);
    vars.sec_map = map_organizer(vars.fd);;
    vars.i = ft_strlen(vars.sec_map[vars.x]);
    while(vars.sec_map[vars.x])
        vars.x++;
    vars.mlx_ptr = mlx_init();
    vars.win_ptr = mlx_new_window(vars.mlx_ptr, vars.i*64, vars.x*64, "Test Window");
    map_drawer(vars.sec_map, vars.mlx_ptr, vars.win_ptr);
	mlx_hook(vars.win_ptr, 2, 0, handle_keypress, &vars);
    mlx_loop(vars.mlx_ptr);

    return 0;
}