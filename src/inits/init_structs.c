/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:01:33 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/02 16:09:01 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_game	*init_game_struct(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		exit_program(game, "Error\nError allocating memory for game\n", 2);
	game->map = init_map_struct(game);
	game->moves = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->wall = NULL;
	game->floor = NULL;
	game->collect = NULL;
	game->p_front = NULL;
	game->p_back = NULL;
	game->p_right = NULL;
	game->p_left = NULL;
	game->closed_exit = NULL;
	game->opened_exit = NULL;
	return (game);
}

t_map	*init_map_struct(t_game *game)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit_program(game, "Error\nError allocating memory for map\n", 2);
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
