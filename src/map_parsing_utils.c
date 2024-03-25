/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:18:09 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/25 14:24:57 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Function used to view the path taken by my dfs.
void	print_map(t_so_long *game, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (map[i][j] == '0')
				ft_printf("\x1b[92m");
			if (map[i][j] == '1')
				ft_printf("\x1b[91m");
			ft_printf("%c", map[i][j]);
			if (map[i][j] == '1' || map[i][j] == '0')
				ft_printf("\x1b[0m");
		}
		ft_printf("\n");
	}
}
