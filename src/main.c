/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:42:03 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/23 11:02:11 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_so_long			game;

	if (argc != 2)
	{
		ft_printf("Usage: ./so_short <map_file.ber>\n");
		return (1);
	}
	game.map.path = argv[1];
	check_ber_format(game.map.path, &game);
	map_stock(&game);
	wall_checker(&game);
	not_rectangular(&game);
	not_enough_exit(&game);
	check_player(&game);
	other_caracter(&game);
	not_enough_collectible(&game);
	aff_tab(&game);
	check_last_line(&game);
	ft_printf("\n");
	//map_parser_stock_exit_1(&game);
	map_parser_stock(&game);
	aff_1tab(&game);
	init_test(&game);
	//map_parser_stock(&game);
	ft_printf("x%d \n", game.player_pos.p_position.x);
	ft_printf("y%d \n", game.player_pos.p_position.y);
	dfs(game.player_pos.p_position, game.map.maptest, &game);
	print_map(&game, game.map.maptest);
	ft_printf("collectible find %d\n", game.map.collectible_find);
	ft_printf("exit find %d\n", game.map.exit_find);
	ft_printf("collectible count%d\n", game.count_collectible);
	if (game.map.collectible_find != game.count_collectible
		|| game.map.player_find != 1
		|| game.map.exit_find != 1)
		map_error_parser("Cant reach exit or all collectible", &game);
	free_tab_maptest(&game);
	map_parser_stock_exit_1(&game);
	aff_1tab(&game);
	init_test(&game);
	dfs2(game.player_pos.p_position, game.map.maptest, &game);
	print_map(&game, game.map.maptest);
	if (game.map.collectible_find != game.count_collectible
		|| game.map.player_find != 1)
		map_error_parser("Exit is blocking the way", &game);
	game.window = NULL;
	game.mlx = mlx_init();
	init_sprites(&game);
	create_game_window(&game);
	put_sprite_on_screen(&game);
	mlx_hook(game.window, 2, 1 << 0, &input_handler, &game);
	mlx_hook(game.window, 17, (1L << 0), &exit_game, &game);
	mlx_loop(game.mlx);
	mlx_loop_hook(game.mlx, &input_handler, &game);
}
