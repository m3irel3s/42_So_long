/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:24:43 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/02 16:14:38 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	check_valid_path(t_game *game, t_map *map)
{
	dup_grid(game, map);
	flood_fill(map->grid_copy, map->player_pos.x, map->player_pos.y);
	if (count_occurs(map, map->grid_copy, 'C') > 0
		|| count_occurs(map, map->grid_copy, 'E') > 0)
		exit_program(game, "Error\nInvalid path, not possible\
 to complete the game!\n", 2);
}

void	flood_fill(char **copy, int x, int y)
{
	if (copy[x][y] == '1' || copy[x][y] == 'V' || copy[x][y] == 'X')
		return ;
	if (copy[x][y] == 'E')
	{
		copy[x][y] = 'V';
		return ;
	}
	if (copy[x][y] == '0' || copy[x][y] == 'C')
		copy[x][y] = 'V';
	flood_fill(copy, x - 1, y);
	flood_fill(copy, x + 1, y);
	flood_fill(copy, x, y - 1);
	flood_fill(copy, x, y + 1);
}
