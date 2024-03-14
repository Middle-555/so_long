/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_initialisation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:16:03 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/14 11:22:44 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_sprites(t_so_long *game, t_sprites *sprites)
{
	int	size;

	size = 32;
	sprites->player = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm", &size,
					      &size);
	if (sprites->player == NULL)
		map_error("Couldn't load the 'player' XPM.");
	sprites->exit = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm", &size,
					    &size);
	if (sprites->exit == NULL)
		map_error("Couldn't load the 'exit' XPM.");
	sprites->collectible = mlx_xpm_file_to_image(game->mlx,
						   "sprites/collectible.xpm", &size, &size);
	/*if (sprites->collectible == NULL)
		map_error("Couldn't load the 'collectible' XPM.");
	sprites->wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm", &size,
					    &size);*/
	if (sprites->wall == NULL)
		map_error("Couldn't load the 'wall' XPM.");
	sprites->ground = mlx_xpm_file_to_image(game->mlx, "sprites/ground.xpm", &size,
					      &size);
	if (sprites->ground == NULL)
		map_error("Couldn't load the 'ground' XPM.");
}

void	put_sprite_on_screen(t_so_long *game, int height, int width)
{
	if (height < 0 || height >= game->map->height || width < 0 || width >= game->map->width)
		return;
	if (game->map->tab[height][width] == WALL)
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.wall,
					width * 30, height * 30);
	else if (game->map->tab[height][width] == COLLECT)
		mlx_put_image_to_window(game->mlx, game->window,
					game->sprite.collectible, width * 30, height * 30);
	else if (game->map->tab[height][width] == EXIT)
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.exit,
					width * 30, height * 30);
	else if (game->map->tab[height][width] == PLAYER)
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.player,
					width * 30, height * 30);
	else
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.ground,
					width * 30, height * 30);
}
