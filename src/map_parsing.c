/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:59:48 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/22 16:19:40 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

t_position	direction_finder(t_position pos, int dir)
{
	if (dir == 0)
		pos.x++;
	if (dir == 1)
		pos.x--;
	if (dir == 2)
		pos.y++;
	if (dir == 3)
		pos.y--;
	return (pos);
}

void	dfs(t_position pos, char **visited, t_so_long *game)
{
	t_position	voisins[4];
	int			i;

	i = -1;
	if (pos.x < 0 || pos.x >= game->map.height || pos.y < 0
		|| pos.y >= game->map.width)
		return ;
	if (game->map.maptest[pos.x][pos.y] == '2' || visited[pos.x][pos.y] == '2')
		return ;
	visited[pos.x][pos.y] = '2';
	if (game->map.maptest[pos.x][pos.y] == EXIT)
		game->map.exit_find++;
	if (game->map.maptest[pos.x][pos.y] == PLAYER)
		game->map.player_find++;
	if (game->map.maptest[pos.x][pos.y] == COLLECT)
		game->map.collectible_find++;
	while (++i < 4)
		voisins[i] = direction_finder(pos, i);
	i = -1;
	while (++i < 4)
		dfs(voisins[i], visited, game);
}
