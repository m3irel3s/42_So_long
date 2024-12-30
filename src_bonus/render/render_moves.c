/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:57:09 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/30 15:10:10 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	render_moves(t_game *game)
{
	char	*moves;
	char	*text;
	int		text_width;

	text_width = 0;
	moves = ft_itoa(game->moves);
	text = ft_strjoin("Current moves: ", moves);
	text_width = ft_strlen(text) * 10;
	if (!game->hud_moves)
		game->hud_moves = mlx_new_image(game->mlx, 192, 64);
	mlx_put_image_to_window(game->mlx, game->win, game->hud_moves,
		(game->map->width * 64 - 192) / 2, game->map->height * 64);
	mlx_string_put(game->mlx, game->win,
		(game->map->width * 64 - text_width) / 2,
		game->map->height * 64 + (64 - 20) / 2, 0xFFFFFF, text);
	free(moves);
	free(text);
}
