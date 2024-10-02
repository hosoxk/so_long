/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flooding_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-rudd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:06:42 by yde-rudd          #+#    #+#             */
/*   Updated: 2024/10/02 22:56:41 by yde-rudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	flooding_algo(char **data, int y, int x)
{
	data[y][x] = '1';
	if (data[y - 1][x] != '1')
		flooding_algo(data, y - 1, x);
	if (data[y + 1][x] != '1')
		flooding_algo(data, y + 1, x);
	if (data[y][x - 1] != '1')
		flooding_algo(data, y, x - 1);
	if (data[y][x + 1] != '1')
		flooding_algo(data, y, x + 1);
}

static bool	check_flooded_map(char **data)
{
	int	i;
	int	j;

	i = 0;
	while (data[i] != NULL)
	{
		j = 0;
		while (data[i][j] != '\0')
		{
			if (data[i][j] == 'C' || data[i][j] == 'E')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	checking_algo(char **data, t_point start)
{
	char	**copy_map;
	bool	ret;

	copy_map = ft_cpyarr(data);
	if (!copy_map)
		return (ft_freearr(data), ft_printf("Error:\nfailed memory allocation"
				" for copy map\n"), exit(1), false);
	flooding_algo(copy_map, start.y, start.x);
	if (!check_flooded_map(copy_map))
		ret = false;
	else
		ret = true;
	ft_freearr(copy_map);
	return (ret);
}
