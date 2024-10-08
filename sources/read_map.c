/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-rudd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:43:21 by yde-rudd          #+#    #+#             */
/*   Updated: 2024/10/08 12:08:52 by yde-rudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	is_ber_file(const char *filename)
{
	const char	*dot;

	dot = ft_strrchr(filename, '.');
	if (dot && (ft_strcmp(dot, ".ber") == 0))
		return (true);
	else
		return (ft_printf("Error:\nfile is no .ber file\n"),
			false);
}

static void	allocate_map_memory(t_map *map)
{
	map->data = (char **)malloc(sizeof (char *) * (map->height + 1));
	if (map->data == NULL)
	{
		perror("Error:\nmemory allocation for height failed\n");
		exit(1);
	}
}

static void	set_map_width_and_height(t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (ft_printf("Error:\nempty file\n"),
			close(fd), exit(1));
	map->width = ft_strlen_map(line);
	while (line != NULL)
	{
		if (line[0] == '\n')
			return (ft_printf("Error:\nempty line at %d\n", map->height + 1),
				free_gnl(fd, line), exit(1));
		if (map->width != (int)ft_strlen_map(line))
			return (ft_printf("Error:\ninconsistent map width\n"),
				free_gnl(fd, line), exit(1));
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
}

static void	read_in_map_data(t_map *map, int fd, const char *filename)
{
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("Error:\nopening file\n"), ft_freearr(map->data),
			exit(1));
	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (ft_freearr(map->data), close(fd), exit(1));
	while (line != NULL)
	{
		line[map->width] = '\0';
		map->data[i] = ft_strdup(line);
		if (!map->data[i])
			return (ft_freearr(map->data), free_gnl(fd, line), ft_printf(
					"Error:\nfailed to allocate memory for line\n"), exit(1));
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map->data[i] = NULL;
	close(fd);
}

t_map	read_map(const char *filename)
{
	t_map	map;
	int		fd;

	init_map(&map);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error:\nopening file\n");
		exit(1);
	}
	if (!is_ber_file(filename))
	{
		close(fd);
		exit(1);
	}
	set_map_width_and_height(&map, fd);
	close(fd);
	allocate_map_memory(&map);
	read_in_map_data(&map, fd, filename);
	return (map);
}
