/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:04:39 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/25 14:20:04 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Check is the map is rectangular.
int	not_rectangular(t_so_long *game)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(game->map.tab[i]);
	while (game->map.tab[i])
	{
		if (len != ft_strlen(game->map.tab[i]))
			map_error("The map need to be rectangular.", game);
		i++;
	}
	game->map.width = len;
	game->map.height = i;
	game->count_step = 1;
	return (0);
}

// Check if there is enough collectible to play the game.
int	not_enough_collectible(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	game->count_collectible = 0;
	while (game->map.tab[i])
	{
		j = 0;
		while (game->map.tab[i][j])
		{
			if (game->map.tab[i][j] == COLLECT)
				game->count_collectible++;
			j++;
		}
		i++;
	}
	if (game->count_collectible < 1)
		map_error("Please put at least 1 collectible", game);
	return (0);
}

// Check if there is only 1 exit.
int	not_enough_exit(t_so_long *game)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while (game->map.tab[i])
	{
		j = 0;
		while (game->map.tab[i][j])
		{
			if (game->map.tab[i][j] == EXIT)
			{
				exit++;
				game->end.x_end = i;
				game->end.y_end = j;
			}
			j++;
		}
		i++;
	}
	if (exit != 1)
		map_error("Please put 1 exit.", game);
	return (0);
}

// Check if there is only 1 player is the map.
int	check_player(t_so_long *game)
{
	int			i;
	int			j;
	int			player_count;

	i = 0;
	player_count = 0;
	while (game->map.tab[i])
	{
		j = 0;
		while (game->map.tab[i][j])
		{
			if (game->map.tab[i][j] == PLAYER)
			{
				player_count++;
				game->player_pos.p_position.y = i;
				game->player_pos.p_position.x = j;
			}
			j++;
		}
		i++;
	}
	if (player_count != 1)
		map_error("Please put only 1 player.", game);
	return (0);
}

// Check that the first line, the first caracter of each line,
// and the last caracter of each line are entirely composed of wall.
int	wall_checker(t_so_long *game)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(game->map.tab[i]);
	ft_printf("len%d \n", len);
	while (game->map.tab[i])
	{
		j = 0;
		while (game->map.tab[i][j])
		{
			if (game->map.tab[0][j] != WALL)
				map_error("need wall.", game);
			j++;
		}
		if (game->map.tab[i][0] != WALL || game->map.tab[i][len - 1] != WALL)
			map_error("Need wall.", game);
		i++;
	}
	return (0);
}
