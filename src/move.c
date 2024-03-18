/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:23:43 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/18 18:30:33 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	player_move_up(t_so_long *game)
{
	int	new_y;
	int	new_x;

	new_y = game->player_pos.p_position.y - 1;
	new_x = game->player_pos.p_position.x;
	if (new_y >= 0 && game->map.tab[new_y][game->player_pos.p_position.x] != WALL)
	{
		game->map.tab[game->player_pos.p_position.y][game->player_pos.p_position.x] = GROUND;
		game->player_pos.p_position.x = new_x;
		game->map.tab[new_y][game->player_pos.p_position.x] = PLAYER;
		game->count_step++;
		printf("Nouvelles coordonnées : x=%d, y=%d\n", new_x, new_y);
		printf("Contenu de la case : %c\n", game->map.tab[new_y][new_x]);

	}
	return (0);
}

int	player_move_down(t_so_long *game)
{
	int	new_y;
	int	new_x;

//new_y < game->map->height
		//&& 
	ft_printf("%d test P.pos x\n", game->player_pos.p_position.x);
	ft_printf("%d test P.pos y\n", game->player_pos.p_position.y);
	new_y = game->player_pos.p_position.y + 1;
	new_x = game->player_pos.p_position.x;
	ft_printf("%d test new_y\n", new_y);
	ft_printf("%d height\n", game->map.height);
	//ft_printf("%d game height\n", game->map->height);
	ft_printf("%d width \n", game->map.width);
	ft_printf("%d test P.pos x\n", game->player_pos.p_position.x);
	ft_printf("%d test P.pos y\n", game->player_pos.p_position.y);
	if (game->map.tab[new_y][game->player_pos.p_position.x] != WALL)
	{
		game->map.tab[game->player_pos.p_position.y][game->player_pos.p_position.x] = GROUND;
		game->player_pos.p_position.y = new_y;
		game->map.tab[new_y][game->player_pos.p_position.x] = PLAYER;
		game->count_step++;
		printf("Nouvelles coordonnées : x=%d, y=%d\n", new_x, new_y);
		printf("Contenu de la case : %c\n", game->map.tab[new_y][new_x]);

	}
	return (0);
}

int	player_move_right(t_so_long *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_pos.p_position.x + 1;
	new_y = game->player_pos.p_position.y;
	if (new_x < game->map.width
		&& game->map.tab[game->player_pos.p_position.y][new_x] != WALL)
	{
		game->map.tab[game->player_pos.p_position.y][game->player_pos.p_position.x] = GROUND;
		game->player_pos.p_position.x = new_x;
		game->map.tab[game->player_pos.p_position.y][new_x] = PLAYER;
		game->count_step++;
		printf("Nouvelles coordonnées : x=%d, y=%d\n", new_x, new_y);
		printf("Contenu de la case : %c\n", game->map.tab[new_y][new_x]);
	}
	return (0);
}

int	player_move_left(t_so_long *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_pos.p_position.x - 1;
	new_y = game->player_pos.p_position.y;
	if (new_x >= 0 && game->map.tab[game->player_pos.p_position.y][new_x] != WALL)
	{
		game->map.tab[game->player_pos.p_position.y][game->player_pos.p_position.x] = GROUND;
		game->player_pos.p_position.x = new_x;
		game->map.tab[game->player_pos.p_position.y][new_x] = PLAYER;
		game->count_step++;
		printf("Nouvelles coordonnées : x=%d, y=%d\n", new_x, new_y);
		printf("Contenu de la case : %c\n", game->map.tab[new_y][new_x]);
	}
	return (0);
}
