/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:34:23 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/23 22:16:57 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc == 2)
	{
		game = init_game_struct();
		game->map->map_name = argv[1];
		map_validation(game, game->map);
		render_win(game, game->map);
		free_struct(game);
	}
	else
		exit_program(game, "Error\n getting arguments\n");
}
