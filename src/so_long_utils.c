/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:41:08 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/04 17:06:50 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_ber_format(char *str)
{
	size_t	size;

	size = ft_strlen(str - 1);
	if (str[size] == 'r' && str[size - 1] == 'e' && str[size - 2] == 'b'
		&& str[size - 3] == '.')
	{
		map_error("Please use a game with the .ber extension");
		return (1);
	}
	return (0);
}

void	map_error(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(1);
}

void	free_tab(t_so_long *game)
{
	int	i;

	i = 0;
	if (game && game->map.tab)
	{
		while (game->map.tab[i])
		{
			free(game->map.tab[i]);
			i++;
		}
	}
	free (game->map.tab);
}

void	free_game(t_so_long *game)
{
	if (!game)
		return ;
	if (game->sprite.player)
		mlx_destroy_image(game->mlx, game->sprite.player);
	if (game->sprite.wall)
		mlx_destroy_image(game->mlx, game->sprite.wall);
	if (game->sprite.ground)
		mlx_destroy_image(game->mlx, game->sprite.ground);
	if (game->sprite.collectible)
		mlx_destroy_image(game->mlx, game->sprite.collectible);
	if (game->sprite.exit)
		mlx_destroy_image(game->mlx, game->sprite.exit);
	if (game->mlx && game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
}
//if (game->game.tab)
		//free_tab(game->game.tab);

int	ft_total_len(char *path)
{
	int		fd;
	int		i;
	char	c;

	c = 'c';
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, &c, 1) != '\0')
	{
		i++;
	}
	close (fd);
	return (i);
}
