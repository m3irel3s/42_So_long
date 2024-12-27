/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_conditions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:57:05 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/27 17:07:57 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	is_valid_move(t_map *map, int x, int y)
{
	if (map->grid[x][y] == '1')
		return (0);
	if (map->grid[x][y] == 'E' && map->collects > 0)
		return (0);
	return (1);
}

void	update_collects(t_map *map, int x, int y)
{
	if (map->grid[x][y] == 'C')
		map->collects--;
}

void	update_position(t_game *game, int x, int y, void *new_img)
{
	t_map	*map;

	map = game->map;
	check_exit(game, map, x, y);
	replace_img(game, map->player_pos.x, map->player_pos.y, game->floor);
	map->grid[map->player_pos.x][map->player_pos.y] = '0';
	map->player_pos.x = x;
	map->player_pos.y = y;
	map->grid[x][y] = 'P';
	replace_img(game, x, y, new_img);
	game->moves++;
	render_moves(game);
}

void	check_exit(t_game *game, t_map *map, int x, int y)
{
	if (map->grid[x][y] == 'E' && map->collects == 0)
		exit_program(game, "Game Over! You've collected all items\n");
}
