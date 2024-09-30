#include "../so_long.h"

int	**initialize_visited(t_map *map)
{
	int	**visited;
	int	i;

	visted = (int **)malloc(map->height * sizeof (int *));
	if (!visited)
		perror_exit("Error:\n memory allocation failed", map);
	i = 0;
	while (i < map->height)
	{
		visited[i] = (int *)ft_calloc(map->width, sizeof (int));
		if (!visited[i])
		{
		perror_exit("Error:\n memory allocation failed", map);
		free_visited(visited, i);
		}
	}
	return visited;
}

t_point	*initialize_queue(t_map *map, t_point start, t_bfs_state *state)
{
	t_point	*queue

	queue = (t_point *)malloc(map->height * map->width * sizeof (t_point));
	if (!queue)
		perror_exit("Error:\n memory allocation failed", map);
	queue[state->rear++] = start;
	state->visited[start.x][start.y] = 1;
	return (queue);
}

void	explore_adjacent(t_map *map, t_point current, t_bfs_state *state)
{
	t_point	directions[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	int	new_x;
	int	new_y;
	int	i;

	while (i < 4)
	{
		new_x = current.x + directions[i].x;
		new_y = current.y + directions[i].y;
		if (is_valid(new_x, new_y, map, state->visited))
		{
			state->queue[state->rear++] = (t_point){new_x, new_y};
			state->visited[new_x][new_y] = 1;
		}
	i++;
	}
}

bool	is_valid(int x, int y, t_map *map, int **visited)
{
	if (x >= 0 && x < map->height && y >= 0 && y < map->width
		&& map->data[x][y] != WALL && !visited[x][y])
		return (true);
	return (false);
}

void	perror_exit(const char *message, t_map *map)
{
	perror(message);
	free_map_data(map);
	exit(1);
}
