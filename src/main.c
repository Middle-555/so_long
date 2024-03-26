/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:42:03 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/26 14:51:21 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_infos(t_so_long *game)
{
	check_ber_format(game->map.path, game);
	map_stock(game);
	not_rectangular(game);
	wall_checker(game);
	not_enough_exit(game);
	check_player(game);
	other_caracter(game);
	check_last_line(game);
	not_enough_collectible(game);
}

void	parsing(t_so_long *game)
{
	map_parser_stock(game);
	init_test(game);
	dfs(game->player_pos.p_position, game->map.maptest, game);
	if (game->map.collectible_find != game->count_collectible
		|| game->map.player_find != 1
		|| game->map.exit_find != 1)
		map_error_parser("Cant reach exit or all collectible", game);
	free_tab_maptest(game);
	map_parser_stock_exit_1(game);
	init_test(game);
	dfs(game->player_pos.p_position, game->map.maptest, game);
	if (game->map.collectible_find != game->count_collectible
		|| game->map.player_find != 1)
		map_error_parser("Exit is blocking the way", game);
}

int	main(int argc, char **argv)
{
	t_so_long			game;

	if (argc != 2)
	{
		ft_printf("Usage: ./so_long <map_file.ber>\n");
		return (1);
	}
	game.map.path = argv[1];
	check_map_infos(&game);
	parsing(&game);
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
