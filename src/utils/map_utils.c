/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:48:02 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/17 15:29:05 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	set_map_height(t_map *map)
{
	int		rows;
	int		fd;
	char	*line;

	rows = 0;
	fd = open(map->map_name, O_RDONLY);
	if (!fd)
		ft_print_error("Error opening the file descriptor\n");
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