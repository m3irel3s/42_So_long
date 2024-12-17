/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:26:55 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/17 12:47:07 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "../42_Libft/FT_Libft/inc/libft.h"
# include "../42_Libft/FT_Printf/inc/ft_printf.h"
# include "../42_Libft/Get_next_line/inc/get_next_line.h"

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
	char		**grid;
	int			width;
	int			height;
	int			collects;
	int			exits;
	int			players;
	char		*map_name;
	t_pos	*player_pos;
}	t_map;

typedef struct s_game
{
	t_map	*map;
	int		moves;
}	t_game;

//===============================================================//
//                       PARSING FUNCTIONS                       //
//===============================================================//

int		map_name_checker(t_map *map);

//===============================================================//
//                        UTILS FUNCTIONS                        //
//===============================================================//

void	ft_print_error(char *str);

//===============================================================//
//                      INIT STRUCTS FUNCS                       //
//===============================================================//

t_game	*init_game_struct(void);
t_map	*init_map_struct(t_game *game);
t_pos	*init_pos_struct(t_game *game);

void	free_struct(t_game *game);



#endif
