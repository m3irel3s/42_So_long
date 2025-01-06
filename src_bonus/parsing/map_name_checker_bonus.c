/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name_checker_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:11:17 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/06 10:52:04 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	map_name_checker(t_game *game, t_map *map)
{
	char	*extension;
	char	*to_compare;

	extension = ft_strrchr(map->map_name, '.');
	to_compare = ft_strrchr(map->map_name, '/');
	if (extension && (ft_strcmp(extension, ".ber") == 0)
		&& (ft_strlen(to_compare) > 5))
		return ;
	exit_program(game, "Error\nMap name invalid\n", 2);
}
