/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:48:17 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/15 11:48:16 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map		map;
	t_so_long	game;
	t_sprites	sprites;

	map.path = argv[1];
	if (argc != 2)
	{
		ft_printf("Usage: ./so_short <map_file.ber>\n");
		return (1);
	}
	game.window = NULL;
	game.mlx = mlx_init();
	map_stock(&map);
	not_enough_exit(&map);
	check_player(&map);
	not_enough_collectible(&map);
	not_rectangular(&map);
	wall_checker(&map);
	check_last_line(&map);
	//player_move_down(&game, &map);
	//player_move_up(&game, &map);
	//player_move_left(&game, &map);
	//player_move_right(&game, &map);
	//input_handler(,&game);

	init_sprites(&game, &sprites);
	create_game_window(&game, &map, &sprites);
	put_sprite_on_screen(&game, &map, &sprites);
	mlx_loop(game.mlx);
}
