/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:01:46 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/15 14:59:23 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL '1'
# define GROUND '0'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECT 'C'

# include "../libraries/ft_printf/include/ft_printf.h"
# include "../libraries/get_next_line/include/get_next_line.h"
# include "../libraries/libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# ifdef __linux__
#  include <X11/X.h>
#  include <X11/keysym.h>
# elif __APPLE__
#  include <ApplicationServices/ApplicationServices.h>
# endif

// Keycode definitions
# define KEY_ESC 65307
# define KEY_Z 122
# define KEY_Q 113
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361

// Window size
//# define WINDOWS_WIDTH 500
//# define WINDOWS_HEIGHT 500

typedef struct s_position
{
	int					x;
	int					y;
}						t_position;

typedef struct s_player_position
{
	t_position			p_position;
	void				*player;
}						t_player_position;

typedef struct s_map
{
	char				*path;
	char				**tab;
	char				*line;
	int					fd;
	int					height;
	int					width;
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
	t_map				*map;
	void				*mlx;
	void				*window;
	void				*img;
	int					count_step;
	int					count_player;
	int					count_collectible;
	int					count_exit;
}						t_so_long;

// Function prototypes
int						input_handler(int keycode, t_so_long *game);
int						player_move_up(t_so_long *game, t_map *map);
int						player_move_down(t_so_long *game, t_map *map);
int						player_move_right(t_so_long *game, t_map *map);
int						player_move_left(t_so_long *game, t_map *man);
int						map_parser(t_map *map);
void					fill_map(t_so_long *game, const char *path);
void					alloc_map(t_so_long *game);
int						check_wall_error(t_map *map);
void					create_game_window(t_so_long *game, t_map *map,
							t_sprites *sprites);
size_t					ft_size_line(char *str);
int						check_ber_format(char *str);
void					map_error(char *str);
char					*ft_strjoin_n(char *s1, char *s2);
void					init_sprites(t_so_long *game, t_sprites *sprites);
void					put_sprite_on_screen(t_so_long *game, t_map *map,
							t_sprites *sprites);
int						ft_total_len(char *path);
int						map_stock(t_map *map);
void					free_tab(t_map *map);
int						not_rectangular(t_map *map);
int						not_enough_collectible(t_map *map);
int						not_enough_exit(t_map *map);
int						check_player(t_map *map);
int						wall_checker(t_map *map);
int						check_last_line(t_map *map);

#endif // SO_LONG_H//