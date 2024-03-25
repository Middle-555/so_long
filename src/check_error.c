/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:03:01 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/25 14:20:31 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Check if the last line is entirely constitued of walls.
int	check_last_line(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.tab[i])
		i++;
	while (game->map.tab[i - 1][j])
	{
		if (game->map.tab[i -1][j] != WALL)
			map_error("Please put wall.", game);
		j++;
	}
	return (0);
}

// Check for other caracter in the map. If there is use map_error to stop.
int	other_caracter(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.tab[i])
	{
		j = 0;
		while (game->map.tab[i][j])
		{
			if (game->map.tab[i][j] != '1'
			&& game->map.tab[i][j] != '0'
			&& game->map.tab[i][j] != 'C'
			&& game->map.tab[i][j] != 'E'
			&& game->map.tab[i][j] != 'P')
				map_error("Please put valid caracter in the map.", game);
			j++;
		}
		i++;
	}
	return (0);
}
