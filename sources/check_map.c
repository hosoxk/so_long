#include "../so_long.h"

static bool	check_illegal_characters(char **data)
{
	if (data != 'C' || data != 'E' || data !=  'P' || data != '1' || data != '0')
	{
		ft_printf("Error:\nfound illegal characters in map");
		free_map_data(map);
		exit(1);
	}
}

bool	is_map_valid(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			check_illegal_characters(map->data[i][j]);
			j++;
		}
		i++;
	}
}
