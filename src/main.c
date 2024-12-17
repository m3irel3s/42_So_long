/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:34:23 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/17 15:54:56 by jmeirele         ###   ########.fr       */
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
		set_map_height(game->map);
		map_name_checker(game->map);
		map_validation(game->map);
		free_grid(game->map);
		free_struct(game);
	}
	else
		ft_print_error("Error\n");
}
