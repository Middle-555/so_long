/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:23:43 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/19 14:38:13 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	player_move_up(t_so_long *game, t_sprites *sprites)
{
	int	new_y;

	new_y = game->player_pos.p_position.y - 1;
	if (new_y >= 0
		&& game->map.tab[new_y][game->player_pos.p_position.x] != WALL
		&& game->map.tab[new_y][game->player_pos.p_position.x] != EXIT)
	{
		game->map.tab[game->player_pos.p_position.y][game->player_pos.p_position.x] = GROUND;
		// mlx_put_image_to_window(game->mlx, game->window, game->sprite.ground,
		// 	game->player_pos.p_position.x * 96,
		// 	game->player_pos.p_position.y * 96);
		game->player_pos.p_position.y = new_y;
		game->map.tab[new_y][game->player_pos.p_position.x] = PLAYER;
		// mlx_put_image_to_window(game->mlx, game->window, game->sprite.player,
		// 	game->player_pos.p_position.x * 96,
		// 	new_y * 96);
		put_sprite_on_screen(game, sprites);
		game->count_step++;
		aff_tab(game);
	}
	return (0);
}

int	player_move_down(t_so_long *game)
{
	int	new_y;

	new_y = game->player_pos.p_position.y + 1;
	if (new_y < game->map.height
		&& game->map.tab[new_y][game->player_pos.p_position.x] != WALL
		&& game->map.tab[new_y][game->player_pos.p_position.x] != EXIT)
	{
		game->map.tab[game->player_pos.p_position.y][game->player_pos.p_position.x] = GROUND;
		game->player_pos.p_position.y = new_y;
		game->map.tab[new_y][game->player_pos.p_position.x] = PLAYER;
		game->count_step++;
	}
	return (0);
}

int	player_move_right(t_so_long *game)
{
	int	new_x;

	new_x = game->player_pos.p_position.x + 1;
	if (new_x < game->map.width
		&& game->map.tab[game->player_pos.p_position.y][new_x] != WALL
		&& game->map.tab[game->player_pos.p_position.y][new_x] != EXIT)
	{
		game->map.tab[game->player_pos.p_position.y][game->player_pos.p_position.x] = GROUND;
		game->player_pos.p_position.x = new_x;
		game->map.tab[game->player_pos.p_position.y][new_x] = PLAYER;
		game->count_step++;
	}
	return (0);
}

int	player_move_left(t_so_long *game)
{
	int	new_x;

	new_x = game->player_pos.p_position.x - 1;
	if (new_x >= 0
		&& game->map.tab[game->player_pos.p_position.y][new_x] != WALL
		&& game->map.tab[game->player_pos.p_position.y][new_x] != EXIT)
	{
		game->map.tab[game->player_pos.p_position.y][game->player_pos.p_position.x] = GROUND;
		game->player_pos.p_position.x = new_x;
		game->map.tab[game->player_pos.p_position.y][new_x] = PLAYER;
		game->count_step++;
	}
	return (0);
}

