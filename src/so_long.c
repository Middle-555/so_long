/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:01:49 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/14 14:14:20 by kpourcel         ###   ########.fr       */
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

void	create_game_window(t_so_long *game, int height, int width)
{
	if (game->mlx == NULL)
		return ;
	game->window = mlx_new_window(game->mlx, height * 80, width * 80,
			"kpourcel - So_long");
	if (game->window == NULL)
	{
		free(game->mlx);
		return ;
	}
	mlx_loop(game->mlx);
}
