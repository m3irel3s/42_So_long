/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:11:17 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/02 16:11:52 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	map_name_checker(t_game *game, t_map *map)
{
	char	*extension;

	extension = ft_strrchr(map->map_name, '.');
	if (extension && ft_strcmp(extension, ".ber") == 0)
		return ;
	exit_program(game, "Error\nMap name invalid\n", 2);
}
