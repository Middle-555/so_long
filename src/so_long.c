/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:01:49 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/14 17:39:12 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_stock(t_map *map)
{
	int		len;
	int		i;
	char	c;

	i = 0;
	c = 'c';
	len = ft_total_len(map->path);
	map->line = malloc(sizeof(char) * (len + 1));
	if (!map->line)
		return (0);
	map->fd = open(map->path, O_RDONLY);
	while (read(map->fd, &c, 1) != '\0')
	{
		map->line[i] = c;
		i++;
	}
	map->line[i] = '\0';
	map->tab = ft_split(map->line, '\n');
	free(map->line);
	close(map->fd);
	return (0);
}

void	create_game_window(t_so_long *game, t_map *map, t_sprites *sprites)
{
	if (game->mlx == NULL)
		return ;
	game->window = mlx_new_window(game->mlx, map->height * 500, map->width *500,
			"kpourcel - So_long");
	if (game->window == NULL)
	{
		free(game->mlx);
		return ;
	}
	put_sprite_on_screen(game, map, sprites);
	//mlx_loop(game->mlx);
}
