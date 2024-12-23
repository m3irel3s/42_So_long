/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:54:37 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/23 22:08:51 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	free_struct(t_game *game)
{
	if (game)
	{
		if (game->map)
		{
			if (game->map->grid_copy)
				free_grid(game->map, game->map->grid_copy);
			free_grid(game->map, game->map->grid);
			free(game->map);
		}
		free_images(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
			mlx_destroy_display(game->mlx);
		free(game->mlx);
		free(game);
	}
}

void	free_images(t_game *game)
{
	if (game->mlx)
	{
		if (game->wall_img)
			mlx_destroy_image(game->mlx, game->wall_img);
		if (game->floor_img)
			mlx_destroy_image(game->mlx, game->floor_img);
		if (game->collectable_img)
			mlx_destroy_image(game->mlx, game->collectable_img);
		if (game->player_img)
			mlx_destroy_image(game->mlx, game->player_img);
		if (game->exit_img)
			mlx_destroy_image(game->mlx, game->exit_img);
	}
}

void	free_grid(t_map *map, char **grid)
{
	int	i;

	if (grid)
	{
		i = 0;
		while (i < map->height)
			free(grid[i++]);
		free(grid);
	}	
}
