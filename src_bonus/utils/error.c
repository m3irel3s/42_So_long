/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:50:26 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/27 16:50:02 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	exit_program(t_game *game, char *str)
{
	if (game)
		free_struct(game);
	ft_putstr_fd(str, 2);
	exit(1);
}
