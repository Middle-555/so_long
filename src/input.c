/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:49:42 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/18 18:40:46 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	input_handler(int keycode, t_so_long *game)
{
	ft_printf("%d \n", keycode);
	if (keycode == KEY_Z || keycode == KEY_UP)
	{
		player_move_up(game);
		ft_printf("Fonction player_move_up appelée\n");
	}
	if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		player_move_down(game);
		ft_printf("Fonction player_down appelée\n");
		ft_printf("%dx\n",  game->player_pos.p_position.x);
		ft_printf("%dy\n",  game->player_pos.p_position.y);
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		player_move_right(game);
		ft_printf("Fonction player move right appelée\n");
	}
	if (keycode == KEY_Q || keycode == KEY_LEFT)
	{
		player_move_left(game);
		ft_printf("Fonction player move left appelée\n");
	}
		
	if (keycode == KEY_ESC)
	{
		ft_printf("Fonction exit appelée\n");
		exit(0);
	}	
		
	return (0);
}
//exit_game(game);