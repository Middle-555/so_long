/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:04:39 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/11 16:31:14 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Verify that we have a playable map (rectangular + not empty).
// Give the dimension of the map.
int	map_parser(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		map_error("Can't find the map. Try to compile with the map.ber");
	ft_printf("Opened map file successfully.\n");
	map->height = 0;
	map->width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_printf("Read line: %s\n", line);
		map->height++;
		if (map->height == 1)
			map->width = ft_size_line(line);
		else if (ft_size_line(line) != (size_t)map->width)
			map_error("The map needs to be rectangular.");
		free(line);
	}
	ft_printf("Finished reading map.\n");
	close(fd);
	if (map->height == 0)
		map_error("The map is empty. Please provide a valid map.");
	return (0);
}

/*
// Fill our tab with the map infos.
int	tab_filler(t_map *map, char **map_data)
{
	char	**data_ptr;
	int		i;

	data_ptr = map_data;
	map->tab = (char **)malloc(sizeof(char *) * (map->height));
	if (!map->tab)
		return (0);
	i = 0;
	while (*data_ptr && i < map->height)
	{
		map->tab[i] = (char *)malloc(sizeof(char) * (map->width + 1));
		if (!map->tab[i])
			return (1);
		ft_strlcpy(map->tab[i], *data_ptr, map->width + 1);
			// On copie map->width + 1 pour inclure le caractère nul à la fin.
		data_ptr++;
		i++;
	}
	return (0);
}

*/
/*
void	alloc_map(t_so_long *game)
{
	int	i;

	i = 0;
	game->map.tab = (char **)malloc(sizeof(char *) * (game->map.height + 1));
	if (game->map.tab == NULL)
		return ;
	while (i < game->map.height)
	{
		game->map.tab[i] = (char *)malloc(sizeof(char) * (game->map.width + 1));
		if (game->map.tab[i] == NULL)
			return ;
		i++;
	}
	game->map.tab[game->map.height] = NULL;
}

void	fill_map(t_so_long *game, const char *path)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_strlcpy(game->map.tab[i], line, game->map.width + 1);
		free(line);
		i++;
	}
	close(fd);
}

// Check that the map is surrounded by walls

int	check_wall_error(t_map *map)
{
	char	*first_row;
	char	*last_row;
	char	**current_row;
	char	**end_row;

	first_row = map->tab[0];
	last_row = map->tab[map->height - 1];
	current_row = map->tab + 1;
	end_row = map->tab + map->height - 1;
	while (*first_row && *last_row)
	{
		if (*first_row != WALL || *last_row != WALL)
			return (1);
		first_row++;
		last_row++;
	}
	while (current_row < end_row)
	{
		if (**current_row != WALL || *(*current_row + map->width - 1) != WALL)
			return (1);
		current_row++;
	}
	return (0);
}

void read_map(t_so_long *game, const char *file)
{
    int fd;
    char *line;

    game->map.width = 0;
    game->map.height = 0;
    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        // Gestion de l'erreur d'ouverture du fichier
        // Vous pouvez ajouter ici une logique pour gérer l'erreur
        return;
    }
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        if (game->map.height == 0)
        {
            // Calcul de la largeur de la carte
            game->map.width = ft_strlen(line);
        }
        game->map.height++;
        free(line);
    }
    close(fd);
}
*/