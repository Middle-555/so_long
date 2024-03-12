/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:04:39 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/12 19:28:28 by kpourcel         ###   ########.fr       */
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

int	not_rectangular(t_map *map)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen(map->tab[i]);
	while (map->tab[i])
	{
		if (len != ft_strlen(map->tab[i]))
			map_error("The map need to have the same height and width.");
		i++;
	}
	if (i != len)
		map_error("The map need to have the same height and width.");
	return (0);
}
