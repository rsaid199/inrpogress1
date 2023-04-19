/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaid <rsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:07:13 by rsaid             #+#    #+#             */
/*   Updated: 2023/04/10 02:16:46 by rsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <limits.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <string.h>
# include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
// #include <mlx.h>
#include <math.h>
// #include <AppKit/NSGraphics.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_vars
{
	char		*buffer;
	char		*line;
	int			read_size;
}		t_vars;

int		ft_strlen(char *s);
char	*buffer_appender(char *buffer, char *storage);
char	*ft_strchr(char *s, int c);
char	*linemaker(char *buffer, int c);
char	*get_next_line(int fd);
int		new_line_checker(char *buffer);
void 	map_maker(char *line, void *mlx_ptr, void *win_ptr, int ra2si);
char	*ft_strjoin(char *s1, char *s2);
int 	map_strlen(char *str);
char 	**map_organizer(int fd);
char 	**handle_keypress(int keycode, char **param);
char	**ft_split(char *s, char c);
char	*maker(char *x, int start, int end);
int		wordcounter(char *s, char c);
void 	map_drawer(char **sec_map, void *mlx_ptr, void *win_ptr);
int 	checker_c(char **sec_map);

#endif