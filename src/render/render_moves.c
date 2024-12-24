/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:37:07 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/24 00:36:47 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"


void render_moves(t_game *game)
{
	char *moves;
	void *img;
	int width = 64 * 3;
	int height = 64;
	int text_width = 0;
	int text_height = 20;
	
	moves = ft_itoa(game->moves);
	text_width = ft_strlen(moves) * 20;
	img = mlx_new_image(game->mlx, width, height);
	mlx_put_image_to_window(game->mlx, game->win, img, (game->map->width * 64 - width) / 2, game->map->height * 64);
	mlx_string_put(game->mlx, game->win, (game->map->width * 64 - text_width) / 2, game->map->height * 64 + (height - text_height) / 2, 0xFFFFFF, moves);
	
	free(moves);
}

