/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:57:09 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/02 15:45:58 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	render_moves(t_game *game, t_map *map)
{
	char	*moves;
	char	*text;
	int		text_width;

	text_width = 0;
	moves = ft_itoa(game->moves);
	text = ft_strjoin("Current moves: ", moves);
	text_width = ft_strlen(text) * 7;
	if (!game->hud_moves)
		game->hud_moves = mlx_new_image(game->mlx, map->width * 64, 48);
	mlx_put_image_to_window(game->mlx, game->win, game->hud_moves, 0,
		map->height * 64);
	mlx_string_put(game->mlx, game->win, (map->width * 64 / 2)
		-(text_width / 2), map->height * 64 + 26, 0xFFFFFF, text);
	free(moves);
	free(text);
}
