/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:11:17 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/17 12:49:38 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	map_name_checker(t_map *map)
{
	char	*extension;

	extension = ft_strrchr(map->map_name, '.');
	if (extension && ft_strcmp(extension, ".ber") == 0)
		return (0);
	return (1);
}