/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:20:09 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/19 17:32:01 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	render_win(t_game *game, t_map *map)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, map->width * 64, map->height * 64, "SO LONG");
	int i = 0;
	int j = 0;
	void	*img;
	int	size;
	size = 64;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->grid[i][j] == '1')
			{
				img = mlx_xpm_file_to_image(game->mlx, WALL, &size, &size);
				mlx_put_image_to_window(game->mlx, game->win, img, j * size, i * size);
			}
			else if (game->map->grid[i][j] == 'C')
			{
				img = mlx_xpm_file_to_image(game->mlx, COLLECTABLE, &size, &size);
				mlx_put_image_to_window(game->mlx, game->win, img, j * size, i * size);
			}
			else if (game->map->grid[i][j] == 'P')
			{
				img = mlx_xpm_file_to_image(game->mlx, PLAYER_FRONT, &size, &size);
				mlx_put_image_to_window(game->mlx, game->win, img, j * size, i * size);
			}
			else if (game->map->grid[i][j] == '0')
			{
				img = mlx_xpm_file_to_image(game->mlx, FLOOR, &size, &size);
				mlx_put_image_to_window(game->mlx, game->win, img, j * size, i * size);
			}
			else if (game->map->grid[i][j] == 'E')
			{
				img = mlx_xpm_file_to_image(game->mlx, EXIT, &size, &size);
				mlx_put_image_to_window(game->mlx, game->win, img, j * size, i * size);
			}
			j++;
		}
		i++;
	}
	set_player_position(map);
	printf("pos x => %d\n", map->player_pos->x);
	printf("pos y => %d\n", map->player_pos->y);
	mlx_key_hook(game->win, )
	mlx_loop(game->mlx);
}


