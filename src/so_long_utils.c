/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:41:08 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/04 17:06:50 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	ft_size_line(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	check_ber_format(char *str)
{
	size_t	size;

	size = ft_strlen(str - 1);
	if (str[size] == 'r' && str[size - 1] == 'e' && str[size - 2] == 'b'
		&& str[size - 3] == '.')
	{
		map_error("Please use a map with the .ber extension");
		return (1);
	}
	return (0);
}

void	map_error(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(1);
}

void	free_game(t_so_long *game)
{
	if (!game)
		return ;
	if (game->sprite.player)
		mlx_destroy_image(game->mlx, game->sprite.player);
	if (game->sprite.wall)
		mlx_destroy_image(game->mlx, game->sprite.wall);
	if (game->sprite.ground)
		mlx_destroy_image(game->mlx, game->sprite.ground);
	if (game->sprite.collectible)
		mlx_destroy_image(game->mlx, game->sprite.collectible);
	if (game->sprite.exit)
		mlx_destroy_image(game->mlx, game->sprite.exit);
	if (game->mlx && game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	if (game)
		free(game);
}

char	*ft_strjoin_n(char *s1, char *s2)
{
	size_t	i;
	size_t	k;
	char	*s3;

	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k])
	{
		s3[i + k] = s2[k];
		k++;
	}
	s3[i + k] = '\n';
	s3[i + k + 1] = '\0';
	free(s1);
	free(s2);
	return (s3);
}
