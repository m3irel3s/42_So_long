/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:42:10 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/27 15:51:22 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	replace_img(t_game *game, int x, int y, void *new_img)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->floor, y * SIZE, x * SIZE);
	mlx_put_image_to_window(game->mlx, game->win,
		new_img, y * SIZE, x * SIZE);
}
