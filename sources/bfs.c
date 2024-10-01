/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-rudd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:51:50 by yde-rudd          #+#    #+#             */
/*   Updated: 2024/10/01 12:51:52 by yde-rudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_bfs_state(t_bfs_state *state, t_map *map, t_point start)
{
	state->front = 0;
	state->rear = 0;
	state->collectibles_found = 0;
	state->exit_reached = 0;
	state->visited = initialize_visited(map);
	state->queue = initialize_queue(map, start, state);
}

static void	process_nodes(t_bfs_state *state, t_map *map)
{
	t_point	current;

	while (state->front < state->rear)
	{
		current = state->queue[state->front++];
		if (map->data[current.x][current.y] == COLLECTIBLE)
			state->collectibles_found++;
		else if (map->data[current.x][current.y] == EXIT)
			state->exit_reached = 1;
		explore_adjacent(map, current, state);
	}
}

bool	bfs(t_map *map, t_point start, int total_collectibles)
{
	t_bfs_state	state;

	init_bfs_state(&state, map, start);
	process_nodes(&state, map);
	cleanup(state.visited, state.queue, map);
	if (state.collectibles_found == total_collectibles && state.exit_reached)
		return (true);
	ft_printf("Error: Some collectibles or exit are not reachable.\n");
	exit(1);
}
