/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:26:55 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/19 15:44:24 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "../42_Libft/FT_Libft/inc/libft.h"
# include "../42_Libft/FT_Printf/inc/ft_printf.h"
# include "../42_Libft/Get_next_line/inc/get_next_line.h"
# include "../libs/minilibx-linux/mlx.h"
# include "./macros.h"


//===============================================================//
//                          STRUCTURES                           //
//===============================================================//

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collects;
	int		exits;
	int		players;
	char	*map_name;
	t_pos	*player_pos;
}	t_map;

typedef struct s_game
{
	t_map	*map;
	int		moves;
	void	*mlx;
	void	*win;
	t_img	*img;
}	t_game;

//===============================================================//
//                       PARSING FUNCTIONS                       //
//===============================================================//

void	map_name_checker(t_game *game, t_map *map);
int		map_validation(t_game *game, t_map *map);
void	populate_map_grid(t_game *game, t_map *map);
void	check_width_and_set(t_game *game, t_map *map);
int		count_occurs(t_map *map, char c);
void	check_chars(t_game *game, t_map *map);
void	check_invalid_chars(t_game *game, t_map *map);

//===============================================================//
//                        UTILS FUNCTIONS                        //
//===============================================================//

void	ft_print_error(t_game *game, char *str);
void	set_map_height(t_game *game, t_map *map);

//===============================================================//
//                      INIT STRUCTS FUNCS                       //
//===============================================================//

t_game	*init_game_struct(void);
t_map	*init_map_struct(t_game *game);
t_pos	*init_pos_struct(t_game *game);

//===============================================================//
//                      RENDER IMAGE FUNCS                       //
//===============================================================//

void	render_win(t_game *game, t_map *map);


void	free_struct(t_game *game);
void	free_grid(t_map *map);

#endif
