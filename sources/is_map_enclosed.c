/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_enclosed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-rudd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:35:13 by yde-rudd          #+#    #+#             */
/*   Updated: 2024/10/02 19:53:37 by yde-rudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	check_first_and_last_column(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->data[i][0] != WALL || map->data[i][map->width - 1] != WALL)
			return (ft_printf("Error:\nfirst or last column,"
					" row %d is not enclosed\n", i + 1), false);
		i++;
	}
	return (true);
}

static bool	check_first_and_last_row(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->data[0][i] != WALL || map->data[map->height -1][i] != WALL)
			return (ft_printf("Error:\nfirst or last row,"
					" column %d is not enclosed\n", i + 1), false);
		i++;
	}
	return (true);
}

bool	is_map_enclosed(t_map *map)
{
	if (check_first_and_last_row(map) && check_first_and_last_column(map))
		return (true);
	return (false);
}
