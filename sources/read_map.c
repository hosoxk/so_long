#include "../so_long.h"

static void	allocate_memory(t_map *map)
{
	int	i;

	map->data = (char **)malloc(sizeof(char *) * map->heigth);
	if (!map->data)
	{
		perror("Error:\n");
		exit(1);
	}
	i = 0;
	while (i < map->height)
	{
		map->data[i] = (char *)malloc(sizeof(char *) * (map->width + 1));
		if (!map->data[i])
		{
			perror("Error:\n");
			exit(1);
		}
		i++;
	}
}

static void	set_map_width(t_map *map, int fd, char **data)
{
	char	*line;
	int	i;

	line = get_next_line(fd);
	map->width = ft_strlen(line);
	if (!line)
	{
		ft_printf("Error:\nempty map or empty line");
		exit(1);
	}
	allocate_map_memory(map);
	i = 0;
	while (line != NULL)
	{
		if (ft_strlen(line) != map->width)
		{
			ft_printf("Error:\ninconsistent map width");
			exit(1);
		}
		ft_strcpy(map->data[i], line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
}

static void	set_map_height(t_map *map, int fd, char **data)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Error:\nempty map or empty line");
		exit(1);
	}
	while (line != NULL)
	{
		map->height++;
		line = get_next_line(fd);
	}
	free(line);
}

t_map	read_map(const char *filename)
{
	t_map	map;
	int	fd;

	map.data = NULL;
	map.width = 0;
	map.height = 0;
	map.total_collectibles = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error:\n");
		exit(1);
	}
	set_map_height(&map, fd, &map.data);
	set_map_width(&map, fd, &map.data);
	close(fd);
}
