/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:54:37 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/30 15:14:38 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

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
		if (game->wall)
			mlx_destroy_image(game->mlx, game->wall);
		if (game->floor)
			mlx_destroy_image(game->mlx, game->floor);
		if (game->collect)
			mlx_destroy_image(game->mlx, game->collect);
		if (game->p_front)
			mlx_destroy_image(game->mlx, game->p_front);
		if (game->p_right)
			mlx_destroy_image(game->mlx, game->p_right);
		if (game->p_left)
			mlx_destroy_image(game->mlx, game->p_left);
		if (game->p_back)
			mlx_destroy_image(game->mlx, game->p_back);
		if (game->closed_exit)
			mlx_destroy_image(game->mlx, game->closed_exit);
		if (game->opened_exit)
			mlx_destroy_image(game->mlx, game->opened_exit);
		if (game->zombie)
			mlx_destroy_image(game->mlx, game->zombie);
		if (game->hud_moves)
			mlx_destroy_image(game->mlx, game->hud_moves);
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
