/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:50:26 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/02 16:13:22 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	exit_program(t_game *game, char *str, int fd)
{
	if (game)
		free_struct(game);
	ft_putstr_fd(str, fd);
	exit(1);
}
