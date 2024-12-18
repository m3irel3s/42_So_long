/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:01:33 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/18 12:01:34 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

t_game	*init_game_struct(void)
{
	t_game	*game;
	
	game = malloc(sizeof(t_game));
	if (!game)
		free_struct(game);
	M_TRACK;
	game->map = init_map_struct(game);
	game->moves = 0;
	return (game);
}

t_map	*init_map_struct(t_game *game)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		free_struct(game);
	M_TRACK;
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->collects = 0;
	map->exits = 0;
	map->players = 0;
	map->map_name = NULL;
	map->player_pos = init_pos_struct(game);
	return (map);
}

t_pos	*init_pos_struct(t_game *game)
{
	t_pos *position;

	position = malloc(sizeof(t_pos));
	M_TRACK;
	if (!position)
		free_struct(game);
	position->x = 0;
	position->y = 0;
	return (position);
}