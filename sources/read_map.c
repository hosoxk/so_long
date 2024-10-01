/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-rudd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:43:21 by yde-rudd          #+#    #+#             */
/*   Updated: 2024/10/01 14:46:28 by yde-rudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	allocate_map_memory(t_map *map, const char *filename)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("Error:\nopening map"), exit(1));
	map->data = (char **)malloc(sizeof(char *) * map->height);
	if (!map->data)
		return (perror("Error:\nallocating height"), exit(1));
	line = get_next_line(fd);
	if (!line)
		return (ft_printf("Error:\nempty file or empty first line"), exit(1));
	while (line != NULL)
	{
		*map->data = ft_strdup(line);
		if (!*map->data)
			return (perror("Error:\nduplicating data into map"), exit(1));
		map->data++;
		line = get_next_line(fd);
	}
	free(line);
}

static void	set_map_height(t_map *map, int fd)
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
	close(fd);
}

t_map	read_map(const char *filename)
{
	t_map	map;
	int		fd;

	map.data = NULL;
	map.width = 0;
	map.height = 0;
	map.total_collectibles = 0;
	map.total_exits = 0;
	map.total_players = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error:\n");
		exit(1);
	}
	set_map_height(&map, fd);
	allocate_map_memory(&map, filename);
	close(fd);
	return (map);
}
