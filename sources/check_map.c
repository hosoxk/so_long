#include "../so_long.h"

static bool	check_illegal_characters(char **data)
{
	if (data != 'C' && data != 'E' && data !=  'P'
		&& data != '1' && data != '0')
	{
		ft_printf("Error:\nfound illegal characters in map");
		free_map_data(map);
		exit(1);
	}
}

static void	count_elements(char **data, bool *exit, bool *player, t_map *map)
{
	if (data == 'E')
		*exit = true;
	else if (data == 'P')
		*player = true;
	else if (data == 'C')
		map->total_collectibles++;
}

bool	is_map_valid(t_map *map)
{
	int	i;
	int	j;
	bool	*exit_available;
	bool	*player_available;

	i = 0;
	exit_available = false;
	player_available = false;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			check_illegal_characters(map->data[i][j]);
			count_elements(map->data[i][j], &exit_available, *player_available);
			j++;
		}
		i++;
	}
}
