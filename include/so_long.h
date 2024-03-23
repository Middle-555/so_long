/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:01:46 by kpourcel          #+#    #+#             */
/*   Updated: 2024/03/23 10:42:29 by kpourcel         ###   ########.fr       */
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
	int					y;
	int					x;
	int					x_end;
	int					y_end;
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
	char				**maptest;
	char				*line;
	int					fd;
	int					height;
	int					width;
	int					collectible_find;
	int					exit_find;
	int					player_find;
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
	t_position			end;
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
int						player_move_up(t_so_long *game);
int						player_move_down(t_so_long *game);
int						player_move_right(t_so_long *game);
int						player_move_left(t_so_long *game);
int						map_parser(t_so_long *game);
void					fill_map(t_so_long *game, const char *path);
void					alloc_map(t_so_long *game);
int						check_wall_error(t_so_long *game);
void					create_game_window(t_so_long *game);
size_t					ft_size_line(char *str);
int						check_ber_format(char *str, t_so_long *game);
void					map_error(char *str, t_so_long *game);
char					*ft_strjoin_n(char *s1, char *s2);
void					init_sprites(t_so_long *game);
void					put_sprite_on_screen(t_so_long *game);
int						ft_total_len(char *path);
int						map_stock(t_so_long *game);
void					free_tab(t_so_long *game);
int						not_rectangular(t_so_long *game);
int						not_enough_collectible(t_so_long *game);
int						not_enough_exit(t_so_long *game);
int						check_player(t_so_long *game);
int						wall_checker(t_so_long *game);
int						check_last_line(t_so_long *game);
void					aff_tab(t_so_long *game);
void					refresh(t_so_long *game, int i, int j);
int						move_ok(t_so_long *game, int new_x, int new_y);
void					game_success(t_so_long *game);
void					free_game(t_so_long *game);
int						map_parser_stock(t_so_long *game);
int						other_caracter(t_so_long *game);
int						exit_game(t_so_long *game);
t_position				direction_finder(t_position pos, int dir);
void					dfs(t_position pos, char **visited, t_so_long *game);
void	aff_1tab(t_so_long *game);
void	init_test(t_so_long *game);
void	free_tab_maptest(t_so_long *game);
void	print_map(t_so_long *game, char **map);
void	map_error_parser(char *str, t_so_long *game);
void	map_error_standard(char *str);
void	dfs2(t_position pos, char **visited, t_so_long *game);
int	map_parser_stock_exit_1(t_so_long *game);
#endif // SO_LONG_H//