/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:49:42 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/15 19:28:31 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	input_handler(int keycode, t_so_long *game, t_map *map)
{
	if (keycode == KEY_Z || keycode == KEY_UP)
		player_move_up(game, map);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		player_move_down(game, map);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		player_move_right(game, map);
	if (keycode == KEY_Q || keycode == KEY_LEFT)
		player_move_left(game, map);
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
//exit_game(game);