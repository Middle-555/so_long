/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:02:20 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/15 19:17:48 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	player_move_up(t_so_long *game, t_map *map)
{
	int	i;
	int	j;

	i = game->player_pos.p_position.y;
	j = game->player_pos.p_position.x;
	ft_printf("%d y\n", game->player_pos.p_position.y);
	ft_printf("%d x\n", game->player_pos.p_position.x);
	if (map->tab[i - 1][j] != WALL)
	{
		map->tab[i][j] = GROUND;
		map->tab[i - 1][j] = PLAYER;
		game->player_pos.p_position.y = i - 1;
		return (1);
	}
	return (0);
}

int	player_move_down(t_so_long *game, t_map *map)
{
	int	i;
	int	j;


	i = game->player_pos.p_position.y;
	j = game->player_pos.p_position.x;
	ft_printf("%d y\n", game->player_pos.p_position.y);
	ft_printf("%d x\n", game->player_pos.p_position.x);

	ft_printf("%d\n", i);
	ft_printf("%d\n", j);
	ft_printf("%d\n", map->tab[i]);
	ft_printf("%d\n", map->tab[j]);
	if (map->tab[i + 1][j] != WALL)
	{
		map->tab[i][j] = GROUND;
		map->tab[i + 1][j] = PLAYER;
		game->player_pos.p_position.y = i + 1;
		return (1);
	}
	return (0);
}

int	player_move_right(t_so_long *game, t_map *map)
{
	int	i;
	int	j;

	i = game->player_pos.p_position.y;
	j = game->player_pos.p_position.x;
	ft_printf("%d y\n", game->player_pos.p_position.y);
	ft_printf("%d x\n", game->player_pos.p_position.x);
	if (map->tab[i][j + 1] != WALL)
	{
		map->tab[i][j] = GROUND;
		map->tab[i][j + 1] = PLAYER;
		game->player_pos.p_position.x = j + 1;
		return (1);
	}
	return (0);
}

int	player_move_left(t_so_long *game, t_map *map)
{
	int	i;
	int	j;

	i = game->player_pos.p_position.y;
	j = game->player_pos.p_position.x;
	ft_printf("%d y\n", game->player_pos.p_position.y);
	ft_printf("%d x\n", game->player_pos.p_position.x);
	if (map->tab[i][j - 1] != WALL)
	{
		map->tab[i][j] = GROUND;
		map->tab[i][j - 1] = PLAYER;
		game->player_pos.p_position.x = j - 1;
		return (1);
	}
	return (0);
}
