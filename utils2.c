/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaid <rsaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:21:54 by rsaid             #+#    #+#             */
/*   Updated: 2023/05/01 12:22:34 by rsaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	borders(char **map)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (map[x][i])
	{
		if (map[x][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[x])
		x++;
	x--;
	while (map[x][i])
	{
		if (map[x][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	free_dp(char **dp)
{
	int	i;

	i = 0;
	while (dp[i])
	{
		free (dp[i]);
		i++;
	}
	free (dp);
}

void	bor_valid_exit(char *str, char **str1)
{
	write(1, "Error\n", 6);
	free_dp(str1);
	free(str);
	exit(2);
}

void	ep_exit(char *str)
{
	write(1, "Error\n", 6);
	free(str);
	exit(2);
}
