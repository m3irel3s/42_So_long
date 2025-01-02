/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:13:08 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/02 19:23:31 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_validation(t_game *game, t_map *map)
{
	set_map_height(game, map);
	map_name_checker(game, map);
	populate_map_grid(game, map);
	check_width_and_set(game, map);
	check_chars(game, map);
	set_player_position(map);
	set_exit_position(map);
	check_walls(game, map);
	check_valid_path(game, map);
	return (0);
}

void	populate_map_grid(t_game *game, t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(map->map_name, O_RDONLY);
	if (fd == -1)
		exit_program(game, "Error\nError opening the file descriptor\n", 2);
	map->grid = malloc(sizeof(char *) * map->height);
	if (!map->grid)
		exit_program(game, "Error\nError allocating memory for map->grid\n", 2);
	line = get_next_line(fd);
	while (line && *line)
	{
		map->grid[i] = malloc(sizeof(char) * ft_strlen(line) + 1);
		if (!map->grid[i])
			exit_program(game, "Error\nError allocating memory for \
map->grid[i]\n", 2);
		ft_strlcpy(map->grid[i], line, ft_strlen(line) + 1);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	check_width_and_set(t_game *game, t_map *map)
{
	int	*tab;
	int	i;

	i = 0;
	tab = populate_grid_line_sizes(game, map);
	while (i < map->height - 1)
	{
		if (tab[i] != tab[i + 1])
		{
			free(tab);
			exit_program(game, "Error\nThe map is not a rectangle\n", 2);
		}
		i++;
	}
	map->width = tab[0];
	free(tab);
}

int	*populate_grid_line_sizes(t_game *game, t_map *map)
{
	int		*tab;
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(map->map_name, O_RDONLY);
	if (fd == -1)
		exit_program(game, "Error\nError opening the file descriptor\n", 2);
	tab = malloc(sizeof(int) * map->height + 1);
	if (!tab)
		exit_program(game, "Error\nFailed to allocate memory for tab\n", 2);
	while (i < map->height)
	{
		line = get_next_line(fd);
		tab[i++] = ft_strlen_to_new_line(line);
		free(line);
	}
	close(fd);
	return (tab);
}

void	check_walls(t_game *game, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
			exit_program(game, "Error\nFound another thing, \
except a wall!\n", 2);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
			exit_program(game, "Error\nFound another thing, \
except a wall!\n", 2);
		i++;
	}
}
