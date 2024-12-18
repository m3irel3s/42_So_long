/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:13:08 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/18 16:44:47 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
int	map_validation(t_game *game, t_map *map)
{
	populate_map_grid(game, map);
	check_width_and_set(game, map);
	check_chars(game, game->map);
	return 0;
}

void	populate_map_grid(t_game *game, t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(map->map_name, O_RDONLY);
	if (fd == -1)
		ft_print_error(game, "Error opening the file descriptor\n");
	map->grid = malloc(sizeof(char *) * map->height);
	M_TRACK;
	line = get_next_line(fd);
	while (line && *line)
	{
		map->grid[i] = malloc(sizeof(char) * ft_strlen(line) + 1);
		M_TRACK;
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
	int		i;
	int		fd;
	char	*line;
	int		size;
	int		ref;

	fd = open(map->map_name, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	ref = ft_strlen_to_new_line(line);
	while (i < map->height)
	{
		size = ft_strlen_to_new_line(line);
		if (size != ref)
		{
			close(fd);
			free(line);
			ft_print_error(game, "Found different width!\n");
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	map->width = ref;
}
