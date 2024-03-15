/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:04:39 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/15 16:11:41 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	not_rectangular(t_map *map)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(map->tab[i]);
	while (map->tab[i])
	{
		if (len != ft_strlen(map->tab[i]))
			map_error("The map need to be rectangular.");
		i++;
	}
	map->width = len;
	map->height = i;
	return (0);
}

int	not_enough_collectible(t_map *map)
{
	int	i;
	int	j;
	int	collectible;

	i = 0;
	collectible = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (map->tab[i][j] == COLLECT)
				collectible++;
			j++;
		}
		i++;
	}
	if (collectible < 1)
		map_error("Please put at least 1 collectible");
	return (0);
}

int	not_enough_exit(t_map *map)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (map->tab[i][j] == EXIT)
				exit++;
			j++;
		}
		i++;
	}
	if (exit != 1)
		map_error("Please put 1 exit.");
	return (0);
}

int	check_player(t_map *map,t_so_long *game)
{
	int			i;
	int			j;
	int			player_count;

	i = 0;
	player_count = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (map->tab[i][j] == PLAYER)
			{
				player_count++;
				ft_printf("%d\n", i);
				ft_printf("%d\n", j);
				game->player_pos.p_position.y = j;
				game->player_pos.p_position.x = i;
				ft_printf("%d\n", game->player_pos.p_position.y);
				ft_printf("%d\n", game->player_pos.p_position.x);
			}
			j++;
		}
		i++;
	}
	if (player_count != 1)
		map_error("Please put only 1 player.");
	return (0);
}

int	wall_checker(t_map *map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(map->tab[i]);
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[0][j])
		{
			if (map->tab[0][j] != WALL)
				map_error("need wall.");
			j++;
		}
		if (map->tab[i][0] != WALL && map->tab[i][len] != WALL)
			map_error("Need wall.");
		i++;
	}
	return (0);
}
