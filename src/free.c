/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:20:53 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/25 14:23:01 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Free our tab.
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

// free the second tab where we stock our map
// with exit define on '1' and not 'E'/.
void	free_tab_maptest(t_so_long *game)
{
	int	i;

	i = 0;
	if (game && game->map.maptest)
	{
		while (game->map.maptest[i])
		{
			free(game->map.maptest[i]);
			i++;
		}
	}
	free (game->map.maptest);
}

// Free everything.
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
	if (game->map.tab)
		free_tab(game);
	if (game->map.maptest)
		free_tab_maptest(game);
	if (game->mlx)
		free(game->mlx);
	exit (0);
}

// Function needed to exit the game when we click.
int	exit_game(t_so_long *game)
{
	free_game(game);
	return (0);
}
