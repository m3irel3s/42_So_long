/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:54:37 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/19 15:44:20 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	free_struct(t_game *game)
{
	if (game)
	{
		if (game->map)
		{
			if(game->map->player_pos)
				free(game->map->player_pos);
			free(game->map);
		}
	free(game);
	}
}

void	free_grid(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
		free(map->grid[i++]);
	free(map->grid);
}
