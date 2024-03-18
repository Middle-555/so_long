/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:23:43 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/18 15:42:24 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	player_move_up(t_so_long *game, t_map *map)
{
	int	new_y;
	int	new_x;

	new_y = game->player_pos.p_position.y - 1;
	new_x = game->player_pos.p_position.x;
	if (new_y >= 0 && map->tab[new_y][game->player_pos.p_position.x] != WALL)
	{
		map->tab[game->player_pos.p_position.y][game->player_pos.p_position.x] = GROUND;
		game->player_pos.p_position.x = new_x;
		map->tab[new_y][game->player_pos.p_position.x] = PLAYER;
		game->count_step++;
		printf("Nouvelles coordonnées : x=%d, y=%d\n", new_x, new_y);
		printf("Contenu de la case : %c\n", map->tab[new_y][new_x]);

	}
	return (0);
}

int	player_move_down(t_so_long *game, t_map *map)
{
	int	new_y;
	int	new_x;

	new_y = game->player_pos.p_position.y + 1;
	new_x = game->player_pos.p_position.x;
	ft_printf("%d height\n", map->height);
	if (new_y < map->height
		&& map->tab[new_y][game->player_pos.p_position.x] != WALL)
	{
		map->tab[game->player_pos.p_position.y][game->player_pos.p_position.x] = GROUND;
		game->player_pos.p_position.y = new_y;
		map->tab[new_y][game->player_pos.p_position.x] = PLAYER;
		game->count_step++;
		printf("Nouvelles coordonnées : x=%d, y=%d\n", new_x, new_y);
		printf("Contenu de la case : %c\n", map->tab[new_y][new_x]);

	}
	return (0);
}

int	player_move_right(t_so_long *game, t_map *map)
{
	int	new_x;
	int	new_y;

	new_x = game->player_pos.p_position.x + 1;
	new_y = game->player_pos.p_position.y;
	if (new_x < map->width
		&& map->tab[game->player_pos.p_position.y][new_x] != WALL)
	{
		map->tab[game->player_pos.p_position.y][game->player_pos.p_position.x] = GROUND;
		game->player_pos.p_position.x = new_x;
		map->tab[game->player_pos.p_position.y][new_x] = PLAYER;
		game->count_step++;
		printf("Nouvelles coordonnées : x=%d, y=%d\n", new_x, new_y);
		printf("Contenu de la case : %c\n", map->tab[new_y][new_x]);
	}
	return (0);
}

int	player_move_left(t_so_long *game, t_map *map)
{
	int	new_x;
	int	new_y;

	new_x = game->player_pos.p_position.x - 1;
	new_y = game->player_pos.p_position.y;
	if (new_x >= 0 && map->tab[game->player_pos.p_position.y][new_x] != WALL)
	{
		map->tab[game->player_pos.p_position.y][game->player_pos.p_position.x] = GROUND;
		game->player_pos.p_position.x = new_x;
		map->tab[game->player_pos.p_position.y][new_x] = PLAYER;
		game->count_step++;
		printf("Nouvelles coordonnées : x=%d, y=%d\n", new_x, new_y);
		printf("Contenu de la case : %c\n", map->tab[new_y][new_x]);
	}
	return (0);
}
