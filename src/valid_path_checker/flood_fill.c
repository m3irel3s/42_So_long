/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:24:43 by jmeirele          #+#    #+#             */
/*   Updated: 2024/12/23 12:24:14 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	flood_fill(char **copy, int x, int y)
{
	if (copy[x][y] == '1' || copy[x][y] == 'V')
		return ;
	if (copy[x][y] == 'E')
	{
		copy[x][y] = 'V';
		return ;
	}
	if (copy[x][y] == '0' || copy[x][y] == 'C')
		copy[x][y] = 'V';

	flood_fill(copy, x - 1, y);
	flood_fill(copy, x + 1, y);
	flood_fill(copy, x, y - 1);
	flood_fill(copy, x, y + 1);
}


