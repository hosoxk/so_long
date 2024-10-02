/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-rudd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:24:00 by yde-rudd          #+#    #+#             */
/*   Updated: 2024/10/02 23:10:00 by yde-rudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_point	find_player_pos(t_map *map)
{
	int		i;
	int		j;
	t_point	player;

	player.x = -1;
	player.y = -1;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->data[i][j] == PLAYER)
			{
				player.y = i;
				player.x = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (player);
}

static void	check_illegal_characters(t_map *map, int i, int j)
{
	if (map->data[i][j] != 'C' && map->data[i][j] != 'E'
			&& map->data[i][j] != 'P' && map->data[i][j] != '1'
			&& map->data[i][j] != '0')
	{
		ft_printf("Error:\nfound illegal characters in map: %c\n",
			map->data[i][j]);
		ft_freearr(map->data);
		exit(1);
	}
}

static void	count_elements(char data, t_map *map)
{
	if (data == 'E')
		map->total_exits++;
	else if (data == 'P')
		map->total_players++;
	else if (data == 'C')
		map->total_collectibles++;
}

bool	is_map_valid(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			check_illegal_characters(map, i, j);
			count_elements(map->data[i][j], map);
			j++;
		}
		i++;
	}
	if (map->total_collectibles == 0 || map->total_exits != 1
		|| map->total_players != 1 || !is_map_enclosed(map))
		return (ft_printf("Error:\ninvalid amount of items\n"), false);
	if (!checking_algo(map->data, find_player_pos(map)))
		return (ft_printf("Error:\nitems or exit not reachable\n"), false);
	return (true);
}
