/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:01:46 by kpourcel          #+#    #+#             */
/*   Updated: 2024/02/29 18:44:29 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WALL '1'
# define FLOOR '0'
# define START 'P'
# define EXIT 'E'
# define COLLECT 'C'

# ifdef __linux__
#  include <X11/keysym.h>
#  include <X11/X.h>
# elif __APPLE__
#  include <ApplicationServices/ApplicationServices.h>
# endif

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libraries/get_next_line/include/get_next_line.h"
# include "../libraries/ft_printf/include/ft_printf.h"
# include "../libraries/libft/include/libft.h"

// keycode
# define KEY_ESC 65307
# define KEY_Z 122
# define KEY_Q 113
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361

// Windows size
# define WINDOWS_WIDTH 500
# define WINDOWS_HEIGHT 500

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