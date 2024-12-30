/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:07:53 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/30 14:41:51 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_player_up(t_game *game, t_map *map)
{
	int	x;
	int	y;

	x = map->player_pos.x;
	y = map->player_pos.y;
	if (is_valid_move(map, x - 1, y))
	{
		update_collects(map, x - 1, y);
		update_position(game, x - 1, y, game->p_back);
	}
}

void	move_player_down(t_game *game, t_map *map)
{
	int	x;
	int	y;

	x = map->player_pos.x;
	y = map->player_pos.y;
	if (is_valid_move(map, x + 1, y))
	{
		update_collects(map, x + 1, y);
		update_position(game, x + 1, y, game->p_front);
	}
}

void	move_player_left(t_game *game, t_map *map)
{
	int	x;
	int	y;

	x = map->player_pos.x;
	y = map->player_pos.y;
	if (is_valid_move(map, x, y - 1))
	{
		update_collects(map, x, y - 1);
		update_position(game, x, y - 1, game->p_left);
	}
}

void	move_player_right(t_game *game, t_map *map)
{
	int	x;
	int	y;

	x = map->player_pos.x;
	y = map->player_pos.y;
	if (is_valid_move(map, x, y + 1))
	{
		update_collects(map, x, y + 1);
		update_position(game, x, y + 1, game->p_right);
	}
}
