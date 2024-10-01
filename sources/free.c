/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-rudd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:55:36 by yde-rudd          #+#    #+#             */
/*   Updated: 2024/10/01 13:49:40 by yde-rudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map_data(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->data[i]);
		i++;
	}
	free(map->data);
}

void	free_visited(int **visited, int up_to)
{
	int	i;

	i = 0;
	while (i < up_to)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	cleanup(int **visited, t_point *queue, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
	free(queue);
}
