/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_initialisation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:16:03 by kpourcel          #+#    #+#             */
/*   Updated: 2024/02/29 16:07:58 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_sprites	init_sprites(void *mlx, t_so_long *game)
{
	t_sprites	sprite;
	int			width;
	int			height;

	sprite.player = mlx_xpm_file_to_image(mlx, "sprites/player.xpm",
			&width, &height);
	if (sprite.player == NULL)
		map_error("Couldn't load the player XPM.");
	sprite.exit = mlx_xpm_file_to_image(mlx, "sprites/exit.xpm",
			&width, &height);
	if (sprite.exit == NULL)
		map_error("Couldn't load the exit XPM.");
	sprite.collectible = mlx_xpm_file_to_image(mlx, "sprites/collectible.xpm",
			&width, &height);
	if (sprite.collectible == NULL)
		map_error("Couldn't load the collectible XPM.");
	sprite.wall = mlx_xpm_file_to_image(mlx, "sprites/wall.xpm",
			&width, &height);
	if (sprite.wall == NULL)
		map_error("Couldn't load the wall XPM.");
	sprite.ground = mlx_xpm_file_to_image(mlx, "sprites/ground.xpm",
			&width, &height);
	if (sprite.ground == NULL)
		map_error("Couldn't load the ground XPM.");
	return (sprite);
}
