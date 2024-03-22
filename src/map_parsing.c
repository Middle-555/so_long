/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:59:48 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/22 19:14:03 by kpourcel         ###   ########.fr       */
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
		pos.y++;
	if (dir == 1)
		pos.y--;
	if (dir == 2)
		pos.x--;
	if (dir == 3)
		pos.x++;
	return (pos);
}
void	init_test(t_so_long *game)
{

	game->map.exit_find = 0;
	game->map.player_find = 0;
	game->map.collectible_find = 0;
}

void	print_map(t_so_long *game, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (map[i][j] == '0')
				ft_printf("\x1b[92m");
			if (map[i][j] == '1')
				ft_printf("\x1b[91m");
			ft_printf("%c", map[i][j]);
			if (map[i][j] == '1' || map[i][j] == '0')
				ft_printf("\x1b[0m");
		}
		ft_printf("\n");
	}
}


void	dfs(t_position pos, char **visited, t_so_long *game)
{
	t_position	voisins[4];
	int			i;

	i = -1;
	if (pos.y < 0 || pos.y >= game->map.width || pos.x < 0
		|| pos.x >= game->map.height)
		return ;
	if (game->map.tab[pos.x][pos.y] == '1' || visited[pos.x][pos.y] == '1')
		return ;
	visited[pos.x][pos.y] = '1';
	if (game->map.tab[pos.x][pos.y] == 'P')
		game->map.player_find++;
	if (game->map.tab[pos.x][pos.y] == 'C')
		game->map.collectible_find++;
	if (game->map.tab[pos.x][pos.y] == 'E')
		game->map.exit_find++;
	//visited[pos.y][pos.x] = '1';
	while (++i < 4)
		voisins[i] = direction_finder(pos, i);
	i = -1;
	while (++i < 4)
		dfs(voisins[i], visited, game);
}
