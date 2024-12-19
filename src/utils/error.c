/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:50:26 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/19 15:44:21 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_print_error(t_game *game, char *str)
{
	if(game)
	{
		free_grid(game->map);
		free_struct(game);
	}
	ft_putstr_fd(str, 2);
	exit(1);
}
