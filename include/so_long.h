/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:01:46 by kpourcel          #+#    #+#             */
/*   Updated: 2024/02/29 15:58:46 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WALL '1'
# define FLOOR '0'
# define START 'P'
# define EXIT 'E'
# define COLLECT 'C'

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libraries/get_next_line/include/get_next_line.h"
# include "../libraries/ft_printf/include/ft_printf.h"
# include "../libraries/libft/include/libft.h"


typedef struct s_map
{
	char	*path;
	int		height;
	int		width;
	int		fd;
}	t_map;

typedef struct s_sprites
{
	void	*player;
	void	*collectible;
	void	*exit;
	void	*ground;
	void	*wall;
}	t_sprites;


typedef struct s_so_long
{
	t_sprites	sprite;
	t_sprites	map;
	void		*mlx;
	void		*win;
	void		*img;

}	t_so_long;

//					input							//
int		input_handler(int keycode, t_so_long so_long);
// 					map_check 						//
void	map_error(char	*str);
int		map_parser(t_map *map);

//					so_long.c						//
int		tab_filler(t_map *map, char **map_data);

// 					utils 							//

size_t	ft_size_line(char *str);
int		check_ber_format(char	*str);

#endif