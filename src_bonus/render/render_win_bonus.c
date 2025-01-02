/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_win_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:20:09 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/02 16:58:58 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	render_win(t_game *game, t_map *map)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, map->width * 64,
			(map->height * 64) + 48, "SO LONG");
	preload_images(game);
	render_map(game, map);
	mlx_hook(game->win, KeyPress, KeyPressMask, handle_key_press, game);
	mlx_hook(game->win, DestroyNotify, 0, close_window, game);
	render_moves(game, map);
	mlx_loop(game->mlx);
}

void	render_map(t_game *game, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			print_current_img(game, map, i, j);
			j++;
		}
		i++;
	}
}

void	print_current_img(t_game *game, t_map *map, int i, int j)
{
	if (map->grid[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall, j * SIZE, i * SIZE);
	else if (map->grid[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collect, j * SIZE, i * SIZE);
	else if (map->grid[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->p_front, j * SIZE, i * SIZE);
	else if (map->grid[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->floor, j * SIZE, i * SIZE);
	else if (map->grid[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->closed_exit, j * SIZE, i * SIZE);
	else if (map->grid[i][j] == 'X')
		mlx_put_image_to_window(game->mlx, game->win,
			game->zombie, j * SIZE, i * SIZE);
}
