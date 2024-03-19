/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:23:43 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/20 00:57:39 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	player_move_up(t_so_long *game)
{
	int	new_y;

	new_y = game->player_pos.p_position.y - 1;
	if (move_ok(game, new_y, game->player_pos.p_position.x) == 0)
	{
		if (game->map.tab[new_y][game->player_pos.p_position.x] == COLLECT)
			game->count_collectible--;
		ft_printf("%d new_y \n", new_y);
		if (new_y == game->end.y_end
			&& game->player_pos.p_position.x == game->end.y_end)
			game_success(game);
		game->map.tab[game->player_pos.p_position.y]
		[game->player_pos.p_position.x] = GROUND;
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.ground,
			game->player_pos.p_position.x * 96,
			game->player_pos.p_position.y * 96);
		game->player_pos.p_position.y = new_y;
		game->map.tab[new_y][game->player_pos.p_position.x] = PLAYER;
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.player,
			game->player_pos.p_position.x * 96,
			new_y * 96);
		game->count_step++;
	}
	return (0);
}

int	player_move_down(t_so_long *game)
{
	int	new_y;

	new_y = game->player_pos.p_position.y + 1;
	if (move_ok(game, new_y, game->player_pos.p_position.x) == 0)
	{
		if (game->map.tab[new_y][game->player_pos.p_position.x] == COLLECT)
			game->count_collectible--;
		if (new_y == game->end.y_end
			&& game->player_pos.p_position.x == game->end.y_end)
			game_success(game);
		game->map.tab[game->player_pos.p_position.y]
		[game->player_pos.p_position.x] = GROUND;
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.ground,
			game->player_pos.p_position.x * 96,
			game->player_pos.p_position.y * 96);
		game->player_pos.p_position.y = new_y;
		game->map.tab[new_y][game->player_pos.p_position.x] = PLAYER;
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.player,
			game->player_pos.p_position.x * 96,
			new_y * 96);
		game->count_step++;
		//if (game->player_pos.p_position.y == game->end.y_end
			//&& game->player_pos.p_position.x == game->end.y_end)
			//game_success(game);
	}
	return (0);
}

int	player_move_right(t_so_long *game)
{
	int	new_x;

	new_x = game->player_pos.p_position.x + 1;
	ft_printf("%dright\n", game->count_collectible);
	if (move_ok(game, game->player_pos.p_position.y, new_x) == 0)
	{
		if (game->map.tab[game->player_pos.p_position.y][new_x] == COLLECT)
			game->count_collectible--;
		if (game->player_pos.p_position.y == game->end.y_end
			&& new_x == game->end.y_end)
			game_success(game);
		game->map.tab[game->player_pos.p_position.y]
		[game->player_pos.p_position.x] = GROUND;
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.ground,
			game->player_pos.p_position.x * 96,
			game->player_pos.p_position.y * 96);
		game->player_pos.p_position.x = new_x;
		game->map.tab[game->player_pos.p_position.y][new_x] = PLAYER;
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.player,
			game->player_pos.p_position.x * 96,
			game->player_pos.p_position.y * 96);
		game->count_step++;
	//if (game->player_pos.p_position.y == game->end.y_end
			//&& game->player_pos.p_position.x == game->end.y_end)
		//	game_success(game);
	}
	return (0);
}

int	player_move_left(t_so_long *game)
{
	int	new_x;

	new_x = game->player_pos.p_position.x - 1;
	ft_printf("%dleft\n", game->count_collectible);
	if (move_ok(game, game->player_pos.p_position.y, new_x) == 0)
	{
		if (game->map.tab[game->player_pos.p_position.y][new_x] == COLLECT)
			game->count_collectible--;
		if (game->player_pos.p_position.y == game->end.y_end
			&& new_x == game->end.y_end)
			game_success(game);
		game->map.tab[game->player_pos.p_position.y]
		[game->player_pos.p_position.x] = GROUND;
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.ground,
			game->player_pos.p_position.x * 96,
			game->player_pos.p_position.y * 96);
		game->player_pos.p_position.x = new_x;
		game->map.tab[game->player_pos.p_position.y][new_x] = PLAYER;
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.player,
			game->player_pos.p_position.x * 96,
			game->player_pos.p_position.y * 96);
	//if (game->player_pos.p_position.y == game->end.y_end
			//&& game->player_pos.p_position.x == game->end.y_end)
			//game_success(game);
		game->count_step++;
	}
	return (0);
}

int	move_ok(t_so_long *game, int new_y, int new_x)
{
	//ft_printf("%d new y\n", game->map.tab[new_y][new_x]);
	if (game->map.tab[new_y][new_x] == WALL)
		return (1);
	else if (game->map.tab[new_y][new_x] == EXIT)
	{
		if (game->count_collectible != 0)
			return (1);
	}
	return (0);
}
