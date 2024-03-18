/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:01:49 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/18 18:45:49 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_stock(t_so_long *game)
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
	game->map.tab = ft_split(game->map.line, '\n');
	free(game->map.line);
	close(game->map.fd);
	return (0);
}

void	create_game_window(t_so_long *game)
{
	if (game->mlx == NULL)
		return ;
	game->window = mlx_new_window(game->mlx, game->map.width * 96, game->map.height * 96,
			"So_long");
	if (game->window == NULL)
	{
		free(game->mlx);
		return ;
	}
	//mlx_loop(game->mlx);
}
