/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:04:39 by kpourcel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/20 00:37:27 by kpourcel         ###   ########.fr       */
=======
/*   Updated: 2024/03/19 18:50:52 by kpourcel         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Check is the map is rectangular.
int	not_rectangular(t_so_long *game)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(game->map.tab[i]);
	while (game->map.tab[i])
	{
		if (len != ft_strlen(game->map.tab[i]))
			map_error("The map need to be rectangular.");
		i++;
	}
	game->map.width = len;
	game->map.height = i;
	ft_printf("%d  w\n ", game->map.width);
	ft_printf("%d  h\n ", game->map.height);
	return (0);
}

// Check if there is enough collectible to play the game.
int	not_enough_collectible(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	game->count_collectible = 0;
	while (game->map.tab[i])
	{
		j = 0;
		while (game->map.tab[i][j])
		{
			if (game->map.tab[i][j] == COLLECT)
				game->count_collectible++;
			j++;
		}
		i++;
	}
	if (game->count_collectible < 1)
		map_error("Please put at least 1 collectible");
	return (0);
}

// Check if there is 1 exit.
int	not_enough_exit(t_so_long *game)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while (game->map.tab[i])
	{
		j = 0;
		while (game->map.tab[i][j])
		{
			if (game->map.tab[i][j] == EXIT)
			{
<<<<<<< HEAD
				exit++;
				game->end.x_end = i;
				game->end.y_end = j;
				ft_printf("%d y test\n", i);
                		ft_printf("%d x  test\n", j);
                		ft_printf("%d x \n", game->end.x_end);
                		ft_printf("%d y \n", game->end.y_end);
=======
				//game->end.x = i;
				//game->end.y = j;
				//ft_printf("%d y \n", i);
				//ft_printf("%d x \n", j);
				//ft_printf("%d x \n", game->end.x);
				//ft_printf("%d y \n", game->end.y);		
				exit++;
>>>>>>> main
			}
			j++;
		}
		i++;
	}
	if (exit != 1)
		map_error("Please put 1 exit.");
	return (0);
}

// Check if there is 
int	check_player(t_so_long *game)
{
	int			i;
	int			j;
	int			player_count;

	i = 0;
	player_count = 0;
	while (game->map.tab[i])
	{
		j = 0;
		while (game->map.tab[i][j])
		{
			if (game->map.tab[i][j] == PLAYER)
			{
				player_count++;
				game->player_pos.p_position.y = i;
				game->player_pos.p_position.x = j;
			}
			j++;
		}
		i++;
	}
	if (player_count != 1)
		map_error("Please put only 1 player.");
	return (0);
}

int	wall_checker(t_so_long *game)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(game->map.tab[i]);
	while (game->map.tab[i])
	{
		j = 0;
		while (game->map.tab[0][j])
		{
			if (game->map.tab[0][j] != WALL)
				map_error("need wall.");
			j++;
		}
		if (game->map.tab[i][0] != WALL && game->map.tab[i][len] != WALL)
			map_error("Need wall.");
		i++;
	}
	return (0);
}
