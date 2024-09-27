/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-rudd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:26:17 by yde-rudd          #+#    #+#             */
/*   Updated: 2024/09/17 11:13:08 by yde-rudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char			*new_line;
	static char		*buffer;

	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0 || read (fd, 0, 0) < 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = read_from_file(fd, buffer);
	if (!buffer)
		return (NULL);
	new_line = line_from_buffer(buffer);
	buffer = update_buffer(buffer);
	return (new_line);
}

char	*free_buffer(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*update_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!buffer[0])
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*line_from_buffer(char *buffer)
{
	char	*line;
	int		length;
	int		allocate_length;

	if (!buffer)
		return (NULL);
	if (!buffer[0])
		return (NULL);
	length = 0;
	while (buffer[length] && buffer[length] != '\n')
		length++;
	allocate_length = length + 1;
	if (buffer[length] == '\n')
		allocate_length++;
	line = NULL;
	line = handle_line(line, buffer, allocate_length);
	return (line);
}

char	*read_from_file(int fd, char *current_content)
{
	char	*buffer;
	int		bytes_read;

	if (!current_content)
		current_content = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = 0;
		current_content = free_buffer(current_content, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free (buffer);
	return (current_content);
}
