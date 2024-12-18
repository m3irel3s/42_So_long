/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chars_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:30:15 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/18 13:29:31 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	check_chars(t_game *game, t_map *map)
{
	if (count_occurs(map, 'P') != 1 || count_occurs(map, 'E') != 1 || count_occurs(map, 'C') == 0)
		ft_print_error(game, "Map with more than 1 exit, or more than 1 player, or dont have any collectables.\n");
	check_invalid_chars(game, map);
}

void	check_invalid_chars(t_game *game, t_map *map)
{
	char	*map_chars;
	int		i;
	int		j;

	map_chars = "01CEP\n";
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (!ft_strchr(map_chars, map->grid[i][j]))
				ft_print_error(game, "Found invalid char\n");
			j++;
		}
		i++;
	}
}

int	count_occurs(t_map *map, char c)
{
	int	i;
	int	j;
	int count;

	i = 0;
	count = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == c)
				count++;
			j++;
		}
	i++;
	}
	return (count);
}