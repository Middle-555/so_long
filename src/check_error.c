/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:03:01 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/13 16:49:07 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_last_line(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->tab[i])
		i++;
	while (map->tab[i - 1][j])
	{
		if (map->tab[i -1][j] != WALL)
			map_error("Please put wall.");
		j++;
	}
	return (0);
}
