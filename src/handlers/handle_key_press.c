/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:24:56 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/19 17:31:59 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	key_press(int keycode, void *param)
{
	if (keycode == 119)
		move_player_up(game);
	else if (keycode == 115)
		move_player_down(game);
	else if (keycode == 97)
		move_player_left(game);
	else if (keycode == 100)
		move_player_right(game);
	else if (keycode == 53)
		ft_print_error(game, "Game closed, pressed escape\n");
}