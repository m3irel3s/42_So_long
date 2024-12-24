/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preload_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:31:25 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/23 22:01:13 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	preload_images(t_game *game)
{
	int	size;

	size = 64;
	game->wall_img = mlx_xpm_file_to_image(game->mlx, WALL, &size, &size);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, FLOOR, &size, &size);
	game->collectable_img = mlx_xpm_file_to_image(game->mlx, COLLECTABLE, &size, &size);
	game->player_img = mlx_xpm_file_to_image(game->mlx, PLAYER_FRONT, &size, &size);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, EXIT, &size, &size);
}
