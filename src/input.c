/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:49:42 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/19 16:18:15 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	input_handler(int keycode, t_so_long *game)
{
	ft_printf("%d \n", keycode);
	if (keycode == KEY_Z || keycode == KEY_UP)
		player_move_up(game);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		player_move_down(game);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		player_move_right(game);
	if (keycode == KEY_Q || keycode == KEY_LEFT)
		player_move_left(game);
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

//exit_game(game);