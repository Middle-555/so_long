/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:59:48 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/25 14:28:35 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Copy of our first map we use this one with the dfs.
int	map_parser_stock(t_so_long *game)
{
	int		len;
	int		i;
	char	c;

	i = 0;
	c = 'c';
	len = ft_total_len(game->map.path);
	game->map.line = malloc(sizeof(char) * (len + 1));
	if (!game->map.line)
		return (0);
	game->map.fd = open(game->map.path, O_RDONLY);
	while (read(game->map.fd, &c, 1) != '\0')
	{
		game->map.line[i] = c;
		i++;
	}
	game->map.line[i] = '\0';
	game->map.maptest = ft_split(game->map.line, '\n');
	free(game->map.line);
	close(game->map.fd);
	return (0);
}

// Copy of our map except that we change our exit with a '1'.
int	map_parser_stock_exit_1(t_so_long *game)
{
	int		len;
	int		i;
	char	c;

	i = 0;
	c = 'c';
	len = ft_total_len(game->map.path);
	game->map.line = malloc(sizeof(char) * (len + 1));
	if (!game->map.line)
		return (0);
	game->map.fd = open(game->map.path, O_RDONLY);
	while (read(game->map.fd, &c, 1) != '\0')
	{
		if (c == 'E')
			c = '1';
		game->map.line[i] = c;
		i++;
	}
	game->map.line[i] = '\0';
	game->map.maptest = ft_split(game->map.line, '\n');
	free(game->map.line);
	close(game->map.fd);
	return (0);
}

// Different direction for our dfs.
t_position	direction_finder(t_position pos, int dir)
{
	if (dir == 0)
		pos.y++;
	if (dir == 1)
		pos.y--;
	if (dir == 2)
		pos.x--;
	if (dir == 3)
		pos.x++;
	return (pos);
}

// Initiation of value that we want to find with the dfs.
void	init_test(t_so_long *game)
{
	game->map.exit_find = 0;
	game->map.player_find = 0;
	game->map.collectible_find = 0;
}

// The dfs is used to determine whether our map is feasible or not. 
//Replaces each accessible cell with a '1'. 
void	dfs(t_position pos, char **visited, t_so_long *game)
{
	t_position	voisins[4];
	int			i;

	i = -1;
	if (pos.y < 0 || pos.x >= game->map.width || pos.x < 0
		|| pos.y >= game->map.height)
		return ;
	if (game->map.tab[pos.y][pos.x] == '1' || visited[pos.y][pos.x] == '1')
		return ;
	visited[pos.y][pos.x] = '1';
	if (game->map.tab[pos.y][pos.x] == 'P')
		game->map.player_find++;
	if (game->map.tab[pos.y][pos.x] == 'C')
		game->map.collectible_find++;
	if (game->map.tab[pos.y][pos.x] == 'E')
		game->map.exit_find++;
	while (++i < 4)
		voisins[i] = direction_finder(pos, i);
	i = -1;
	while (++i < 4)
		dfs(voisins[i], visited, game);
}
