/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preload_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:31:25 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/27 16:50:02 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	preload_images(t_game *game)
{
	int	size;

	size = 64;
	game->wall = mlx_xpm_file_to_image(game->mlx, WALL, &size, &size);
	game->floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &size, &size);
	game->collect = mlx_xpm_file_to_image(game->mlx, COLLECT, &size, &size);
	game->p_front = mlx_xpm_file_to_image(game->mlx, P_FRONT, &size, &size);
	game->p_back = mlx_xpm_file_to_image(game->mlx, P_BACK, &size, &size);
	game->p_right = mlx_xpm_file_to_image(game->mlx, P_RIGHT, &size, &size);
	game->p_left = mlx_xpm_file_to_image(game->mlx, P_LEFT, &size, &size);
	game->closed_exit = mlx_xpm_file_to_image(game->mlx, C_EXIT, &size, &size);
	game->opened_exit = mlx_xpm_file_to_image(game->mlx, O_EXIT, &size, &size);
}
