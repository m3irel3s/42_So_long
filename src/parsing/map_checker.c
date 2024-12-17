/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:13:08 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/17 15:31:06 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
int	map_checker(t_map *map)
{
	populate_map_grid(map);
	int i = 0;
	while (i < map->height)
	{
		printf("%s", map->grid[i++]);
	}
	return 0;
}

void	populate_map_grid(t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(map->map_name, O_RDONLY);
	map->grid = malloc(sizeof(char *) * map->height);
	line = get_next_line(fd);
	while (line && *line)
	{
		map->grid[i] = malloc(sizeof(char) * ft_strlen(line));
		ft_strlcpy(map->grid[i], line, ft_strlen(line) + 1);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

