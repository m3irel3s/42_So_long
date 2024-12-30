/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chars_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:30:15 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/30 14:30:13 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	check_chars(t_game *game, t_map *map)
{
	if (count_occurs(map, map->grid, 'P') != 1 || count_occurs
		(map, map->grid, 'E') != 1 || count_occurs(map, map->grid, 'C') == 0)
		exit_program(game, "Error\nMap with more than 1 exit, or more than \
1 player, or don't have any collectables.\n");
	map->collects = count_occurs(map, map->grid, 'C');
	map->exits = 1;
	map->players = 1;
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
		while (j < map->width)
		{
			if (!ft_strchr(map_chars, map->grid[i][j]))
				exit_program(game, "Error\nFound invalid char\n");
			j++;
		}
		i++;
	}
}

int	count_occurs(t_map *map, char **grid, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->grid[i][j])
		{
			if (grid[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
