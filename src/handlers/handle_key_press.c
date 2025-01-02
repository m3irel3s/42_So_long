/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:24:56 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/02 20:46:12 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == XK_Up || keycode == 'w')
		move_player_up(game, game->map);
	else if (keycode == XK_Down || keycode == 's')
		move_player_down(game, game->map);
	else if (keycode == XK_Left || keycode == 'a')
		move_player_left(game, game->map);
	else if (keycode == XK_Right || keycode == 'd')
		move_player_right(game, game->map);
	else if (keycode == XK_Escape)
		exit_program(game, "Game closed, pressed escape\n", 1);
	if (game->map->collects == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->opened_exit,
			game->map->exit_pos.y * 64, game->map->exit_pos.x * 64);
	return (0);
}

int	close_window(t_game *game)
{
	exit_program(game, "Game closed by clicking on the X\n", 1);
	return (0);
}
