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

int	check_ber_format(char *str, t_so_long *game)
{
	int	size;

	size = ft_strlen(game->map.path) - 1;
	if (str[size] == 'r' && str[size - 1] == 'e' && str[size - 2] == 'b'
		&& str[size - 3] == '.')
		return (0);
	else
	{
		map_error_standard("Please use a game with the .ber extension");
		return (1);
	}
	return (0);
}

void	map_error(char *str, t_so_long *game)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	free_tab(game);
	exit(0);
}

void	map_error_parser(char *str, t_so_long *game)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	free_tab(game);
	free_tab_maptest(game);
	exit(0);
}

void	map_error_standard(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(0);
}

int	ft_total_len(char *path)
{
	int		fd;
	int		i;
	char	c;

	c = 'c';
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, &c, 1) != '\0')
	{
		i++;
	}
	close (fd);
	return (i);
}
