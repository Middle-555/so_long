/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:04:39 by kpourcel          #+#    #+#             */
/*   Updated: 2024/02/29 16:09:06 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Verify that we have a playable map (rectangular + not empty) + give the dimension of the map.
int		map_parser(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map ->path, O_RDONLY);
	if (fd < 0)
		map_error("Can't find the map. Try to compile with the map.ber");
	map ->height = 0;
	map ->width = 0;
	line = get_next_line(fd);
	while (line)
	{
		map -> height++;
		if (map -> height == 1)
			map ->width = ft_size_line(line);
		if (ft_size_line(line) != map-> width)
			map_error("The map need to be rectangular.");
		line = get_next_line(fd);
	}
	close (fd);
	free (line);
	if (map ->height == 0)
		map_error("The map is empty. Please put a valid map.");
	return (1);
}


/*int		tab_filler(t_map *map, char **map_data)
{
	map->tab = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->tab)
		return (0);
	char **data_ptr = map_data;
	char **tab_ptr = map->tab;
	while (*data_ptr)
	{
		*tab_ptr = (char *)malloc(sizeof(char) * (map->width + 1));
		if (!*tab_ptr)
			return (0);
		strncpy(*tab_ptr, *data_ptr, map->width);
		(*tab_ptr)[map->width] = '\0';
        	data_ptr++;
		tab_ptr++;
	}
	*tab_ptr = NULL;
    	return (1);
}*/

