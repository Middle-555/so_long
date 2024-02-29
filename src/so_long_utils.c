/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:41:08 by kpourcel          #+#    #+#             */
/*   Updated: 2024/02/29 16:02:53 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	ft_size_line(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != "\n")
		i++;
	return (i);
}

int		check_ber_format(char	*str)
{
	size_t	size;

	size = ft_strlen(str - 1);
	if (str[size] == 'r' && str[size - 1] == 'e' && str[size - 2] == 'b' && str[size - 3] == '.')
	{
		map_error("Please use a map with the .ber extension");
		return (0);
	}
	return (1);
}

void	map_error(char	*str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(1);
}
/* void	free_game(t_so_long *so_long)
{
	if (!so_long)
		return (NULL);
	if (so_long -> sprite.player)
		mlx_destroy_image(so_long -> mlx , so_long -> sprite.player);
	if (so_long -> sprite.wall)
		mlx_destroy_image(so_long -> mlx, so_long -> sprite.wall);
	if (so_long -> sprite.ground)
		mlx_destroy_image(so_long -> mlx, so_long -> sprite.ground);
	if (so_long -> sprite.collectible)
		mlx_destroy_image(so_long -> mlx, so_long -> sprite.collectible);
	if (so_long -> sprite.exit)
		mlx_destroy_image(so_long -> mlx, so_long -> sprite.exit);
	if (so_long -> map)
		free(so_long -> map);
	
}
*/