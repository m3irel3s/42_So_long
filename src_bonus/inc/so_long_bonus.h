/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:26:55 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/02 15:17:01 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../../42_Libft/FT_Libft/inc/libft.h"
# include "../../42_Libft/FT_Printf/inc/ft_printf.h"
# include "../../42_Libft/Get_next_line/inc/get_next_line.h"
# include "../../libs/minilibx-linux/mlx.h"
# include "./macros_bonus.h"

# include <X11/X.h>
# include <X11/keysym.h>

//===============================================================//
//                          STRUCTURES                           //
//===============================================================//

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	char	**grid;
	char	**grid_copy;
	int		width;
	int		height;
	int		collects;
	int		exits;
	int		players;
	char	*map_name;
	t_pos	player_pos;
	t_pos	exit_pos;
}	t_map;

typedef struct s_game
{
	t_map	*map;
	int		moves;
	void	*mlx;
	void	*win;

	void	*wall;
	void	*floor;
	void	*collect;
	void	*p_right;
	void	*p_left;
	void	*p_back;
	void	*p_front;
	void	*opened_exit;
	void	*closed_exit;
	void	*hud_moves;
	void	*zombie;
}	t_game;

//===============================================================//
//                       PARSING FUNCTIONS                       //
//===============================================================//

void	map_name_checker(t_game *game, t_map *map);
int		map_validation(t_game *game, t_map *map);
void	populate_map_grid(t_game *game, t_map *map);
void	check_width_and_set(t_game *game, t_map *map);
int		count_occurs(t_map *map, char **grid, char c);
void	check_chars(t_game *game, t_map *map);
void	check_invalid_chars(t_game *game, t_map *map);
void	check_walls(t_game *game, t_map *map);

//===============================================================//
//                        UTILS FUNCTIONS                        //
//===============================================================//

void	set_map_height(t_game *game, t_map *map);
void	set_player_position(t_map *map);
void	set_exit_position(t_map *map);
void	dup_grid(t_game *game, t_map *map);

//===============================================================//
//                      INIT STRUCTS FUNCS                       //
//===============================================================//

t_game	*init_game_struct(void);
t_map	*init_map_struct(t_game *game);

//===============================================================//
//                      RENDER IMAGE FUNCS                       //
//===============================================================//

void	preload_images(t_game *game);
void	render_win(t_game *game, t_map *map);
void	render_map(t_game *game, t_map *map);
void	replace_img(t_game *game, int x, int y, void *new_img);
void	render_moves(t_game *game, t_map *map);
void	print_current_img(t_game *game, t_map *map, int i, int j);

//===============================================================//
//                       HANDLE KEY_PRESS                        //
//===============================================================//

int		handle_key_press(int keycode, t_game *game);
int		close_window(t_game *game);

//===============================================================//
//                            MOVES                              //
//===============================================================//

void	move_player_up(t_game *game, t_map *map);
void	move_player_down(t_game *game, t_map *map);
void	move_player_left(t_game *game, t_map *map);
void	move_player_right(t_game *game, t_map *map);
void	update_position(t_game *game, int x, int y, void *new_img);
void	check_exit(t_game *game, t_map *map, int x, int y);
void	update_collects(t_map *map, int x, int y);
int		is_valid_move(t_map *map, int x, int y);
void	check_zombie(t_game *game, t_map *map, int x, int y);

//===============================================================//
//                     VALID PATH CHECKER                        //
//===============================================================//

void	check_valid_path(t_game *game, t_map *map);
void	flood_fill(char **copy, int x, int y);

//===============================================================//
//                  CONTROL ERRORS AND FREES                     //
//===============================================================//

void	exit_program(t_game *game, char *str);
void	free_struct(t_game *game);
void	free_grid(t_map *map, char **grid);
void	free_images(t_game *game);

#endif