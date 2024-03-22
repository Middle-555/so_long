#include "../include/so_long.h"

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

int	exit_game(t_so_long *game)
{
	free_game(game);
	return(0);
}
