/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_initialisation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:16:03 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/14 17:48:42 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_sprites(t_so_long *game, t_sprites *sprites)
{
	int	size;

	size = 32;
	sprites->player = mlx_xpm_file_to_image(game->mlx, "./sprites/player.xpm",
			&size, &size);
	if (sprites->player == NULL)
		map_error("Couldn't load the 'player' XPM.");
	sprites->exit = mlx_xpm_file_to_image(game->mlx, "./sprites/exit.xpm",
			&size, &size);
	if (sprites->exit == NULL)
		map_error("Couldn't load the 'exit' XPM.");
	sprites->collectible = mlx_xpm_file_to_image(game->mlx,
			"./sprites/collectible.xpm", &size, &size);
	if (sprites->collectible == NULL)
		map_error("Couldn't load the 'collectible' XPM.");
	sprites->wall = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm",
			&size, &size);
	if (sprites->wall == NULL)
		map_error("Couldn't load the 'wall' XPM.");
	sprites->ground = mlx_xpm_file_to_image(game->mlx, "./sprites/ground.xpm",
			&size, &size);
	if (sprites->ground == NULL)
		map_error("Couldn't load the 'ground' XPM.");
}

void	put_sprite_on_screen(t_so_long *game, t_map *map, t_sprites *sprites)
{
	int	i;
	int	j;
	//int	width;
	//int	height;

	i = 0;

	//game->sprite.player = (t_img*)malloc(sizeof(t_img));
	//game->sprite.player.img = mlx_xpm_file_to_image(game->mlx, "./sprites/player.xpm", &width, &height);
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			// if (j < 0 || height >= game->map->height || i < 0
				//|| width >= game->map->width)
			// return ;
			if (map->tab[i][j] == WALL)
				mlx_put_image_to_window(game->mlx, game->window, sprites->wall,
					j * 32, i * 32);
			else if (map->tab[i][j] == COLLECT)
				mlx_put_image_to_window(game->mlx, game->window,
					sprites->collectible, j * 32, i * 32);
			else if (map->tab[i][j] == EXIT)
				mlx_put_image_to_window(game->mlx, game->window, sprites->exit,
					j * 32, i * 32);
			else if (map->tab[i][j] == PLAYER)
				mlx_put_image_to_window(game->mlx, game->window,
					sprites->player, j * 32, i * 32);
			else if (map->tab[i][j] == GROUND)
				mlx_put_image_to_window(game->mlx, game->window,
					sprites->ground, j * 32, i * 32);
			j++;
		}
		i++;
	}
}
