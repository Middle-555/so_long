/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:42:03 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/18 15:20:48 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	exit_game(t_so_long *game)
{
	(void)game; 
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map				map;
	t_so_long			game;
	t_sprites			sprites;

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
	check_player(&map, &game);
	not_enough_collectible(&map);
	not_rectangular(&map);
	wall_checker(&map);
	check_last_line(&map);
	init_sprites(&game, &sprites);
	create_game_window(&game, &map);
	put_sprite_on_screen(&game, &map, &sprites);
	mlx_hook(game.window, 2, 1 << 0, &input_handler, &game);
	mlx_hook(game.window, 2, 1L << 0, &input_handler, &game);
	mlx_loop(game.mlx);
	mlx_loop_hook(game.mlx, &input_handler, &game);
	mlx_hook(game.window, 17, 0, &exit_game, NULL);
	mlx_loop(game.mlx);
	//mlx_hook(game.window, 2, 1 << 0, &input_handler, &game);
	//mlx_hook(game.window, 2, 1L << 0, &input_handler, &game);
}
