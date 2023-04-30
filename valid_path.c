#include "get_next_line.h"

int valid_helper(char **str)
{
	t_helper vars;
	vars.i = 0;
	vars.px = 0;
	vars.py = 0;
	vars.c_count = 0;
	vars.e_count = 1;
	while(str[vars.px][vars.py])
	{
		if(str[vars.px][vars.py] == 'C')
			vars.c_count++;
		if(str[vars.px][vars.py] == 'P')
		{
			vars.px_v = vars.px;
			vars.py_v = vars.py;
		}
		vars.py++;
		if(vars.py == (ft_strlen(str[vars.px]) - 1) && str[vars.px + 1] != NULL)
        {
            vars.px++;
            vars.py = 0;
        }
	}
	walking_in_map(vars.px_v, vars.py_v, str, &vars);
	while(str[vars.i])
	{
		free(str[vars.i]);
		vars.i++;
	}
	free(str);
	if(vars.e_count > 0 || vars.c_count > 0)
		return(0);
	return(1);
}

void	walking_in_map(int px, int py, char **map, t_helper *path)
{
	if (map[py][px] == '1' || map[py][px] == 'X')
		return ;
	if (map[py][px] == 'C')
		path->c_count--;
	else if (map[py][px] == 'E')
	{
		path->e_count--;
		return ;
	}
	map[py][px] = 'X';
	walking_in_map(px + 1, py, map, path);
	walking_in_map(px - 1, py, map, path);
	walking_in_map(px, py - 1, map, path);
	walking_in_map(px, py + 1, map, path);
}
