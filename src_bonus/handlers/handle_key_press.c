/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:24:56 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/30 15:32:18 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == XK_Up)
		move_player_up(game, game->map);
	else if (keycode == XK_Down)
		move_player_down(game, game->map);
	else if (keycode == XK_Left)
		move_player_left(game, game->map);
	else if (keycode == XK_Right)
		move_player_right(game, game->map);
	else if (keycode == XK_Escape)
		exit_program(game, "Game closed, pressed ESC\n");
	if (game->map->collects == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->opened_exit,
			game->map->exit_pos.y * 64, game->map->exit_pos.x * 64);
	return (0);
}

int	close_window(t_game *game)
{
	exit_program(game, "Game closed, pressed X\n");
	return (0);
}
