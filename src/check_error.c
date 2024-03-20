/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:03:01 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/20 17:51:38 by kpourcel         ###   ########.fr       */
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
			map_error("Please put wall.");
		j++;
	}
	return (0);
}
