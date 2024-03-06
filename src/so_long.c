/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:01:49 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/06 01:28:06 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	create_game_window(t_so_long *game, int height, int width)
{
	if (game->mlx == NULL)
		return ;
	game->window = mlx_new_window(game->mlx, height * 80, width * 80,
			"kpourcel - So_long");
	if (game->window == NULL)
	{
		free(game->mlx);
		return ;
	}
}
