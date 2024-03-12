/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:48:17 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/12 16:20:55 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		ft_printf("Usage: ./so_short <map_file.ber>\n");
		return (1);
	}
	map.path = argv[1];
	if (map_parser(&map) != 0)
	{
		ft_printf("Error: Invalid map\n");
		return (1);
	}
	// Ajoute ici le code pour le reste du jeu
	return (0);
}
