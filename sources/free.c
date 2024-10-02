/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-rudd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:55:36 by yde-rudd          #+#    #+#             */
/*   Updated: 2024/10/02 20:54:43 by yde-rudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_gnl(int fd, char *line)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
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
