/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:01:33 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/23 22:16:57 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

t_game	*init_game_struct(void)
{
	t_game	*game;
	
	game = malloc(sizeof(t_game));
	if (!game)
		exit_program(game, "Error\nError allocating memory for game\n");
	M_TRACK;
	game->map = init_map_struct(game);
	game->moves = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->wall_img = NULL;
	game->floor_img = NULL;
	game->collectable_img = NULL;
	game->player_img = NULL;
	game->exit_img = NULL;
	return (game);
}

t_map	*init_map_struct(t_game *game)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit_program(game, "Error\nError allocating memory for map\n");
	M_TRACK;
	map->grid = NULL;
	map->grid_copy = NULL;
	map->width = 0;
	map->height = 0;
	map->collects = 0;
	map->exits = 0;
	map->players = 0;
	map->map_name = NULL;
	map->player_pos.x = 0;
	map->player_pos.y = 0;
	return (map);
}
