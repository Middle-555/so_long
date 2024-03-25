/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:01:49 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/25 17:45:16 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Stock the real map.
int	map_stock(t_so_long *game)
{
	int		len;
	int		i;
	char	c;

	i = 0;
	c = 'c';
	game->map.fd = open(game->map.path, O_RDONLY);
	if (game->map.fd == -1)
	{
		map_error_standard("please put a real .ber");
	}
	len = ft_total_len(game->map.path);
	game->map.line = malloc(sizeof(char) * (len + 1));
	if (!game->map.line)
		return (0);
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

// Create game windows with my dimensions.
void	create_game_window(t_so_long *game)
{
	if (game->mlx == NULL)
		return ;
	game->window = mlx_new_window(game->mlx, game->map.width * 96,
			game->map.height * 96, "So_long");
	if (game->window == NULL)
	{
		free(game->mlx);
		return ;
	}
}

// Show my map.
void	aff_tab(t_so_long *game)
{
	int	i;

	i = 0;
	while (game->map.tab[i])
	{
		ft_printf("%s\n", game->map.tab[i]);
		i++;
	}
	ft_printf("\n");
}

// show the copy of my map.
void	aff_1tab(t_so_long *game)
{
	int	i;

	i = 0;
	while (game->map.maptest[i])
	{
		ft_printf("%s\n", game->map.maptest[i]);
		i++;
	}
	ft_printf("\n");
}

// Print the success and exit without leaks.
void	game_success(t_so_long *game)
{
	ft_printf("%s \n", "Congratulation you finished the game.");
	free_game(game);
}
