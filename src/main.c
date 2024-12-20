/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:34:23 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/20 16:33:43 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int main(int argc, char **argv)
{
	t_game	*game;
	t_map	*map;
	t_pos	*pos;

	game = NULL;
	map = NULL;
	pos = NULL;
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
