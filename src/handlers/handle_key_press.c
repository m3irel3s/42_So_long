/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:24:56 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/23 22:39:40 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

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
		exit_program(game, "Game closed, pressed escape\n");
	printf("Player position => x:[%d] y:[%d]\n", game->map->player_pos.x, game->map->player_pos.y);
	printf("Moves => %d\n", game->moves);
	printf("Collects => %d\n", game->map->collects);
	render_moves(game);
	return (0);
}