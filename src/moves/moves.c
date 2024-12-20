/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:49:15 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/20 15:14:36 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void move_player_up(t_game *game, t_map *map)
{
    int x = map->player_pos.x;
	int y = map->player_pos.y;

	if (map->grid[map->player_pos.x - 1][map->player_pos.y] != '1')
	{
		if (map->grid[map->player_pos.x - 1][map->player_pos.y] == 'C')
			map->collects--;
		replace_img(game, x, y, game->floor_img);
		map->grid[map->player_pos.x][map->player_pos.y] = '0';
		map->player_pos.x -= 1;
		map->grid[map->player_pos.x][map->player_pos.y] = 'P';
		replace_img(game, map->player_pos.x, map->player_pos.y, game->player_img);
		game->moves++;
	}
}

void	move_player_down(t_game *game, t_map *map)
{
	int x = map->player_pos.x;
	int y = map->player_pos.y;
	if (map->grid[map->player_pos.x + 1][map->player_pos.y] != '1')
	{
		if (map->grid[map->player_pos.x + 1][map->player_pos.y] == 'C')
			map->collects--;
		replace_img(game, x, y, game->floor_img);
		map->grid[map->player_pos.x][map->player_pos.y] = '0';
		map->player_pos.x += 1;
		map->grid[map->player_pos.x][map->player_pos.y] = 'P';
		replace_img(game, map->player_pos.x, map->player_pos.y, game->player_img);
		game->moves++;
	}
}

void	move_player_left(t_game *game, t_map *map)
{
	int x = map->player_pos.x;
	int y = map->player_pos.y;
	if (map->grid[map->player_pos.x][map->player_pos.y - 1] != '1')
	{
		if (map->grid[map->player_pos.x][map->player_pos.y - 1] == 'C')
			map->collects--;
		replace_img(game, x, y, game->floor_img);
		map->grid[map->player_pos.x][map->player_pos.y] = '0';
		map->player_pos.y -= 1;
		map->grid[map->player_pos.x][map->player_pos.y] = 'P';
		replace_img(game, map->player_pos.x, map->player_pos.y, game->player_img);
		game->moves++;
	}
}

void	move_player_right(t_game *game, t_map *map)
{
	int x = map->player_pos.x;
	int y = map->player_pos.y;
	if (map->grid[map->player_pos.x][map->player_pos.y + 1] != '1')
	{
		if (map->grid[map->player_pos.x][map->player_pos.y + 1] == 'C')
			map->collects--;
		replace_img(game, x, y, game->floor_img);
		map->grid[map->player_pos.x][map->player_pos.y] = '0';
		map->player_pos.y += 1;
		map->grid[map->player_pos.x][map->player_pos.y] = 'P';
		replace_img(game, map->player_pos.x, map->player_pos.y, game->player_img);
		game->moves++;
	}
	
}

