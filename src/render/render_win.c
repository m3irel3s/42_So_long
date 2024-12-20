/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:20:09 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/20 15:52:37 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"


void	render_win(t_game *game, t_map *map)
{
	set_player_position(map);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, map->width * 64, map->height * 64, "SO LONG");
	preload_images(game);
	render_map(game, map);
	mlx_hook(game->win, KeyPress, KeyPressMask, handle_key_press, game);
	mlx_loop(game->mlx);
}

void render_map(t_game *game, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img, j * SIZE, i * SIZE);
			else if (map->grid[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collectable_img, j * SIZE, i * SIZE);
			else if (map->grid[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player_img, j * SIZE, i * SIZE);
			else if (map->grid[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor_img, j * SIZE, i * SIZE);
			else if (map->grid[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img, j * SIZE, i * SIZE);
			j++;
		}
		i++;
	}
}




