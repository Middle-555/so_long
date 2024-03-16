/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_initialisation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:16:03 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/16 12:46:51 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_sprites(t_so_long *game, t_sprites *sprites)
{
	int	size;

	size = 96;
	sprites->player = mlx_xpm_file_to_image(game->mlx, "./sprites/player.xpm",
			&size, &size);
	if (sprites->player == NULL)
		map_error("Couldn't load the 'player' XPM.");
	sprites->exit = mlx_xpm_file_to_image(game->mlx, "./sprites/exittest.xpm",
			&size, &size);
	if (sprites->exit == NULL)
		map_error("Couldn't load the 'exit' XPM.");
	sprites->collectible = mlx_xpm_file_to_image(game->mlx,
			"./sprites/collectibletest.xpm", &size, &size);
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

	i = 0;
	while (map->tab[i])
	{
		printf("i=%d\n", i); // Afficher la valeur de i
		j = 0;
		while (map->tab[i][j])
		{
			if (!map->tab[i])
			{
				printf("map->tab[i] est NULL à l'indice i=%d\n", i);
				break;
			}
			if (map->tab[i][j] == WALL)
				mlx_put_image_to_window(game->mlx, game->window, sprites->wall,
					j * 96, i * 96);
			else if (map->tab[i][j] == COLLECT)
				mlx_put_image_to_window(game->mlx, game->window,
					sprites->collectible, j * 96, i * 96);
			else if (map->tab[i][j] == EXIT)
				mlx_put_image_to_window(game->mlx, game->window, sprites->exit,
					j * 96, i * 96);
			else if (map->tab[i][j] == PLAYER)
				mlx_put_image_to_window(game->mlx, game->window,
					sprites->player, j * 96, i * 96);
			else if (map->tab[i][j] == GROUND)
				mlx_put_image_to_window(game->mlx, game->window,
					sprites->ground, j * 96, i * 96);
			printf("j=%d\n", j); // Afficher la valeur de j
			j++;
		}
		i++;
	}
}
