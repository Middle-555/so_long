/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:02:20 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/13 10:23:26 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
/*
int	player_move_up(t_so_long *game)
{
	t_map	*map;
	int		i;
	int		j;

	map = &(game->map);
	i = game->player_pos.p_position.y;
	j = game->player_pos.p_position.x;
	if (i - 1 >= 0 && map->tab[i - 1][j] != WALL)
	{
		map->tab[i][j] = GROUND;
		map->tab[i - 1][j] = PLAYER;
		game->player_pos.p_position.y = i - 1;
		return (1);
	}
	return (0);
}

int	player_move_down(t_so_long *game)
{
	t_map	*map;
	int		i;
	int		j;

	map = &(game->map);
	i = game->player_pos.p_position.y;
	j = game->player_pos.p_position.x;
	if (i + 1 < map->height && map->tab[i + 1][j] != WALL)
	{
		map->tab[i][j] = GROUND;
		map->tab[i + 1][j] = PLAYER;
		game->player_pos.p_position.y = i + 1;
		return (1);
	}
	return (0);
}


int	player_move_right(t_so_long *game)
{
	t_map	*map;
	int		i;
	int		j;

	map = &(game->map);
	i = game->player_pos.p_position.y;
	j = game->player_pos.p_position.x;
	if (j + 1 < map->width && map->tab[i][j + 1] != WALL)
	{
		map->tab[i][j] = GROUND;
		map->tab[i][j + 1] = PLAYER;
		game->player_pos.p_position.x = j + 1;
		return (1);
	}
	return (0);
}

int	player_move_left(t_so_long *game)
{
	t_map	*map;
	int		i;
	int		j;

	map = &(game->map);
	i = game->player_pos.p_position.y;
	j = game->player_pos.p_position.x;
	if (j - 1 >= 0 && map->tab[i][j - 1] != WALL)
	{
		map->tab[i][j] = GROUND;
		map->tab[i][j - 1] = PLAYER;
		game->player_pos.p_position.x = j - 1;
		return (1);
	}
	return (0);
}
*/