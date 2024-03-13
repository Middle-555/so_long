/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:48:17 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/13 16:48:12 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	map.path = argv[1];
	if (argc != 2)
	{
		ft_printf("Usage: ./so_short <map_file.ber>\n");
		return (1);
	}
	map_stock(&map);
	not_enough_exit(&map);
	check_player(&map);
	not_enough_collectible(&map);
	not_rectangular(&map);
	wall_checker(&map);
	check_last_line(&map);
}

