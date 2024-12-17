/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:54:37 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/17 12:33:09 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	free_struct(t_game *game)
{
	if (game)
	{
		if (game->map)
		{
			if(game->map->player_pos)
				free(game->map->player_pos);
			free(game->map);
		}
	free(game);
	}
}
