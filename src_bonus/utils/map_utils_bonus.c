/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:48:02 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/02 19:43:46 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	set_map_height(t_game *game, t_map *map)
{
	int		rows;
	int		fd;
	char	*line;

	rows = 0;
	fd = open(map->map_name, O_RDONLY);
	if (fd == -1)
		exit_program(game, "Error\nError opening the file descriptor\n", 2);
	line = get_next_line(fd);
	while (line && *line)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	map->height = rows;
	close(fd);
}

void	dup_grid(t_game *game, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->grid_copy = malloc(sizeof(char *) * map->height);
	if (!map->grid_copy)
		exit_program(game, "Error\nFailed to allocate memory for grid \
copy\n", 2);
	while (i < map->height)
	{
		j = 0;
		map->grid_copy[i] = malloc(sizeof(char) * map->width + 1);
		if (!map->grid_copy[i])
			exit_program(game, "Error\nFailed to allocate memory for grid \
 copy\n", 2);
		while (j < map->width)
		{
			map->grid_copy[i][j] = map->grid[i][j];
			j++;
		}
		map->grid_copy[i][j] = '\0';
		i++;
	}
}
