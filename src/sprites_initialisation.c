/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_initialisation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:16:03 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/19 14:43:34 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Stock the sprites with the correct size.
void	init_sprites(t_so_long *game)
{
	int	size;

	size = 96;
	game->sprite.player = mlx_xpm_file_to_image(game->mlx,
			"./sprites/player.xpm", &size, &size);
	if (game->sprite.player == NULL)
		map_error("Couldn't load the 'player' XPM.", game);
	game->sprite.exit = mlx_xpm_file_to_image(game->mlx,
			"./sprites/exittest.xpm", &size, &size);
	if (game->sprite.exit == NULL)
		map_error("Couldn't load the 'exit' XPM.", game);
	game->sprite.collectible = mlx_xpm_file_to_image(game->mlx,
			"./sprites/collectibletest.xpm", &size, &size);
	if (game->sprite.collectible == NULL)
		map_error("Couldn't load the 'collectible' XPM.", game);
	game->sprite.wall = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm",
			&size, &size);
	if (game->sprite.wall == NULL)
		map_error("Couldn't load the 'wall' XPM.", game);
	game->sprite.ground = mlx_xpm_file_to_image(game->mlx,
			"./sprites/ground.xpm", &size, &size);
	if (game->sprite.ground == NULL)
		map_error("Couldn't load the 'ground' XPM.", game);
}

// Displays sprites on the screen.
void	put_sprite_on_screen(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.tab[i])
	{
		j = 0;
		while (game->map.tab[i][j])
		{
			refresh(game, i, j);
			j++;
		}
		i++;
	}
}

// Refresh the position everytime the player move. 
// This fonction put a ground where the player was and put the 
// the player to his new localisation.
void	refresh(t_so_long *game, int i, int j)
{
	if (game->map.tab[i][j] == WALL)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite.wall, j * 96, i * 96);
	else if (game->map.tab[i][j] == COLLECT)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite.collectible, j * 96, i * 96);
	else if (game->map.tab[i][j] == EXIT)
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.exit, j
			* 96, i * 96);
	else if (game->map.tab[i][j] == PLAYER)
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.player, j
			* 96, i * 96);
	else if (game->map.tab[i][j] == GROUND)
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.ground, j
			* 96, i * 96);
}
