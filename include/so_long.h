/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:01:46 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/05 15:44:27 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WALL '1'
# define GROUND '0'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECT 'C'

# ifdef __linux__
#  include <X11/X.h>
#  include <X11/keysym.h>
# elif __APPLE__
#  include <ApplicationServices/ApplicationServices.h>
# endif

# include "../libraries/ft_printf/include/ft_printf.h"
# include "../libraries/get_next_line/include/get_next_line.h"
# include "../libraries/libft/include/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

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

typedef struct s_position
{
	int					x;
	int					y;
}						t_position;

typedef struct s_player_position
{
	t_position			p_position;
	t_position			start_position;
	void				*player;
}						t_player_position;

typedef struct s_map
{
	char				*path;
	char				**tab;
	char				*map;
	int					height;
	int					width;
	int					fd;
}						t_map;

typedef struct s_sprites
{
	void				*player;
	void				*collectible;
	void				*exit;
	void				*ground;
	void				*wall;
}						t_sprites;

typedef struct s_so_long
{
	t_player_position	player_pos;
	t_sprites			sprite;
	t_map				map;
	void				*mlx;
	void				*window;
	void				*img;
	int					count_step;
	int					count_player;
	int					counter_collectible;
	int					count_exit;
}						t_so_long;

// Check_error
//
// Input
int						input_handler(int keycode, t_so_long *game);
// Move.c
int						player_move_up(t_so_long *game);
int						player_move_down(t_so_long *game);
int						player_right(t_so_long *game);
int						player_left(t_so_long *game);
// Map_error
int						map_parser(t_map *map);
int						tab_filler(t_map *map, char **map_data);
int						check_wall_error(t_map *map);
// So_long.c
// So_long_utils.c
size_t					ft_size_line(char *str);
int						check_ber_format(char *str);
void					map_error(char *str);
void					free_game(t_so_long *game);
void					create_game_window(t_so_long *game, int height,
							int width);
// Sprites_initialisation.c
t_sprites				init_sprites(void *mlx, t_so_long *game);
void					put_sprite_on_screen(t_so_long *game, int height,
							int width);

// Main
int						main(int argc, char **argv);

#endif