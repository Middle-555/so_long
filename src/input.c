/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:49:42 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/15 14:46:51 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	input_handler(int keycode, t_so_long *game)
{
	if (keycode == KEY_Z || keycode == KEY_UP)
		player_move_up(&game->player_pos, game);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		player_move_down(&game->player_pos, game);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		player_move_right(&game->player_pos, game);
	if (keycode == KEY_Q || keycode == KEY_LEFT)
		player_move_left(&game->player_pos, game);
	//if (keycode == KEY_ESC)
		//exit_game(game);
}
