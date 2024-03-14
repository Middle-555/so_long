/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_initialisation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:16:03 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/14 10:59:48 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_sprites	init_sprites(void *mlx)
{
	t_sprites	sprite;
	int			width;
	int			height;

	sprite.player = mlx_xpm_file_to_image(mlx, "../sprites/player.xpm", &width,
			&height);
	if (sprite.player == NULL)
		map_error("Couldn't load the 'player' XPM.");
	sprite.exit = mlx_xpm_file_to_image(mlx, "../sprites/exit.xpm", &width,
			&height);
	if (sprite.exit == NULL)
		map_error("Couldn't load the 'exit' XPM.");
	sprite.collectible = mlx_xpm_file_to_image(mlx,
			"../sprites/collectible.xpm", &width, &height);
	if (sprite.collectible == NULL)
		map_error("Couldn't load the 'collectible' XPM.");
	sprite.wall = mlx_xpm_file_to_image(mlx, "../sprites/wall.xpm", &width,
			&height);
	if (sprite.wall == NULL)
		map_error("Couldn't load the 'wall' XPM.");
	sprite.ground = mlx_xpm_file_to_image(mlx, "../sprites/ground.xpm", &width,
			&height);
	if (sprite.ground == NULL)
		map_error("Couldn't load the 'ground' XPM.");
	return (sprite);
}

void	put_sprite_on_screen(t_so_long *game, int height, int width)
{
	if (height < 0 || height >= game->map->height || width < 0
		|| width >= game->map->width)
		return ;
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
